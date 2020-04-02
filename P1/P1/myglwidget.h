#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>

class MyGLWidget : public QOpenGLWidget
{
private:
    int m_FOV;
    int m_Angle;
    bool m_ProjectionMode;
    double m_Far;
    double m_Near;
    int m_RotationA;
    int m_RotationB;
    int m_RotationC;
public:
    MyGLWidget();
    MyGLWidget(QWidget *parent):QOpenGLWidget(parent){}

    void setFOV(int value);
    void setAngle(int value);
    void setProjectionMode();
    void setNear(double value);
    void setFar(double value);
    void setRotationA(int value);
    void setRotationB(int value);
    void setRotationC(int value);
};

#endif // MYGLWIDGET_H
