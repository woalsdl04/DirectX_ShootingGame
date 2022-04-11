#include "DXUT.h"
#include "cSoundManager.h"

void cSoundManager::Init()
{
	m_Manager.Initialize(DXUTGetHWND(), 1);
}

void cSoundManager::Update()
{
	DWORD Status;
	for (auto& iter = m_Channels.begin(); iter != m_Channels.end();)
	{
		(*iter)->GetStatus(&Status);
		if ((Status & DSBSTATUS_PLAYING) == 0)
		{
			(*iter)->Release();
			iter = m_Channels.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void cSoundManager::Render()
{
}

void cSoundManager::Release()
{
	StopAll();
	for (auto& iter : m_Sounds)
	{
		delete iter.second;
	}
}

void cSoundManager::AddSound(string _Key, string _Path)
{
	CSound* Temp;
	wstring Path = wstring(_Path.begin(), _Path.end());
	m_Manager.Create(&Temp, (LPWSTR)Path.c_str());
	m_Sounds.insert(make_pair(_Key, Temp));
}

LPDIRECTSOUNDBUFFER cSoundManager::Play(string _Key, long _Volume, bool _Loop)
{
	LPDIRECTSOUNDBUFFER Temp;
	m_Manager.GetDirectSound()->DuplicateSoundBuffer(m_Sounds[_Key]->GetBuffer(0), &Temp);
	Temp->Play(0, 0, _Loop ? DSBPLAY_LOOPING : 0);
	Temp->SetVolume(_Volume);
	m_Channels.push_back(Temp);
	return Temp;
}

void cSoundManager::StopAll()
{
	for (auto& iter : m_Channels)
	{
		iter->Release();
	}
}
