#pragma once
#include "cComponent.h"
enum Boss_State
{
    Boss_Ready, 
    Boss_Wait,
    Boss_Idle,
    Boss_Move,
    Boss_Attack
};
 
class Boss :
    public cComponent
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
    void Boss_Attack1();
    void Boss_Attack2();
    void Boss_Attack3();
    bool Timer(float _time);

    float WaitTime;
    int Boss_Hp;
    float BossSpeed;
    int BossState;
    Vec2 TargetPos, a;
    int ang, rotate, BulletCount;
    int BossAttack_Sel;
    cObject* Player;
    float Judo;
};

