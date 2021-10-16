#ifndef THORN_TRAP_H
#define THORN_TRAP_H

#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites
enum thornType
{
	NORMAL_THORN = 10,
};
class Thorn :public Object {
private:
	Sprite* thorn = nullptr;
	Color color;

public:

	Thorn(float posX,float posY,Color tint);
	~Thorn();

	void Update();
	void Draw();
};
inline void Thorn::Draw() {
	thorn->Draw(x, y, z, 1.0f, 0.0f, color);
}
#endif // !THORN_TRAP_H

