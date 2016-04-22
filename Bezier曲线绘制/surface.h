#include "spline.h"
#include "curve.h"

class Surface: public Spline
{
public:
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

class SurfaceOfRevolution :public Surface
{
public: 
	SurfaceOfRevolution(Curve *c){};
};

class BezierPatch :public Surface
{

};