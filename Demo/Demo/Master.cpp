#include "Master.h"


Master Master::master;

void Master::Request(AttackRequest && request)
{
	if (true)
	{
		__service_queue.emplace(request);
	}
}

Master::Master()
{

}

void Master::Work()
{
	while (true)
	{
		if (__service_queue.size())
		{
			//new std::thread(
		}
	}
}