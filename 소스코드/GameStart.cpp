#include "DXUT.h"
#include "GameStart.h"
#include "Screen.h"

void GameStart::Init()
{
	CAMERA->m_Pos = Vec2(0, 0);
	OBJECT->AddObject("Screen", Vec2(0, 0), Obj_None)->AddComponent<Screen>();
	ScreenSpeed = 83;
	Swh = false;
}

void GameStart::Update()
{
	if (INPUT->KeyDown(VK_SPACE))
	{
		Swh = true;
	}

	if(Swh)
	{
		ScreenSpeed += 10;
	}

	if(ScreenSpeed >= 250)
	{
		SCENE->ChangeScene("INGAME");
	}	
}

void GameStart::Render()
{
	IMAGE->Render(IMAGE->Find("Stage1"), Vec2(0, -1695), 0, Vec2(1, 1), 1);

	IMAGE->Render(IMAGE->Find("PressStart"), Vec2(0, 200), 0, Vec2(3, 3), 0);

	IMAGE->Render(IMAGE->Find("Screen_A"), Vec2(0, 220), 0, Vec2(1.4, 1.4), 0.1);
	IMAGE->Render(IMAGE->Find("Screen_A"), Vec2(0, -220), 0, Vec2(1.4, 1.4), 0.1);
	IMAGE->Render(IMAGE->Find("Screen_A"), Vec2(0, 420), 0, Vec2(1.4, 1.4), 0.1);
	IMAGE->Render(IMAGE->Find("Screen_A"), Vec2(0, -420), 0, Vec2(1.4, 1.4), 0.1);

	IMAGE->Render(IMAGE->Find("Screen_Left"), Vec2(-ScreenSpeed, 0), 0, Vec2(1.4, 1.4), 0.1);
	IMAGE->Render(IMAGE->Find("Screen_Right"), Vec2(ScreenSpeed, 0), 0, Vec2(1.4, 1.4), 0.1);
}

void GameStart::Release()
{
}
