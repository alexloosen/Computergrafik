#include "skybox.h"

Skybox::Skybox()
{
    initializeOpenGLFunctions();

    QImage left;
    QImage right;
    QImage top;
    QImage bottom;
    QImage front;
    QImage back;

    left.load("../P1/resources/skybox/left.jpg");
    right.load("../P1/resources/skybox/right.jpg");
    top.load("../P1/resources/skybox/top.jpg");
    bottom.load("../P1/resources/skybox/bottom.jpg");
    front.load("../P1/resources/skybox/front.jpg");
    back.load("../P1/resources/skybox/back.jpg");

    glGenTextures(1, &m_cubeTex);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_cubeTex);

    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA8, left.width(), left.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(left.constBits()));
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA8, right.width(), right.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(right.constBits()));
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA8, top.width(), top.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(top.constBits()));
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA8, bottom.width(), bottom.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(bottom.constBits()));
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA8, front.width(), front.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(front.constBits()));
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA8, back.width(), back.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(back.constBits()));

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

    static const GLfloat vertexData[] = {
        -1, 1, -1,
        -1, -1, -1,
        1, -1, -1,
        1, 1, -1,
        -1, -1, 1,
        -1, 1, 1,
        1, -1, 1,
        1, 1, 1,
    };

    static const GLuint indicesData[] = {
            0, 1, 2, 2, 3, 0,
            4, 1, 0, 0, 5, 4,
            2, 6, 7, 7, 3, 2,
            4, 5, 7, 7, 6, 4,
            0, 3, 7, 7, 5, 0,
            1, 4, 2, 2, 4, 6,
    };

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);

    glGenBuffers(1, &m_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesData), indicesData, GL_STATIC_DRAW);

    m_prog = new QOpenGLShaderProgram();
    m_prog->addShaderFromSourceFile(QOpenGLShader::Vertex, "../P1/skybox.vert");
    m_prog->addShaderFromSourceFile(QOpenGLShader::Fragment, "../P1/skybox.frag");
    m_prog->link();
    Q_ASSERT(m_prog->isLinked());

    glBindVertexArray(0);
}

Skybox::~Skybox(){
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);

    glDeleteTextures(1, &m_cubeTex);

    glDeleteBuffers(1, &m_ibo);

    delete m_prog;
}

void Skybox::render(const QMatrix4x4 &projection, QMatrix4x4 view)
{
    glDepthMask(GL_FALSE);
    view.column(3) = QVector4D(0.0, 0, 0.0, 0.0);
    view.scale(10.0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_cubeTex);
    glBindVertexArray(m_vao);

    Q_ASSERT(m_prog->bind());
    m_prog->setUniformValue(0, projection);
    m_prog->setUniformValue(1, view);
    m_prog->setUniformValue(2, 0);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0);
    glDepthMask(GL_TRUE);
}
