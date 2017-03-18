#include "Hero.h"
#include "Skill.h"


class Request
{
public:
	Request(Hero& src, Skill& skill, Hero& dst);

private:
	Hero* __src;
	Skill* __skill;
	Hero* __dst;
};