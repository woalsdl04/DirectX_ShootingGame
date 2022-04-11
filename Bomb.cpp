#include "DXUT.h"
#include "Bomb.h"

void Bomb::Init()
{
	AddComponent<cRenderer>();

	AddComponent<cAnimation>()->AddAnimation("Bomb", "PlayerBomb", 0.1f, false);
	
	AddComponent<cCircleCollider>()->AddCollideWith(Obj_Enemy);
	GetComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 300);
	
	
	GetComponent<cAnimation>()->SetAnimation("Bomb");
}

void Bomb::Update()
{
	
}

void Bomb::Render()
{
}

void Bomb::Release()
{
}

void Bomb::OnAlarm(string _Key)
{
}

void Bomb::OnCollision(cObject* _Other)
{
}

void Bomb::OnAnimationEnd(string _Key)
{
	if (_Key == "Bomb")
	{
		m_Owner->m_isDestroyed = true;
	}
}
