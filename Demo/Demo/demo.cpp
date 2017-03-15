#include "Hero.h"
#include "Master.h"
#include "IExtraDamage.h"
#include "Common.h"

class Punching : public Skill
{
private:
	Punching()
	{
		
	}
public:
	static Punching punching;
	virtual int Damage() override
	{
		return 10;
	}
};

Punching Punching::punching;

class ReinforcedPunching : public Skill, public IExtraDamage
{
private:
	ReinforcedPunching()
	{

	}
public:

	virtual int Damage() override
	{
		return 20;
	}

	static ReinforcedPunching reinforcedpunching;
};

ReinforcedPunching ReinforcedPunching::reinforcedpunching;


class Doge : public Hero
{
private:
	Doge()
	{
		HP = 100;
	}

	virtual void OnAttackRequestSent() override
	{// 重载该函数，实现收到Master的响应后的逻辑
		xcout << "Attack Request Received. -- by Master." << std::endl;
	}

	virtual void OnAttackPerformed(Hero & dst, const BattleResult& result)
	{// 重载该函数，实现收到攻击目标响应后的逻辑
		xcout << "Attack Performed. " <<
			"HP Decreased: " << result.HPDecreased << " -- by opposite side." << std::endl;
	}

	virtual void SendResponse(Hero & src, BattleResult&& result)
	{// 重载该函数，实现受到攻击时的逻辑
		src.OnAttackPerformed(*this, result);
	}

	virtual void ApplySkill(Skill& skill) override
	{// 重载该函数，实现被Skill攻击时的伤害逻辑
		HP -= skill.Damage();
	}

public:
	static Doge doge;
};

Doge Doge::doge;

class Nhr :public Hero
{
private:
	Nhr()
	{

	}

	virtual void OnAttackRequestSent() override
	{
		xcout << "Attack Request Received. -- by Master." << std::endl;
	}

	virtual void OnAttackPerformed(Hero & dst, const BattleResult& result)
	{
		xcout << "Attack Performed. " <<
			"HP Decreased: " << result.HPDecreased << " -- by opposite side." << std::endl;
	}

	virtual void SendResponse(Hero & src, BattleResult&& result)
	{
		src.OnAttackPerformed(*this, result);
	}

	virtual void ApplySkill(Skill& skill) override
	{
		// special effect, -20% damage
		HP -= skill.Damage()*0.8;
	}

public:
	static Nhr nhr;
};

Nhr Nhr::nhr;

int main()
{
	Nhr::nhr.Action(Punching::punching, Doge::doge);
	Doge::doge.Action(Punching::punching, Nhr::nhr);
	Master::master.Join();
}