#include "DXUT.h"
#include "cAnimation.h"

void cAnimation::Init()
{
	m_CurAnim = nullptr;
	m_Frame = 0;
	m_LastFrame = -1;
	m_Speed = 1;
}

void cAnimation::Update()
{
	if (m_CurAnim)
	{
		m_Frame += m_CurAnim->Speed * DT;
		if (m_Frame >= m_CurAnim->MaxFrame + 1)
		{
			if (m_CurAnim->isLoop)
			{
				m_Frame -= m_CurAnim->MaxFrame + 1;
			}
			else
			{
				m_Frame = m_CurAnim->MaxFrame;
				m_Speed = 0;
			}
			for (auto& iter : m_Owner->m_Components)
			{
				iter->OnAnimationEnd(m_CurAnim->Key);
			}
		}
		if (m_LastFrame != (int)m_Frame)
		{
			m_LastFrame = (int)m_Frame;
			GetComponent<cRenderer>()->m_Image = (*m_CurAnim->Anim)[m_LastFrame];
		}
	}
}

void cAnimation::Render()
{
	//IMAGE->RenderText(to_string(m_LastFrame), m_Owner->m_Pos + Vec2(0, -100), 0, Vec2(0.5, 0.5), 0);
}

void cAnimation::Release()
{
	for (auto& iter : m_Animations)
	{
		delete iter.second;
	}
}

void cAnimation::OnAlarm(string _Key)
{
}

void cAnimation::OnCollision(cObject * _Other)
{
}

void cAnimation::OnAnimationEnd(string _Key)
{
}

void cAnimation::AddAnimation(string _Key, string _Resource, float _Speed, bool _isLoop)
{
	Animation* Temp = new Animation;
	Temp->Key = _Key;
	Temp->isLoop = _isLoop;
	Temp->Speed = 1 / _Speed;
	Temp->Anim = IMAGE->FindAnimation(_Resource);
	Temp->MaxFrame = Temp->Anim->size() - 1;
	m_Animations.insert(make_pair(_Key, Temp));
}

void cAnimation::SetAnimation(string _Key)
{
	m_CurAnim = m_Animations[_Key];
	m_Frame = 0;
	m_LastFrame = -1;
	m_Speed = 1;
}
