#pragma once
class GameStart : public cScene
{
	// cScene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	float ScreenSpeed;
	bool Swh;
};

