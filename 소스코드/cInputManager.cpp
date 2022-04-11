#include "DXUT.h"
#include "cInputManager.h"

void cInputManager::Init()
{
}

void cInputManager::Update()
{
	memcpy(m_Old, m_Cur, 128);
	memset(m_Cur, false, 128);
	for (int i = 0; i < 128; i++)
	{
		if (GetAsyncKeyState(i) & 0x8000)
		{
			m_Cur[i] = true;
		}
	}

	POINT Point;
	GetCursorPos(&Point);
	ScreenToClient(DXUTGetHWND(), &Point);
	m_MousePos = Vec2(Point.x, Point.y);
}

void cInputManager::Render()
{
}

void cInputManager::Release()
{
}

void cInputManager::SetMousePosition(Vec2 _Pos)
{
	POINT Point = { _Pos.x, _Pos.y };
	ClientToScreen(DXUTGetHWND(), &Point);
	SetCursorPos(Point.x, Point.y);
}
