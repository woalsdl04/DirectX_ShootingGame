#pragma once
class cIngameScene : public cScene
{
public:

	// cScene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	float ScrollSpeed, curSpown, maxSpown;
	int	PlayerHp;
	float score;
	char Text[32];
	bool BossOn;
	bool Boss2On;
	Texture* Img;
	cObject* a;
	cObject* b;
};

