#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <iostream>
using namespace std;
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QImage>
#include <QDesktopWidget>
#include <QInputDialog>
#include <QMainWindow>
#include <QMessageBox>
#include "model/paintpp.h"
#include "model/point_image.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:

    static const int minimumMoveY = 100;

    static const int minimumMoveX = 10;

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void initGUIPaintPP();

private:

    Ui::MainWindow *ui;

    PaintPP* paintPP = nullptr;

    QPainter* mPainter;

    QImage* canvasImage;

    vectorStructure<PointImage> vectorMove;

    bool enablePainter = false;


protected:

    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void printCurrentImage();

    void restartVectorMove();

    void addElementVectorMove(int i, int j);

    [[maybe_unused]] void printVectorMove();

    int selectWidth();

    int selectHeight();

    void chooseOption();

    void openImage();

    void createEmptyCanvas();

private slots:

    void magicSelectAction();

    void chopSquareAction();

    void chopFreeAction();

    void drawAction();

    void eraseAction();

    void lineAction();

    void figureSquareAction();

    void figureTriangleAction();

    void figureRectangleAction();

    void colorPickerAction();

    void paintFillAction();

    void undoAction();

    void redoAction();

    void saveAction();

    void openAction();

    void selectColorAction();

    void filterRAction();

    void filterGAction();

    void filterBAction();

    void rotateAction();

};
#endif // MAIN_WINDOW_H
