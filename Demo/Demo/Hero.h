#pragma once

#include "Skill.h"
#include <thread>

// 战斗结算结果
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

	// 仅被 Master::SendResponse() 调用，
	// 实现攻击后收到第一次响应的逻辑
	virtual void OnAttackRequestSent() = 0;

	// 仅被 Hero::SendResponse() 调用，
	// 实现攻击后收到第二次响应的逻辑
	virtual void OnAttackPerformed(Hero& dst, const BattleResult& result) = 0;
	
	// 收到 Master 转发的攻击请求后向攻击源发出响应的逻辑，
	// 包含战斗结算结果
	virtual void SendResponse(Hero& src, BattleResult&& result) = 0;
protected:
	Hero();
	virtual void ApplySkill(Skill& skill) = 0;
	int HP;
private:
	std::thread __request_sender;
	std::thread __request_handler;
};