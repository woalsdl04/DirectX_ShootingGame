#pragma once
namespace Math
{
	int Random(int _Min, int _Max);
	float Random(float _Min, float _Max);
	float Sign(float _Value);
	float Clamp(float _Value, float _Min, float _Max);
	Vec2 RotateVec2(Vec2 _Vec, float _Rot);
	float Distance(Vec2 _Vec);
	float Direction(Vec2 _From, Vec2 _To);
}