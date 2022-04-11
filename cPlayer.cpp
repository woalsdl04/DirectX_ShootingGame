#include "DXUT.h"
#include "cPlayer.h"
#include "Player_Bullet.h"
#include "Eff_Exp_A.h"
#include "Shoot_Fire.h"
#include "Eff_Exp_Big.h"
#include "Bomb.h"

void cPlayer::Init()
{
	//AddComponent<cRenderer>()->m_Image = IMAGE->Find("Player_Idle");
	AddComponent<cRenderer>();

	AddComponent<cAnimation>()->AddAnimation("Idle", "Player_Idle", 0.1f);
	//GetComponent<cAnimation>()->AddAnimation("Star", "Player_Star", 0.1f);
	GetComponent<cAnimation>()->AddAnimation("Move", "Player_Move", 0.05f, false);

	AddComponent<cBoxCollider>()->AddCollideWith(Obj_EnemyBullet);
	GetComponent<cBoxCollider>()->AddCollideWith(Obj_Enemy);
	GetComponent<cBoxCollider>()->AddCollideWith(Obj_Item);
	GetComponent<cBoxCollider>()->m_Rect = RECT{-4,-4,4,4};

	m_Speed = 300;

	GetComponent<cAnimation>()->SetAnimation("Idle");

	CAMERA->m_Pos = Vec2(0,0);

	curShoot = 0;
	maxShoot = 0.5;

	StarTime = 0;
}

void cPlayer::Update()
{
	curShoot += DT;
	StarTime += DT;

	bool isMoved = false;
	if (INPUT->KeyPress('W'))
	{
		if (m_Owner->m_Pos.y <= -330)
			m_Owner->m_Pos.y += m_Speed * DT;

		m_Owner->m_Pos.y -= m_Speed * DT;
	}
	else if (INPUT->KeyPress('S'))
	{
		if (m_Owner->m_Pos.y >= 330)
			m_Owner->m_Pos.y -= m_Speed * DT;

		m_Owner->m_Pos.y += m_Speed * DT;
	}

	if (INPUT->KeyPress('A'))
	{
		if(m_Owner->m_Pos.x <= - 140)
			m_Owner->m_Pos.x += m_Speed * DT;

		m_Owner->m_Pos.x -= m_Speed * DT;
		m_Owner->m_Scale.x = -1;
		isMoved = true;
	}
	else if (INPUT->KeyPress('D'))
	{
		if (m_Owner->m_Pos.x >= 140)
			m_Owner->m_Pos.x -= m_Speed * DT;

		m_Owner->m_Pos.x += m_Speed * DT;
		m_Owner->m_Scale.x = 1;
		isMoved = true;
	}

	if (isMoved)
	{
		if(GetComponent<cAnimation>()->m_CurAnim->Key != "Move")
			GetComponent<cAnimation>()->SetAnimation("Move");
	}
	else
	{
		if (GetComponent<cAnimation>()->m_CurAnim->Key == "Move")
			GetComponent<cAnimation>()->SetAnimation("Idle");
	}
	
	//Debug(L"%d\n", (int)m_Owner->m_Pos.y);

	if (INPUT->KeyDown('X'))
	{
		OBJECT->AddObject("Bomb", Vec2(0, 0), Obj_Bomb)->AddComponent<Bomb>();
	}

	Fire();
	

}

void cPlayer::Render()
{
	//AddComponent<cRenderer>()->m_Image = IMAGE->Find("Player_Shadow");
	//GetComponent<cRenderer>()->m_Color = D3DCOLOR_RGBA(0, 0, 0, 155);
	//GetComponent<cRenderer>()->add_pos = { 20,20 };
}

void cPlayer::Release()
{
}

void cPlayer::OnAlarm(string _Key)
{

}

void cPlayer::OnCollision(cObject * _Other)
{
	switch (_Other->m_Tag)
	{
	case Obj_EnemyBullet:

		_Other->m_isDestroyed = true;
		
		if (StarTime <= 3)
			return;
		
		OBJECT->AddObject("Eff_Exp_Big", Vec2(m_Owner->m_Pos.x, m_Owner->m_Pos.y), Obj_None)->AddComponent<Eff_Exp_Big>()->m_Owner->m_Scale = Vec2(0.5, 0.5);
		m_Owner->m_isDestroyed = true;
		
		break;
	case Obj_Enemy:
		OBJECT->AddObject("Eff_Exp_Big", Vec2(m_Owner->m_Pos.x, m_Owner->m_Pos.y), Obj_None)->AddComponent<Eff_Exp_Big>()->m_Owner->m_Scale = Vec2(0.5, 0.5);
		m_Owner->m_isDestroyed = true;
		break;
	case Obj_Item:
		_Other->m_isDestroyed = true;
		break;
	}

}

void cPlayer::OnAnimationEnd(string _Key)
{

}

void cPlayer::Fire()
{
	if (curShoot <= maxShoot)
		return;

	for (int i = -2; i <= 2; i++)
	{
		OBJECT->AddObject("Player_Bullet", Vec2(m_Owner->m_Pos.x + 0.5, m_Owner->m_Pos.y), Obj_PlayerBullet)->AddComponent<Player_Bullet>()->BulletSet(0, 600, 270 + i * 10);
	}

	//OBJECT->AddObject("Shoot_Fire", Vec2(m_Owner->m_Pos.x + 0.5, m_Owner->m_Pos.y - 20), Obj_None)->AddComponent<Shoot_Fire>();
	curShoot = 0;
}
