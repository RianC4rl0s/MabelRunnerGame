
#ifndef DECORATION_H
#define DECORATION_H

#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites


enum DECORATIONS_TYPE { SMALL_TREE, MEDIUM_TREE_1, MEDIUM_TREE_2, PINE, DEAD_TREE,FINISH_LINE};


class Decoration :public Object {
private:
    Sprite* decoration = nullptr;            // sprite da plataforma
    Color color;                            // cor da plataforma
    float width;
public:
    Decoration(float posX,float PosY,uint treeType,Color tint,float layer);
    ~Decoration();

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    float Width();

};

inline void Decoration::Draw()
{
    decoration->Draw(x, y, z, 1.0f, 0.0f, color);
}

#endif