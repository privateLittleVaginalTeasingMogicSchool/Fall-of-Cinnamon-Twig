#include "Hero.h"
#include "Master.h"
#include "IExtraDamage.h"

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

	virtual void ApplySkill(Skill& skill) override
	{
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