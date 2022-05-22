#include "controller.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect((ui->openButton), SIGNAL(clicked()), this,
            SLOT(openAction()));
    connect(ui->undoButton, SIGNAL(clicked()), this,
            SLOT(undoAction()));
    connect(ui->redoButton, SIGNAL(clicked()), this,
            SLOT(redoAction()));
    connect(ui->saveButton, SIGNAL(clicked()), this,
            SLOT(saveAction()));
    connect(ui->magicSelectButton, SIGNAL(clicked()), this,
            SLOT(magicSelectAction()));
    connect(ui->chopSquareButton, SIGNAL(clicked()), this,
            SLOT(chopSquareAction()));
    connect(ui->chopFreeButton, SIGNAL(clicked()), this,
            SLOT(chopFreeAction()));
    connect(ui->drawButton, SIGNAL(clicked()), this,
            SLOT(drawAction()));
    connect(ui->eraseButton, SIGNAL(clicked()), this,
            SLOT(eraseAction()));
    connect(ui->lineButton, SIGNAL(clicked()), this,
            SLOT(lineAction()));
    connect(ui->squareButton, SIGNAL(clicked()), this,
            SLOT(figureSquareAction()));
    connect(ui->triangleButton, SIGNAL(clicked()), this,
            SLOT(figureTriangleAction()));
    connect(ui->rectangleButton, SIGNAL(clicked()), this,
            SLOT(figureRectangleAction()));
    connect(ui->paintfillButton, SIGNAL(clicked()), this,
            SLOT(paintFillAction()));
    connect(ui->pickColorButton, SIGNAL(clicked()), this,
            SLOT(colorPickerAction()));
    connect(ui->filterRButton, SIGNAL(clicked()), this,
            SLOT(filterRAction()));
    connect(ui->filterGButton, SIGNAL(clicked()), this,
            SLOT(filterGAction()));
    connect(ui->filterBButton, SIGNAL(clicked()), this,
            SLOT(filterBAction()));
    connect(ui->colorSelectButton, SIGNAL(clicked()), this,
            SLOT(selectColorAction()));
    connect(ui->rotateButton, SIGNAL(clicked()), this,
            SLOT(rotateAction()));
    connect(ui->tickness1RadioButton, SIGNAL(clicked()), this,
            SLOT(thicknessAction()));
    connect(ui->tickness2RadioButton, SIGNAL(clicked()), this,
            SLOT(thicknessAction()));
    connect(ui->tickness3RadioButton, SIGNAL(clicked()), this,
            SLOT(thicknessAction()));
}

MainWindow::~MainWindow(){
    delete ui;
    delete paintPP;
    delete mPainter;
    delete canvasImage;
}

