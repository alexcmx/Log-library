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

void Log::printf(const char* format, ...)
{
	if (this->enabled)
	{
		va_list args;
		va_start(args, format);

		vfprintf(stdout, format, args);

		va_end(args);
	}
}

void Log::message(const char *data) {
	if (this->enabled){
			printf(data);
		}
}

void Log::disable() {
	enabled = false;
}

void Log::enable() {
	enabled = true;
}

