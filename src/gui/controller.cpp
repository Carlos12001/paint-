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
    mBegin = event->pos();
    Utilities::printMessageInfo("CLICK!");
    Utilities::printMessageInfo("Me muevo! En x: " + to_string(mBegin.rx()-minimumMoveX) + + " .En y: " + to_string(mBegin.ry()-minimumMoveY));
    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if(!enablePainter){
        event->accept();
        return;
    }else{
//        QPen pen(Qt::white);
//        pen.setCapStyle(Qt::RoundCap);
//        pen.setWidth(10);
//        mEnd = event->pos();
//        mPainter->setPen(pen);
//        mPainter->drawLine(mBegin, mEnd);
        update();
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    enablePainter = false;
    event->accept();
}

void MainWindow::printCurrentImage(){
    auto colors = paintPP->getColorOfCurrentImage();
    int width =  paintPP->getWidthCanvas();
    int height =  paintPP->getHeightCanvas();
    cout << "(" << width << "," << height << ")" << "\t";
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            Color tempColor = colors.getElement(j*width+i);
            auto r = (tempColor.r);
            auto g = (tempColor.g);
            auto b = (tempColor.b);
            auto a = (tempColor.a);
            QPen pen(QColor(r+0, g+0, b+0, a+0));
            mPainter->setPen(pen);
            mPainter->drawPoint(i, height-j);
        }
//        cout << endl;
    }

    update();
}
