/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hlMain;
    QGroupBox *vbControls_2;
    QVBoxLayout *vbControls;
    QGroupBox *gbRotation;
    QVBoxLayout *gbRoation;
    QFormLayout *Rotations;
    QLabel *labelA;
    QLabel *labelB;
    QLabel *labelC;
    QSlider *hsRotationA;
    QSlider *hsRotationB;
    QSlider *hsRotationC;
    QGroupBox *gbProjection_2;
    QVBoxLayout *gbProjection;
    QRadioButton *rbPerspective;
    QRadioButton *rbOrthogonal;
    QGroupBox *gbClipping_2;
    QVBoxLayout *gbClipping;
    QFormLayout *Clipping;
    QLabel *labelFar;
    QLabel *labelNear;
    QDoubleSpinBox *dsbNear;
    QDoubleSpinBox *dsbFar;
    QHBoxLayout *Sliders;
    QVBoxLayout *Slider2;
    QSlider *vsFOV;
    QLabel *LabelFOV;
    QSpinBox *spFOV;
    QVBoxLayout *Slider1;
    QSlider *vsAngle;
    QLabel *LabelAngle;
    QSpinBox *spAngle;
    QFormLayout *flControlButtons;
    QPushButton *fbReset;
    QPushButton *fbInitializeTest;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *Window;
    MyGLWidget *openGLWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(788, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 171, 581));
        hlMain = new QHBoxLayout(horizontalLayoutWidget);
        hlMain->setObjectName(QString::fromUtf8("hlMain"));
        hlMain->setContentsMargins(0, 0, 0, 0);
        vbControls_2 = new QGroupBox(horizontalLayoutWidget);
        vbControls_2->setObjectName(QString::fromUtf8("vbControls_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(vbControls_2->sizePolicy().hasHeightForWidth());
        vbControls_2->setSizePolicy(sizePolicy1);
        vbControls = new QVBoxLayout(vbControls_2);
        vbControls->setObjectName(QString::fromUtf8("vbControls"));
        vbControls->setSizeConstraint(QLayout::SetDefaultConstraint);
        gbRotation = new QGroupBox(vbControls_2);
        gbRotation->setObjectName(QString::fromUtf8("gbRotation"));
        gbRotation->setLayoutDirection(Qt::LeftToRight);
        gbRoation = new QVBoxLayout(gbRotation);
        gbRoation->setObjectName(QString::fromUtf8("gbRoation"));
        Rotations = new QFormLayout();
        Rotations->setObjectName(QString::fromUtf8("Rotations"));
        Rotations->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        Rotations->setRowWrapPolicy(QFormLayout::DontWrapRows);
        Rotations->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelA = new QLabel(gbRotation);
        labelA->setObjectName(QString::fromUtf8("labelA"));
        labelA->setEnabled(true);
        sizePolicy.setHeightForWidth(labelA->sizePolicy().hasHeightForWidth());
        labelA->setSizePolicy(sizePolicy);
        labelA->setLayoutDirection(Qt::LeftToRight);
        labelA->setAutoFillBackground(false);
        labelA->setLineWidth(1);
        labelA->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Rotations->setWidget(4, QFormLayout::LabelRole, labelA);

        labelB = new QLabel(gbRotation);
        labelB->setObjectName(QString::fromUtf8("labelB"));

        Rotations->setWidget(7, QFormLayout::LabelRole, labelB);

        labelC = new QLabel(gbRotation);
        labelC->setObjectName(QString::fromUtf8("labelC"));

        Rotations->setWidget(10, QFormLayout::LabelRole, labelC);

        hsRotationA = new QSlider(gbRotation);
        hsRotationA->setObjectName(QString::fromUtf8("hsRotationA"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(hsRotationA->sizePolicy().hasHeightForWidth());
        hsRotationA->setSizePolicy(sizePolicy2);
        hsRotationA->setMinimumSize(QSize(0, 0));
        hsRotationA->setMaximum(100);
        hsRotationA->setOrientation(Qt::Horizontal);

        Rotations->setWidget(4, QFormLayout::FieldRole, hsRotationA);

        hsRotationB = new QSlider(gbRotation);
        hsRotationB->setObjectName(QString::fromUtf8("hsRotationB"));
        hsRotationB->setOrientation(Qt::Horizontal);

        Rotations->setWidget(7, QFormLayout::FieldRole, hsRotationB);

        hsRotationC = new QSlider(gbRotation);
        hsRotationC->setObjectName(QString::fromUtf8("hsRotationC"));
        hsRotationC->setOrientation(Qt::Horizontal);

        Rotations->setWidget(10, QFormLayout::FieldRole, hsRotationC);


        gbRoation->addLayout(Rotations);


        vbControls->addWidget(gbRotation);

        gbProjection_2 = new QGroupBox(vbControls_2);
        gbProjection_2->setObjectName(QString::fromUtf8("gbProjection_2"));
        gbProjection = new QVBoxLayout(gbProjection_2);
        gbProjection->setObjectName(QString::fromUtf8("gbProjection"));
        rbPerspective = new QRadioButton(gbProjection_2);
        rbPerspective->setObjectName(QString::fromUtf8("rbPerspective"));

        gbProjection->addWidget(rbPerspective);

        rbOrthogonal = new QRadioButton(gbProjection_2);
        rbOrthogonal->setObjectName(QString::fromUtf8("rbOrthogonal"));

        gbProjection->addWidget(rbOrthogonal);


        vbControls->addWidget(gbProjection_2);

        gbClipping_2 = new QGroupBox(vbControls_2);
        gbClipping_2->setObjectName(QString::fromUtf8("gbClipping_2"));
        gbClipping = new QVBoxLayout(gbClipping_2);
        gbClipping->setObjectName(QString::fromUtf8("gbClipping"));
        Clipping = new QFormLayout();
        Clipping->setObjectName(QString::fromUtf8("Clipping"));
        labelFar = new QLabel(gbClipping_2);
        labelFar->setObjectName(QString::fromUtf8("labelFar"));

        Clipping->setWidget(1, QFormLayout::LabelRole, labelFar);

        labelNear = new QLabel(gbClipping_2);
        labelNear->setObjectName(QString::fromUtf8("labelNear"));

        Clipping->setWidget(0, QFormLayout::LabelRole, labelNear);

        dsbNear = new QDoubleSpinBox(gbClipping_2);
        dsbNear->setObjectName(QString::fromUtf8("dsbNear"));
        dsbNear->setDecimals(2);
        dsbNear->setMaximum(100.000000000000000);
        dsbNear->setStepType(QAbstractSpinBox::DefaultStepType);
        dsbNear->setValue(1.000000000000000);

        Clipping->setWidget(0, QFormLayout::FieldRole, dsbNear);

        dsbFar = new QDoubleSpinBox(gbClipping_2);
        dsbFar->setObjectName(QString::fromUtf8("dsbFar"));
        dsbFar->setMaximum(100.000000000000000);
        dsbFar->setValue(90.000000000000000);

        Clipping->setWidget(1, QFormLayout::FieldRole, dsbFar);


        gbClipping->addLayout(Clipping);


        vbControls->addWidget(gbClipping_2);

        Sliders = new QHBoxLayout();
        Sliders->setObjectName(QString::fromUtf8("Sliders"));
        Slider2 = new QVBoxLayout();
        Slider2->setObjectName(QString::fromUtf8("Slider2"));
        vsFOV = new QSlider(vbControls_2);
        vsFOV->setObjectName(QString::fromUtf8("vsFOV"));
        vsFOV->setLayoutDirection(Qt::LeftToRight);
        vsFOV->setMinimum(45);
        vsFOV->setMaximum(180);
        vsFOV->setPageStep(10);
        vsFOV->setValue(90);
        vsFOV->setSliderPosition(90);
        vsFOV->setOrientation(Qt::Vertical);
        vsFOV->setInvertedAppearance(false);
        vsFOV->setInvertedControls(false);

        Slider2->addWidget(vsFOV);

        LabelFOV = new QLabel(vbControls_2);
        LabelFOV->setObjectName(QString::fromUtf8("LabelFOV"));

        Slider2->addWidget(LabelFOV);

        spFOV = new QSpinBox(vbControls_2);
        spFOV->setObjectName(QString::fromUtf8("spFOV"));
        spFOV->setMinimum(45);
        spFOV->setMaximum(180);
        spFOV->setValue(90);

        Slider2->addWidget(spFOV);


        Sliders->addLayout(Slider2);

        Slider1 = new QVBoxLayout();
        Slider1->setObjectName(QString::fromUtf8("Slider1"));
        vsAngle = new QSlider(vbControls_2);
        vsAngle->setObjectName(QString::fromUtf8("vsAngle"));
        vsAngle->setMaximum(360);
        vsAngle->setOrientation(Qt::Vertical);

        Slider1->addWidget(vsAngle);

        LabelAngle = new QLabel(vbControls_2);
        LabelAngle->setObjectName(QString::fromUtf8("LabelAngle"));

        Slider1->addWidget(LabelAngle);

        spAngle = new QSpinBox(vbControls_2);
        spAngle->setObjectName(QString::fromUtf8("spAngle"));
        spAngle->setMaximum(360);

        Slider1->addWidget(spAngle);


        Sliders->addLayout(Slider1);


        vbControls->addLayout(Sliders);

        flControlButtons = new QFormLayout();
        flControlButtons->setObjectName(QString::fromUtf8("flControlButtons"));
        fbReset = new QPushButton(vbControls_2);
        fbReset->setObjectName(QString::fromUtf8("fbReset"));

        flControlButtons->setWidget(0, QFormLayout::LabelRole, fbReset);

        fbInitializeTest = new QPushButton(vbControls_2);
        fbInitializeTest->setObjectName(QString::fromUtf8("fbInitializeTest"));

        flControlButtons->setWidget(1, QFormLayout::LabelRole, fbInitializeTest);


        vbControls->addLayout(flControlButtons);


        hlMain->addWidget(vbControls_2);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(190, 10, 591, 581));
        Window = new QHBoxLayout(horizontalLayoutWidget_3);
        Window->setSpacing(0);
        Window->setObjectName(QString::fromUtf8("Window"));
        Window->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new MyGLWidget(horizontalLayoutWidget_3);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy3);
        openGLWidget->setMinimumSize(QSize(560, 480));
        openGLWidget->setMaximumSize(QSize(560, 16777215));

        Window->addWidget(openGLWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(vsFOV, SIGNAL(valueChanged(int)), spFOV, SLOT(setValue(int)));
        QObject::connect(vsAngle, SIGNAL(valueChanged(int)), spAngle, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelA->setText(QCoreApplication::translate("MainWindow", "Ring A", nullptr));
        labelB->setText(QCoreApplication::translate("MainWindow", "Ring B", nullptr));
        labelC->setText(QCoreApplication::translate("MainWindow", "Ring C", nullptr));
        rbPerspective->setText(QCoreApplication::translate("MainWindow", "Perspective", nullptr));
        rbOrthogonal->setText(QCoreApplication::translate("MainWindow", "Orthogonal", nullptr));
        labelFar->setText(QCoreApplication::translate("MainWindow", "Far", nullptr));
        labelNear->setText(QCoreApplication::translate("MainWindow", "Near", nullptr));
        LabelFOV->setText(QCoreApplication::translate("MainWindow", "Field of View", nullptr));
        LabelAngle->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        fbReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        fbInitializeTest->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
