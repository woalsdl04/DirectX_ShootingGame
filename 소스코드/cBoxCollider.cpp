#include "DXUT.h"
#include "cBoxCollider.h"

void cBoxCollider::Init()
{
}

void cBoxCollider::Update()
{
}

void cBoxCollider::Render()
{
}

void cBoxCollider::Release()
{
}

void cBoxCollider::OnAlarm(string _Key)
{
}

void cBoxCollider::OnCollision(cObject * _Other)
{
}

void cBoxCollider::OnAnimationEnd(string _Key)
{
}

void cBoxCollider::AddCollideWith(ObjectTag _Tag)
{
	m_CollWith.push_back(_Tag);
}

void cBoxCollider::UpdateCollider()
{
}
