#include "DXUT.h"
#include "EnemyBullet_A.h"
#include "cPlayer.h"

void EnemyBullet_A::Init()
{
	Player = OBJECT->m_Objects[Obj_Player].front();

	AddComponent<cCircleCollider>()->AddCollideWith(Obj_Player);
	GetComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 3);

	//BulletSpeed = 300;
	//BulletRotate = 90;
}

void EnemyBullet_A::Update()
{
	if (m_Owner->m_Pos.y >= 350 || m_Owner->m_Pos.y <= -350 || m_Owner->m_Pos.x <= -160 || m_Owner->m_Pos.x >= 160)
		m_Owner->m_isDestroyed = true;

	//Judo = atan2(Player->m_Pos.y - m_Owner->m_Pos.y, Player->m_Pos.x - m_Owner->m_Pos.x);\

	m_Owner->m_Pos += Vec2(cosf(D3DXToRadian(BulletRotate)), sinf(D3DXToRadian(BulletRotate))) * BulletSpeed * DT;
}

void EnemyBullet_A::Render()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find(ImgKey);
	GetComponent<cRenderer>()->m_Color = D3DCOLOR_RGBA(0, 0, 0, 55);
	GetComponent<cRenderer>()->add_pos = { 10,10 };
}

void EnemyBullet_A::Release()
{
}

void EnemyBullet_A::OnAlarm(string _Key)
{
}

void EnemyBullet_A::OnCollision(cObject* _Other)
{

}

void EnemyBullet_A::OnAnimationEnd(string _Key)
{
}

void EnemyBullet_A::BulletSet(int _dmg, float _speed, float _ang, string _Key)
{
	BulletRotate = _ang;
	BulletSpeed = _speed;
	ImgKey = _Key;

	AddComponent<cRenderer>()->m_Image = IMAGE->Find(ImgKey);
}
