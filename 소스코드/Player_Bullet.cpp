#include "DXUT.h"
#include "Player_Bullet.h"
#include "Eff_Exp_A.h"

void Player_Bullet::Init()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Player_Bullet");

	AddComponent<cCircleCollider>()->AddCollideWith(Obj_Enemy);
	GetComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 10);

}

void Player_Bullet::Update()
{
	if (m_Owner->m_Pos.y <= -350)
		m_Owner->m_isDestroyed = true;	

	m_Owner->m_Pos += Vec2(cosf(D3DXToRadian(Ang)), sinf(D3DXToRadian(Ang))) * BulletSpeed * DT;
}

void Player_Bullet::Render()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Player_Bullet");
	GetComponent<cRenderer>()->m_Color = D3DCOLOR_RGBA(0, 0, 0, 55);
	GetComponent<cRenderer>()->add_pos = { 10,10 };
}

void Player_Bullet::Release()
{
}

void Player_Bullet::OnAlarm(string _Key)
{
}

void Player_Bullet::OnCollision(cObject* _Other)
{

	//m_Owner->m_isDestroyed = true;
}

void Player_Bullet::OnAnimationEnd(string _Key)
{
}

void Player_Bullet::BulletSet(int _dmg, float _speed, float _ang)
{
	Dmg = _dmg;
	BulletSpeed = _speed;
	Ang = _ang;
}