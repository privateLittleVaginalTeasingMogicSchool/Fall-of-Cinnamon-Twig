#pragma once

#include "Skill.h"
#include <thread>

class Hero
{
public:
	void Action(Skill& skill, Hero& dst);


protected:
	Hero();

private:
	std::thread __request_sender;
};