#include "Master.h"

#include <future>

Master Master::master;

void Master::Request(AttackRequest && request)
{
	if (true)
	{
		__service_queue.emplace(request);
		request.AttackSource().OnAttackRequestSent();
	}
}

Master::Master()
{
	__service_queue_cleaner = std::thread([&]() {Work(); });
}

void Master::Join()
{
	__service_queue_cleaner.join();
}

void Master::Work()
{
	while (true)
	{
		bool mutex = false;
		if (__service_queue.size())
		{
			while (mutex);
			mutex = true;
			std::async(std::launch::async, [&]()->void
			{
				AttackRequest& req = __service_queue.front();
				req.AttackDestination().WakeUp(req.AttackSkill(), req.AttackSource());
				__service_queue.pop();
			});
			mutex = false;
		}
	}
}