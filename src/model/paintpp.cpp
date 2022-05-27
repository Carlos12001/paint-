//
// Created by carlo on 5/3/22.
//

#include "paintpp.h"


/**
     * DO the paint in the image
     * @param vectorMove the move
     * @param imageCanvas imagen to draw
     * @param grossorE the thickness
     * @param colorPaint the color
     * @return image changed
     */
auto PaintPP::paintCoordinates(vectorStructure<PointImage> vectorMove, Image *imageCanvas,
                               int grossorE, Color colorPaint) -> Image * {
    int WIDTH = imageCanvas->getWidth();
    int HEIGHT = imageCanvas->getHeight();
//    Utilities::printMessageInfo(to_string(vectorMove.size()) + " y: " + to_string(vectorMove.size()));
    int mayorElementY = vectorMove.getElement(vectorMove.size()-1).y;
    int mayorElementX = vectorMove.getElement(vectorMove.size()-1).x;
    int menorElementY = vectorMove.getElement(0).y;
    int menorElementX = vectorMove.getElement(0).x;
    if ((vectorMove.getElement(0).y) > (vectorMove.getElement(vectorMove.size()-1).y)) {
        mayorElementY = vectorMove.getElement(0).y;
        menorElementY = vectorMove.getElement(vectorMove.size()-1).y;
    }
    if ((vectorMove.getElement(0).x) > (vectorMove.getElement(vectorMove.size()-1).x)) {
        mayorElementX = vectorMove.getElement(0).x;
        menorElementX = vectorMove.getElement(vectorMove.size()-1).x;
    }
    for(int index = 0; index < vectorMove.size(); index++){
        int elementY = vectorMove.getElement(index).y;
        int elementX = vectorMove.getElement(index).x;


        for(int applyGrossor = 0; applyGrossor < grossorE; applyGrossor++){
             if(elementX+applyGrossor < WIDTH && elementX+applyGrossor > 0
             && elementY+applyGrossor < HEIGHT && elementY+applyGrossor > 0
             &&(((elementY + applyGrossor < mayorElementY) && mayorElementX == menorElementX)
             || ((elementX + applyGrossor < mayorElementX) && mayorElementY == menorElementY))){
                 imageCanvas->setColor(colorPaint,
                                       (elementX),
                                       (elementY + applyGrossor));
                 imageCanvas->setColor(colorPaint,
                                       (elementX+ applyGrossor),
                                       (elementY));
             }
            if(elementX+applyGrossor < WIDTH && elementX+applyGrossor > 0
               && elementY+applyGrossor < HEIGHT && elementY+applyGrossor > 0
               && elementX-applyGrossor < WIDTH && elementX-applyGrossor > 0
               && elementY-applyGrossor < HEIGHT && elementY-applyGrossor > 0
               && mayorElementY != menorElementY
               && mayorElementX != menorElementX){
                imageCanvas->setColor(colorPaint,
                                      (elementX),
                                      (elementY + applyGrossor));
                imageCanvas->setColor(colorPaint,
                                      (elementX+ applyGrossor),
                                      (elementY));
                imageCanvas->setColor(colorPaint,
                                      (elementX),
                                      (elementY - applyGrossor));
                imageCanvas->setColor(colorPaint,
                                      (elementX- applyGrossor),
                                      (elementY));
            }
             if(elementX-applyGrossor < WIDTH && elementX-applyGrossor > 0
                && elementY-applyGrossor < HEIGHT && elementY-applyGrossor > 0
                && (((elementY - applyGrossor > menorElementY) && mayorElementX == menorElementX)
                || ((elementX - applyGrossor > menorElementX) && mayorElementY == menorElementY))){
                 imageCanvas->setColor(colorPaint,
                                       (elementX),
                                       (elementY - applyGrossor));
                 imageCanvas->setColor(colorPaint,
                                       (elementX - applyGrossor),
                                       (elementY));
             }
        }
    }
    return imageCanvas;
}

