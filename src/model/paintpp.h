//
// Created by carlo on 5/3/22.
//

#ifndef PAINT_PAINT_PP_H
#define PAINT_PAINT_PP_H
#include <iostream>
using namespace std;
#include "utils/doublyLinkedList.h"
#include "utils/vectorStructure.h"
#include "utils/utilities.h"
#include "image.h"
#include <fstream>
#include <math.h>
#include <cstdlib>
#include "point_image.h"

/**
 * THe real paint pp aplication
 */
class PaintPP {
    private:

    /**
     * Use to select filter
     */
    enum FiltersImage{
        White,
        Blue,
        Green,
        Red
    };

    /**
     * DO the paint in the image
     * @param vectorMove the move
     * @param imageCanvas imagen to draw
     * @param grossorE the thickness
     * @param colorPaint the color
     * @return image changed
     */
    static auto paintCoordinates(vectorStructure<PointImage> vectorMove, Image* imageCanvas, int grossorE, Color colorPaint)->Image*; //paint-funcion-auxiliar-erase-line-draw-figure

    /**
     * do the rect line
     * @param coordinates the 2 coordnates
     * @param distance the distances
     * @param lineDireccion the direction of line
     * @return image chanfged
     */
    static vectorStructure<PointImage> rectLine(vectorStructure<PointImage> coordinates,int distance,vectorDireccion lineDireccion);

    /**
     * chenck the four line for square and rectangle
     * @param coord the coordinate center
     * @param imageCanvas the image to draw
     * @param grossorE the thickness
     * @param colorSelect the color to paint
     * @param Side the num of side
     * @param Bottom the num of bottom
     * @return  image to  draw
     */
    static auto figureFourLines(PointImage coord, Image* imageCanvas, int grossorE,Color colorSelect,int Side, int Bottom)->Image*;

    /**
    * chenck the four line for square and rectangle
     * @param coord the coordinate center
     * @param imageCanvas the image to draw
     * @param grossorE the thickness
     * @param colorSelect the color to paint
     * @param Side the num of side
     * @param Bottom the num of bottom
     * @return  image to  draw
     */
    static auto figureThreeLines(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect,
                                 int base) -> Image *;
    /**
     * simulatoin of vector move
     * @param positionX num x
     * @param positionY num y
     * @return the vector
     */
    static vectorStructure<PointImage> mouseMovement(int positionX, int positionY);

    /**
     * erase in image
     * @param vectorMove the vector
     * @param imageCanvas the image to erease
     * @param grossorE the thickness
     * @return the image changed
     */
    static auto erase(vectorStructure<PointImage> vectorMove, Image* imageCanvas,int grossorE)->Image*; //erease


    /**
    * draw  in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
    static auto pencil(vectorStructure<PointImage> vectorMove, Image* imageCanvas,int grossorE, Color colorSelect)->Image*; //draw


    /**
    * draw line in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
    static auto pen(vectorStructure<PointImage> vectorTwoCordinates, Image* imageCanvas, int grossorE, Color colorSelect)->Image*; //line


    /**
    * draw figure square in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
    static auto figureSquare(PointImage coord, Image* imageCanvas, int grossorE,Color colorSelect,int Size)->Image*;


    /**
    * draw figure rectangle in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
    static auto figureRectangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side, int bottom)-> Image*;

    /**
    * draw figure triangle in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
    static auto figureTriangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side)-> Image*;

    /**
     * POsitioni of history
     */
    int positionInHistory = -1;

    /**
     * Can do undo
     */
    bool readyUndo = false;

    /**
     * Can do redo
     */
    bool readyRedo = false;

    /**
     * The hsitory of image
     */
    vectorStructure<string> historyImage;

    /**
     * THe image in the canvas
     */
    Image* currentImage = nullptr;

    /**
     * Create image white
     * @param width width
     * @param height height
     */
    void createEmptyCanvas(int width, int height);

    /**
     * GEt the next history name
     */
    string getNextHistoryName();

    /**
    * Create image to read
    * @param path the path
    */
    void createImageCanvas(string path);

    /**
     * cHANGE THE CURRENT IMAGE
     */
    void changeCurrentImage();

    /**
     * delete next history non necesary
     */
    void checkEraseHistory();

