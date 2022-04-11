#pragma once
#include "cComponent.h"

enum Boss2_State
{
    Boss2_Ready,
    Boss2_Wait,
    Boss2_Idle,
    Boss2_Move,
    Boss2_Attack
};

class Boss2 :
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

    float WaitTime;
    int Boss_Hp;
    float BossSpeed;
    int BossState;
    Vec2 TargetPos, a;
    int ang, rotate, BulletCount;
    int BossAttack_Sel;
    cObject* Player;
    float Judo;
    float BossAttack3_Ang;
    float curShot;
    int AttackCount;
};

