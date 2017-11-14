#include <stdio.h>
#include "Camera.hpp"
#include "Matrix.hpp"

bool DEBUG = false;

Camera::Camera() {
	eye.x = 3.0, eye.y = 3.0, eye.z = 7.0;
	ref.x = 0.0, ref.y = 0.0, ref.z = 0.0;
	viewup.x = 0.0, viewup.y = 1.0, viewup.z = 0.0;
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 10.0;
}

void Camera::setDefaultCamera(void) { // make default camera
	eye.x = 3.0, eye.y = 3.0, eye.z = 7.0;
	ref.x = 0.0, ref.y = 0.0, ref.z = 0.0;
	viewup.x = 0.0, viewup.y = 1.0, viewup.z = 0.0;
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 10.0;
}

void Camera::set(Point Eye, Point Look, Vector Up) {
	eye.set(Eye);
	ref.set(Look);
	viewup.set(Up);
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 10.0;
	//setModelViewMatrix();
}

void Camera::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) { //w.r.p.t WC
	angle = angle * 3.1415926 / 180;

	Point temp = eye;
	if (ry == 1) {
		eye.x = temp.z * sin(angle) + temp.x * cos(angle);
		eye.z = temp.z * cos(angle) - temp.x * sin(angle);
	} else if (rx == 1) {
		eye.y = temp.y * cos(angle) - temp.z * sin(angle);
		eye.z = temp.y * sin(angle) + temp.z * cos(angle);
	} else if (rz == 1) {
		eye.x = temp.x * cos(angle) - temp.y * sin(angle);
		eye.y = temp.x * sin(angle) + temp.y * cos(angle);
	}
}

void Camera::translate(GLfloat tx, GLfloat ty, GLfloat tz) { //w.r.p.t WC
	eye.x += tx;
	eye.y += ty;
	eye.z += tz;
	// need to be implemented
}

void Camera::clipfar(float speed) {
	farDist += speed;
	printf("%f\n", farDist);
}

void Camera::clipnear(float speed) {
	nearDist += speed;
	printf("%f\n", nearDist);
}

void Camera::angle(float angle) {
	/*
	Point temp = eye;
	eye.x += angle;
	eye.y = eye.x * temp.y / temp.x;
	 eye.z = eye.x * temp.z / temp.x;*/
	viewAngle += angle;
}
void Camera::setProjectionMatrix() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(viewAngle, aspect, nearDist, farDist);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, ref.x, ref.y, ref.z, viewup.x, viewup.y,
			viewup.z);

}
