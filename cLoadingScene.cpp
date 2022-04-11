#include "DXUT.h"
#include "cLoadingScene.h"

void cLoadingScene::Init()
{
	LoadImage("Player_Shadow", "Player_Shadow");

	LoadImage("Player_Idle", "Player/Player_Idle", 2);
	IMAGE->AddAnimation("Player_Idle");
	LoadImage("Player_Star", "Player/Player_Star", 2);
	IMAGE->AddAnimation("Player_Star");
	LoadImage("Player_Move", "Player/Player_Move", 12);
	IMAGE->AddAnimation("Player_Move");
	LoadImage("PlayerHP_UI", "UI/PlayerHP_UI");

	LoadImage("Eff_Exp_A", "Eff/Eff_Exp_A", 12);
	IMAGE->AddAnimation("Eff_Exp_A");
	LoadImage("Eff_Exp_Big", "Eff/Eff_Exp_Big", 12);
	IMAGE->AddAnimation("Eff_Exp_Big");
	LoadImage("PlayerBomb", "Eff/Bomb", 9);
	IMAGE->AddAnimation("PlayerBomb");
	LoadImage("Shoot_Fire", "Eff/Shoot_Fire", 11);
	IMAGE->AddAnimation("Shoot_Fire");

	//LoadImage("Player_Idle", "Player/Player_Idle1");

	LoadImage("Stage1", "Bg");
	LoadImage("PressStart", "UI/Start");
	LoadImage("GameOver", "UI/GameOver");
	LoadImage("Neko", "UI/Neko");


	LoadImage("Screen", "UI/Screen", 15);
	IMAGE->AddAnimation("Screen");
	LoadImage("Screen_A", "UI/ScreenA");
	LoadImage("Screen_Left", "UI/Screen_Left");
	LoadImage("Screen_Right", "UI/Screen_Right");

	LoadImage("Boss", "Boss/Boss");
	LoadImage("Boss2", "Boss/Boss2");

	LoadImage("Enemy", "Enemy/Enemy");
	LoadImage("Enemy_B", "Enemy/Enemy_B");
	LoadImage("EnemyBullet1", "Enemy/EnemyBullet1");
	LoadImage("EnemyBullet2", "Enemy/EnemyBullet2");
	LoadImage("EnemyBullet3", "Enemy/EnemyBullet3");
	LoadImage("EnemyBulletJudo", "Enemy/EnemyBullet_Judo");

	LoadImage("Player_Bullet", "Player/Player_Bullet");
	
	LoadImage("Bomb_Item", "Item/Bomb_Item");
	LoadImage("Trash", "Eff/Trash", 6);

	SCENE->ChangeScene("GAMESTART");
}

void cLoadingScene::Update()
{
}

void cLoadingScene::Render()
{
}

void cLoadingScene::Release()
{
}

void cLoadingScene::LoadImage(string _Key, string _Path, int _Amount)
{
	char Path[128];
	if (_Amount == 1)
	{
		sprintf(Path, "./Resource/Image/%s.png", _Path.c_str());
		IMAGE->AddImage(_Key, Path);
	}
	else
	{
		char Key[64];
		for (int i = 1; i <= _Amount; i++)
		{
			sprintf(Path, "./Resource/Image/%s%d.png", _Path.c_str(), i);
			sprintf(Key, "%s%d", _Key.c_str(), i);
			IMAGE->AddImage(Key, Path);
		}
	}
}

void cLoadingScene::LoadSound(string _Key, string _Path, int _Amount)
{
	char Path[128];
	if (_Amount == 1)
	{
		sprintf(Path, "./Resource/Sound/%s.wav", _Path.c_str());
		SOUND->AddSound(_Key, Path);
	}
	else
	{
		char Key[64];
		for (int i = 1; i <= _Amount; i++)
		{
			sprintf(Path, "./Resource/Sound/%s%d.wav", _Path.c_str(), i);
			sprintf(Key, "%s%d", _Key.c_str(), i);
			SOUND->AddSound(Key, Path);
		}
	}
}
