#include "node.h"
#include "debug.h"

Node::Node() :
    _uuid(QUuid::createUuid()),
    _posX(0),
    _posY(0)
{
    METHOD_BEGIN

    time.start();
    timeMean = 0;
    timeNum = 0;
    timeResult = 0;

    METHOD_END
}

Node::~Node()
{

}

QJsonObject Node::getJson()
{
    QJsonObject json;
    json["uuid"] = uuid();
    json["name"] = name();
    json["posX"] = posX();
    json["posY"] = posY();
    json["control"] = getControlJson();
    return json;
}

void Node::setJson(QJsonObject json)
{
    setPos(json["posX"].toInt(), json["posY"].toInt());
    setControlJson(json["control"].toObject());
}

void Node::processNext()
{
    foreach (Port *port, outputs) {
        foreach (Link *link, port->links) {
            Node *next = link->node;

            Q_ASSERT(next);
            Q_ASSERT(next->inputs.count() > link->port_id);

            if (!next->isProcessing()) {
                next->inputs.at(link->port_id)->mat = port->mat.clone();
                next->inputs.at(link->port_id)->human = port->human;
                next->inputs.at(link->port_id)->rect = port->rect;
                next->inputs.at(link->port_id)->booleans = port->booleans;
                next->process();
            }
        }
    }
}

void Node::timing_start()
{
    time.restart();
}

void Node::timing_finish()
{
    timeMean += time.elapsed();
    timeNum++;
    if ( timeNum == 10 ) {
        timeResult = timeMean/10;
        timeMean = 0;
        timeNum = 0;

        //qDebug() << name() << timeResult;
    }
}

void Node::input(PortType type)
{
    inputs.append(new Port(type));
}

void Node::output(PortType type)
{
    outputs.append(new Port(type));
}
