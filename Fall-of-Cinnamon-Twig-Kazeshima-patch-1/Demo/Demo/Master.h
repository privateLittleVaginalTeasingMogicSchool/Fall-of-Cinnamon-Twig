#pragma once

#include <queue>
#include <thread>
#include "Common.h"
#include "Request.h"



class Master
{
public:
	static Master master;
	void AttackRequest(Request&& request);

protected:
	Master();
	


private:
	std::queue<Request> __service_queue;
	std::thread __service_queue_cleaner;
	std::thread 
};