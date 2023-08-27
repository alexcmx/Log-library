#ifndef __LOG_H
#define __LOG_H
#include "Singleton.hpp"
#include <iostream>
#include <cstring>
#include "stdio.h"
#include <cstdarg>
#include <stdint.h>

#include <map>
#include <mutex>

enum log_flow{
	LOG_DISABLE = 0,
	LOG_ERROR,
	LOG_INFO,
	LOG_TEMP,
	LOG_DEBUG
};
using namespace std;

class Log:public Singleton<Log>{
private:
	log_flow log_level = LOG_TEMP;
	mutex mtx; 
	void _printf(const char* format, ...);
public:
	void init();
	void printf(log_flow flow_num, const char* format, ...);
	void set_log_level(log_flow val);
	bool check(log_flow level);
	void dump(log_flow flow_num, const char * buff, int size);
	void dump(log_flow flow_num, const pair<char*,int>&p);
};
#endif /* __LOG_H */
