#pragma once
#include "EnemyBase.h"
class Enemy_Air : public EnemyBase
{
public:
    // cComponent��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void OnAlarm(string _Key) override;
    virtual void OnCollision(cObject* _Other) override;
    virtual void OnAnimationEnd(string _Key) override;
    void Fire();

    int Enemy_Hp;
    float EnemySpeed;
    float curShoot;
    float maxShoot;
};

