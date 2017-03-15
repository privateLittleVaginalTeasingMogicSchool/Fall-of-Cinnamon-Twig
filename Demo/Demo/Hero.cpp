#include "Hero.h"
#include "Subject.h"
#include "Common.h"
#include <future>

Hero::Hero()
{

}



void Hero::Action(Skill& skill, Hero& dst)
{
	std::async(std::launch::async, [&]() -> void
	{
		Subject(*this, skill).SendTo(dst);
	});
}

void Hero::WakeUp(Skill& skill, Hero& src)
{
	std::async(std::launch::async, [&]() -> void
	{
		if (true)
		{
			ApplySkill(skill);
			SendResponse(src, { true, 10 });
		}
	});
}