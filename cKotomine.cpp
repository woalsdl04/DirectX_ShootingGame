#include "DXUT.h"
#include "cKotomine.h"


cKotomine::cKotomine()
{
}


cKotomine::~cKotomine()
{
}

void cKotomine::Init()
{
	AddComponent<cRenderer>()->m_Image = IMAGE->Find("Enemy");

	AddComponent<cCircleCollider>()->AddCollider(Vec2(0, 0), 200);
	m_Owner->m_Scale = Vec2(0.1, 0.1);
}

void cKotomine::Update()
{
}

void cKotomine::Render()
{
}

void cKotomine::Release()
{
	SOUND->Play("Yorokobe");
}

void cKotomine::OnAlarm(string _Key)
{
}

void cKotomine::OnCollision(cObject * _Other)
{
}

void cKotomine::OnAnimationEnd(string _Key)
{
}
