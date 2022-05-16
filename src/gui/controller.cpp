#include "controller.h"
#include "./ui_mainwindow.h"
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
    delete paintPP;
    delete mPainter;
    delete canvasImage;
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

    canvasImage = new QImage(1280,720, QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(canvasImage);

    printCurrentImage();

    return;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(minimumMoveX, minimumMoveY, *canvasImage);
    event->accept();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    enablePainter = true;
    restartVectorMove();
    addElementVectorMove(event->pos().rx(), event->pos().ry());
    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if(enablePainter){
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        event->accept();
    }else{
        event->accept();
        return;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
//    if(enablePainter){
//        Color colorSelect = Color(0,0,0);
//        int brushSize = 5;
//        paintPP->draw(vectorMove, colorSelect,brushSize; );
//    }
//    else if (enableDelete){
//
//    }
    enablePainter = false;
    event->accept();
    update();
}

void MainWindow::printCurrentImage(){
    auto colors = paintPP->getColorOfCurrentImage();
    int width =  paintPP->getWidthCanvas();
    int height =  paintPP->getHeightCanvas();
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            Color tempColor = colors.getElement(j*width+i);
            auto r = (tempColor.r);
            auto g = (tempColor.g);
            auto b = (tempColor.b);
            auto a = (tempColor.a);
            QPen pen(QColor(r, g, b, a-a+255));
            mPainter->setPen(pen);
            mPainter->drawPoint(i, height-j);
        }
    }
    update();
}


void MainWindow::restartVectorMove(){
    while (vectorMove.size()!=0){
        vectorMove.pop();
    }
}

void MainWindow::addElementVectorMove(int i, int j){
    bool canAdded = true;
    canAdded = canAdded && i>= minimumMoveX;
    canAdded = canAdded && i<= minimumMoveX+paintPP->getWidthCanvas();
    canAdded = canAdded && j>= minimumMoveY;
    canAdded = canAdded && j<= minimumMoveY+paintPP->getHeightCanvas();

    if(canAdded){
        auto pos = PointImage(i - minimumMoveX, j - minimumMoveY);
        vectorMove.addElement(pos);
    }

}

void  MainWindow::printVectorMove(){
    for (int i = 0; i < vectorMove.size() ; ++i) {
        cout << "(";
        cout << vectorMove.getElement(i).x << ':';
        cout << vectorMove.getElement(i).y;
        cout << ")\t";
    }
    cout<<"\n--------------------------------\n";
}


