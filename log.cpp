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
	if (this->enabled_flow & flow_num)
	{
		va_list args;
		va_start(args, format);

		vfprintf(stdout, format, args);

		va_end(args);
	}
}


void Log::disable(log_flow val) {
	this->enabled_flow &= (~static_cast<uint16_t>(val));
}

void Log::enable(log_flow val) {
	this->enabled_flow |= val;
}

