#include <stdio.h>
#include "Camera.hpp"
#include "Objects/Basic/Matrix.hpp"

Camera::Camera() {
	eye.x = 3, eye.y = 3, eye.z = 5.0;
	ref.x = 0.0, ref.y = 0.0, ref.z = 0.0;
	viewup.x = 0.0, viewup.y = 1.0, viewup.z = 0.0;
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 15.0, W = 0, H = 0;
}

void Camera::setDefaultCamera(void) { // make default camera
	eye.x = 3, eye.y = 3, eye.z = 5.0;
	ref.x = 0.0, ref.y = 0.0, ref.z = 0.0;
	viewup.x = 0.0, viewup.y = 1.0, viewup.z = 0.0;
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 15.0;
}

void Camera::set(Point Eye, Point Look, Vector Up) {
	eye.set(Eye);
	ref.set(Look);
	viewup.set(Up);
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 3.0;
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

void Camera::eyetranslate(GLfloat tx, GLfloat ty, GLfloat tz) { //w.r.p.t WC
	eye.x += tx;
	eye.y += ty;
	eye.z += tz;
}

void Camera::reftranslate(GLfloat tx, GLfloat ty, GLfloat tz) {
	eye.x += tx;
	eye.y += ty;
	eye.z += tz;
}

void Camera::move(int direction) {
	printf("eye:%f,%f,%f\n", eye.x, eye.y, eye.z);
	printf("ref:%f,%f,%f\n", ref.x, ref.y, ref.z);
	GLfloat x1 = eye.x;
	GLfloat y1 = eye.z;
	GLfloat x2 = ref.x;
	GLfloat y2 = ref.z;
	GLfloat a = (y2 - y1) / (x2 - x1);
	GLfloat b = y1 - (y2 - y1) / (x2 - x1) * x1;
	int d = (ref.x - eye.x) / abs(ref.x - eye.x);
	switch (direction) {
	case CAMERA_MOVE_FORWARD: {
		eye.x += d * CAMERA_MOVE_SPEED;
		eye.z = a * eye.x + b;
		ref.x += d * CAMERA_MOVE_SPEED;
		ref.z = a * ref.x + b;
		break;

	}
	case CAMERA_MOVE_BACKWARD: {
		eye.x += -d * CAMERA_MOVE_SPEED;
		eye.z = a * eye.x + b;
		ref.x += -d * CAMERA_MOVE_SPEED;
		ref.z = a * ref.x + b;
		break;
	}

	}

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
