#pragma once

#include "Hero.h"
#include "Skill.h"


class AttackRequest
{
public:
	AttackRequest(Hero& src, Skill& skill, Hero& dst);

private:
	Hero* __src;
	Skill* __skill;
	Hero* __dst;
};