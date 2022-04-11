#pragma once
class cComponent;
enum ObjectTag
{
	Obj_Player,
	Obj_Enemy,
	Obj_PlayerBullet,
	Obj_EnemyBullet,
	Obj_Item,
	Obj_Map,
	Obj_None,
	Obj_Bomb,
	Obj_End
};
class cObject
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	Vec2 m_Pos = Vec2(0, 0);
	Vec2 m_Scale = Vec2(1, 1);
	float m_Rot = 0;
	string m_Name = "";
	ObjectTag m_Tag = Obj_None;
	float m_Depth = 0;
	bool m_isDestroyed = false;
	list<pair<float, string>> m_Alarm;
	list<cComponent*> m_Components;
	
	void SetAlarm(string _Key, float _Time);

	template<typename T>
	T* AddComponent()
	{
		T* Temp = new T;
		Temp->m_Owner = this;
		m_Components.push_back(Temp);
		Temp->Init();
		return Temp;
	}

	template<typename T>
	T* GetComponent()
	{
		for (auto& iter : m_Components)
		{
			if (typeid(iter) == typeid(T*))
			{
				return static_cast<T*>(iter);
			}
		}
		T* Cast = nullptr;
		for (auto& iter : m_Components)
		{
			Cast = dynamic_cast<T*>(iter);
			if (Cast != nullptr)
			{
				return Cast;
			}
		}
		return nullptr;
	}
};

