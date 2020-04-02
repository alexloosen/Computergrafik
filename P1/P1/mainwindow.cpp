#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect()
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
