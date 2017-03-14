#pragma once

#include "Skill.h"
#include <thread>


struct BattleResult
{
	bool AttackValid;
	int HPDecreased;
};

class Hero
{
public:
	void Action(Skill& skill, Hero& dst);
	void WakeUp(Skill& skill, Hero& src);

	// Only called by Master::SendResponse()
	void OnAttackRequestSent();

	// Only called by SendResponse()
	void OnAttackPerformed(Hero& dst, const BattleResult& result);
	void SendResponse(Hero& src, BattleResult&& result);
protected:
	Hero();
	virtual void ApplySkill(Skill& skill) = 0;
	int HP;
private:
	std::thread __request_sender;
	std::thread __request_handler;
};