#include "DXUT.h"
#include "Enemy_Air.h"
#include "EnemyBullet_A.h"
#include "Eff_Exp_A.h"
#include "Eff_Exp_Big.h"
#include "EnemyBase.h"
#include "BulletJudo.h"

void Enemy_Air::Init()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Enemy");

	AddComponent<cCircleCollider>()->AddCollideWith(Obj_PlayerBullet);
	GetComponent<cCircleCollider>()->AddCollideWith(Obj_Bomb);
	GetComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 20);

	EnemySpeed = Random(90, 130);

	Enemy_Hp = 4;

	curShoot = 3;
	maxShoot = 4;
}

void Enemy_Air::Update()
{
	curShoot += DT;

	if(m_Owner->m_Pos.y >= 400)
		m_Owner->m_isDestroyed = true;

	m_Owner->m_Pos.y += EnemySpeed * DT;

	Fire();


	Debug(L"%d\n", (int)curShoot);

	//Debug(L"%d\n", (int)Enemy_Hp);

}

void Enemy_Air::Render()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Enemy");
	GetComponent<cRenderer>()->m_Color = D3DCOLOR_RGBA(0, 0, 0, 155);
	GetComponent<cRenderer>()->add_pos = { 20,20 };
}

void Enemy_Air::Release()
{
}

void Enemy_Air::OnAlarm(string _Key)
{
}

void Enemy_Air::OnCollision(cObject* _Other)
{
	if (m_Owner->m_Pos.y >= 350)
		return;

	switch (_Other->m_Tag)
	{
	case Obj_PlayerBullet:

		Enemy_Hp-= 1;
		_Other->m_isDestroyed = true;
		break;
	case Obj_Bomb:
		Enemy_Hp -= 10;
		break;
	}

	if (Enemy_Hp <= 0)
	{
		OBJECT->AddObject("Eff_Exp_Big", Vec2(m_Owner->m_Pos.x, m_Owner->m_Pos.y), Obj_None)->AddComponent<Eff_Exp_Big>()->m_Owner->m_Scale = Vec2(0.5, 0.5);
		m_Owner->m_isDestroyed = true;
	}
	else
		OBJECT->AddObject("Eff_Exp_A", Vec2(_Other->m_Pos.x, _Other->m_Pos.y), Obj_None)->AddComponent<Eff_Exp_A>();
	
	
}

void Enemy_Air::OnAnimationEnd(string _Key)
{
}

void Enemy_Air::Fire()
{
	if (curShoot <= maxShoot)
		return;

	float ang = 60;
	
	for (int i = 0; i < 3; i++)
	{
		//OBJECT->AddObject("EnemyBullet_A", Vec2(m_Owner->m_Pos.x, m_Owner->m_Pos.y), Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, ang, "EnemyBullet1");
		OBJECT->AddObject("EnemyBullet_A", Vec2(m_Owner->m_Pos.x, m_Owner->m_Pos.y), Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, ang, "EnemyBullet1");
		ang += 30;
	}
	
	
	curShoot = 0;
}
