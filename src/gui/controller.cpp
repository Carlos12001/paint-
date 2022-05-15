#include "controller.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
    delete paintPP;
}


void MainWindow::initGUIPaintPP(){
    Utilities::printMessageInfo("Init the GUIPaintPP");
    bool openImage =  true;
    if(openImage){
        string pathImage = "ai-hayasaka.bmp";
        paintPP = new PaintPP(pathImage);
    }
    else{
        int width = 1280;
        int height = 720;
        paintPP = new PaintPP(width, height);
    }

    return;
}