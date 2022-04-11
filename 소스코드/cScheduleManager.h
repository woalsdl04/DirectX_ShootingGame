#pragma once
struct Schedule
{
	float Time;
	bool isOnce;
	function<bool()> Func;
};
class cScheduleManager : public cSingleton<cScheduleManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	list<Schedule*> m_Schedules;

	void AddSchedule(float _Time, bool _isOnce, function<bool()> _Func);
};

#define SCHEDULE cScheduleManager::GetInstance()