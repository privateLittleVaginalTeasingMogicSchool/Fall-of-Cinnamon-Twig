#pragma once

#include "Hero.h"
#include "Skill.h"


class AttackRequest
{
public:
	AttackRequest(Hero& src, Skill& skill, Hero& dst);

	// ��ȡ�����е� Skill
	Skill&& AttackSkill();

	// ��ȡ����������
	Hero&& AttackSource();

	// ��ȡ����Ŀ��
	Hero&& AttackDestination();
private:
	Hero* __src;
	Skill* __skill;
	Hero* __dst;
};