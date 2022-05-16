#include "controller.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect((ui->openButton), SIGNAL(clicked()), this,
            SLOT(openAction()));
    connect(ui->saveButton, SIGNAL(clicked()), this,
            SLOT(saveAction()));
    connect(ui->magicSelectButton, SIGNAL(clicked()), this,
            SLOT(magicSelectAction()));
    connect(ui->chopSquareButton, SIGNAL(clicked()), this,
            SLOT(chopSquareAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));
//    connect(ui->saveButton, SIGNAL(clicked()), this,
//            SLOT(saveAction()));



}

MainWindow::~MainWindow(){
    delete ui;
    delete paintPP;
    delete mPainter;
    delete canvasImage;
}


void MainWindow::initGUIPaintPP(){



    Utilities::printMessageInfo("Init the GUIPaintPP");
    chooseOption();
    canvasImage = new QImage(1280,720, QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(canvasImage);

    printCurrentImage();

//    // Create pen width action and tie to MainWindow::penWidth()
//    penWidthAct = new QAction(tr("Pen &Width..."), this);
//    connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));


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

[[maybe_unused]] void  MainWindow::printVectorMove(){
    for (int i = 0; i < vectorMove.size() ; ++i) {
        cout << "(";
        cout << vectorMove.getElement(i).x << ':';
        cout << vectorMove.getElement(i).y;
        cout << ")\t";
    }
    cout<<"\n--------------------------------\n";
}


int MainWindow::selectWidth(){
    // Stores button value
    bool ok = false;
    int width = QInputDialog::getInt(this, tr("Select width"),
                                     tr("Select width:"),
                                     1280, 1, 1280, 1, &ok);
    // Change the pen width
    if (ok){
        return width;
    }
    else{
        return 1280;
    }
}

int MainWindow::selectHeight(){
    // Stores button value
    bool ok = false;
    int height = QInputDialog::getInt(this, tr("Select height"),
                                      tr("Select pen height:"),
                                      720, 1, 720, 1, &ok);
    // Change the pen width
    if (ok) {
        return height;
    }
    else{
        return 720;
    }
}

void MainWindow::chooseOption(){
    QMessageBox msgBox;
    msgBox.setText("You want to open an image o create an empty canvas.");
    msgBox.setInformativeText("Choose");
    msgBox.setStandardButtons(QMessageBox::Open | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    switch (ret) {
        case QMessageBox::Open:
            openImage();
            break;
        case QMessageBox::No:
            createEmptyCanvas();
            break;
        default:
            break;
    }
}

void MainWindow::openImage(){
    QString pathInput = QInputDialog::getText(this,
                                              "Ingrese el nombre del imagen",
                                              "Recuerde que la iamgen tiene que encontrar a la par del ejecutable.");
    string pathImage;
//    pathImage = "ai-hayasaka.bmp";
    pathImage = pathInput.toStdString();
    if(paintPP == nullptr)
        paintPP = new PaintPP(pathImage);
}

void MainWindow::createEmptyCanvas(){
    int width = selectWidth();
    int height = selectHeight();
    paintPP = new PaintPP(width, height);
}

void MainWindow::magicSelectAction() {

}

void MainWindow::chopSquareAction() {

}

void MainWindow::chopFreeAction() {

}

void MainWindow::filterBAction() {

}

void MainWindow::eraseAction() {

}

void MainWindow::rectLineAction() {

}

void MainWindow::figureSquareAction() {

}

void MainWindow::figureTriangleAction() {

}

void MainWindow::figureRectangleAction() {

}

void MainWindow::colorPickerAction() {

}

void MainWindow::paintFillAction() {

}

void MainWindow::undoAction() {

}

void MainWindow::redoAction() {

}

void MainWindow::saveAction() {

}

void MainWindow::openAction() {

}

void MainWindow::selectColor() {

}

void MainWindow::filterRAction() {

}

void MainWindow::filterGAction() {

}

void MainWindow::drawAction() {

}
