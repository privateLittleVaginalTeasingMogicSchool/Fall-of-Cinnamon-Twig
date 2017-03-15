#pragma once

#include "Hero.h"
#include "Skill.h"


class AttackRequest
{
public:
	AttackRequest(Hero& src, Skill& skill, Hero& dst);

	// 获取请求中的 Skill
	Skill&& AttackSkill();

	// 获取攻击发出者
	Hero&& AttackSource();

	// 获取攻击目标
	Hero&& AttackDestination();
private:
	Hero* __src;
	Skill* __skill;
	Hero* __dst;
};