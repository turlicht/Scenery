#ifndef CONTROL_H
#define CONTROL_H

#include "elements/color.h"

#include "controls/controlint.h"
#include "controls/controldouble.h"
#include "controls/controlbool.h"
#include "controls/controlstring.h"
#include "controls/controlcolor.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class Control
{
public:
    Control();

    QWidget *getWidget() { return widget; }

    void control(int &x, QString description, int min=0, int max=100);
    void control(double &x, QString description, double min=0, double max=100, int precision=1);
    void control(bool &x, QString description);
    void control(QString &string, QString description, QStringList list);
    void control(Color &color, QString description);

private:
    QWidget *widget;
    QGridLayout *layout;

    void addWidget(QWidget *widget, QString description);
};

#endif // CONTROL_H
