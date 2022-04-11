#include "DXUT.h"
#include "cMainGame.h"
#include "cLoadingScene.h"
#include "cIngameScene.h"
#include "GameStart.h"
#include "GameOver.h"
#include "Clear.h"

void cMainGame::Init()
{
	IMAGE->CreateInstance();
	OBJECT->CreateInstance();
	CAMERA->CreateInstance();
	SOUND->CreateInstance();
	INPUT->CreateInstance();
	SCHEDULE->CreateInstance();
	SCENE->CreateInstance();

	SCENE->AddScene("LOADING", new cLoadingScene);
	SCENE->AddScene("INGAME", new cIngameScene);
	SCENE->AddScene("GAMESTART", new GameStart);
	SCENE->AddScene("GAMEOVER", new GameOver);
	SCENE->AddScene("NEKO", new Clear);

	SCENE->ChangeScene("LOADING");
}

void cMainGame::Update()
{
	INPUT->Update();
	SCENE->Update();
	OBJECT->Update();
	SOUND->Update();
	SCHEDULE->Update();
	CAMERA->Update();
}

void cMainGame::Render()
{
	IMAGE->Begin();

	CAMERA->Render();
	SCENE->Render();
	OBJECT->Render();

	IMAGE->End();
}

void cMainGame::Release()
{
	OBJECT->ReleaseInstance();
	SCHEDULE->ReleaseInstance();
	SCENE->ReleaseInstance();
	INPUT->ReleaseInstance();
	CAMERA->ReleaseInstance();
	SOUND->ReleaseInstance();
	IMAGE->ReleaseInstance();
}

void cMainGame::OnLostDevice()
{
	IMAGE->OnLostDevice();
}

void cMainGame::OnResetDevice()
{
	IMAGE->OnResetDevice();
}
