#include "brush.h"

Brush::Brush()
{
    button(0, "Rand color");

    control(mode="None", "Type of brush", QStringList() << "Line" << "Blots");

    control(backColor=Color(0,0,0,1), "Background");

    control(lineColor=Color(1,1,1,1), "Line Color");
    control(lineSize=8, "Line size", 0, 300);
    control(lineLimit=10, "Line speed limit", 0, 100);

    control(blotColor=Color(1,1,1,1), "Blot Color");
    control(blotSize=100, "Blot size", 0, 300);
    control(blotLimit=50, "Blot speed limit", 0, 100);

    blotImages[0] = loadImage("images/brushes/blot01.png");
    blotImages[1] = loadImage("images/brushes/blot02.png");
    blotImages[2] = loadImage("images/brushes/blot03.png");
    blotImages[3] = loadImage("images/brushes/blot04.png");
    blotImages[4] = loadImage("images/brushes/blot05.png");
}

void Brush::setup()
{
    size(getWidth(0), getHeight(0));
    background(0.0f, 0.0f, 0.0f, 1.0f);
}

void Brush::paint()
{
    if (mode == "Line") {
        SeqAreas &seqAreas = getSeqAreas(0);
        for (unsigned int i=0; i<seqAreas.size(); i++) {
            SeqArea &seqArea = seqAreas.at(i);
            if (seqArea.number > 1 && seqArea.length > blotLimit) {
                color(lineColor);
                lineWidth(lineSize);
                line(seqArea.pt[0], seqArea.pt[1], seqArea.ptPrev[0], seqArea.ptPrev[1]);
            }
        }
    }
    else if (mode == "Blots") {
        SeqAreas &seqAreas = getSeqAreas(0);
        for (unsigned int i=0; i<seqAreas.size(); i++) {
            SeqArea &seqArea = seqAreas.at(i);
            if (seqArea.number > 1 && seqArea.length > blotLimit) {
                glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
                GLfloat envColor2[4] = {blotColor.r, blotColor.g, blotColor.b, 0};
                glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, envColor2);

                float x = seqArea.pt[0];
                float y = seqArea.pt[1];
                image(blotImages[random(5)], x, y,
                      blotSize, blotSize, random(360)/2.0*M_PI);
            }
        }
    }
}

void Brush::push(int id)
{
    switch(id) {
    case 0:
        blotColor.randomRGB();
        break;
    }
}
