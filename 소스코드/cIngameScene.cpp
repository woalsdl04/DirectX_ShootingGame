#include "DXUT.h"
#include "cIngameScene.h"
#include "cPlayer.h"
#include "cKotomine.h"
#include "Enemy_Air.h"
#include "Enemy_Speeder.h"
#include "Boss.h"
#include "Boss2.h"
#include "Bomb.h"
#include "Bomb_Item.h"


void cIngameScene::Init()
{
	ScrollSpeed = -1695;
	CAMERA->m_Scale = 1;
	OBJECT->AddObject("Bomb_Item", Vec2(0,0), Obj_Item)->AddComponent<Bomb_Item>();
	OBJECT->AddObject("Player", Vec2(0, 300), Obj_Player)->AddComponent<cPlayer>();;
	
	OBJECT->AddObject("Player", Vec2(0, 300), Obj_Player)->AddComponent<cPlayer>();
	
	//b = OBJECT->m_Objects[Obj_Enemy].front();

	for (int i = 0; i < 10; i++)
	{
		//OBJECT->AddObject("Kotomine", Vec2(Random(-1000, 1000), Random(-1000, 1000)), Obj_Enemy)->AddComponent<cKotomine>();
	}

	OBJECT->AddObject("Stage1", Vec2(0,0), Obj_Map);

	curSpown = 0;

	maxSpown = 1;
	PlayerHp = 3;
	score = 0;
	Boss2On = true;
	BossOn = true;
}

void cIngameScene::Update()
{
	srand(time(NULL));

	ScrollSpeed += 1;

	curSpown += DT;
	score += 60 * DT;

	if (curSpown >= maxSpown && Boss2On)
	{
		if(Random(0, 1) == 0)
		OBJECT->AddObject("Enemy", Vec2(Random(-150, 150), -400), Obj_Enemy)->AddComponent<Enemy_Air>();
		else
		OBJECT->AddObject("Enemy_B", Vec2(Random(-150, 150), -400), Obj_Enemy)->AddComponent<Enemy_Speeder>();

		curSpown = 0;
	}

	if(OBJECT->m_Objects[Obj_Player].front()->m_isDestroyed == true)
	{
		if(PlayerHp >= 0)
		{
			OBJECT->AddObject("Player", Vec2(0, 300), Obj_Player)->AddComponent<cPlayer>();;
		}
		PlayerHp--;
	}

	

	if(score >= 2000 && BossOn)
	{
		OBJECT->AddObject("Boss", Vec2(0, -400), Obj_Enemy)->AddComponent<Boss>();
		BossOn = false;
	}
	if(score >= 4000 && Boss2On)
	{
		OBJECT->AddObject("Boss2", Vec2(0, -400), Obj_Enemy)->AddComponent<Boss2>();
		Boss2On = false;
	}

	if(PlayerHp <= 0)
	{
		//b->m_isDestroyed = true;
		SCENE->ChangeScene("GAMEOVER");
	}

	if (INPUT->KeyDown('Z')) // 치트키
		PlayerHp++;
	
}

void cIngameScene::Render()
{
	float pos = -145;
	for(int i =0; i < PlayerHp; i++)
	{
		IMAGE->Render(IMAGE->Find("PlayerHP_UI"), Vec2(pos, 340), 0, Vec2(1.5, 1.5), 0);
		pos += 25;
	}
	IMAGE->Render(IMAGE->Find("Stage1"), Vec2(0, ScrollSpeed), 0, Vec2(1, 1), 1);
	IMAGE->Render(IMAGE->Find("Stage1"), Vec2(0, ScrollSpeed - 4116), 0, Vec2(1, 1), 1);
	IMAGE->Render(IMAGE->Find("Stage1"), Vec2(0, ScrollSpeed - 8232), 0, Vec2(1, 1), 1);

	IMAGE->RenderText(Text, Vec2(10, -340), 0, Vec2(0.5, 0.5), 0);
	sprintf(Text, "Score:%d", (int)score);
}

void cIngameScene::Release()
{
}
