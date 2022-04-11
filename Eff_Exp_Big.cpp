#include "DXUT.h"
#include "Eff_Exp_Big.h"

void Eff_Exp_Big::Init()
{
	AddComponent<cRenderer>();

	AddComponent<cAnimation>()->AddAnimation("Eff_Exp_Big", "Eff_Exp_Big", 0.05f, false);



	GetComponent<cAnimation>()->SetAnimation("Eff_Exp_Big");

	//m_Owner->m_Scale = Vec2(10, 10);
}

void Eff_Exp_Big::Update()
{
}

void Eff_Exp_Big::Render()
{
}

void Eff_Exp_Big::Release()
{
}

void Eff_Exp_Big::OnAlarm(string _Key)
{
}

void Eff_Exp_Big::OnCollision(cObject* _Other)
{
}

void Eff_Exp_Big::OnAnimationEnd(string _Key)
{
	if (_Key == "Eff_Exp_Big")
	{
		m_Owner->m_isDestroyed = true;
	}
}
