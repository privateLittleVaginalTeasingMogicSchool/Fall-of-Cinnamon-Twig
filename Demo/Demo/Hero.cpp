#include "Hero.h"
#include "Subject.h"
#include "Common.h"
#include <future>

Hero::Hero()
{

}

void Hero::OnAttackRequestSent()
{
	xcout << "Attack Request Received. -- by Master." << std::endl;
}

void Hero::OnAttackPerformed(Hero & dst, const BattleResult& result)
{
	xcout << "Attack Performed. " <<
		"HP Decreased: " << result.HPDecreased << " -- by opposite side."<< std::endl;
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