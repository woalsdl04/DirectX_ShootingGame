#include "DXUT.h"
#include "Shoot_Fire.h"

void Shoot_Fire::Init()
{
	AddComponent<cRenderer>();

	AddComponent<cAnimation>()->AddAnimation("Shoot_Fire", "Shoot_Fire", 0.02f, false);


	GetComponent<cAnimation>()->SetAnimation("Shoot_Fire");
}

void Shoot_Fire::Update()
{
	m_Owner->m_Pos = OBJECT->m_Objects[Obj_Player].front()->m_Pos + Vec2(0.5, -20);
}

void Shoot_Fire::Render()
{
}

void Shoot_Fire::Release()
{
}

void Shoot_Fire::OnAlarm(string _Key)
{
}

void Shoot_Fire::OnCollision(cObject* _Other)
{
}

void Shoot_Fire::OnAnimationEnd(string _Key)
{
	if (_Key == "Shoot_Fire")
	{
		m_Owner->m_isDestroyed = true;
	}
}
