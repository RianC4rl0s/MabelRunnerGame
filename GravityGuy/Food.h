#ifndef FOOD_H
#define FOOD_H

#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"

enum foodType{NORMAL_FOOD = 30};
class Food :public Object {
private:
	Sprite* food= nullptr;
	Color  color;
public:

	Food(float posX,float posY, Color tint);
	~Food();


	void Update();
	void Draw();
	void OnCollision(Object* obj);
};
inline void Food::Draw() {
	food->Draw(x, y, z, 1.0f,0.0f, color);
}
#endif// !FOOD_H