#ifndef SKELETON_H
#define SKELETON_H

#include "graphics/scene.h"

class Skeleton : public Scene
{
public:
    Skeleton();

    QString name() { return "Skeleton"; }

    void setup();
    void resize();
    void paint();

private:
    Image *imageShip;

};

#endif // SKELETON_H