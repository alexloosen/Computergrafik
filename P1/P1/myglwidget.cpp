#include "myglwidget.h"

MyGLWidget::MyGLWidget()
{
    initializeGL();
}

MyGLWidget::~MyGLWidget()
{
    makeCurrent();

    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);

    glDeleteTextures(1, &m_tex);

    glDeleteBuffers(1, &m_ibo);

    delete m_prog;
    delete m_prog1;

    doneCurrent();
}

void MyGLWidget::setFOV(int value)
{
    this->m_FOV = value;
}

void MyGLWidget::setAngle(int value)
{
    this->m_Angle = value;
}

void MyGLWidget::setProjectionMode()
{
    this->m_ProjectionMode = !this->m_ProjectionMode;
}

void MyGLWidget::setNear(double value)
{
    if (value != m_Near)
    {
        // wenn zu nah aufeinander gerückt -> signal aussenden und Lambda-Methode neue Value setzen lassen
        if ((m_Far - value) < 2)
        {
            emit incrementNear(value);
        }
        m_Near = value;
    }
}

void MyGLWidget::setFar(double value)
{
    if (value != m_Far)
    {
        // wenn zu nah aufeinander gerückt -> signal aussenden und Lambda-Methode neue Value setzen lassen
        if ((value - m_Near) < 2)
        {
            emit decrementFar(value);
        }
        m_Far = value;
    }
}

void MyGLWidget::setRotationA(int value)
{
    float conv = value;
    conv /= 100;
    m_Alpha = conv;
}

void MyGLWidget::setRotationB(int value)
{
    float conv = value;
    conv /= 100;
    this->m_RotationB = value;
}

void MyGLWidget::setRotationC(int value)
{
    this->m_RotationC = value;
}

void MyGLWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {


    }
    else
    {
        QOpenGLWidget::keyPressEvent(event);

        if(event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
        {
            cameraPos.setX(cameraPos.x() + 0.2);
        }
        else if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
        {
            cameraPos.setZ(cameraPos.z() - 0.2);
        }
        else if(event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
        {
            cameraPos.setX(cameraPos.x() - 0.2);
        }
        else if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
        {
            cameraPos.setZ(cameraPos.z() + 0.2);
        }
        qDebug() << "X: " + QString::number(cameraPos.x()) + " Z: " + QString::number(cameraPos.z());
    }
}

void MyGLWidget::initializeGL()
{
    bool success = initializeOpenGLFunctions();
    Q_ASSERT(success); Q_UNUSED(success);
    if (success)
    {
        qDebug() << "GL initialized!";
    }
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    struct Vertex
    {
        GLfloat position[2];
        GLfloat color[3];
        GLfloat tex_pos[2];
    };

    Vertex vert1, vert2, vert3, vert4;

    vert1.position[0] = -0.5f;
    vert1.position[1] = -0.5f;
    vert1.color[0] = 1.0f;
    vert1.color[1] = 0.0f;
    vert1.color[2] = 0.0f;
    vert1.tex_pos[0] = 0.0f;
    vert1.tex_pos[1] = 0.0f;

    vert2.position[0] = 0.5f;
    vert2.position[1] = -0.5f;
    vert2.color[0] = 0.0f;
    vert2.color[1] = 1.0f;
    vert2.color[2] = 0.0f;
    vert2.tex_pos[0] = 0.0f;
    vert2.tex_pos[1] = 1.0f;

    vert3.position[0] = 0.0f;
    vert3.position[1] = 0.5f;
    vert3.color[0] = 0.0f;
    vert3.color[1] = 0.0f;
    vert3.color[2] = 1.0f;
    vert3.tex_pos[0] = 1.0f;
    vert3.tex_pos[1] = 0.0f;

    vert4.position[0] = 1.0f;
    vert4.position[1] = 0.5f;
    vert4.color[0] = 0.0f;
    vert4.color[1] = 0.0f;
    vert4.color[2] = 1.0f;
    vert4.tex_pos[0] = 1.0f;
    vert4.tex_pos[1] = 1.0f;

    Vertex vert[] {vert1, vert2, vert3, vert4};

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    GLuint data[] = {0, 1, 2, 1, 2, 3};
    glGenBuffers(1, &m_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    #define OFS(s, a) reinterpret_cast<void* const>(offsetof(s, a))
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFS(Vertex, position));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFS(Vertex, color));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFS(Vertex, tex_pos));
    #undef OFS

    glBindVertexArray(0);

    QImage texImg;
    texImg.load("../P1/sample_texture.jpg");
    Q_ASSERT(!texImg.isNull());
    if (!texImg.isNull())
    {
        qDebug() << "Textur geladen!";
    }

    glEnable(GL_TEXTURE_2D);
    glTex = new QOpenGLTexture(texImg);
    glGenTextures(1, &m_tex);
    glBindTexture(GL_TEXTURE_2D, m_tex);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texImg.width(), texImg.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, texImg.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

    m_prog = new QOpenGLShaderProgram();
    m_prog->addShaderFromSourceFile(QOpenGLShader::Vertex, "../P1/sample.vert");
    m_prog->addShaderFromSourceFile(QOpenGLShader::Fragment, "../P1/sample_alpha.frag");
    m_prog->link();
    Q_ASSERT(m_prog->isLinked());
    if (m_prog->isLinked())
    {
        qDebug() << "Program linked!";
    }

    m_prog1 = new QOpenGLShaderProgram();
    m_prog1->addShaderFromSourceFile(QOpenGLShader::Vertex, "../P1/sample.vert");
    m_prog1->addShaderFromSourceFile(QOpenGLShader::Fragment, "../P1/sample.frag");
    m_prog1->link();
    Q_ASSERT(m_prog1->isLinked());
    if (m_prog1->isLinked())
    {
        qDebug() << "Program-1 linked!";
    }
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(m_vao);

    m_prog->bind();
    m_prog->setUniformValue(0, m_Alpha);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

    m_prog1->bind();
//    GLuint timeLocation = m_prog1->uniformLocation("time");
//   m_prog1->setUniformValue(timeLocation, m_time);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_tex);
    m_prog1->setUniformValue(6, 0);
    float posOffset = m_RotationB / 100.f;
    m_prog1->setUniformValue(7, posOffset);

    //glDrawArrays(GL_TRIANGLES, 0, 3);
    void* const offset = reinterpret_cast<void* const>(sizeof(GLuint)*3);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, offset);

    update();
    m_time += 0.01f;
}

void MyGLWidget::resizeGL(int w, int h)
{
}

QString MyGLWidget::toString()
{
    QString result = "";
    QString orth = (this->m_ProjectionMode) ? "true" : "false";
    result += "FOV: " + QString::number(this->m_FOV) +
            " | Angle: " + QString::number(this->m_Angle) +
            " | Near: " + QString::number(this->m_Near) +
            " | Far: " + QString::number(this->m_Far) +
            " | Rota A: " + QString::number(this->m_RotationA) +
            " | Rota B: " + QString::number(this->m_RotationB) +
            " | Rota C: " + QString::number(this->m_RotationC) +
            " | Orthogonal?  " + orth;
    return result;
}
