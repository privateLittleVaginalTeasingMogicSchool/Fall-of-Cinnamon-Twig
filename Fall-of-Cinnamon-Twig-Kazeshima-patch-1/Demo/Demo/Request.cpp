#include "Request.h"


Request::Request(Hero& src, Skill& skill, Hero& dst)
{
	__src = &src;
	__skill = &skill;
	__dst = &dst;
}