/**
     * simulatoin of vector move
     * @param positionX num x
     * @param positionY num y
     * @return the vector
     */
[[maybe_unused]] vectorStructure<PointImage> PaintPP::mouseMovement(int positionX, int positionY) {
    vectorStructure<PointImage> eraseMove;
    for(int startx = 1; startx < positionX; startx++)
        eraseMove.addElement(PointImage(startx,startx));
    return eraseMove;
}

/**
     * erase in image
     * @param vectorMove the vector
     * @param imageCanvas the image to erease
     * @param grossorE the thickness
     * @return the image changed
     */
auto PaintPP::erase(vectorStructure<PointImage> vectorMove, Image *imageCanvas, int grossorE)->Image* {
    Color colorErase = Color(255,255,255,255);
    imageCanvas = PaintPP::paintCoordinates(vectorMove,imageCanvas,grossorE, colorErase);
    return imageCanvas;
}

/**
    * draw  in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
auto PaintPP::pencil(vectorStructure<PointImage> vectorMove, Image *imageCanvas, int grossorE,
                     Color colorSelect) -> Image * {
    imageCanvas = PaintPP::paintCoordinates(vectorMove,imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}

/**
    * draw line in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
auto PaintPP::pen(vectorStructure<PointImage> vectorTwoCordinates, Image *imageCanvas, int grossorE,
                  Color colorSelect) -> Image * {
    vectorDireccion lineDireccion(false,false,false,false);
    if((vectorTwoCordinates.getElement(1).x - vectorTwoCordinates.getElement(0).x) >= 0)
        lineDireccion.Right = true;
    if((vectorTwoCordinates.getElement(1).x - vectorTwoCordinates.getElement(0).x) == 0)
        lineDireccion.Vertical = true;
    if((vectorTwoCordinates.getElement(1).y - vectorTwoCordinates.getElement(0).y) >= 0)
        lineDireccion.Up = true;
    if((vectorTwoCordinates.getElement(1).y - vectorTwoCordinates.getElement(0).y) == 0)
        lineDireccion.Horizontal = true;


    int distance = (int)sqrt(pow((vectorTwoCordinates.getElement(0).x)-(vectorTwoCordinates.getElement(1).x),2)
            +pow((vectorTwoCordinates.getElement(0).y)-(vectorTwoCordinates.getElement(1).y),2));
//    Utilities::printMessageInfo(to_string(distance) + "Distance");
    vectorStructure<PointImage> Move = PaintPP::rectLine(vectorTwoCordinates,distance,lineDireccion);
    imageCanvas = PaintPP::paintCoordinates(Move,imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}

/**
     * do the rect line
     * @param coordinates the 2 coordnates
     * @param distance the distances
     * @param lineDireccion the direction of line
     * @return image chanfged
     */
