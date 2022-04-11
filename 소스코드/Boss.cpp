#include "DXUT.h"
#include "Boss.h"
#include "EnemyBullet_A.h"
#include "Eff_Exp_A.h"
#include "Eff_Exp_Big.h"

void Boss::Init()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Boss");

	AddComponent<cCircleCollider>()->AddCollideWith(Obj_PlayerBullet);
	GetComponent<cCircleCollider>()->AddCollideWith(Obj_Bomb);
	GetComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 50);

	Player = OBJECT->m_Objects[Obj_Player].front();

	BossState = Boss_Ready;
	BossSpeed = 120;
	TargetPos = Vec2(0, 0);
	a = Vec2(0, 0);
	BulletCount = 30;
	ang = 0;
	Boss_Hp = 100;
	WaitTime = 0;
	BossAttack_Sel = 0;
	rotate = 360 / BulletCount;

	Judo = atan2(Player->m_Pos.y - m_Owner->m_Pos.y, Player->m_Pos.x - m_Owner->m_Pos.x);
}

void Boss::Update()
{
	WaitTime += DT;
	switch(BossState)
	{
	case Boss_Ready:
		m_Owner->m_Pos.y += BossSpeed * DT;
		if (m_Owner->m_Pos.y >= -200)
			BossState = Boss_Idle;
		break;
	case Boss_Wait:
		if(WaitTime >= 0.5)
			BossState = Boss_Idle;
		break;
	case Boss_Idle:
		TargetPos = Vec2(Random(-150, 150), m_Owner->m_Pos.y);
		a = (TargetPos - m_Owner->m_Pos);
		BossAttack_Sel = Random(0, 1);
		BossState = Random(Boss_Move, Boss_Attack);
		break;
	case Boss_Move:
		m_Owner->m_Pos += a * DT;
		if (m_Owner->m_Pos.x >= TargetPos.x - 10 && m_Owner->m_Pos.x <= TargetPos.x + 10)
			BossState = Boss_Wait;
		WaitTime = 0;
		break;
	case Boss_Attack:
		switch (BossAttack_Sel)
		{
		case 0:
			Boss_Attack1();
			break;
		case 1:
			Boss_Attack2();
			break;
		case 2:
			Boss_Attack3();
			break;
		default:
			break;
		}
		
		WaitTime = 0;
		break;
	}
}

void Boss::Render()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Boss");
	GetComponent<cRenderer>()->m_Color = D3DCOLOR_RGBA(0, 0, 0, 155);
	GetComponent<cRenderer>()->add_pos = { 20,20 };
}

void Boss::Release()
{
}

void Boss::OnAlarm(string _Key)
{
}

void Boss::OnCollision(cObject* _Other)
{
	switch (_Other->m_Tag)
	{
	case Obj_PlayerBullet:
		Boss_Hp -= 1;
		_Other->m_isDestroyed = true;
		OBJECT->AddObject("Eff_Exp_A", Vec2(_Other->m_Pos.x, _Other->m_Pos.y), Obj_None)->AddComponent<Eff_Exp_A>();
		break;
	case Obj_Bomb:
		//Boss_Hp -= 10;
		break;
	}

	if (Boss_Hp <= 0)
	{
		OBJECT->AddObject("Eff_Exp_Big", Vec2(m_Owner->m_Pos.x, m_Owner->m_Pos.y), Obj_None)->AddComponent<Eff_Exp_Big>();
		m_Owner->m_isDestroyed = true;
	}
		
	
}

void Boss::OnAnimationEnd(string _Key)
{
}

void Boss::Boss_Attack1()
{
	
	for (int B = 0; B < BulletCount; B++)
	{
		OBJECT->AddObject("EnemyBullet", m_Owner->m_Pos, Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, ang, "EnemyBullet2");
		ang += rotate;
	}
	
	BossState = Boss_Wait;
}

void Boss::Boss_Attack2()
{
	/*float angle = 45;

	for(int i = 0; i < 10; i++)
	{
		OBJECT->AddObject("EnemyBullet", m_Owner->m_Pos, Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, angle, "EnemyBullet2");
		angle += 10;
	}*/

	if(m_Owner->m_Pos.y <= 200)
		m_Owner->m_Pos.y += BossSpeed * 3 * DT;
	else
	{
		for (int B = 0; B < 10; B++)
		{
			OBJECT->AddObject("EnemyBullet", m_Owner->m_Pos, Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, ang, "EnemyBullet2");
			ang += 36;
		}

		BossAttack_Sel = 2;
	}
		
}

void Boss::Boss_Attack3()
{
	if (m_Owner->m_Pos.y >= -200)
		m_Owner->m_Pos.y -= BossSpeed * 2 * DT;
	else
	{
		BossState = Boss_Wait;
	}
}


bool Boss::Timer(float _time)
{
	
	if (WaitTime <= _time)
		return true;
	else
		return false;
}
