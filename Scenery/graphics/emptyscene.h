#ifndef EMPTYSCENE_H
#define EMPTYSCENE_H

#include "sscene.h"

class EmptyScene : public SScene
{
public:
    EmptyScene(){}

    void virtual setupEvent(void *){}
    void virtual paintEvent(){}
    void virtual resizeEvent(int, int){}
};

#endif // EMPTYSCENE_H
