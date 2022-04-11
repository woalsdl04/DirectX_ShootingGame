#include "DXUT.h"
#include "cRenderer.h"

void cRenderer::Init()
{
}

void cRenderer::Update()
{
}

void cRenderer::Render()
{
	IMAGE->Render(m_Image, m_Owner->m_Pos + add_pos, m_Owner->m_Rot, m_Owner->m_Scale, m_Owner->m_Depth, Vec2(0.5, 0.5), m_Color);
}

void cRenderer::Release()
{
}

void cRenderer::OnAlarm(string _Key)
{
}

void cRenderer::OnCollision(cObject * _Other)
{
}

void cRenderer::OnAnimationEnd(string _Key)
{
}
