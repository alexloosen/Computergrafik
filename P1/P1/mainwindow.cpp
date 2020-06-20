#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Signale/Slots setzen (SignalSender, WidgetSignal, Empfängerklasse, Methode)
    QObject::connect(ui->rbOrthogonal, &QRadioButton::toggled, ui->openGLWidget, &MyGLWidget::setProjectionMode);
    QObject::connect(ui->hsRotationA, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationA);
    QObject::connect(ui->hsRotationB, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationB);
    QObject::connect(ui->hsRotationC, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setRotationC);
    QObject::connect(ui->cbIsAnimated, &QCheckBox::stateChanged , ui->openGLWidget, &MyGLWidget::setIsAnimated);
    QObject::connect(ui->cbFixedCam, &QCheckBox::stateChanged , ui->openGLWidget, &MyGLWidget::setFixedCam);
    QObject::connect(ui->dsbFar, QOverload<double>::of(&QDoubleSpinBox::valueChanged), ui->openGLWidget, &MyGLWidget::setFar);
    QObject::connect(ui->dsbNear, QOverload<double>::of(&QDoubleSpinBox::valueChanged), ui->openGLWidget, &MyGLWidget::setNear);
    QObject::connect(ui->vsFOV, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setFOV);
    QObject::connect(ui->vsAngle, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setAngle);

    //QObject::connect(ui->Slider1, &QSlider::valueChanged, ui->openGLWidget, &MyGLWidget::setAlpha);

    // Lambda Methode zur Ausgabe und Setzen von FOV
    QObject::connect(ui->vsFOV, &QSlider::valueChanged,
    [this]()
    {
        qDebug() << "FOV: " + QString::number(ui->vsFOV->value());
    });
    QObject::connect(ui->vsAngle, &QSlider::valueChanged,
    [this]()
    {
        qDebug() << "Angle: " + QString::number(ui->vsAngle->value());
    });

    // Near-Ebene darf sich nicht durch Far-Ebene hindurchschieben
    // stattdessen muss das erhöhen der Near-Ebene die Far-Ebene um +2 "vor sich her schieben"
    // andersrum muss das erniedrigen der Far-Ebene auch die Near-Ebene erniedrigen
    // (nur wenn beide um weniger als +-2 voneinander entfernt sind
    QObject::connect(ui->openGLWidget, &MyGLWidget::decrementFar,
    [this]()
    {
        //if(qFabs(ui->dsbNear->value() - ui->dsbFar->value()) < 2)
           ui->dsbNear->setValue(ui->dsbFar->value()-2);
    });
    QObject::connect(ui->openGLWidget, &MyGLWidget::incrementNear,
    [this]()
    {
        //if(qFabs(ui->dsbFar->value() - ui->dsbNear->value()) < 2)
           ui->dsbFar->setValue(ui->dsbNear->value()+2);
    });

    QObject::connect(ui->fbReset, &QPushButton::clicked, this, &MainWindow::reset);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openGLWidget_windowIconChanged(const QIcon &icon)
{

}

void MainWindow::on_openGLWidget_aboutToCompose()
{

}

void MainWindow::reset()
{
    //qDebug() << ui->openGLWidget->toString();
    ui->vsFOV->setValue(ui->vsFOV->minimum());
    ui->vsAngle->setValue(ui->vsAngle->minimum());
    ui->dsbNear->setValue(ui->dsbNear->minimum());
    ui->dsbFar->setValue(ui->dsbFar->minimum());
    ui->hsRotationA->setValue(ui->hsRotationA->minimum());
    ui->hsRotationB->setValue(ui->hsRotationB->minimum());
    ui->hsRotationC->setValue(ui->hsRotationC->minimum());
    //qDebug() << ui->openGLWidget->toString();
}

