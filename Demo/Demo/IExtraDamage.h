#pragma once

#include "Hero.h"
#include "Skill.h"


class ISpecialEffect
{
public:
	virtual void operator ()(Hero& dst) = 0;
};

class IExtraDamage : public ISpecialEffect
{
public:
	virtual void operator ()(Hero& dst) override
	{
		
	}
};