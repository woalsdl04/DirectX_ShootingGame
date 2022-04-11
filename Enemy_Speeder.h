#pragma once
#include "EnemyBase.h"
class Enemy_Speeder : public EnemyBase
{
public:
	// cComponent을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnAlarm(string _Key) override;
	virtual void OnCollision(cObject* _Other) override;
	virtual void OnAnimationEnd(string _Key) override;

	float EnemySpeed;
	int Enemy_Hp;
	int ang, rotate, BulletCount;
};


