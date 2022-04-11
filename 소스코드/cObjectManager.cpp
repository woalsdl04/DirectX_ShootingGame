#include "DXUT.h"
#include "cObjectManager.h"

void cObjectManager::Init()
{
}

void cObjectManager::Update()
{
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto& iter = m_Objects[Tag].begin(); iter != m_Objects[Tag].end();)
		{
			if ((*iter)->m_isDestroyed)
			{
				(*iter)->Release();
				delete *iter;
				iter = m_Objects[Tag].erase(iter);
			}
			else
			{
				(*iter)->Update();
				if ((*iter)->GetComponent<cCircleCollider>() != nullptr)
				{
					CheckCollisionCircle(*iter);
				}
				else
				{
					CheckCollisionBox(*iter);
				}
				iter++;
			}
		}
	}
}

void cObjectManager::Render()
{
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto& iter : m_Objects[Tag])
		{
			iter->Render();
		}
	}
}

void cObjectManager::Release()
{
	Clear();
}

void cObjectManager::CheckCollisionCircle(cObject * _Object)
{
	cCircleCollider* SelfColl = _Object->GetComponent<cCircleCollider>();
	cCircleCollider* OtherCircle = nullptr;
	cBoxCollider* OtherBox = nullptr;
	for (auto& Tag : SelfColl->m_CollWith)
	{
		for (auto& iter : m_Objects[Tag])
		{
			OtherCircle = iter->GetComponent<cCircleCollider>();
			if (OtherCircle != nullptr)
			{
				for (auto& Self : SelfColl->m_Colliders)
				{
					for (auto& Other : OtherCircle->m_Colliders)
					{
						if (Distance(Self->WorldPos - Other->WorldPos) <= Self->Radius * _Object->m_Scale.x + Other->Radius * iter->m_Scale.x)
						{
							for (auto& Component : _Object->m_Components)
							{
								Component->OnCollision(iter);
								goto Next;
							}
						}
					}
				}
			}
			else
			{
				OtherBox = iter->GetComponent<cBoxCollider>();
				Vec2 Point, Pos;
				RECT WorldRect = {	OtherBox->m_Rect.left * abs(iter->m_Scale.x),
									OtherBox->m_Rect.top * abs(iter->m_Scale.y),
									OtherBox->m_Rect.right * abs(iter->m_Scale.x),
									OtherBox->m_Rect.bottom * abs(iter->m_Scale.y) };
				for (auto& Self : SelfColl->m_Colliders)
				{
					Pos = iter->m_Pos;
					Point = Vec2(Clamp(Self->WorldPos.x, Pos.x + WorldRect.left, Pos.x + WorldRect.right), Clamp(Self->WorldPos.y, Pos.y + WorldRect.top, Pos.y + WorldRect.bottom));
					if (Distance(Self->WorldPos - Point) <= Self->Radius * _Object->m_Scale.x);
					{
						for (auto& Component : _Object->m_Components)
						{
							Component->OnCollision(iter);
							goto Next;
						}
					}
				}
			}
		Next:
			continue;
		}
	}
}

void cObjectManager::CheckCollisionBox(cObject * _Object)
{
	cBoxCollider* SelfBox = _Object->GetComponent<cBoxCollider>();
	if (SelfBox == nullptr)
		return;
	cCircleCollider* OtherCircle = nullptr;
	cBoxCollider* OtherBox = nullptr;
	for (auto& Tag : SelfBox->m_CollWith)
	{
		for (auto& iter : m_Objects[Tag])
		{
			OtherCircle = iter->GetComponent<cCircleCollider>();
			if (OtherCircle != nullptr)
			{
				Vec2 Point, Pos;
				RECT WorldRect = {	SelfBox->m_Rect.left * abs(_Object->m_Scale.x),
									SelfBox->m_Rect.top * abs(_Object->m_Scale.y),
									SelfBox->m_Rect.right * abs(_Object->m_Scale.x),
									SelfBox->m_Rect.bottom *abs(_Object->m_Scale.y) };
				for (auto& Other : OtherCircle->m_Colliders)
				{
					Pos = _Object->m_Pos;
					Point = Vec2(Clamp(Other->WorldPos.x, Pos.x + WorldRect.left, Pos.x + WorldRect.right), Clamp(Other->WorldPos.y, Pos.y + WorldRect.top, Pos.y + WorldRect.bottom));
					if (Distance(Other->WorldPos - Point) <= Other->Radius * iter->m_Scale.x)
					{
						for (auto& Component : _Object->m_Components)
						{
							Component->OnCollision(iter);
							goto Next;
						}
					}
				}
			}
			else
			{
				OtherBox = iter->GetComponent<cBoxCollider>();
				RECT Rect;
				RECT SelfWorldRect = {	SelfBox->m_Rect.left * abs(_Object->m_Scale.x),
										SelfBox->m_Rect.top * abs(_Object->m_Scale.y),
										SelfBox->m_Rect.right * abs(_Object->m_Scale.x),
										SelfBox->m_Rect.bottom * abs(_Object->m_Scale.y) };

				RECT OtherWorldRect = { OtherBox->m_Rect.left * abs(iter->m_Scale.x),
										OtherBox->m_Rect.top * abs(iter->m_Scale.y),
										OtherBox->m_Rect.right * abs(iter->m_Scale.x),
										OtherBox->m_Rect.bottom * abs(iter->m_Scale.y) };
				if (IntersectRect(&Rect, &SelfWorldRect, &OtherWorldRect))
				{
					for (auto& Component : _Object->m_Components)
					{
						Component->OnCollision(iter);
					}
				}
			}
		Next:
			continue;
		}
	}
}

cObject * cObjectManager::AddObject(string _Name, Vec2 _Pos, ObjectTag _Tag)
{
	cObject* Temp = new cObject;
	Temp->m_Name = _Name;
	Temp->m_Pos = _Pos;
	Temp->m_Tag = _Tag;
	m_Objects[_Tag].push_back(Temp);
	return Temp;
}

void cObjectManager::Clear()
{
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto& iter : m_Objects[Tag])
		{
			iter->Release();
			delete iter;
		}
		m_Objects[Tag].clear();
	}
}
