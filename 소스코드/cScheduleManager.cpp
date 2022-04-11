#include "DXUT.h"
#include "cScheduleManager.h"

void cScheduleManager::Init()
{
}

void cScheduleManager::Update()
{
	for (auto& iter = m_Schedules.begin(); iter != m_Schedules.end();)
	{
		(*iter)->Time -= DT;
		if ((*iter)->isOnce)
		{
			if ((*iter)->Time <= 0)
			{
				(*iter)->Func();
				delete (*iter);
				iter = m_Schedules.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		else
		{
			if ((*iter)->Func() == false || (*iter)->Time <= 0)
			{
				delete (*iter);
				iter = m_Schedules.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
}

void cScheduleManager::Render()
{
}

void cScheduleManager::Release()
{
	for (auto& iter : m_Schedules)
	{
		delete iter;
	}
}

void cScheduleManager::AddSchedule(float _Time, bool _isOnce, function<bool()> _Func)
{
	Schedule* Temp = new Schedule;
	Temp->Time = _Time;
	Temp->isOnce = _isOnce;
	Temp->Func = _Func;
	m_Schedules.push_back(Temp);
}
