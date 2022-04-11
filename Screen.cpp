#include "DXUT.h"
#include "Screen.h"



void Screen::Init()
{
	AddComponent<cRenderer>();
	AddComponent<cAnimation>()->AddAnimation("Screen", "Screen", 0.1f, false);

	GetComponent<cAnimation>()->SetAnimation("Screen");

	m_Owner->m_Scale = Vec2(1.4, 1.4);
}

void Screen::Update()
{
}

void Screen::Render()
{
	
}

void Screen::Release()
{
}

void Screen::OnAlarm(string _Key)
{
}

void Screen::OnCollision(cObject* _Other)
{
}

void Screen::OnAnimationEnd(string _Key)
{
	if (_Key == "Screen")
	{
		m_Owner->m_isDestroyed = true;
	}
}
