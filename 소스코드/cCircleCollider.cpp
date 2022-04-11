#include "DXUT.h"
#include "cCircleCollider.h"

void cCircleCollider::Init()
{
}

void cCircleCollider::Update()
{
	UpdateCollider();
}

void cCircleCollider::Render()
{
}

void cCircleCollider::Release()
{
	for (auto& iter : m_Colliders)
	{
		delete iter;
	}
}

void cCircleCollider::OnAlarm(string _Key)
{
}

void cCircleCollider::OnCollision(cObject * _Other)
{
}

void cCircleCollider::OnAnimationEnd(string _Key)
{
}

void cCircleCollider::AddCollider(Vec2 _Offset, float _Radius)
{
	CircleCollider* Temp = new CircleCollider;
	Temp->LocalPos = _Offset;
	Temp->Radius = _Radius;
	Temp->WorldPos = m_Owner->m_Pos + RotateVec2(_Offset, m_Owner->m_Rot);
	m_Colliders.push_back(Temp);
}

void cCircleCollider::AddCollideWith(ObjectTag _Tag)
{
	m_CollWith.push_back(_Tag);
}

void cCircleCollider::UpdateCollider()
{
	for (auto& iter : m_Colliders)
	{
		iter->WorldPos = m_Owner->m_Pos + RotateVec2(iter->LocalPos, m_Owner->m_Rot);
	}
}
