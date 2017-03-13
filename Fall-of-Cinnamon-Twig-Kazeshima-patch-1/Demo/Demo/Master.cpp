#include "Master.h"


Master Master::master;

void Master::AttackRequest(Request && request)
{
	if (true)
	{
		__service_queue.emplace(request);
	}
}

Master::Master()
{

}