void MainWindow::initGUIPaintPP(){
    chooseOption();
    canvasImage = new QImage(1280,720, QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(canvasImage);
    printCurrentImage();
    checkUndo();
    checkRedo();
    update();
    return;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(minimumMoveX, minimumMoveY, *canvasImage);
    event->accept();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    checkUndo();
    checkRedo();

    if(enableDraw){
        restartVectorMove();
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        getInformationMouseMove = true;
    }
    else if(enableErase){
        restartVectorMove();
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        getInformationMouseMove = true;
    }
    else if(enableLine){
        counterClicks++;
        if(counterClicks==2){
            counterClicks = 0;
            addElementVectorMove(event->pos().rx(), event->pos().ry());
            paintPP->createLineImage(vectorMove, thickness, colorSelect);
            restartVectorMove();
            printCurrentImage();
        }
        else if(1 == counterClicks) {
            addElementVectorMove(event->pos().rx(), event->pos().ry());
        }
        else{
            restartVectorMove();
        }
    }
    else if(enableMagicSelect){

    }
    else if(enableChopSquare){

    }
    else if(enableChopFree){
        restartVectorMove();
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        getInformationMouseMove = true;
    }
    else if(enableFigureSquare){
        restartVectorMove();
        int size = 100;
        size = QInputDialog::getInt(this, tr("Select size"),
                                         tr("Select size:"),
                                         100, 100, 400, 1);
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        paintPP->createSquareImage(vectorMove.getElement(0), thickness, colorSelect, size);
        printCurrentImage();
        restartVectorMove();
        update();
    }
    else if(enableFigureRectangle){
        restartVectorMove();
        int size = 100;
        size = QInputDialog::getInt(this, tr("Select size"),
                                    tr("Select size:"),
                                    100, 100, 400, 1);
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        paintPP->createTriangleImage(vectorMove.getElement(0), thickness, colorSelect, size);
        printCurrentImage();
        restartVectorMove();
        update();

    }
    else if(enableFigureTriangle){
        restartVectorMove();
        int width = 100;
        width = QInputDialog::getInt(this, tr("Select width"),
                                     tr("Select width:"),
                                     100, 100, 400, 1);
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        paintPP->createSquareImage(vectorMove.getElement(0), thickness, colorSelect, width);
        int height = 100;
        height = QInputDialog::getInt(this, tr("Select height"),
                                     tr("Select height:"),
                                     100, 100, 400, 1);
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        paintPP->createRectangleImage(vectorMove.getElement(0), thickness, colorSelect, width, height);
        printCurrentImage();
        restartVectorMove();
        update();

    }
    else if(enableColorPicker){
        restartVectorMove();
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        colorSelect = paintPP->getPicker(vectorMove.getElement(0));
        colorSelect = Color(colorSelect.r, colorSelect.g, colorSelect.b, colorSelect.a);
    }
    else if(enablePaintFill){

    }

    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    checkUndo();
    checkRedo();
    if(getInformationMouseMove){
        addElementVectorMove(event->pos().rx(), event->pos().ry());
        event->accept();
    }else{
        event->accept();
        return;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if(enableDraw){
        getInformationMouseMove = false;
        paintPP->drawImage(vectorMove, thickness, colorSelect);
        printCurrentImage();
        restartVectorMove();
    }
    else if (enableErase){
        getInformationMouseMove = false;
        paintPP->eraseImage(vectorMove, thickness);
        printCurrentImage();
        restartVectorMove();
    }
    else if (enableChopFree){
        getInformationMouseMove = false;
//        paintPP->chopFree(vectorMove);
//        printCurrentImage();
        restartVectorMove();
    }
    checkUndo();
    checkRedo();
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
            QPen pen(QColor(g, b, a, r));
            mPainter->setPen(pen);
            mPainter->drawPoint(i, height-j);
        }
    }
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
        auto pos = PointImage(i - minimumMoveX, abs(paintPP->getHeightCanvas()-j + minimumMoveY));
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
    bool ok = false;
    int width = QInputDialog::getInt(this, tr("Select width"),
                                     tr("Select width:"),
                                     1280, 1, 1280, 1, &ok);
    if (ok){
        return width;
    }
    else{
        return 1280;
    }
}

int MainWindow::selectHeight(){
    bool ok = false;
    int height = QInputDialog::getInt(this, tr("Select height"),
                                      tr("Select pen height:"),
                                      720, 1, 720, 1, &ok);
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
                                              "Ingresa el nombre del imagen",
                                              "Recuerde que la iamgen tiene que encontrar a la par del ejecutable.");
    string pathImage;
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
    setEnableFalse();

    enableMagicSelect = true;
}

void MainWindow::chopSquareAction() {
    setEnableFalse();

    enableChopSquare = true;
}

void MainWindow::chopFreeAction() {
    setEnableFalse();

    enableChopFree = true;
}

void MainWindow::eraseAction() {
    setEnableFalse();

    enableErase = true;
}

void MainWindow::lineAction() {
    setEnableFalse();

    enableLine = true;
}

void MainWindow::figureSquareAction() {
    setEnableFalse();

    enableFigureSquare = true;
}

void MainWindow::figureTriangleAction() {
    setEnableFalse();

    enableFigureTriangle = true;
}

