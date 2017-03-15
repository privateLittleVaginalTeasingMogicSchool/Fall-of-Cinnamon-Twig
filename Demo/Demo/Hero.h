#pragma once

#include "Skill.h"
#include <thread>

// ս��������
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

	// ���� Master::SendResponse() ���ã�
	// ʵ�ֹ������յ���һ����Ӧ���߼�
	virtual void OnAttackRequestSent() = 0;

	// ���� Hero::SendResponse() ���ã�
	// ʵ�ֹ������յ��ڶ�����Ӧ���߼�
	virtual void OnAttackPerformed(Hero& dst, const BattleResult& result) = 0;
	
	// �յ� Master ת���Ĺ���������򹥻�Դ������Ӧ���߼���
	// ����ս��������
	virtual void SendResponse(Hero& src, BattleResult&& result) = 0;
protected:
	Hero();
	virtual void ApplySkill(Skill& skill) = 0;
	int HP;
private:
	std::thread __request_sender;
	std::thread __request_handler;
};