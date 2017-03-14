#include "Subject.h"
#include "Master.h"


Subject::Subject(Hero& src, Skill& skill)
{
	__src = &src;
	__skill = &skill;
}

void Subject::SendTo(Hero& dst)
{
	Master::master.Request(AttackRequest(*__src, *__skill, dst));
}