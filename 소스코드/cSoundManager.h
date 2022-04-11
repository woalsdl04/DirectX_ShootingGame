#pragma once
class cSoundManager : public cSingleton<cSoundManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	map<string, CSound*> m_Sounds;
	list<LPDIRECTSOUNDBUFFER> m_Channels;
	CSoundManager m_Manager;

	void AddSound(string _Key, string _Path);
	LPDIRECTSOUNDBUFFER Play(string _Key, long _Volume = 0, bool _Loop = false);
	void StopAll();
};

#define SOUND cSoundManager::GetInstance()