    /**
     * change yhe color image
     * @param imageCanvas the image
     * @param setFilter the filter
     */
    void changedColor(Image *imageCanvas, FiltersImage setFilter);

    /**
     * filter white
     * @return the white color
     */
    Color filterWhite();

    /**
     * fiklter blue
     * @param colorTemp color to change
     * @return the color changed
     */
    Color filterBlue(Color colorTemp);

    /**
     * fiklter green
     * @param colorTemp color to change
     * @return the color changed
     */
    Color filterGreen(Color colorTemp);

    /**
     * fiklter red
     * @param colorTemp color to change
     * @return the color changed
     */
    Color filterRed(Color colorTemp);

public:

    /**
     * Create the inital canvas
     * @param width the width
     * @param height the height
     */
    PaintPP(int width, int height);

    /**
     * Create the inital canvas
     * @param pathImage the path
     */
    PaintPP(string pathImage);

    /**
     * GEt a vectorcolors
     * @return the vectorcolors
     */
    vectorStructure<Color> getColorOfCurrentImage();

    /**
     * the width
     */
    int getWidthCanvas();

    /**
     * the height
     */
    int getHeightCanvas();

    /**
     * The destructor
     */
    virtual ~PaintPP();

    /**
     * Draw canvas
     * @param vectorMove the move in image
     * @param thickness the thickness
     * @param color the color
     */
    void drawImage(vectorStructure<PointImage> vectorMove, int thickness, Color color);

    /**
     * Erase canvas
     * @param vectorMove the move in image
     * @param thickness the thickness
     */
    void eraseImage(vectorStructure<PointImage> vectorMove, int thickness);

    /**
     * Draw line canvas
     * @param vectorMove the 2 points in image
     * @param thickness the thickness
     * @param color the color
     */
    void createLineImage(vectorStructure<PointImage> vectorMove, int thickness, Color color);

    /**
     * Magic select
     * @param pointClick the position
     */
    void magicSelectImage(PointImage pointClick);

    /**
     * Draw square canvas
     * @param vectorMove the move in image
     * @param thickness the thickness
     * @param color the color
     * @param pointCickled  the position
     * @param size the size of figure
     */
    void createSquareImage(PointImage pointCickled,int tickness, Color color,int size);

    /**
    * Draw triangle canvas
    * @param vectorMove the move in image
    * @param thickness the thickness
    * @param color the color
    * @param pointCickled  the position
    * @param size the size of figure
    */
    void createTriangleImage(PointImage pointCickled,int tickness, Color color,int size);

    /**
    * Draw square canvas
    * @param vectorMove the move in image
    * @param thickness the thickness
    * @param color the color
    * @param pointCickled  the position
    * @param size the size of figure
     * @param size2 the size2 of figure
    */
    void createRectangleImage(PointImage pointCickled,int tickness, Color color,int size, int size2);


    /**
     * Get a color
     * @param pointCickled  the position
     * @return the color piked
     */
    Color getPicker(PointImage pointCickled);

    /**
     * Fill the image
     * @param click the position
     * @param color the color
     */
    void paintFill(PointImage click, Color color);

    /**
     * Save image
     * @param pathImage the path of image
     */
    void saveImage(string pathImage);

    /**
     * DO the redo
     */
    void redoImage();

    /**
     * DO the undo
     */
    void undoImage();

    /**
     * Set the filter red
     */
    void doFilterRImage();

    /**
     * Set the filter green
     */
    void doFilterGImage();

    /**
     * Set the filter blue
     */
    void doFilterBImage();

    /**
     * ROtate the image
     */
    void rotateImage();

    /**
     * Make image white
     */
    void clearAllCanvasImage();

    /**
     * Get is ready undo
     * @return is ready undo
     */
    bool getReadyUndo();

    /**
     * GEt is reeady redo
     * @return
     */
    bool getReadyRedo();

    /**
     * PRint vector move
     * @param vectorMove the vecotr to print
     */
    [[maybe_unused]] void vectorPrint(vectorStructure<PointImage> vectorMove);

    /**
     * Delte history
     */
    void removeHistory();

    /**
     * Check is name is canvas_
     */
    string stringCheckCanvas(string text);
};


#endif //PAINT_PAINT_PP_H
