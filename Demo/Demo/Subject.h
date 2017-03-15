#pragma once

#include "Hero.h"
#include "Skill.h"

class Subject
{
public:
	Subject(Hero& src, Skill& skill);

	// 将技能投放给Master
	void SendTo(Hero& dst);
private:
	Hero* __src;
	Skill* __skill;
};