void MainWindow::figureRectangleAction() {
    setEnableFalse();

    enableFigureRectangle = true;
}

void MainWindow::colorPickerAction() {
    setEnableFalse();

    enableColorPicker = true;
}

void MainWindow::paintFillAction() {
    setEnableFalse();

    enablePaintFill = true;
}

void MainWindow::undoAction() {
    setEnableFalse();
    paintPP->undoImage();
    checkUndo();
    checkRedo();
    restartVectorMove();
    printCurrentImage();
    update();
}

void MainWindow::redoAction() {
    setEnableFalse();
    paintPP->redoImage();
    checkUndo();
    checkRedo();
    restartVectorMove();
    printCurrentImage();
    update();
}

void MainWindow::saveAction() {
    setEnableFalse();
    QString pathInput = QInputDialog::getText(this,
                                              "Ingrese el nombre del imagen",
                                              "El nombre no puede empezar canvas_ ");
    string pathImage;
    pathImage = pathInput.toStdString();
    pathImage = paintPP->stringCheckCanvas(pathImage);
    paintPP->saveImage(pathImage);
}

void MainWindow::openAction() {
    setEnableFalse();
}

void MainWindow::filterBAction() {
    setEnableFalse();

    paintPP->doFilterBImage();
    printCurrentImage();
    restartVectorMove();
    checkUndo();
    checkRedo();
    update();
}

void MainWindow::filterRAction() {
    setEnableFalse();

    paintPP->doFilterRImage();
    printCurrentImage();
    restartVectorMove();
    checkUndo();
    checkRedo();
    update();
}

void MainWindow::filterGAction() {
    setEnableFalse();

    paintPP->doFilterGImage();
    printCurrentImage();
    restartVectorMove();
    checkUndo();
    checkRedo();
    update();
}

void MainWindow::drawAction() {
    setEnableFalse();

    enableDraw = true;
}

void MainWindow::rotateAction() {
    setEnableFalse();
    paintPP->rotateImage();
    checkUndo();
    checkRedo();
    restartVectorMove();
    printCurrentImage();
    update();
}

void MainWindow::setEnableFalse(){

    enableDraw = false;

    enableErase = false;

    enableLine = false;

    enableMagicSelect = false;

    enableChopSquare = false;

    enableChopFree = false;

    enableFigureSquare = false;

    enableFigureRectangle = false;

    enableFigureTriangle = false;

    enableColorPicker = false;

    enablePaintFill = false;
}

void MainWindow::selectColorAction() {
    QColor defaultColor = QColor(colorSelect.g, colorSelect.b, colorSelect.a, colorSelect.r);
    QColor qColor = QColorDialog::getColor(defaultColor, this, "Chose color");
    colorSelect = qColor.isValid() ?
            Color(qColor.alpha(), qColor.red(), qColor.green(), qColor.blue())
            :
            Color(255, 0, 0, 0);
}

void MainWindow::thicknessAction() {
    if(ui->tickness1RadioButton->isChecked())
        thickness = 5;
    else if(ui->tickness2RadioButton->isChecked())
        thickness = 10;
    else if(ui->tickness3RadioButton->isChecked())
        thickness = 15;
    else
        thickness = 5;
}

void MainWindow::checkUndo(){
    if(paintPP->getReadyUndo()){
        ui->undoButton->setEnabled(true);
        ui->undoButton->setStyleSheet("background-color: rgb(0,255,0);");
    }
    else{
        ui->undoButton->setEnabled(false);
        ui->undoButton->setStyleSheet("background-color: rgb(255,0,0);");
    }
}

void MainWindow::checkRedo() {
    if(paintPP->getReadyRedo()){
        ui->redoButton->setEnabled(true);
        ui->redoButton->setStyleSheet("background-color: rgb(0,255,0);");
    }
    else{
        ui->redoButton->setEnabled(false);
        ui->redoButton->setStyleSheet("background-color: rgb(255,0,0);");
    }
}