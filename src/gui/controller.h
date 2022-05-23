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
#include <QColorDialog>
#include <cmath>
#include "model/paintpp.h"
#include "model/point_image.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    /**
     * move minunmj y
     */
    static const int minimumMoveY = 100;

    /**
     * move miuunj x
     */
    static const int minimumMoveX = 10;

    /**
     * counstor
     * @param parent the parent
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * the destructor
     */
    ~MainWindow() override;

    /**
     * init the GUI paint pp
     */
    void initGUIPaintPP();

private:

    /**
     * the interface references
     */
    Ui::MainWindow *ui;

    /**
     * the paint pp
     */
    PaintPP* paintPP = nullptr;

    /**
     * the painter of the image
     */
    QPainter* mPainter;

    /**
     * the canvas to paint
     */
    QImage* canvasImage;

    /**
     * the move into image
     */
    vectorStructure<PointImage> vectorMove;

    /**
     * need information of position
     */
    bool getInformationMouseMove = false;

    /**
     * can draw
     */
    bool enableDraw = false;

    /**
     * can erase
     */
    bool enableErase = false;

    /**
     * can create line
     */
    bool enableLine = false;

    /**
     * can magic
     */
    bool enableMagicSelect = false;

    /**
     * can chop square
     */
    bool enableChopSquare = false;

    /**
     * can chop free
     */
    bool enableChopFree = false;

    /**
     * can crate square
     */
    bool enableFigureSquare = false;

    /**
     * can create recrtanagle
     */
    bool enableFigureRectangle = false;

    /**
     * can create traugnle
     */
    bool enableFigureTriangle = false;

    /**
     * can pin color
     */
    bool enableColorPicker = false;

    /**
     * can fiil color
     */
    bool enablePaintFill = false;

    /**
     * the counter od clicks
     */
    int counterClicks = 0;

    /**
     * the color select
     */
    Color colorSelect = Color(255,0,0,0);

    /**
     * the thickness
     */
    int thickness = 5;

    /**
     * event to set canvas
     * @param event event qt
     */
    void paintEvent(QPaintEvent* event) override;

    /**
     * event to mouse click mouse
     * @param event event qt
     */
    void mousePressEvent(QMouseEvent* event) override;

    /**
     * event to move mouse
     * @param event event qt
     */
    void mouseMoveEvent(QMouseEvent* event) override;

    /**
     * event relase mouse
     * @param event event qt
     */
    void mouseReleaseEvent(QMouseEvent* event) override;

    /**
     * print the current image
     */
    void printCurrentImage();

    /**
     * restart the vecot r move
     */
    void restartVectorMove();

    /**
     * add element to vector move
     * @param i postion x
     * @param j position y
     */
    void addElementVectorMove(int i, int j);

    /**
     * print the vector move
     */
    [[maybe_unused]] void printVectorMove();

    /**
     * select the width
     * @return the width selected
     */
    int selectWidth();

    /**
     * select the height
     * @return the height selected
     */
    int selectHeight();

    /**
     * chosee the option
     */
    void chooseOption();

    /**
     * open an image of paint pp
     */
    void openImage();

    /**
     * crate the empty canvas of paint pp
     */
    void createEmptyCanvas();

    /**
     * set false all enable or cans
     */
    void setEnableFalse();

private slots:

    /**
     * Set enable magic true
     */
    void magicSelectAction();

   /**
    *
    */
    void chopSquareAction();

    /**
     *
     */
    void chopFreeAction();

    /**
     *
     */
    void drawAction();

    /**
     *
     */
    void eraseAction();

    /**
     *
     */
    void lineAction();

    /**
     *
     */
    void figureSquareAction();

    /**
     *
     */
    void figureTriangleAction();

    /**
     *
     */
    void figureRectangleAction();

    /**
     *
     */
    void colorPickerAction();

    /**
     *
     */
    void paintFillAction();

    /**
     *
     */
    void undoAction();

    /**
     *
     */
    void redoAction();

    /**
     *
     */
    void saveAction();

    /**
     *
     */
    void openAction();

    /**
     *
     */
    void selectColorAction();

    /**
     *
     */
    void filterRAction();

    /**
     *
     */
    void filterGAction();

    /**
     *
     */
    void filterBAction();

    /**
     *
     */
    void rotateAction();

    /**
     *
     */
    void thicknessAction();

    /**
     *
     */
    void checkUndo();

    /**
     *
     */
    void checkRedo();
};
#endif // MAIN_WINDOW_H
