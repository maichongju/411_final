#ifndef SRC_OBJECTS_ENVIRONMENT_MOUNTAIN_HPP_
#define SRC_OBJECTS_ENVIRONMENT_MOUNTAIN_HPP_

#include "../Basic/Pyramid.hpp"
#include "../Basic/Point.hpp"
#include "../../Constant.hpp"

class Mountain{
public:
	Mountain();
	Mountain(float x,float y,float z);
	void translate(float x, float y, float z);
	void draw();
	void scale(float s);
	void setTextureID(int Texture);
	//void scale(float x, float y , float z);
private:
	//Point *position;
	Pyramid *p;
	int TextureID;

};


#endif