vectorStructure<PointImage> PaintPP::rectLine(vectorStructure<PointImage> coordinates, int distance,vectorDireccion lineDireccion) {
    vectorStructure<PointImage> allCoordinates;
    for(int allDistance = 0;allDistance < distance;allDistance++ ){
        if(lineDireccion.Up && !lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x + allDistance,
                                                         coordinates.getElement(1).y - allDistance));
            }
            else if(lineDireccion.Vertical){
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x,
                                                         coordinates.getElement(1).y - allDistance));
            }
            else{
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x + allDistance,
                                                         coordinates.getElement(1).y));
            }
        }
        else if(!lineDireccion.Up && lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x - allDistance,
                                                         coordinates.getElement(1).y + allDistance));
            }
            else if(lineDireccion.Horizontal) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x - allDistance,
                                                         coordinates.getElement(1).y));
            }
            else{
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x,
                                                         coordinates.getElement(1).y + allDistance));
            }
        }
        else if(!lineDireccion.Up && !lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x + allDistance,
                                                         coordinates.getElement(1).y + allDistance));
            }
            else if(lineDireccion.Horizontal){
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x + allDistance,
                                                         coordinates.getElement(1).y));
            }
            else{
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x,
                                                         coordinates.getElement(1).y - allDistance));
            }
        }
        else{
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x - allDistance,
                                                         coordinates.getElement(1).y - allDistance));
            }
            else if(lineDireccion.Vertical){
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x,
                                                         coordinates.getElement(1).y - allDistance));
            }
            else{
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x - allDistance,
                                                         coordinates.getElement(1).y));
            }
        }
    }
    return allCoordinates;
}

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
auto PaintPP::figureFourLines(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side,int bottom) -> Image * {
    vectorStructure<PointImage> SquareVertices;
    vectorStructure<PointImage>Square;
    SquareVertices.addElement(PointImage(coord.x,coord.y));
    SquareVertices.addElement(PointImage(coord.x + bottom, coord.y));
    Square = PaintPP::rectLine(SquareVertices, bottom, vectorDireccion(true, false, true, false));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(PointImage(coord.x, coord.y + side), 1);
    Square = PaintPP::rectLine(SquareVertices, side, vectorDireccion(true, true, false, true));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(PointImage(coord.x + bottom, coord.y + side), 1);
    Square = PaintPP::rectLine(SquareVertices, side, vectorDireccion(true, true, false, true));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(PointImage(coord.x + bottom, coord.y + side), 1);
    Square = PaintPP::rectLine(SquareVertices, bottom, vectorDireccion(true, false, true, false));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}

/**
    * draw figure square in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
auto PaintPP::figureSquare(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int Size) -> Image * {
    imageCanvas = PaintPP::figureFourLines(coord,imageCanvas,grossorE,colorSelect,Size,Size);
    return imageCanvas;
}

/**
    * draw figure rectangle in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
auto PaintPP::figureRectangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side,int bottom) -> Image * {
    imageCanvas = PaintPP::figureFourLines(coord,imageCanvas,grossorE,colorSelect,side,bottom);
    return imageCanvas;
}

/**
    * draw figure triangle in image
    * @param vectorMove the vector
    * @param imageCanvas the image to change
    * @param grossorE the thickness
    * @param colorSelect the color
    * @return the image changed
    */
auto PaintPP::figureTriangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side) -> Image * {
    imageCanvas = PaintPP::figureThreeLines(coord, imageCanvas, grossorE, colorSelect, side);
    return imageCanvas;
}

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
auto PaintPP::figureThreeLines(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect,
                               int base) -> Image * {
    vectorStructure<PointImage> Vertices;
    vectorStructure<PointImage>Triangle;
    Vertices.addElement(PointImage(coord.x, coord.y));
    Vertices.addElement(PointImage(coord.x, coord.y));
    Triangle = PaintPP::rectLine(Vertices, base, vectorDireccion(true, false, true, false));
    imageCanvas = PaintPP::paintCoordinates(Triangle, imageCanvas, grossorE, colorSelect);
    Vertices.addElement(PointImage(coord.x - base/2, coord.y + base/2), 1);
    Triangle = PaintPP::rectLine(Vertices, base/2, vectorDireccion(false, true, false, false));
    imageCanvas = PaintPP::paintCoordinates(Triangle, imageCanvas, grossorE, colorSelect);
    Vertices.addElement(PointImage(coord.x - base/2, coord.y + base/2), 1);
    Triangle = PaintPP::rectLine(Vertices, base/2, vectorDireccion(true, true, false, false));
    imageCanvas = PaintPP::paintCoordinates(Triangle, imageCanvas, grossorE, colorSelect);
    return imageCanvas;
}

/**
     * Create the inital canvas
     * @param width the width
     * @param height the height
     */
PaintPP::PaintPP(int width, int height) {
    string name = getNextHistoryName();
    historyImage.addElement(name);
    createEmptyCanvas(width, height);
    saveImage(name);
}

/**
     * Create the inital canvas
     * @param pathImage the path
     */
