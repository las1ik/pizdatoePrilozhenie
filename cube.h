#ifndef CUBE_H
#define CUBE_H
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class cube : protected QOpenGLFunctions
{
public:
    cube();
    virtual ~cube();

    void drawCubeGeometry(QOpenGLShaderProgram *program);
private:
    void initCubeGeometry();

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};

#endif // CUBE_H
