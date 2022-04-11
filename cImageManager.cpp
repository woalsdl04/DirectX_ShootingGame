#include "DXUT.h"
#include "cImageManager.h"

void cImageManager::Init()
{
	D3DXCreateSprite(g_Device, &m_Sprite);
	D3DXCreateFont(g_Device, 64, 0, 0, 1, 0, DEFAULT_CHARSET, 0, 0, 0, L"µ¸¿ò", &m_Font);
}

void cImageManager::Release()
{
	for (auto& iter : m_Images)
	{
		iter.second->Image->Release();
		delete iter.second;
	}
	for (auto& iter : m_Animations)
	{
		delete iter.second;
	}
	m_Sprite->Release();
	m_Font->Release();
}

void cImageManager::Begin()
{
	m_Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);
	g_Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DX_FILTER_NONE);
	g_Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DX_FILTER_NONE);
	g_Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DX_FILTER_NONE);
}

void cImageManager::End()
{
	m_Sprite->End();
}

void cImageManager::OnLostDevice()
{
	m_Sprite->OnLostDevice();
}

void cImageManager::OnResetDevice()
{
	m_Sprite->OnResetDevice();
}

void cImageManager::AddImage(string _Key, string _Path)
{
	Texture* Tex = new Texture;
	if (D3DXCreateTextureFromFileExA(g_Device, _Path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_POINT, D3DX_FILTER_POINT, 0, &Tex->Info, 0, &Tex->Image) == S_OK)
	{
		m_Images.insert(make_pair(_Key, Tex));
		return;
	}
	delete Tex;
}

Texture * cImageManager::Find(string _Key)
{
	return m_Images[_Key];
}

void cImageManager::AddAnimation(string _Key)
{
	char Key[64];
	vector<Texture*>* Vec = new vector<Texture*>;
	for (int i = 1; true; i++)
	{
		sprintf(Key, "%s%d", _Key.c_str(), i);
		auto Find = m_Images.find(Key);
		if (Find != m_Images.end())
		{
			Vec->push_back((*Find).second);
		}
		else
		{
			m_Animations.insert(make_pair(_Key, Vec));
			break;
		}
	}
}

vector<Texture*>* cImageManager::FindAnimation(string _Key)
{
	return m_Animations[_Key];
}

void cImageManager::Render(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, Vec2 _Pivot, D3DCOLOR _Color, bool _isView)
{
	Matrix Mat;
	Vec2 Center = Vec2(_Pivot.x * (float)_Image->Info.Width, _Pivot.y * (float)_Image->Info.Height);
	D3DXMatrixTransformation2D(&Mat, &Center, 0, &_Scale, &Center, _Rot, &(_Pos - Center));
	Mat._43 = _Depth;
	if (_isView) Mat *= CAMERA->GetViewMatrix();
	m_Sprite->SetTransform(&Mat);
	m_Sprite->Draw(_Image->Image, nullptr, nullptr, nullptr, _Color);
}

void cImageManager::RenderRect(Texture * _Image, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, RECT _Rect, Vec2 _Pivot, D3DCOLOR _Color, bool _isView)
{
	Matrix Mat;
	Vec2 Center = Vec2(_Pivot.x * (float)_Image->Info.Width, _Pivot.y * (float)_Image->Info.Height);
	D3DXMatrixTransformation2D(&Mat, &Center, 0, &_Scale, &Center, _Rot, &(_Pos - Center));
	if (_isView) Mat *= CAMERA->GetViewMatrix();
	Mat._43 = _Depth;
	m_Sprite->SetTransform(&Mat);
	m_Sprite->Draw(_Image->Image, &_Rect, nullptr, nullptr, _Color);
}

void cImageManager::RenderText(string _Text, Vec2 _Pos, float _Rot, Vec2 _Scale, float _Depth, Vec2 _Pivot, D3DCOLOR _Color, bool _isView)
{
	Matrix Mat;
	RECT Rect = RECT{ 0,0,0,0 };
	m_Font->DrawTextA(m_Sprite, _Text.c_str(), -1, &Rect, DT_NOCLIP | DT_CENTER | DT_VCENTER | DT_CALCRECT, 0xffffffff);
	Vec2 Center = Vec2(_Pivot.x * (float)Rect.right, _Pivot.y * (float)Rect.bottom) * 2;
	D3DXMatrixTransformation2D(&Mat, &Center, 0, &_Scale, &Center, _Rot, &(_Pos - Center));
	if (_isView) Mat *= CAMERA->GetViewMatrix();
	Mat._43 = _Depth;
	m_Sprite->SetTransform(&Mat);
	m_Font->DrawTextA(m_Sprite, _Text.c_str(), -1, nullptr, DT_NOCLIP | DT_CENTER | DT_VCENTER, _Color);
}