PaintPP::PaintPP(string pathImage) {
    string name = getNextHistoryName();
    historyImage.addElement(name);
    createImageCanvas(pathImage);
    saveImage(name);
}

/**
     * Create image white
     * @param width width
     * @param height height
     */
void PaintPP::createEmptyCanvas(int width, int height){
    if(width<=1280 && height<= 720){
        currentImage = Image::createImageEmpty(width,height);
    }
    else{
        Utilities::printMessageError("The canvas is too big. "
                                     "The program is going to create the default size.");
        currentImage = Image::createImageEmpty(1280,720);
    }
    return;
}

/**
    * Create image to read
    * @param path the path
    */
void PaintPP::createImageCanvas(string path){
    ifstream file;
    file.open(path, ios::in | ios::binary);
    if(file.is_open()) {
        file.close();
        currentImage = Image::readImage(path);
    }
    else{
        Utilities::printMessageError("Exception opening/reading file. "
                                     "The program is going to create the default canvas.");
        createEmptyCanvas(1280, 720);
    }
    return;
}

/**
     * GEt a vectorcolors
     * @return the vectorcolors
     */
vectorStructure<Color> PaintPP::getColorOfCurrentImage() {
    return currentImage->getColors();
}

/**
     * GEt the next history name
     */
string PaintPP::getNextHistoryName(){
    return string("canvas_") + to_string(++positionInHistory);
}

/**
     * The destructor
     */
PaintPP::~PaintPP() {
    removeHistory();
    delete currentImage;
}

/**
     * the width
     */
int PaintPP::getWidthCanvas(){
    return currentImage->getWidth();
}

/**
     * the height
     */
int PaintPP::getHeightCanvas(){
    return currentImage->getHeight();
}

/**
     * Save image
     * @param pathImage the path of image
     */
void PaintPP::saveImage(string path) {
//    auto path = historyImage->data;
    if(string("").compare(path)){
        path += ".bmp";
        currentImage->exportImage(path);
    }
    else{
        currentImage->exportImage("imageSaved.bmp");
    }
}

/**
     * Draw canvas
     * @param vectorMove the move in image
     * @param thickness the thickness
     * @param color the color
     */
void PaintPP::drawImage(vectorStructure<PointImage> vectorMove, int thickness, Color color){
    checkEraseHistory();
    changeCurrentImage();
    pencil(vectorMove, currentImage, thickness, color);
}

/**
     * cHANGE THE CURRENT IMAGE
     */
void PaintPP::changeCurrentImage() {
    string name = historyImage.getElement(positionInHistory);
    saveImage(name);
    readyUndo = true;
    historyImage.addElement(getNextHistoryName());
}

/**
     * Get is ready undo
     * @return is ready undo
     */
bool PaintPP::getReadyUndo(){
    return readyUndo;
}

/**
     * GEt is reeady redo
     * @return
     */
bool PaintPP::getReadyRedo() {
    return readyRedo;
}

/**
     * delete next history non necesary
     */
void PaintPP::checkEraseHistory(){
    if(readyRedo){
        auto& tmp = historyImage;
        tmp.pop();
        int final = tmp.size()-1;
        for (int i = positionInHistory; i < final; ++i) {
            string command = "rm ";
            command += tmp.getElement(i) + ".bmp";
            char * cstr = new char [command.length()+1];
            strcpy(cstr, command.c_str());
            system(cstr);
            tmp.pop();
            delete[] cstr;
        }
        readyRedo = false;
    }
    readyUndo =  (positionInHistory>=1) &&positionInHistory!=0 && positionInHistory%10!=0;
}

/**
     * PRint vector move
     * @param vectorMove the vecotr to print
     */
[[maybe_unused]] void PaintPP::vectorPrint(vectorStructure<PointImage>vectorMove){
    cout << "-----------Vector MOVE----------\n"<< endl;
    for (int i = 0; i < vectorMove.size(); ++i) {
        cout << "(" << vectorMove.getElement(i).x << "," << vectorMove.getElement(i).y << ")" << "\t";
    }
    cout << endl;
}

