#include "Vector2.h"

Vector2::Vector2() {
	x = y =  0;
}
Vector2::Vector2(float X,float Y) {
	x = X;
	y = Y;
}
Vector2::~Vector2() {

}


void Vector2::setVector2(float X, float Y) {
	x = X;
	y = Y;
}
void Vector2::setX(float X) {
	x = X;
}
void Vector2::setY(float Y) {
	x = Y;
}

void Vector2::applyForce(float X, float Y) {
	x += X;
	y += Y;
}