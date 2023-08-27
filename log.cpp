/*
 * log.cpp
 *
 *  Created on: Sep 8, 2021
 *      Author: User
 */

#include "log.hpp"

void Log::init() {}

void Log::printf(log_flow flow_num, const char* format, ...)
{
	lock_guard<mutex> lock(mtx);
	if (check(flow_num))
	{
		va_list args;
		va_start(args, format);

		vfprintf(stdout, format, args);

		va_end(args);
	}
}

bool Log::check(log_flow level)
{
	if (log_level && level)
	{
		if (level <= log_level) return true;
	}
    return false;
}

void Log::_printf(const char* format, ...)
{
	
	va_list args;
	va_start(args, format);

	vfprintf(stdout, format, args);

	va_end(args);
}


void Log::set_log_level(log_flow val) {
	this->log_level = val;
}

void Log::dump(log_flow flow_num, const char * buff, int size){
	lock_guard<mutex> lock(mtx);
	if (check(flow_num))
	{
		for (int i=0;i<size; i++)
		{
			this->_printf("%02X ", buff[i]);
		}
		this->_printf("\n\n");
	}
}

void Log::dump(log_flow flow_num, const pair<char*,int>&p){
	lock_guard<mutex> lock(mtx);
	if (check(flow_num))
	{
		for (int i=0;i<p.second; i++)
		{
			this->_printf("%02X ", p.first[i]);
		}
		this->_printf("\n\n");
	}
}