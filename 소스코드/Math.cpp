#include "DXUT.h"
#include "Math.h"
#include "Math.h"

int Math::Random(int _Min, int _Max)
{
	return _Min + (rand() | rand() << 16) % (_Max - _Min + 1);
}

float Math::Random(float _Min, float _Max)
{
	return Random(_Min * 10000, _Max * 10000) * 0.0001;
}

float Math::Sign(float _Value)
{
	if (_Value > 0)
		return 1;
	if (_Value < 0)
		return -1;
	return 0;
}

float Math::Clamp(float _Value, float _Min, float _Max)
{
	return min(_Max, max(_Value, _Min));
}

Vec2 Math::RotateVec2(Vec2 _Vec, float _Rot)
{
	float Rot = D3DXToRadian(_Rot);
	return Vec2(_Vec.x * cos(Rot) + _Vec.y * -sin(Rot), _Vec.x * sin(Rot) + _Vec.y * cos(Rot));
}

float Math::Distance(Vec2 _Vec)
{
	return D3DXVec2Length(&_Vec);
}

float Math::Direction(Vec2 _From, Vec2 _To)
{
	return atan2(_To.y - _From.y, _To.x - _From.x);
}
