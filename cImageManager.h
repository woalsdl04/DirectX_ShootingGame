#pragma once
struct Texture
{
	D3DXIMAGE_INFO Info;
	LPDIRECT3DTEXTURE9 Image;
};
class cImageManager : public cSingleton<cImageManager>
{
public:
	void Init();
	void Release();
	void Begin();
	void End();
	void OnLostDevice();
	void OnResetDevice();

	map<string, Texture*> m_Images;
	map<string, vector<Texture*>*> m_Animations;
	LPD3DXSPRITE m_Sprite;
	LPD3DXFONT m_Font;

	void AddImage(string _Key, string _Path);
	Texture* Find(string _Key);
	void AddAnimation(string _Key);
	vector<Texture*>* FindAnimation(string _Key);

	void Render(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, Vec2 _Pivot = Vec2(0.5f, 0.5f), D3DCOLOR _Color = 0xffffffff, bool _isView = false);
	void RenderRect(Texture* _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, Vec2 _Pivot = Vec2(0.5f, 0.5f), D3DCOLOR _Color = 0xffffffff, bool _isView = false);
	void RenderText(string _Text, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, Vec2 _Pivot = Vec2(0.5f, 0.5f), D3DCOLOR _Color = 0xffffffff, bool _isView = false);
};

#define IMAGE cImageManager::GetInstance()