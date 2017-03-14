#include "Hero.h"
#include "Subject.h"


Hero::Hero()
{

}

void Hero::Action(Skill& skill, Hero& dst)
{
	__request_sender = std::thread([&]() -> void {
		Subject(*this, skill).Send(dst);
	});
}
