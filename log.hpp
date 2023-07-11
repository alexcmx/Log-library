#ifndef __LOG_H
#define __LOG_H
#include "Singleton.hpp"
#include <iostream>
#include <cstring>
#include "stdio.h"
#include <cstdarg>
class Log:public Singleton<Log>{
private:
	bool enabled = true;
public:
	void init();
	void message(const char *);
	void printf(const char* format, ...);
	void disable();
	void enable();
};
#endif /* __LOG_H */
