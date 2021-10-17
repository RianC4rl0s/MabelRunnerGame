#ifndef BIRD_H
#define BIRD_H

#include "TileSet.h"
#include "Animation.h"
#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites
enum birdType
{
	NORMAL_BIRD =55,
};
class Bird :public Object {
private:
	TileSet* bird= nullptr;
	Animation* anim = nullptr;
	Color color;

public:

	Bird(float posX, float posY, Color tint);
	~Bird();

	void Update();
	void Draw();
};


#endif // !BIRD_H
