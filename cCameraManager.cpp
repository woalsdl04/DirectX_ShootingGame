#include "DXUT.h"
#include "cCameraManager.h"

void cCameraManager::Init()
{
	m_Pos = Vec2(WINSIZE_X, WINSIZE_Y) * 0.5f;
	m_Scale = 1;
	m_Rot = 0;
	m_ShakeForce = 0;
	m_ShakePos = Vec2(0, 0);
}

void cCameraManager::Update()
{
	/*
	if (m_ShakeForce != 0)
	{
		m_ShakePos = Vec2(Random(-m_ShakeForce, m_ShakeForce), Random(-m_ShakeForce, m_ShakeForce));
		m_ShakeForce -= m_ShakeForcePerFrame * DT;
		if (m_ShakeForce <= 0)
		{
			m_ShakeForce = 0;
			m_ShakePos = Vec2(0, 0);
		}
	}
	*/

	Matrix P, S, R;
	D3DXMatrixTranslation(&P, -m_Pos.x + WINSIZE_X * 0.5f, -m_Pos.y + WINSIZE_Y * 0.5f, 0);
	D3DXMatrixRotationZ(&R, m_Rot);
	D3DXMatrixScaling(&S, m_Scale, m_Scale, 1);
	m_Mat = R * S * P;
	D3DXMatrixInverse(&m_InversedMat, NULL, &m_Mat);
}

void cCameraManager::Render()
{
	g_Device->SetTransform(D3DTS_VIEW, &m_Mat);
}

void cCameraManager::Release()
{
}

void cCameraManager::Shake(float _Force, float _Time)
{
	m_ShakeForce = _Force;
	m_ShakeForcePerFrame = _Force / _Time;
}

Matrix cCameraManager::GetViewMatrix()
{
	return m_InversedMat;
}