/**
     * Erase canvas
     * @param vectorMove the move in image
     * @param thickness the thickness
     */
void PaintPP::eraseImage(vectorStructure<PointImage> vectorMove, int thickness) {
    checkEraseHistory();
    changeCurrentImage();
    erase(vectorMove, currentImage, thickness);
}

/**
     * Draw line canvas
     * @param vectorMove the 2 points in image
     * @param thickness the thickness
     * @param color the color
     */
void PaintPP::createLineImage(vectorStructure<PointImage> vectorMove, int thickness, Color color) {
    checkEraseHistory();
    changeCurrentImage();
    pen(vectorMove, currentImage, thickness, color);
}

/**
     * DO the undo
     */
void PaintPP::undoImage() {
    if(readyUndo){
        if(!readyRedo){
            string name = string("canvas_") + to_string(positionInHistory);
            saveImage(name);
        }
        if(positionInHistory>=1){
            currentImage->readImage(historyImage.getElement(--positionInHistory)+string(".bmp"), currentImage);
        }
        readyRedo = true;
    }
    readyUndo =  (positionInHistory>=1) &&positionInHistory!=0 && positionInHistory%10!=0;
}

/**
     * DO the redo
     */
void PaintPP::redoImage() {
    if(readyRedo && positionInHistory<historyImage.size()-1){
        currentImage->readImage(historyImage.getElement(++positionInHistory)+string(".bmp"), currentImage);
        readyRedo = positionInHistory<historyImage.size()-1;
    }
    readyUndo =  (positionInHistory>=1) &&positionInHistory!=0 && positionInHistory%10!=0;
}

/**
     * Delte history
     */
void PaintPP::removeHistory(){
    string command = "rm canvas_*";
    char * cstr = new char [command.length()+1];
    strcpy(cstr, command.c_str());
    system(cstr);
    delete[] cstr;
}

/**
     * Check is name is canvas_
     */
string PaintPP::stringCheckCanvas(string text){

    for (std::string::size_type i = 0; i < text.size(); ++i) {
        char chr = text[i];
        if(i==0&&chr=='c') continue;
        else if (i==1&&chr=='a') continue;
        else if (i==2&&chr=='n') continue;
        else if (i==3&&chr=='v') continue;
        else if (i==4&&chr=='a') continue;
        else if (i==5&&chr=='s') continue;
        else if (i==6&&chr=='_') return "";
        else return text;
    }
    return text;
}

/**
     * Get a color
     * @param pointCickled  the position
     * @return the color piked
     */
Color PaintPP::getPicker(PointImage pointCickled) {
    return currentImage->getColor(pointCickled.x, pointCickled.y);
}

/**
     * change yhe color image
     * @param imageCanvas the image
     * @param setFilter the filter
     */
void PaintPP::changedColor(Image *imageCanvas, PaintPP::FiltersImage setFilter) {
    for (int j = 0; j < imageCanvas->getHeight(); ++j) {
        for (int i = 0; i < imageCanvas->getWidth(); ++i) {
            Color colorTemp;
            switch (setFilter) {
                case FiltersImage::White:
                    colorTemp = filterWhite();
                    break;
                case FiltersImage::Blue:
                    colorTemp = filterBlue(imageCanvas->getColor(i,j));
                    break;
                case FiltersImage::Green:
                    colorTemp = filterBlue(imageCanvas->getColor(i,j));
                    break;
                case FiltersImage::Red:
                    colorTemp = filterBlue(imageCanvas->getColor(i,j));
                    break;
                default:
                    colorTemp = filterWhite();
                    break;
            }
            imageCanvas->setColor(colorTemp,i ,j);
        }
    }

}

/**
     * filter white
     * @return the white color
     */
Color PaintPP::filterWhite() {
    return Color(255, 255, 255, 255);
}

