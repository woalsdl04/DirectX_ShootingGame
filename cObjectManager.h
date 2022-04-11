#pragma once
#include"cObject.h"

class cObjectManager : public cSingleton<cObjectManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void CheckCollisionCircle(cObject* _Object);
	void CheckCollisionBox(cObject* _Object);

	list<cObject*> m_Objects[Obj_End];

	cObject* AddObject(string _Name, Vec2 _Pos, ObjectTag _Tag);
	void Clear();

	cObject* Player;
};

#define OBJECT cObjectManager::GetInstance()