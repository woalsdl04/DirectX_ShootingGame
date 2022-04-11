#include "DXUT.h"
#include "Boss2.h"
#include "EnemyBullet_A.h"
#include "Eff_Exp_A.h"
#include "Eff_Exp_Big.h"

void Boss2::Init()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Boss2");

	AddComponent<cCircleCollider>()->AddCollideWith(Obj_PlayerBullet);
	GetComponent<cCircleCollider>()->AddCollideWith(Obj_Bomb);
	GetComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 80);

	Player = OBJECT->m_Objects[Obj_Player].front();

	BossState = Boss2_Ready;
	BossSpeed = 120;
	TargetPos = Vec2(0, 0);
	a = Vec2(0, 0);
	BulletCount = 30;
	ang = 0;
	Boss_Hp = 200;
	WaitTime = 0;
	BossAttack_Sel = 0;
	rotate = 360 / BulletCount;
	curShot = 0;
	BossAttack3_Ang = 0;
	Judo = atan2(Player->m_Pos.y - m_Owner->m_Pos.y, Player->m_Pos.x - m_Owner->m_Pos.x);
	AttackCount = 0;
}

void Boss2::Update()
{
	WaitTime += DT;
	curShot += DT;
	switch (BossState)
	{
	case Boss2_Ready:
		m_Owner->m_Pos.y += BossSpeed * DT;
		if (m_Owner->m_Pos.y >= -200)
			BossState = Boss2_Idle;
		break;
	case Boss2_Wait:
		if (WaitTime >= 0.5)
			BossState = Boss2_Idle;
		break;
	case Boss2_Idle:
		TargetPos = Vec2(Random(-150, 150), m_Owner->m_Pos.y);
		a = (TargetPos - m_Owner->m_Pos);
		BossAttack_Sel = Random(0,1);
		BossState = Random(Boss2_Move, Boss2_Attack);
		break;
	case Boss2_Move:
		m_Owner->m_Pos += a * DT;
		if (m_Owner->m_Pos.x >= TargetPos.x - 10 && m_Owner->m_Pos.x <= TargetPos.x + 10)
		{
			float angle = 60;

			for (int i = 0; i < 3; i++)
			{
				OBJECT->AddObject("EnemyBullet_A", Vec2(m_Owner->m_Pos.x, m_Owner->m_Pos.y), Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, angle, "EnemyBullet1");
				angle += 30;
			}
			BossState = Boss2_Wait;
		}
		WaitTime = 0;
		break;
	case Boss2_Attack:
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

void Boss2::Render()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Boss2");
	GetComponent<cRenderer>()->m_Color = D3DCOLOR_RGBA(0, 0, 0, 155);
	GetComponent<cRenderer>()->add_pos = { 20,20 };
}

void Boss2::Release()
{
}

void Boss2::OnAlarm(string _Key)
{
}

void Boss2::OnCollision(cObject* _Other)
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
		SCENE->ChangeScene("NEKO");
	}
	
}

void Boss2::OnAnimationEnd(string _Key)
{
}

void Boss2::Boss_Attack1()
{
	if (m_Owner->m_Pos.x <= 0)
		m_Owner->m_Pos.x += BossSpeed * DT;
	else if (m_Owner->m_Pos.x >= 0)
		m_Owner->m_Pos.x -= BossSpeed * DT;
	
	if (curShot <= 0.05)
		return;

	for (int i = 0; i < 4; i++)
	{
		OBJECT->AddObject("EnemyBullet3", m_Owner->m_Pos, Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, BossAttack3_Ang, "EnemyBullet3");
		BossAttack3_Ang += 90;
		AttackCount++;
	}
	BossAttack3_Ang += 2;
	
	
	curShot = 0;
	
	if(AttackCount >= 800)
	{
		AttackCount = 0;
		BossState = Boss2_Wait;
	}
	
	Debug(L"%d", (int)BossAttack3_Ang);
}

void Boss2::Boss_Attack2()
{
	if (m_Owner->m_Pos.x <= 150)
		m_Owner->m_Pos.x += BossSpeed * 2 * DT;
	else
	{
		for (int B = 0; B < BulletCount; B++)
		{
			OBJECT->AddObject("EnemyBullet2", m_Owner->m_Pos, Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, ang, "EnemyBullet2");
			ang += rotate;
		}

		BossAttack_Sel = 2;
	}
}

void Boss2::Boss_Attack3()
{
	if (m_Owner->m_Pos.x >= -150)
		m_Owner->m_Pos.x -= BossSpeed * 2 * DT;
	else
		BossState = Boss2_Wait;

	if (curShot <= 0.15)
		return;

	OBJECT->AddObject("EnemyBullet2", m_Owner->m_Pos, Obj_EnemyBullet)->AddComponent<EnemyBullet_A>()->BulletSet(0, 300, 90, "EnemyBullet2");


	curShot = 0;
}
