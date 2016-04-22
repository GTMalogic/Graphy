#ifndef SPLINE
#define SPLINE

//#include <GL/glut.h>
#include "vectors.h"
#include "triangle_mesh.h"
#include "arg_parser.h"

using namespace std;

class Spline
{
public:

	// ���ڻ�ͼ��FOR VISUALIZATION
	virtual void Paint(ArgParser *args){};

	// ����ʵ����������ת����FOR CONVERTING BETWEEN SPLINE TYPES
	virtual void OutputBezier(FILE *file){};
	virtual void OutputBSpline(FILE *file){};

	// ���ڵõ����Ƶ��FOR CONTROL POINT PICKING
	virtual int getNumVertices(){ return 0; };
	virtual Vec3f getVertex(int i){
		Vec3f a = { 0, 0, 0 }; return a;
	};

	// ���ڱ༭������FOR EDITING OPERATIONS
	virtual void moveControlPoint(int selectedPoint, float x, float y){};
	virtual void addControlPoint(int selectedPoint, float x, float y){};
	virtual void deleteControlPoint(int selectedPoint){};
	
	// ���ڲ��������ε�FOR GENERATING TRIANGLES
	virtual TriangleMesh* OutputTriangles(ArgParser *args){ return 0; };
};


#endif