#ifndef __LOG_H
#define __LOG_H
#include "Singleton.hpp"
#include <iostream>
#include <cstring>
#include "stdio.h"
#include <cstdarg>
#include <stdint.h>


enum log_flow{
	LOG_DEBUG = 1,
	LOG_INFO = 2,
	LOG_TEXT = 4
};

class Log:public Singleton<Log>{
private:
	bool enabled = true;
	uint16_t enabled_flow = 0xFFFE;
public:
	void init();
	void printf(log_flow flow_num, const char* format, ...);
	void disable(log_flow val);
	void enable(log_flow val);
};
#endif /* __LOG_H */
