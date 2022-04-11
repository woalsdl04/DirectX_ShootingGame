#pragma once
class cInputManager : public cSingleton<cInputManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	bool m_Cur[128];
	bool m_Old[128];
	Vec2 m_MousePos;

	bool KeyPress(int _Key) { return m_Cur[_Key]; }
	bool KeyDown(int _Key) { return m_Cur[_Key] && !m_Old[_Key]; }
	bool KeyUp(int _Key) { return !m_Cur[_Key] && m_Old[_Key]; }
	Vec2 GetMousePosition() { return m_MousePos; };
	void SetMousePosition(Vec2 _Pos);
};

#define INPUT cInputManager::GetInstance()