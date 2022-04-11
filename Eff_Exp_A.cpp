#include "DXUT.h"
#include "Eff_Exp_A.h"

void Eff_Exp_A::Init()
{
	AddComponent<cRenderer>();

	AddComponent<cAnimation>()->AddAnimation("Exp", "Eff_Exp_A", 0.05f, false);



	GetComponent<cAnimation>()->SetAnimation("Exp");

	//m_Owner->m_Scale = Vec2(10, 10);
}

void Eff_Exp_A::Update()
{
}

void Eff_Exp_A::Render()
{
}

void Eff_Exp_A::Release()
{
}

void Eff_Exp_A::OnAlarm(string _Key)
{
}

void Eff_Exp_A::OnCollision(cObject* _Other)
{
}

void Eff_Exp_A::OnAnimationEnd(string _Key)
{
	if (_Key == "Exp")
	{
		m_Owner->m_isDestroyed = true;
	}
}
