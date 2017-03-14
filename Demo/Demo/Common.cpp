#define _CRT_SECURE_NO_WARNINGS

#include "Common.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <time.h>

bool output_mutex;
Logger xcout;

Logger::Logger()
	:_os(std::cout.rdbuf())
{

}

Logger::~Logger()
{
	
}

Logger& Logger::operator << (const char* str)
{
	_Get_Output_Mutex
		_os << str;
	_Release_Output_Mutex
		return (*this);
}

Logger& Logger::operator << (double num)
{
	_Get_Output_Mutex
		_os << num;
	_Release_Output_Mutex
		return (*this);
}

Logger& Logger::operator << (int num)
{
	_Get_Output_Mutex
		_os << num;
	_Release_Output_Mutex
		return (*this);
}

Logger& Logger::operator << (char c)
{
	_Get_Output_Mutex
		_os << c;
	_Release_Output_Mutex
		return (*this);
}

Logger& Logger::operator<<(Logger& (__cdecl *pfunc)(Logger&))
{
	return ((*pfunc)(*this));
}

Logger& Logger::endl(Logger& logger)
{
	_Get_Output_Mutex
		std::endl(logger._os);
	_Release_Output_Mutex
		return (logger);
}

Logger& Logger::_2point(Logger& logger)
{
	_Get_Output_Mutex
		std::fixed(logger._os);
		(*std::setprecision(2)._Pfun)(logger._os, 2);
	_Release_Output_Mutex
		return (logger);
}

Logger& Logger::t(Logger& logger)
{
	_Get_Output_Mutex
		time_t now = time(NULL);
	char* nows = ctime(&now);
	nows[10] = '[';
	nows[19] = ']';
	nows[20] = ' ';
	nows[21] = 0;
	logger._os << nows;
	_Release_Output_Mutex
		return logger;
}