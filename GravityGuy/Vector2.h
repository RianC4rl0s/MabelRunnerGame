

#ifndef  VECTOR_2
#define VECTOR_2

class Vector2 {
private:
	float x, y;


public:
	Vector2();
	Vector2(float X, float Y);
	~Vector2();
	float X();
	float Y();
	void setVector2(float X,float Y);
	void setY(float Y);
	void setX(float X);

	void applyForce(float X, float Y);
};
inline float Vector2::X() {
	return x;
}
inline float Vector2::Y() {
	return y;
}

#endif // ! VECTOR_2
