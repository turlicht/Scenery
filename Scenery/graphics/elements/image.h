#ifndef IMAGE_H
#define IMAGE_H

#include <QGLFunctions>
#include <QImage>
#include <QString>

class Image : public QImage
{
public:
    Image(const QString &fileName);
    GLuint getID() { return id; }
    void setID(GLuint id) { this->id = id; }
    QString getFileName() { return fileName; }

private:
    GLuint id;
    QString fileName;

};

#endif // IMAGE_H
