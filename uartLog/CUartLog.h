#ifndef __CUARTLOG_H__
#define __CUARTLOG_H__
#include <iostream>
#include <boost/bind.hpp>
#include <boost/filesystem.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/asio/serial_port.hpp>

#include <string>
#include <thread>
#include <memory>


class CUartLog
{
public:
	CUartLog();
	~CUartLog();
	void usage_show();
	void processOptions(int argc, char **argv);	
	std::string GetCurrentUartPortName();	
	void InitUartLogger(std::string iPortName, std::string iFilePath, int iBaudRate = 115200);	
	int StartSavingUartLogs();
	int StartSavingUartLogsSerialPort();	
	int OpenSerialPort();
	int CloseSerialPort();

	void StartReadingFromPortToFile();

	void FileAsyncReadHandler(const boost::system::error_code iError, size_t iBytesTransferred);

		
	static const int BUFFER_SIZE = 512;
	
private:
	static std::string s_WindowsPuttyPath;

	boost::asio::io_service mIoService;
	//boost::asio::serial_port *mSerialPort;

	std::shared_ptr<boost::asio::serial_port> mSerialPort;
	
	std::thread mUartLoggerThread;

	std::string mPortName;
	std::string mFilePath;
	int mBaudRate;
	char mReadMessageBuffer[BUFFER_SIZE];
	
};

#endif /*__CUARTLOG_H__*/
