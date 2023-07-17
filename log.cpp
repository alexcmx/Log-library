/*
 * log.cpp
 *
 *  Created on: Sep 8, 2021
 *      Author: User
 */

#include "log.hpp"

void Log::init() {
	this->enabled = true;
}

void Log::printf(log_flow flow_num, const char* format, ...)
{
	lock_guard<mutex> lock(mtx);
	if (this->enabled_flow & flow_num)
	{
		va_list args;
		va_start(args, format);

		vfprintf(stdout, format, args);

		va_end(args);
	}
}

void Log::_printf(const char* format, ...)
{
	
	va_list args;
	va_start(args, format);

	vfprintf(stdout, format, args);

	va_end(args);
}

void Log::disable(log_flow val) {
	this->enabled_flow &= (~static_cast<uint16_t>(val));
}

void Log::enable(log_flow val) {
	this->enabled_flow |= val;
}

void Log::dump(log_flow flow_num, const char * buff, int size){
	lock_guard<mutex> lock(mtx);
	if (this->enabled_flow & flow_num)
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
	if (this->enabled_flow & flow_num)
	{
		for (int i=0;i<p.second; i++)
		{
			this->_printf("%02X ", p.first[i]);
		}
		this->_printf("\n\n");
	}
}