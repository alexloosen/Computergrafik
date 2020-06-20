#include "QOpenGLFunctions_3_3_Core"
#include "QOpenGLShaderProgram"
#include "QImage"

class Skybox : QOpenGLFunctions_3_3_Core
{
public:
    Skybox();
    ~Skybox();
    void render(const QMatrix4x4 &projection, QMatrix4x4 view);

private:
    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ibo;
    GLuint m_cubeTex;
    QOpenGLShaderProgram* m_prog;
};
