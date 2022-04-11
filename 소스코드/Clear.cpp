#include "DXUT.h"
#include "Clear.h"

void Clear::Init()
{
	CAMERA->m_Pos = Vec2(1000, 1000);
}

void Clear::Update()
{
}

void Clear::Render()
{


	IMAGE->Render(IMAGE->Find("Neko"), Vec2(1000, 850), 0, Vec2(2, 2), 0);
	IMAGE->RenderText("Clear!", Vec2(1000, 1000), 0, Vec2(1, 1), 0);
}

void Clear::Release()
{
}
