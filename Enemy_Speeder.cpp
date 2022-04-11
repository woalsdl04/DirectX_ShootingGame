#include "DXUT.h"
#include "Enemy_Speeder.h"
#include "Eff_Exp_Big.h"
#include "Eff_Exp_A.h"
#include "EnemyBullet_A.h"
#include "EnemyBase.h"

void Enemy_Speeder::Init()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Enemy_B");

	AddComponent<cCircleCollider>()->AddCollideWith(Obj_PlayerBullet);
	GetComponent<cCircleCollider>()->AddCollideWith(Obj_Bomb);
	GetComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 20);
	
	EnemySpeed = 400;
	Enemy_Hp = 2;
	BulletCount = 15;
	ang = 0;
	rotate = 360 / BulletCount;
}

void Enemy_Speeder::Update()
{
	if (m_Owner->m_Pos.y >= 400)
		m_Owner->m_isDestroyed = true;
	
	m_Owner->m_Pos.y += EnemySpeed * DT;
}

void Enemy_Speeder::Render()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Enemy_B");
	GetComponent<cRenderer>()->m_Color = D3DCOLOR_RGBA(0, 0, 0, 155);
	GetComponent<cRenderer>()->add_pos = { 20,20 };
}

void Enemy_Speeder::Release()
{
}

void Enemy_Speeder::OnAlarm(string _Key)
{
}

void Enemy_Speeder::OnCollision(cObject* _Other)
{

	switch (_Other->m_Tag)
	{
	case Obj_PlayerBullet:

		Enemy_Hp -= 1;
		_Other->m_isDestroyed = true;
		break;
	case Obj_Bomb:
		Enemy_Hp -= 10;
		break;
	}
	
	if (Enemy_Hp <= 0)
	{
		OBJECT->AddObject("Eff_Exp_Big", Vec2(m_Owner->m_Pos.x, m_Owner->m_Pos.y), Obj_None)->AddComponent<Eff_Exp_Big>()->m_Owner->m_Scale = Vec2(0.5, 0.5);
		for (int B = 0; B < BulletCount; B++)
		{
			OBJECT->AddObject("EnemyBullet2", m_Owner->m_Pos, Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, ang, "EnemyBullet2");
			ang += rotate;
		}
		m_Owner->m_isDestroyed = true;
	}
	else
		OBJECT->AddObject("Eff_Exp_A", Vec2(_Other->m_Pos.x, _Other->m_Pos.y), Obj_None)->AddComponent<Eff_Exp_A>();
}

void Enemy_Speeder::OnAnimationEnd(string _Key)
{
}
