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

    delete skybox;

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
    m_RotationA = value;
}

void MyGLWidget::setRotationB(int value)
{
    this->m_RotationB = value;
}

void MyGLWidget::setRotationC(int value)
{
    this->m_RotationC = value;
}

void MyGLWidget::setIsAnimated()
{
    isAnimated = !isAnimated;
}

void MyGLWidget::setFixedCam()
{
    fixedCam = !fixedCam;
}

void MyGLWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {


    }
    else
    {
        QOpenGLWidget::keyPressEvent(event);
       // qDebug() << "Model" << mModel;

        if(event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
        {
            cameraPos.setX(cameraPos.x() + 0.2);
            mCamera.rotate(5, 1.0f, 0.0f, 0.0f);
        }
        else if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
        {
            cameraPos.setZ(cameraPos.z() - 0.2);
            mCamera.rotate(5, 0.0f, 1.0f, 0.0f);
        }
        else if(event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
        {
            cameraPos.setX(cameraPos.x() - 0.2);
            mCamera.rotate(5, -1.0f, 0.0f, 0.0f);
        }
        else if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
        {
            cameraPos.setZ(cameraPos.z() + 0.2);
            mCamera.rotate(5, 0.0f, -1.0f, 0.0f);
        }
        else if(event->key() == Qt::Key_Q || event->key() == Qt::Key_Right)
        {
            cameraPos.setZ(cameraPos.z() + 0.2);
            mCamera.translate(0.0f, 0.0f, 0.10f);
        }
        else if(event->key() == Qt::Key_E || event->key() == Qt::Key_Right)
        {
            cameraPos.setZ(cameraPos.z() + 0.2);
            mCamera.translate(0.0f, 0.0f, -0.10f);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mProjection.perspective(m_FOV, 1, m_Near, m_Far);
    qDebug() << "ProjectionMatrix: " << mProjection;

    mCamera.translate(0.0f, 0.0f, -2.0f);
    qDebug() << "CameraPosition:" << mCamera;

    mModel.translate(0.0f, 0.0f, 0.0f);
    qDebug() << "ModelMatrix:" << mModel;

    mModel.scale(0.9f, 0.9f, 0.9f);

    mCamera *= mModel;

    QImage texImg;
    texImg.load("../P1/Resources/gimbal_wood.jpg");
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
    //glEnable(GL_CULL_FACE);
    //glEnable(GL_BACK);

    glEnable(GL_DEPTH_TEST);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texImg.width(), texImg.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, texImg.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    m_prog = new QOpenGLShaderProgram();
    m_prog->addShaderFromSourceFile(QOpenGLShader::Vertex, "../P1/sample.vert");
    m_prog->addShaderFromSourceFile(QOpenGLShader::Fragment, "../P1/sample.frag");
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
        qDebug() << "Program 1 linked!";
    }

    m_prog2 = new QOpenGLShaderProgram();
    m_prog2->addShaderFromSourceFile(QOpenGLShader::Vertex, "../P1/sample.vert");
    m_prog2->addShaderFromSourceFile(QOpenGLShader::Fragment, "../P1/sample.frag");
    m_prog2->link();
    Q_ASSERT(m_prog2->isLinked());
    if (m_prog2->isLinked())
    {
        qDebug() << "Program 2 linked!";
    }

    m_prog3 = new QOpenGLShaderProgram();
    m_prog3->addShaderFromSourceFile(QOpenGLShader::Vertex, "../P1/light.vert");
    m_prog3->addShaderFromSourceFile(QOpenGLShader::Fragment, "../P1/light.frag");
    m_prog3->link();
    Q_ASSERT(m_prog3->isLinked());
    if (m_prog3->isLinked())
    {
        qDebug() << "Program 3 linked!";
    }

    m_gimbal1.initGL("../P1/Resources/gimbal.obj");
    m_gimbal2.initGL("../P1/Resources/gimbal.obj");
    m_gimbal3.initGL("../P1/Resources/gimbal.obj");
    m_sphere.initGL("../P1/Resources/sphere.obj");
    m_light.initGL("../P1/Resources/sphere.obj");

    skybox = new Skybox();

    Model4 = mModel;
    Model4.scale(0.05f, 0.05f, 0.05f);
    Model4.translate(-25.f, 8.0f, 0.0f);

    Model5 = mModel;
    Model5.scale(0.1f, 0.1f, 0.1f);
    Model5.translate(-10.f, 10.0f, 0.0f);
}

void MyGLWidget::paintGL()
{
    QVector3D lightPos;
    QMatrix4x4 Model1, Model2, Model3;
    QMatrix4x4 sphereModel, lightModel;
    QVector3D color;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    skybox->render(mProjection, mCamera);

    Model1 = mModel;
    Model2 = mModel;
    Model3 = mModel;

    float delta = (timer.elapsed() - m_time) / 1000;

    float rotSpeed1 = 20.0f;
    float rotSpeed2 = 40.0f;
    float rotSpeed3 = 60.0f;
    if (isAnimated){
        Model1.rotate(rotSpeed1*delta, 1.0f, 0.0f, 0.0f);
        Model2.rotate(rotSpeed2*delta, 0.0f, 1.0f, 0.0f);
        Model3.rotate(rotSpeed3*delta, 1.0f, 0.0f, 0.0f);
    }
    else{
        Model1.rotate(m_RotationA*delta, 1.0f, 0.0f, 0.0f);
        Model2.rotate(m_RotationB*delta, 0.0f, 1.0f, 0.0f);
        Model3.rotate(m_RotationC*delta, 1.0f, 0.0f, 0.0f);

    }
    mAnchor.rotate(delta * 0.1f, 0.0f, 0.0f, 1.0f);
    mLightAnchor.rotate(delta * 0.1f, 1.0f, 1.0f, 1.0f);

    Model2 *= Model1;
    Model3 *= Model2;

    Model2.scale(0.7f, 0.7f, 0.7f);
    Model3.scale(0.5f, 0.5f, 0.5f);
    sphereModel = Model2 * mAnchor * Model4;
    lightModel = mLightAnchor * Model5;
    float lightX, lightY, lightZ;
    lightX = lightModel.column(3).x();
    lightY = lightModel.column(3).y();
    lightZ = lightModel.column(3).z();

    lightPos = QVector3D(-lightX, -lightY, -lightZ);
    //lightPos = QMatrix4x4();
    //lightPos.translate(0.0f, 0.0f, -2.0f);

    if (fixedCam){
        mCamera = QMatrix4x4();
        mCamera = Model3 * mCamera;
    }
//    else{
//        mCamera = QMatrix4x4();
//        mCamera.translate(0.0f, 0.0f, -2.0f);
//    }
    QVector3D view = {0.0, 0.0, -2.0};
    color = {1.f, 0.1f, 0.1f};
    m_prog->bind();
    m_prog->setUniformValue(0, mCamera);
    m_prog->setUniformValue(1, mProjection);
    m_prog->setUniformValue(2, Model1);
    m_prog->setUniformValue(5, color);
    m_prog->setUniformValue(6, 0);
    m_prog->setUniformValue(8, view);
    m_prog->setUniformValue(9, lightPos);
    m_gimbal1.drawElements();

    color = {0.1f, 1.f, 0.1f};
    m_prog1->bind();
    m_prog1->setUniformValue(0, mCamera);
    m_prog1->setUniformValue(1, mProjection);
    m_prog1->setUniformValue(2, Model2);
    m_prog1->setUniformValue(5, color);
    m_prog1->setUniformValue(6, 0);
    m_prog1->setUniformValue(8, view);
    m_prog1->setUniformValue(9, lightPos);
    m_gimbal2.drawElements();

    color = {0.1f, 0.f, 1.1f};
    m_prog2->bind();
    m_prog2->setUniformValue(0, mCamera);
    m_prog2->setUniformValue(1, mProjection);
    m_prog2->setUniformValue(2, Model3);
    m_prog2->setUniformValue(5, color);
    m_prog2->setUniformValue(6, 0);
    m_prog2->setUniformValue(8, view);
    m_prog2->setUniformValue(9, lightPos);
    m_gimbal3.drawElements();

    color = {1.f, 1.f, 1.f};
    m_prog2->setUniformValue(0, mCamera);
    m_prog2->setUniformValue(1, mProjection);
    m_prog2->setUniformValue(2, sphereModel);
    m_prog2->setUniformValue(5, color);
    m_prog2->setUniformValue(6, 0);
    m_prog2->setUniformValue(8, view);
    m_prog2->setUniformValue(9, lightPos);
    m_sphere.drawElements();

    color = {1.f, 1.f, 1.f};
    m_prog3->setUniformValue(0, mCamera);
    m_prog3->setUniformValue(1, mProjection);
    m_prog3->setUniformValue(2, lightModel);
    m_prog3->setUniformValue(3, color);
    m_light.drawElements();

    update();
    m_time += 1.f;
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
