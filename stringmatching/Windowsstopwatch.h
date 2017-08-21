#pragma once
#ifndef WINDOWS_STOPWATCH_H
#define WINDOWS_STOPWATCH_H

#ifdef linux
#elif defined __APPLE_CC__
#else
#include <Windows.h>
class WindowsStopwatch {
public:
	WindowsStopwatch();
	void start();
	void stop();
	long getTime();
protected:
	__int64 a, b, f;
};
#endif
#endif