#ifndef CURVE
#define CURVE



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "spline.h"
#include <GL/glut.h>

using namespace std;

class Curve :public Spline
{
public:
	Curve();
	Curve(int i);
	void set(int i, Vec3f v);


	// ���ڻ�ͼ��FOR VISUALIZATION
	void Paint(ArgParser *args);

	// ����ʵ����������ת����FOR CONVERTING BETWEEN SPLINE TYPES
	void OutputBezier(FILE *file);
	void OutputBSpline(FILE *file);

	// ���ڵõ����Ƶ��FOR CONTROL POINT PICKING
	int getNumVertices();
	Vec3f getVertex(int i);

	// ���ڱ༭������FOR EDITING OPERATIONS
	void moveControlPoint(int selectedPoint, float x, float y);
	void addControlPoint(int selectedPoint, float x, float y);
	void deleteControlPoint(int selectedPoint);

	// ���ڲ��������ε�FOR GENERATING TRIANGLES
	TriangleMesh* OutputTriangles(ArgParser *args);
};

class BezierCurve :public Curve
{
public:
	BezierCurve(){};
	BezierCurve(int i){};

	void set(int i, Vec3f v);
	void Paint(ArgParser *args);

	/*void ReadFile(ArgParser *args);*/

	float transferBezier(float coord1,float coord2,float coord3,float coord4,float t);
private:
	
};

class BSplineCurve:public Curve
{
public:
	BSplineCurve(){};
	BSplineCurve(int i){};
	
	void Paint(ArgParser *args);
};



#endif