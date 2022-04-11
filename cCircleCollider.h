#pragma once
struct CircleCollider
{
	Vec2 WorldPos;
	Vec2 LocalPos;
	float Radius;
};
class cCircleCollider : public cCollider
{
public:

	// cComponent을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnAlarm(string _Key) override;
	virtual void OnCollision(cObject * _Other) override;
	virtual void OnAnimationEnd(string _Key) override;

	vector<CircleCollider*> m_Colliders;
	vector<ObjectTag> m_CollWith;

	void AddCollider(Vec2 _Offset, float _Radius);
	void AddCollideWith(ObjectTag _Tag);
	void UpdateCollider() override;
};

