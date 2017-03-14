#pragma once

#include <iostream>
#include <fstream>
#include <string>


class Logger
{
public:
	Logger();
	~Logger();
	Logger& operator << (const char* str);
	Logger& operator << (double num);
	Logger& operator << (int num);
	Logger& operator << (char c);
	Logger& operator<<(Logger& (__cdecl *_Pfn)(Logger&));
	static Logger& endl(Logger& logger);
	static Logger& _2point(Logger& logger);
	static Logger& t(Logger& logger);

private:
	std::ostream _os;
};

typedef Logger xostr;
extern Logger xcout;
extern bool output_mutex;

#define _Get_Output_Mutex      while(output_mutex);\
                               output_mutex = true;

#define _Release_Output_Mutex  output_mutex = false;
