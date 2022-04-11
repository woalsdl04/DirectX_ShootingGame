#include "DXUT.h"
#include "GameOver.h"

void GameOver::Init()
{
	CAMERA->m_Pos = Vec2(1000, 1000);
}

void GameOver::Update()
{
}

void GameOver::Render()
{
	IMAGE->Render(IMAGE->Find("Stage1"), Vec2(1000, -695), 0, Vec2(1, 1), 1);

	IMAGE->Render(IMAGE->Find("GameOver"), Vec2(1000, 1000), 0, Vec2(3, 3), 0);
}

void GameOver::Release()
{
}
