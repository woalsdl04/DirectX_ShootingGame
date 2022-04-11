#include "DXUT.h"
#include "Stage1.h"
#include "Enemy_Air.h"

void Stage1::Init()
{
	curSpown = 0;

	maxSpown = 1;

}

void Stage1::Update()
{
	curSpown += DT;

	if (curSpown >= maxSpown)
	{
		OBJECT->AddObject("Enemy", Vec2(0, -330), Obj_Enemy)->AddComponent<Enemy_Air>();
		curSpown = 0;
	}
}

void Stage1::Render()
{
}

void Stage1::Release()
{
}

void Stage1::OnAlarm(string _Key)
{
}

void Stage1::OnCollision(cObject* _Other)
{
}

void Stage1::OnAnimationEnd(string _Key)
{
}
