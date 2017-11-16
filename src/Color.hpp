
#ifndef SRC_COLOR_HPP_
#define SRC_COLOR_HPP_

#include <GL/glut.h>
class Color {
public:
	GLfloat red, green, blue, alpha;
	Color();
	Color(float red, float green, float blue, float alpha);
	void set(float red, float green, float blue, float alpha);

};



#endif /* SRC_COLOR_HPP_ */
