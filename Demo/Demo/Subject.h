#pragma once

#include "Hero.h"
#include "Skill.h"

class Subject
{
public:
	Subject(Hero& src, Skill& skill);

	// ������Ͷ�Ÿ�Master
	void SendTo(Hero& dst);
private:
	Hero* __src;
	Skill* __skill;
};