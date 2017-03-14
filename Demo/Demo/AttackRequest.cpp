#include "AttackRequest.h"


AttackRequest::AttackRequest(Hero& src, Skill& skill, Hero& dst)
{
	__src = &src;
	__skill = &skill;
	__dst = &dst;
}

Skill&& AttackRequest::AttackSkill()
{
	return std::move(*__skill);
}

Hero&& AttackRequest::AttackSource()
{
	return std::move(*__src);
}

Hero&& AttackRequest::AttackDestination()
{
	return std::move(*__dst);
}