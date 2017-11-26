
#ifndef CCAMERA_H
#define CCAMERA_H

#include <GL/glut.h>
#include "Constant.hpp"
#include "Objects/Basic/Point.hpp"
#include "Objects/Basic/Vector.hpp"

class Camera {
 public:
	Point eye; 			//camera position
	Point ref; 			//look at point
	Vector viewup; 		//view up vector
	GLfloat aspect, nearDist, farDist, viewAngle, W, H;
	int Object;
	Camera();
	void set(Point Eye, Point look, Vector up);
	void set(float ex, float ey, float ez, float lx, float ly, float lz, float upx, float upy, float upz);
	void setDefaultCamera();

	void rotate(GLfloat rx, GLfloat rz, GLfloat ry, GLfloat angle);
	void eyetranslate(GLfloat tx, GLfloat ty, GLfloat tz);
	void reftranslate(GLfloat tx, GLfloat ty, GLfloat tz);
	void setViewVolume(float viewAngle, float aspect, float Near, float Far);
	void move(int direction);
	void turn (int direction);
	void updown(int direction);

	void setProjectionMatrix();


};
#endif


