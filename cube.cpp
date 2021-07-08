#include "cube.h"

#include <QVector2D>
#include <QVector3D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

cube::cube()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
        // Vertex data for face 1
    initializeOpenGLFunctions();

    arrayBuf.create();
    indexBuf.create();

    initCubeGeometry();
}

cube::~cube()
{
    arrayBuf.destroy();
    indexBuf.destroy();
}

void cube::initCubeGeometry()
{
//    GLfloat cubeVertexArray[8][3];
//    GLfloat cubeColorArray[8][3];
//    GLubyte cubeIndexArray[6][4];


//    cubeVertexArray[0][0] = 0.0;
//    cubeVertexArray[0][1] = 0.0;
//    cubeVertexArray[0][2] = 1.0;
//    cubeVertexArray[1][0] = 0.0;
//    cubeVertexArray[1][1] = 1.0;
//    cubeVertexArray[1][2] = 1.0;
//    cubeVertexArray[2][0] = 1.0;
//    cubeVertexArray[2][1] = 1.0;
//    cubeVertexArray[2][2] = 1.0;
//    cubeVertexArray[3][0] = 1.0;
//    cubeVertexArray[3][1] = 0.0;
//    cubeVertexArray[3][2] = 1.0;
//    cubeVertexArray[4][0] = 0.0;
//    cubeVertexArray[4][1] = 0.0;
//    cubeVertexArray[4][2] = 0.0;
//    cubeVertexArray[5][0] = 0.0;
//    cubeVertexArray[5][1] = 1.0;
//    cubeVertexArray[5][2] = 0.0;
//    cubeVertexArray[6][0] = 1.0;
//    cubeVertexArray[6][1] = 1.0;
//    cubeVertexArray[6][2] = 0.0;
//    cubeVertexArray[7][0] = 1.0;
//    cubeVertexArray[7][1] = 0.0;
//    cubeVertexArray[7][2] = 0.0;
//    cubeColorArray[0][0] = 0.0;
//    cubeColorArray[0][1] = 0.0;
//    cubeColorArray[0][2] = 1.0;
//    cubeColorArray[1][0] = 0.6;
//    cubeColorArray[1][1] = 0.98;
//    cubeColorArray[1][2] = 0.6;
//    cubeColorArray[2][0] = 1.0;
//    cubeColorArray[2][1] = 0.84;
//    cubeColorArray[2][2] = 0.8;
//    cubeColorArray[3][0] = 0.8;
//    cubeColorArray[3][1] = 0.36;
//    cubeColorArray[3][2] = 0.36;
//    cubeColorArray[4][0] = 1.0;
//    cubeColorArray[4][1] = 0.27;
//    cubeColorArray[4][2] = 0.0;
//    cubeColorArray[5][0] = 0.82;
//    cubeColorArray[5][1] = 0.13;
//    cubeColorArray[5][2] = 0.56;
//    cubeColorArray[6][0] = 0.54;
//    cubeColorArray[6][1] = 0.17;
//    cubeColorArray[6][2] = 0.89;
//    cubeColorArray[7][0] = 0.0;
//    cubeColorArray[7][1] = 1.0;
//    cubeColorArray[7][2] = 1.0;
//    cubeIndexArray[0][0] = 0;
//    cubeIndexArray[0][1] = 3;
//    cubeIndexArray[0][2] = 2;
//    cubeIndexArray[0][3] = 1;
//    cubeIndexArray[1][0] = 0;
//    cubeIndexArray[1][1] = 1;
//    cubeIndexArray[1][2] = 5;
//    cubeIndexArray[1][3] = 4;
//    cubeIndexArray[2][0] = 7;
//    cubeIndexArray[2][1] = 4;
//    cubeIndexArray[2][2] = 5;
//    cubeIndexArray[2][3] = 6;
//    cubeIndexArray[3][0] = 3;
//    cubeIndexArray[3][1] = 7;
//    cubeIndexArray[3][2] = 6;
//    cubeIndexArray[3][3] = 2;
//    cubeIndexArray[4][0] = 1;
//    cubeIndexArray[4][1] = 2;
//    cubeIndexArray[4][2] = 6;
//    cubeIndexArray[4][3] = 5;
//    cubeIndexArray[5][0] = 0;
//    cubeIndexArray[5][1] = 4;
//    cubeIndexArray[5][2] = 7;
//    cubeIndexArray[5][3] = 3;


    // For cube we would need only 8 vertices but we have to
    // duplicate vertex for each face because texture coordinate
    // is different.
    VertexData vertices[] = {
        // Vertex data for face 0
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.0f, 0.0f)},  // v0
        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D(0.33f, 0.0f)}, // v1
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(0.0f, 0.5f)},  // v2
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.33f, 0.5f)}, // v3

        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D( 0.0f, 0.5f)}, // v4
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.33f, 0.5f)}, // v5
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.0f, 1.0f)},  // v6
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.33f, 1.0f)}, // v7

        // Vertex data for face 2
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.66f, 0.5f)}, // v8
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(1.0f, 0.5f)},  // v9
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.66f, 1.0f)}, // v10
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(1.0f, 1.0f)},  // v11

        // Vertex data for face 3
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(0.66f, 0.0f)}, // v12
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(1.0f, 0.0f)},  // v13
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(0.66f, 0.5f)}, // v14
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(1.0f, 0.5f)},  // v15

        // Vertex data for face 4
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(0.33f, 0.0f)}, // v16
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.66f, 0.0f)}, // v17
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.33f, 0.5f)}, // v18
        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D(0.66f, 0.5f)}, // v19

        // Vertex data for face 5
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(0.33f, 0.5f)}, // v20
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.66f, 0.5f)}, // v21
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(0.33f, 1.0f)}, // v22
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.66f, 1.0f)}  // v23
    };

    // Indices for drawing cube faces using triangle strips.
    // Triangle strips can be connected by duplicating indices
    // between the strips. If connecting strips have opposite
    // vertex order then last index of the first strip and first
    // index of the second strip needs to be duplicated. If
    // connecting strips have same vertex order then only last
    // index of the first strip needs to be duplicated.
    GLushort indices[] = {
         0,  1,  2,  3,  3,     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
         4,  4,  5,  6,  7,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
         8,  8,  9, 10, 11, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
        12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
        16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
        20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    };

//! [1]
    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, 24 * sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, 34 * sizeof(GLushort));
//! [1]
}

void cube::drawCubeGeometry(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    indexBuf.bind();

    // Offset for position
    quintptr offset = 0;

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Offset for texture coordinate
    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, nullptr);
}
