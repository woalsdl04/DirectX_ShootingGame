#pragma once
class Player_Bullet : public cComponent
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
	void BulletSet(int _dmg, float _speed, float _ang);
	
	int Dmg;
	float Ang;
	float BulletSpeed;

	
};

