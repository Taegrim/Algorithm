#pragma once
#include <chrono>

class Timer
{
public:
	Timer() {};
	~Timer() {};

	void Start();
	void Stop();

private:
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
};

