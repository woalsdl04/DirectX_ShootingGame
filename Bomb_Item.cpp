#include "DXUT.h"
#include "Bomb_Item.h"

void Bomb_Item::Init()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Bomb_Item");

	AddComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 8);
}

void Bomb_Item::Update()
{
	m_Owner->m_Pos.y += 100 * DT;
}

void Bomb_Item::Render()
{
}

void Bomb_Item::Release()
{
}

void Bomb_Item::OnAlarm(string _Key)
{
}

void Bomb_Item::OnCollision(cObject* _Other)
{
}

void Bomb_Item::OnAnimationEnd(string _Key)
{
}