/**
     * fiklter blue
     * @param colorTemp color to change
     * @return the color changed
     */
Color PaintPP::filterBlue(Color colorTemp) {
    return Color(colorTemp.b, colorTemp.r, colorTemp.a, colorTemp.g);
}

/**
     * fiklter green
     * @param colorTemp color to change
     * @return the color changed
     */
[[maybe_unused]] Color PaintPP::filterGreen(Color colorTemp) {
    return Color(colorTemp.g, colorTemp.g, colorTemp.r, colorTemp.g);
}

/**
     * fiklter red
     * @param colorTemp color to change
     * @return the color changed
     */
[[maybe_unused]] Color PaintPP::filterRed(Color colorTemp) {
    return Color(colorTemp.a, colorTemp.r, colorTemp.b, colorTemp.a);
}

/**
     * Set the filter red
     */
void PaintPP::doFilterRImage() {
    checkEraseHistory();
    changeCurrentImage();
    changedColor(currentImage, FiltersImage::Red);
}

/**
     * Set the filter green
     */
void PaintPP::doFilterGImage() {
    checkEraseHistory();
    changeCurrentImage();
    changedColor(currentImage, FiltersImage::Green);
}

/**
     * Set the filter blue
     */
void PaintPP::doFilterBImage() {
    checkEraseHistory();
    changeCurrentImage();
    changedColor(currentImage, FiltersImage::Blue);
}

/**
     * Make image white
     */
[[maybe_unused]] void PaintPP::clearAllCanvasImage() {
    checkEraseHistory();
    changeCurrentImage();
    changedColor(currentImage, FiltersImage::White);
}

/**
     * Draw square canvas
     * @param vectorMove the move in image
     * @param thickness the thickness
     * @param color the color
     * @param pointCickled  the position
     * @param size the size of figure
     */
void PaintPP::createSquareImage(PointImage pointCickled,int tickness, Color color,int size) {
    checkEraseHistory();
    changeCurrentImage();
    figureSquare(pointCickled,currentImage, tickness, color, size);
}

/**
    * Draw triangle canvas
    * @param vectorMove the move in image
    * @param thickness the thickness
    * @param color the color
    * @param pointCickled  the position
    * @param size the size of figure
    */
void PaintPP::createTriangleImage(PointImage pointCickled,int tickness, Color color,int size) {
    checkEraseHistory();
    changeCurrentImage();
    figureTriangle(pointCickled,currentImage, tickness, color, size);
}

/**
    * Draw square canvas
    * @param vectorMove the move in image
    * @param thickness the thickness
    * @param color the color
    * @param pointCickled  the position
    * @param size the size of figure
     * @param size2 the size2 of figure
    */
void PaintPP::createRectangleImage(PointImage pointCickled,int tickness, Color color,int size, int size2) {
    checkEraseHistory();
    changeCurrentImage();
    figureRectangle(pointCickled,currentImage, tickness, color, size, size2);
}

/**
     * ROtate the image
     */
void PaintPP::rotateImage(){
    checkEraseHistory();
    changeCurrentImage();
    int heightN = currentImage->getHeight();
    int widthN = currentImage->getWidth();
    auto colors = getColorOfCurrentImage();
    for (int j = 0; j < heightN; ++j) {
        for (int i = 0; i < widthN; ++i) {
            currentImage->setColor(colors.getElement(j*widthN+i), widthN-i, heightN-j);
        }
    }
}

/**
     * Fill the image
     * @param click the position
     * @param color the color
     */
void PaintPP::paintFill(PointImage click, Color color) {
    checkEraseHistory();
    changeCurrentImage();
    bfsPaintFill::paintFill(click, color, currentImage);
}

/**
 * do chop qaure
 * @param vectorMove vector move two poitns
 */
void PaintPP::squareChop(vectorStructure<PointImage> vectorMove) {
    checkEraseHistory();
    changeCurrentImage();
    rectangleSelect(vectorMove,currentImage,1);
}

