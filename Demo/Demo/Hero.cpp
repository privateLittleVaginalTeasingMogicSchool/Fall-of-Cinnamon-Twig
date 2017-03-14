#include "Hero.h"
#include "Subject.h"
#include <future>
#include <iostream>

Hero::Hero()
{

}

void Hero::OnAttackRequestSent()
{
	std::cout << "Attack Request Received. -- by Master" << std::endl;
}

void Hero::OnAttackPerformed(Hero & dst, const BattleResult& result)
{
	std::cout << "Attack Performed. -- by opposite side." <<
		"HP Decreased: " << result.HPDecreased << std::endl;
}

void Hero::SendResponse(Hero & src, BattleResult&& result)
{
	src.OnAttackPerformed(*this, result);
}

void Hero::Action(Skill& skill, Hero& dst)
{
	std::async(std::launch::async, [&]() -> void
	{
		Subject(*this, skill).SendTo(dst);
	});
}

void Hero::WakeUp(Skill& skill, Hero& src)
{
	std::async(std::launch::async, [&]() -> void
	{
		if (true)
		{
			ApplySkill(skill);
			SendResponse(src, { true, 10 });
		}
	});
}