#include "surface.h"

void Surface::set(int i, Vec3f v)
{

}

// ���ڻ�ͼ��FOR VISUALIZATION
void Surface::Paint(ArgParser *args)
{

}

// ����ʵ����������ת����FOR CONVERTING BETWEEN SPLINE TYPES
void Surface::OutputBezier(FILE *file)
{

}
void Surface::OutputBSpline(FILE *file)
{

}

// ���ڵõ����Ƶ��FOR CONTROL POINT PICKING
int Surface::getNumVertices()
{
	return 0;
}
Vec3f Surface::getVertex(int i)
{
	Vec3f v(0,0,0);
	return v;
}

// ���ڱ༭������FOR EDITING OPERATIONS
void Surface::moveControlPoint(int selectedPoint, float x, float y)
{

}
void Surface::addControlPoint(int selectedPoint, float x, float y)
{

}
void Surface::deleteControlPoint(int selectedPoint)
{

}

// ���ڲ��������ε�FOR GENERATING TRIANGLES
TriangleMesh* Surface::OutputTriangles(ArgParser *args)
{
	return 0;
}