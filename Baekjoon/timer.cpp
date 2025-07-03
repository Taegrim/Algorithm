#include "timer.h"

void Timer::Start()
{
	start = std::chrono::steady_clock::now();
}

void Timer::Stop()
{
	end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	std::cout << "걸린 시간 : " << elapsed << "ms" << std::endl;
}