auto PaintPP::rectangleSelect(vectorStructure<PointImage> vectorTwoCordinates, Image *imageCanvas, int grossorE) -> Image * {
    {
        Color colorSelect = Color(128, 128, 128, 128);
        int distancex = 0;
        int distancey = 0;
        if (vectorTwoCordinates.getElement(0).x < vectorTwoCordinates.getElement(1).x) {
            distancex = vectorTwoCordinates.getElement(1).x - vectorTwoCordinates.getElement(0).x;
        } else {
            distancex = vectorTwoCordinates.getElement(0).x - vectorTwoCordinates.getElement(1).x;
        }
        if (vectorTwoCordinates.getElement(0).y < vectorTwoCordinates.getElement(1).y) {
            distancey = vectorTwoCordinates.getElement(1).y - vectorTwoCordinates.getElement(0).y;
        } else {
            distancey = vectorTwoCordinates.getElement(0).y - vectorTwoCordinates.getElement(1).y;
        }

        vectorStructure<PointImage> Move = rectangleSelectAux(vectorTwoCordinates, distancex, distancey);
        imageCanvas = pencil(Move, imageCanvas, grossorE, colorSelect);
        return imageCanvas;
    }
}

vectorStructure<PointImage>
PaintPP::rectangleSelectAux(vectorStructure<PointImage> coordinates, int distancex, int distancey) {
    vectorStructure<PointImage> allCoordinates;
    vectorStructure<PointImage> temp;
    temp = coordinates;
    if(coordinates.getElement(0).x < coordinates.getElement(1).x){
        while(distancex > 0){
            //Utilities::printMessageInfo("x1: " + to_string(temp.getElement(0).x));
            //Utilities::printMessageInfo("x2: " + to_string(coordinates.getElement(1).x));
            allCoordinates.addElement(PointImage(temp.getElement(0).x, temp.getElement(0).y));
            allCoordinates.addElement(PointImage(temp.getElement(1).x, temp.getElement(1).y));
            temp.addElement(PointImage(temp.getElement(0).x + 1, temp.getElement(0).y), 0);
            temp.addElement(PointImage(temp.getElement(1).x - 1, temp.getElement(1).y), 1);
            distancex -= 1;
        }}else{
        while(distancex > 0) {
            allCoordinates.addElement(PointImage(temp.getElement(0).x, temp.getElement(0).y));
            allCoordinates.addElement(PointImage(temp.getElement(1).x, temp.getElement(1).y));
            temp.addElement(PointImage(temp.getElement(1).x+1,temp.getElement(1).y),1);
            temp.addElement(PointImage(temp.getElement(0).x-1,temp.getElement(0).y),0);
            distancex -= 1;
        }}
    temp = coordinates;
    if(coordinates.getElement(0).y < coordinates.getElement(1).y){
        while(distancey > 0){
            Utilities::printMessageInfo("y1: " + to_string(temp.getElement(0).y));
            Utilities::printMessageInfo("y2: " + to_string(temp.getElement(1).y));
            allCoordinates.addElement(PointImage(temp.getElement(0).x,temp.getElement(0).y));
            allCoordinates.addElement(PointImage(temp.getElement(1).x,temp.getElement(1).y));

            temp.addElement(PointImage(temp.getElement(0).x,temp.getElement(0).y+1),0);
            temp.addElement(PointImage(temp.getElement(1).x,temp.getElement(1).y-1),1);
            distancey -= 1;
        }}else{
        while(distancey > 0) {

            allCoordinates.addElement(PointImage(temp.getElement(0).x,temp.getElement(0).y));
            allCoordinates.addElement(PointImage(temp.getElement(1).x,temp.getElement(1).y));
            temp.addElement(PointImage(temp.getElement(1).x, temp.getElement(1).y + 1), 1);
            temp.addElement(PointImage(temp.getElement(0).x, temp.getElement(0).y - 1), 0);
            distancey -= 1;
        }
    }
    return allCoordinates;
}
