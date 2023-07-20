
#include <string>
#include <iostream>
#include <ctime>

#include "CUartLog.h"
#include "getopt.h"

#include <windows.h>

#include <boost/bind.hpp>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>


using namespace std;

std::string CUartLog::s_WindowsPuttyPath = "\"C:\\Program Files (x86)\\PuTTY\\putty.exe\"";


//std::shared_ptr<boost::asio::serial_port> CUartLog::mSerialPort = nullptr;

CUartLog::CUartLog(): mIoService(), mUartLoggerThread()
{
	//mSerialPort = new boost::asio::serial_port(mIoService);
	mSerialPort = std::shared_ptr<boost::asio::serial_port>(new boost::asio::serial_port(mIoService));

}

CUartLog::~CUartLog()
{
	//delete mSerialPort;
	CloseSerialPort();
}



std::string CUartLog::GetCurrentUartPortName()
{
	std::string uartPort = "";
	std::string uartPortsPath;
	int currentModule = 0;
#ifdef __ANDROID__
	uartPortsPath = "//sdcard//AutomationData//UartPorts.ini";

#elif __linux__
	uartPortsPath = "//opt//AutomationData//UartPorts.ini";

#elif _WIN32
	uartPortsPath = "C:\\AutomationData\\UartPorts.ini";
#endif

	try
	{
		boost::property_tree::ptree pt;
		boost::property_tree::ini_parser::read_ini(uartPortsPath, pt);
		uartPort = pt.get<std::string>("UartPorts." + std::to_string(currentModule));
		cout<<"uartPort:"<<uartPort<<endl;
	}
	catch(exception e)
	{
		 uartPort = "";
		 cout << "CGlobal::GetCurrentUartPortName: failed to read uart port name from " << uartPortsPath<<" file. Error - "<<e.what()<<endl;		
	}
	return uartPort;
}


void CUartLog::InitUartLogger(std::string iPortName, std::string iFilePath, int iBaudRate)
{
	mPortName = iPortName;
	mFilePath = iFilePath;
	mBaudRate = iBaudRate;
}


int CUartLog::StartSavingUartLogsSerialPort()
{
	int ret = OpenSerialPort();
	if (ret != 0)
	{
		cout<<"CUartLog Error: OpenSerialPort failed!"<<endl;
		return -1;
	}
	
	cout<<"CUartLogger: Serial port " << mPortName << " successfully opened in the following baud rate: "
		<< std::to_string(mBaudRate)<<endl;

	if (boost::filesystem::exists(mFilePath))
	{
		boost::filesystem::remove(mFilePath);
		Sleep(5000);//5000 ms
	}
	
	StartReadingFromPortToFile();
	
	std::thread t(boost::bind(&boost::asio::io_service::run, &mIoService));
	mUartLoggerThread.swap(t);

	cout << "CUartLogger: Starting reading from serial port" <<endl;
	return 0;
}


void CUartLog::StartReadingFromPortToFile()
{
	mSerialPort->async_read_some(boost::asio::buffer(mReadMessageBuffer, BUFFER_SIZE),
		boost::bind(&CUartLog::FileAsyncReadHandler, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

}

void CUartLog::FileAsyncReadHandler(const boost::system::error_code iError, size_t iBytesTransferred)
{
	if(iError == boost::system::errc::success)
	{
		mReadMessageBuffer[iBytesTransferred] = 0;
		std::ofstream mFileStream(mFilePath, std::ios::app);
		if (mFileStream.is_open())
		{	
#if 0
			time_t now = time(nullptr);
			tm* curr_tm = localtime(&now);
			char time[80] = {0};
			strftime(time,80,"[%Y-%m-%d %H:%M:%S]",curr_tm);
			mFileStream << time;
#endif
			mFileStream << mReadMessageBuffer;
			mFileStream.close();
		}
	}
	
	StartReadingFromPortToFile();
}

int CUartLog::OpenSerialPort()
{
	boost::system::error_code error;
	mSerialPort->open(mPortName, error);
	Sleep(2000);//2000 ms
 	if (error != boost::system::errc::success)
	{
		cout << "CUartLogger: Failed to open serial port: " << mPortName <<
			" with the following baud rate: " << std::to_string(mBaudRate) << ". Error - " << error.message()<<endl;
		return -1;		
	}

	mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(mBaudRate), error);
	if (error != boost::system::errc::success)
	{
		cout << "CUartLogger: Failed to set baud rate of: " << std::to_string(mBaudRate) << 
			" to serial port: " << mPortName << ". Error - " << error.message()<<endl;
		CloseSerialPort();
		return -1;
	}

	mSerialPort->set_option(boost::asio::serial_port_base::character_size(8));
	mSerialPort->set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
	mSerialPort->set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
	
	return 0;
}

int CUartLog::CloseSerialPort()
{
	cout << "CUartLogger: Closing serial port: " << mPortName<<endl;
	
	boost::system::error_code error;
	mSerialPort->cancel(error);
	if (error != boost::system::errc::success)
	{
		cout << "CUartLogger: Failed to cancel serial port " << mPortName << ". Error - " << error.message()<<endl;
	}
	
	mSerialPort->close(error);
	if (error != boost::system::errc::success)
	{
		cout << "CUartLogger: Failed to close serial port " << mPortName << ". Error - " << error.message()<<endl;
	}

	mIoService.stop();
	Sleep(2000);
	cout << "CUartLogger: IoService stopped"<<endl;

	return 0;
}


int CUartLog::StartSavingUartLogs()
{
#if 0
	std::string command = "-load MTTF_CONFIG";
	std::wstring stemp = std::wstring(command.begin(), command.end());

	HINSTANCE ret = ShellExecute(NULL, "open", "\"C:\\Program Files (x86)\\PuTTY\\putty.exe\"", "-load MTTF_CONFIG", NULL, SW_SHOW);
	cout<<"ret = "<<(int)ret<<endl;
#endif
	return 0;
}

void CUartLog::usage_show()
{
	char helpStringBuffer[512];
	sprintf(helpStringBuffer,
		"Usage: Uartlog.exe [OPTION]\n"
		"\n"
		"Parameters per Streamer in a configuration: \n"
		"-p port, -p COM8 \n"
		"-b baudrate, -b 115200 \n"
		"-f save file name, -f uarlog.txt");
	printf(helpStringBuffer);
}

void CUartLog::processOptions(int argc, char **argv)
{
	int opt_num = 0;
	for(;;)
	{
		static char const *short_options = "hp:f:b:";
		int c = getopt(argc,argv,(char*)short_options);
		if (c == EOF) break;

		if (optarg)
			opt_num = atoi(optarg);
		
		switch(c)
		{
			case 'h':
				usage_show();
				exit(0);
			break;
			
			case 'p':
				mPortName = optarg;
				cout<<" Port Name: "<<mPortName<<endl;
			break;
				
			case 'f':
				mFilePath = optarg;
				cout<<" Save File Path: "<<mFilePath<<endl;
			break;
			
			case 'b':
				mBaudRate = opt_num;
				cout<<" BaudRate: "<<mBaudRate<<endl;
			break;


			default:
				usage_show();
				exit(0);
			break;
		}
	}
	argc -= optind;
	argv += optind;
}

