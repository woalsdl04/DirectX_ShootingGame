#pragma once
class cCameraManager : public cSingleton<cCameraManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	Vec2 m_Pos;
	float m_Scale;
	float m_Rot;
	float m_ShakeForcePerFrame;
	float m_ShakeForce;
	Vec2 m_ShakePos;
	Matrix m_Mat;
	Matrix m_InversedMat;

	void Shake(float _Force, float _Time);
	Matrix GetViewMatrix();
};

#define CAMERA cCameraManager::GetInstance()