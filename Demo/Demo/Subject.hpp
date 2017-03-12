#pragma once

#include "Hero.hpp"
#include "Skill.hpp"

class Subject
{
public:
	Subject(Hero& src, Skill& skill)
	{
		__src = &src;
		__skill = &skill;
	}

	void Send()
	{

	}
private:
	Hero* __src;
	Skill* __skill;
};