#pragma once
#include "cComponent.h"
class Stage1 :
    public cComponent
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

    float ScrollSpeed, curSpown, maxSpown;

};
