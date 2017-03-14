#pragma once

#include <queue>
#include <thread>

#include "AttackRequest.h"


class Master
{
public:
	static Master master;
	void Request(AttackRequest&& request);
	void Work();

private:
	Master();
	std::queue<AttackRequest> __service_queue;
	std::thread __service_queue_cleaner;
};