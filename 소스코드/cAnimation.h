#pragma once
struct Animation
{
	vector<Texture*>* Anim;
	float Speed;
	int MaxFrame;
	bool isLoop;
	string Key;
};
class cAnimation : public cComponent
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

	map<string, Animation*> m_Animations;
	Animation* m_CurAnim;
	float m_Frame;
	float m_Speed;
	int m_LastFrame;

	void AddAnimation(string _Key, string _Resource, float _Speed, bool _isLoop = true);
	void SetAnimation(string _Key);
};

