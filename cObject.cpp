#include "DXUT.h"
#include "cObject.h"

void cObject::Init()
{
}

void cObject::Update()
{
	for (auto& iter : m_Components)
	{
		if(iter->m_isEnable)
			iter->Update();
	}
	for (auto& iter = m_Alarm.begin(); iter != m_Alarm.end();)
	{
		(*iter).first -= DT;
		if ((*iter).first <= 0)
		{
			string Key = (*iter).second;
			iter = m_Alarm.erase(iter);
			for (auto& Component : m_Components)
			{
				Component->OnAlarm(Key);
			}
		}
		else
		{
			iter++;
		}
	}
}

void cObject::Render()
{
	for (auto& iter : m_Components)
	{
		if (iter->m_isEnable)
			iter->Render();
	}
}

void cObject::Release()
{
	for (auto& iter : m_Components)
	{
		iter->Release();
		delete iter;
	}
}

void cObject::SetAlarm(string _Key, float _Time)
{
	m_Alarm.push_back(make_pair(_Time, _Key));
}
