#ifndef VIEW_H
#define VIEW_H

#include <QGLWidget>
#include <QGLFunctions>
#include <QTime>

#include "iscene.h"
#include "elements/image.h"

class View : public QGLWidget, protected QGLFunctions
{
public:
    View(QGLFormat &format);
    void setScene(IScene *scene);

    int getFPS() { return fpsResult; }
    int getTimeScene();
    int getPaintTimeScene();

    void addImage(Image *image);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    GLint width;
    GLint height;
    IScene *scene;
    QTime timeScene;
    int timePaint;
    int prevTimePaint;
    int differenceTimePaint;

    int time;
    int timeMean;
    int timeNum;

    QTime fpsTime;
    int fpsRest;
    int fpsFrames;
    int fpsResult;

    QVector<Image *> images;
};

#endif // VIEW_H
