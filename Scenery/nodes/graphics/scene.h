#ifndef SCENE_H
#define SCENE_H

#include <QString>
#include <QPainter>

#include "nodes/node.h"
#include "tools.h"
#include "graphic.h"
#include "nodes/controls/icontrol.h"


class Scene: public Tools, public Graphic
{
public:
    Scene();
    ~Scene();

    virtual QString name() { return "Noname"; }
    virtual void setup(){}
    virtual void resize(){}
    virtual void paint(){}
    virtual void action(int){}

    Port *input(int n) { return _inputs->at(n); }

    void control(int &x, QString description, int min=0, int max=999, int step=1);
    void control(double &x, QString description, double min=0, double max=100, int precision=1);
    void control(bool &x, QString description);
    void control(QString &string, QString description, QStringList list);

private:
    friend class View;
    friend class ScenesNode;

    Controls _controls;
    Ports *_inputs;

};

#endif // SCENE_H