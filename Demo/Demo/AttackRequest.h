#pragma once

#include "Hero.h"
#include "Skill.h"


class AttackRequest
{
public:
	AttackRequest(Hero& src, Skill& skill, Hero& dst);
	Skill&& AttackSkill();
	Hero&& AttackSource();
	Hero&& AttackDestination();
private:
	Hero* __src;
	Skill* __skill;
	Hero* __dst;
};