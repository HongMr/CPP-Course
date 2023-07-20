#include<string>
#include<iostream>

#include "CUartLog.h"

#include <windows.h>


using namespace std;



int main(int argc, char **argv)
{
	CUartLog uartLog;
	//std::string uartPort;
	
	//uartPort = uartLog.GetCurrentUartPortName();
	//std::string uartLogPath = "UartLog.txt";
	
	
	//cout<<uartPort<<" save file name:"<<uartLogPath<<endl;

	//uartLog.InitUartLogger(uartPort, uartLogPath);

	uartLog.processOptions(argc, argv);

	uartLog.StartSavingUartLogsSerialPort();

	while(1)
	{
		Sleep(5*1000);//ms
	}
	return 0;
}
