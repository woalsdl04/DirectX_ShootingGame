#pragma once
class cBoxCollider : public cCollider
{
public:

	// cComponent��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnAlarm(string _Key) override;
	virtual void OnCollision(cObject * _Other) override;
	virtual void OnAnimationEnd(string _Key) override;

	RECT m_Rect;
	vector<ObjectTag> m_CollWith;

	void AddCollideWith(ObjectTag _Tag);
	void UpdateCollider() override;
};

