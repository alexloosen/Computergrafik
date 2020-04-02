#include "myglwidget.h"

MyGLWidget::MyGLWidget()
{

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
    this->m_Near = value;
}

void MyGLWidget::setFar(double value)
{
    this->m_Far = value;
}

void MyGLWidget::setRotationA(int value)
{
    this->m_RotationA = value;
}

void MyGLWidget::setRotationB(int value)
{
    this->m_RotationB = value;
}

void MyGLWidget::setRotationC(int value)
{
    this->m_RotationC = value;
}
