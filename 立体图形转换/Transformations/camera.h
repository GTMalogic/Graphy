#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "ray.h"
#include "vectors.h"

class Camera
{
public:
	Camera(){}
	virtual Ray generateRay(Vec2f point) = 0{ Ray ray; return ray; }
	virtual float getTMin() const = 0{}
private:
};

class PerspectiveCamera :public Camera
{
public:
	PerspectiveCamera(Vec3f center, Vec3f direction, Vec3f up, float angle_radians)
	{
		m_center = center;
		m_direction = direction;
		m_direction.Normalize();
		//ʩ��������������
		m_up = up - up.Dot3(direction) / direction.Dot3(direction) * direction;
		m_up.Normalize();

		//��up��direction����ˮƽ��λ����
		Vec3f::Cross3(m_horizon, direction, up);
		m_horizon.Normalize();

		m_angle_radians = angle_radians;

		m_virtual_center = m_center + m_direction;
	}
	Ray generateRay(Vec2f point)
	{
		Vec3f origin;
		float f = 2 * tan(m_angle_radians / 2.0);
		origin = m_virtual_center + (point.y() - 0.5)*f*m_up + (point.x() - 0.5)*f*m_horizon;
		Vec3f direction(origin, m_center);
		direction.Normalize();
		Ray ray(m_center, direction);

		return ray;
	}
	float getTMin()const { return 0.0; }
private:
	Vec3f m_center;
	Vec3f m_direction;
	Vec3f m_up;
	Vec3f m_horizon;
	Vec3f m_virtual_center;
	float m_angle_radians;
};

class OrthographicCamera :public Camera
{
public:
	OrthographicCamera(){}
	OrthographicCamera(Vec3f center, Vec3f direction, Vec3f up,float size):
		m_center(center), m_size(size){
		//ʩ��������������
		m_up = up - up.Dot3(direction) / direction.Dot3(direction) * direction;
		m_up.Normalize();

		//����������λ��
		direction.Normalize();
		m_direction = direction;

		//��up��direction����ˮƽ��λ����
		Vec3f::Cross3(m_horizon, m_up, m_direction);
		m_horizon.Normalize();
		tmin = -100000.0;
	}
	~OrthographicCamera(){}
	Ray generateRay(Vec2f point)
	{
		//��ÿ����Ļ�������һ������ray
		//center - (size*up)/2 - (size*horizontal)/2  ->  center + (size*up)/2 + (size*horizontal)/2
		Vec3f origin;
		//��ͼƬ�����½ǿ�ʼ�����Ϸ��ƶ�
		origin = m_center - (m_size*m_up)*0.5 + (m_size * m_horizon)*0.5 + point.y()*m_up*m_size - point.x()*m_horizon*m_size;
		//origin = m_center + (point.x() - 0.5)*m_size*m_up + (point.y() - 0.5)*m_size*m_horizon;
		Ray ray(origin, m_direction);
		return ray;
	}
	float getTMin()const{ return tmin; }
private:
	Vec3f m_center, m_direction, m_up,m_horizon;
	float m_size;
	float tmin;
};
#endif __CAMERA_H__