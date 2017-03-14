#include "AttackRequest.h"


AttackRequest::AttackRequest(Hero& src, Skill& skill, Hero& dst)
{
	__src = &src;
	__skill = &skill;
	__dst = &dst;
}