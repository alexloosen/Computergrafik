#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QString>
#include <QVector3D>
#include <QDebug>
#include <QKeyEvent>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include "model.h"

class MyGLWidget : public QOpenGLWidget, private QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public slots:
    void setFOV(int value);
    void setAngle(int value);
    void setProjectionMode();
    void setNear(double value);
    void setFar(double value);
    void setRotationA(int value);
    void setRotationB(int value);
    void setRotationC(int value);

signals:
    void incrementNear(int value);
    void decrementFar(int value);

public:
    MyGLWidget();
    ~MyGLWidget();
    MyGLWidget(QWidget *parent):QOpenGLWidget(parent){
        setFocusPolicy(Qt::StrongFocus);
    }

    QString toString();

    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;

private:
    int m_FOV = 90;
    int m_Angle;
    bool m_ProjectionMode;
    double m_Far = 12;
    double m_Near = 1;
    int m_RotationA;
    int m_RotationB;
    int m_RotationC;

    float m_Alpha;

    float m_time;

    QVector3D cameraPos;

    GLuint m_vbo;
    GLuint m_vao;
    GLuint m_ibo;
    GLuint m_tex;
    GLuint m_tex1;
    GLuint m_tex2;

    Model m_gimbal1;
    Model m_gimbal2;
    Model m_gimbal3;

    QImage texImg;
    QOpenGLTexture *glTex;
    QOpenGLTexture *glTex1;
    QOpenGLTexture *glTex2;

    QOpenGLShaderProgram *m_prog;
    QOpenGLShaderProgram *m_prog1;
    QOpenGLShaderProgram *m_prog2;

    QMatrix4x4 mCamera;
    QMatrix4x4 mProjection;
    QMatrix4x4 mModel;

    void keyPressEvent(QKeyEvent *event);
};
#endif // MYGLWIDGET_H
