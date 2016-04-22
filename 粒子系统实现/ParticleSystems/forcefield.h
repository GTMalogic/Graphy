#ifndef __FORCEFIELD_H__
#define __FORCEFIELD_H__
#include "vectors.h"
class ForceField
{
public:
	//���麯������������࣬����಻��ʵ���������ǿ���
	virtual Vec3f getAcceleration(const Vec3f &position, float mass, float t) = 0;
private:

};

class GravityForceField :public ForceField
{
public:
	GravityForceField(Vec3f gravity):G(gravity){ }
	Vec3f getAcceleration(const Vec3f &position, float mass, float t);
private:
	Vec3f G;
};

class ConstantForceField :public ForceField
{
public:
	ConstantForceField(Vec3f force):m_force(force){ }
	Vec3f getAcceleration(const Vec3f &position, float mass, float t);
private:
	Vec3f m_force;
};

class RadialForceField :public ForceField
{
public:
	RadialForceField(float magnitude){ m_magnitude = magnitude; }
	//��δʵ��
	Vec3f getAcceleration(const Vec3f &position, float mass, float t);
private:
	float m_magnitude;
};

class VerticalForceField :public ForceField
{
public:
	VerticalForceField(float magnitude):m_magnitude(magnitude){}
	//��δʵ��
	Vec3f getAcceleration(const Vec3f &position, float mass, float t);
private:
	float m_magnitude;
};

class WindForceField :public ForceField
{
public:
	WindForceField(float magnitude):m_magnitude(magnitude){ }
	//��δʵ��
	Vec3f getAcceleration(const Vec3f &position, float mass, float t){ return position; }
private:
	float m_magnitude;

};

#endif __FORCEFIELD_H__
