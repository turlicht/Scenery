#include "controlcolor.h"

ControlColor::ControlColor(Color &color) :
    color(color)
{
    spinR = new QDoubleSpinBox();
    spinR->setRange(0, 1);
    spinR->setDecimals(2);
    spinR->setSingleStep(0.05);
    spinR->setValue(color.r);

    spinG = new QDoubleSpinBox();
    spinG->setRange(0, 1);
    spinG->setDecimals(2);
    spinG->setSingleStep(0.05);
    spinG->setValue(color.g);

    spinB = new QDoubleSpinBox();
    spinB->setRange(0, 1);
    spinB->setDecimals(2);
    spinB->setSingleStep(0.05);
    spinB->setValue(color.b);

    spinA = new QDoubleSpinBox();
    spinA->setRange(0, 1);
    spinA->setDecimals(2);
    spinA->setSingleStep(0.05);
    spinA->setValue(color.a);

    hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->addWidget(spinR);
    hLayout->addWidget(spinG);
    hLayout->addWidget(spinB);
    hLayout->addWidget(spinA);

    this->setLayout(hLayout);

    connect(spinR, SIGNAL(valueChanged(double)),  SLOT(slotChange()));
    connect(spinG, SIGNAL(valueChanged(double)),  SLOT(slotChange()));
    connect(spinB, SIGNAL(valueChanged(double)),  SLOT(slotChange()));
    connect(spinA, SIGNAL(valueChanged(double)),  SLOT(slotChange()));
}

void ControlColor::setData(QString &data)
{
}

void ControlColor::slotChange()
{
    color.r = spinR->value();
    color.g = spinG->value();
    color.b = spinB->value();
    color.a = spinA->value();
}
