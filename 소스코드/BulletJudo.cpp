#include "DXUT.h"
#include "BulletJudo.h"
#include "cPlayer.h"

void BulletJudo::Init()
{
	Player = OBJECT->m_Objects[Obj_Player].front();

	AddComponent<cCircleCollider>()->AddCollideWith(Obj_Player);
	GetComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 3);
	NowTime = 0;
}

void BulletJudo::Update()
{
	NowTime += DT;

	if (m_Owner->m_Pos.y >= 350 || m_Owner->m_Pos.y <= -350 || m_Owner->m_Pos.x <= -160 || m_Owner->m_Pos.x >= 160)
		m_Owner->m_isDestroyed = true;

	Judo = atan2(Player->m_Pos.y - m_Owner->m_Pos.y, Player->m_Pos.x - m_Owner->m_Pos.x);

	if(NowTime <= 1)
	m_Owner->m_Pos += Vec2(cosf((Judo)), sinf((Judo))) * BulletSpeed * DT;
	else
	{
		m_Owner->m_Pos += Vec2(cosf(D3DXToRadian(BulletRotate)), sinf(D3DXToRadian(BulletRotate))) * BulletSpeed * DT;
	}
}

void BulletJudo::Render()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find(ImgKey);
	GetComponent<cRenderer>()->m_Color = D3DCOLOR_RGBA(0, 0, 0, 55);
	GetComponent<cRenderer>()->add_pos = { 10,10 };
}

void BulletJudo::Release()
{
}

void BulletJudo::OnAlarm(string _Key)
{
}

void BulletJudo::OnCollision(cObject* _Other)
{
}

void BulletJudo::OnAnimationEnd(string _Key)
{

}

void BulletJudo::BulletSet(int _dmg, float _speed, float _ang, string _Key)
{
	BulletRotate = _ang;
	BulletSpeed = _speed;
	ImgKey = _Key;

	AddComponent<cRenderer>()->m_Image = IMAGE->Find(ImgKey);
}

