//
// Created by carlo on 5/3/22.
//

#include "image.h"
#include "utils/vectorStructure.h"

Color::Color():r(255), g(255), b(255), a(255){}

Color::Color(float r, float g, float b):r(r), g(g), b(b), a(255) {}

Color::Color(float r, float g, float b, float a):r(r), g(g), b(b), a(a) {}

Image::Image(int width, int height):
width(width), height(height),
paddingAmount(((4 - (width * bitePerPixel) % 4) % 4)),
fileSize(fileHeaderSize + informationHeaderSize + width*height*bitePerPixel + paddingAmount*height){
}

Color Image::getColor(int x, int y) {
    return colors.getElement(y * width + x);
}

Image::~Image() = default;

void Image::setColor(const Color &color, int i, int j){
    colors.addElement(color, j * width + i);
    return;
}

void Image::exportImage(const string& path) {
    ofstream file;
    file.open(path, ios::out | ios::binary);

    if(!file.is_open()){
        Utilities::printMessageFatal(string("We couldn't open the file ") + path);
    }
    Utilities::printMessageInfo(string("We could open the file ") + path);

    unsigned char fileHeader[fileHeaderSize];

    // File type
    fileHeader[0] = 'B';
    fileHeader[1] = 'M';
    // File size
    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;
    // Reserved 1 (Not used)
    fileHeader[6] = 0;
    fileHeader[7] = 0;
    // Reserved 2 (Not used)
    fileHeader[8] = 0;
    fileHeader[9] = 0;
    // Pixel data offset
    fileHeader[10] = fileHeaderSize + informationHeaderSize;
    fileHeader[11] = 0;
    fileHeader[12] = 0;
    fileHeader[13] = 0;


    unsigned char informationHeader[informationHeaderSize];

    // Header size
    informationHeader[0] = informationHeaderSize;
    informationHeader[1] = 0;
    informationHeader[2] = 0;
    informationHeader[3] = 0;
    // Image width
    informationHeader[4] = width;
    informationHeader[5] = width >> 8;
    informationHeader[6] = width >> 16;
    informationHeader[7] = width >> 24;
    // Image height
    informationHeader[8] = height;
    informationHeader[9] = height >> 8;
    informationHeader[10] = height >> 16;
    informationHeader[11] = height >> 24;
    // Planes
    informationHeader[12] = 1;
    informationHeader[13] = 0;
    // Bits per pixel
    informationHeader[14] = bitePerPixel*8;
    informationHeader[15] = 0;
    // Compression (No compression)
    informationHeader[16] = 0;
    informationHeader[17] = 0;
    informationHeader[18] = 0;
    informationHeader[19] = 0;
    // Image size (No compression)
    informationHeader[20] = 0;
    informationHeader[21] = 0;
    informationHeader[22] = 0;
    informationHeader[23] = 0;
    // X pixels per meter (Not specified)
    informationHeader[24] = 0;
    informationHeader[25] = 0;
    informationHeader[26] = 0;
    informationHeader[27] = 0;
    // Y pixels per meter (Not specified)
    informationHeader[28] = 0;
    informationHeader[29] = 0;
    informationHeader[30] = 0;
    informationHeader[31] = 0;
    // Total colors (Color palette not used)
    informationHeader[32] = 0;
    informationHeader[33] = 0;
    informationHeader[34] = 0;
    informationHeader[35] = 0;
    // Important colors (Generally ignored)
    informationHeader[36] = 0;
    informationHeader[37] = 0;
    informationHeader[38] = 0;
    informationHeader[39] = 0;
    file.write(reinterpret_cast<char*>(fileHeader), (fileHeaderSize));
    file.write(reinterpret_cast<char*>(informationHeader), (informationHeaderSize));

    unsigned char bmpPad[] = {0,0,0,1};
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            auto tempColor = getColor(i, j);
            auto r = static_cast<unsigned char>(tempColor.r);
            auto g = static_cast<unsigned char>(tempColor.g);
            auto b = static_cast<unsigned char>(tempColor.b);
            auto a = static_cast<unsigned char>(tempColor.a);

            unsigned char color[] = {a, b, g, r};

            file.write(reinterpret_cast<char *>(color), bitePerPixel);
        }
        file.write(reinterpret_cast<char*>(bmpPad), paddingAmount);
    }
    file.close();
    Utilities::printMessageInfo("The file was saved.");
    return;
}

auto Image::createImageEmpty(int widthN, int heightN)-> Image * {
    auto image = new Image(widthN, heightN);
    for (int j = 0; j < heightN; ++j) {
        for (int i = 0; i < widthN; ++i) {
//            image->setColor(Color((float)i/(float)widthN, 1.0f-(float)i/(float)widthN, (float)j/(float)heightN), i, j);
            image->setColor(Color(255,255,255,255), i, j);
        }
    }
    return image;
}

int Image::getWidth(){
    return width;
}

int Image::getHeight(){
    return height;
}

[[maybe_unused]] void Image::setColor(const Color &color) {
    colors.addElement(color);
    return;
}

auto Image::readImage(const string &path)->Image*{
    Image* image;

    ifstream file;
    file.open(path, ios::in | ios::binary);

    if(!file.is_open()){
        Utilities::printMessageFatal("File doesn't can open. The path of the file was " + path);
    }
    Utilities::printMessageInfo(string("We could open the file ") + path);

    unsigned char fileHeader[fileHeaderSize];
    file.read(reinterpret_cast<char*>(fileHeader), fileHeaderSize);

    if(fileHeader[0]!='B' or fileHeader[1]!='M'){
        file.close();
        Utilities::printMessageFatal("File isn't an bitmap. The path of the file was " + path);
    }
    Utilities::printMessageInfo(string("The file is .bmp type"));

    unsigned char informationHeader[informationHeaderSize];
    file.read(reinterpret_cast<char*>(informationHeader), informationHeaderSize);

//    const int fileSizeN = fileHeader[2] + (fileHeader[3] << 8) + (fileHeader[4] << 16) + (fileHeader[5] << 24);

    const int widthN = informationHeader[4] + (informationHeader[5] << 8) + (informationHeader[6] << 16) + (informationHeader[7] << 24);

    const int heightN = informationHeader[8] + (informationHeader[9] << 8) + (informationHeader[10] << 16) + (informationHeader[11] << 24);

    image = new Image(widthN, heightN);
    int paddingAmount = (((4 - (widthN * bitePerPixel) % 4) % 4));
    for (int j = 0; j < heightN; ++j) {
        for (int i = 0; i < widthN; ++i) {
            unsigned char color[] = {0, 0, 0, 1};
            file.read(reinterpret_cast<char*>(color), bitePerPixel);
            image->setColor(Color(color[3],color[2], color[1], color[0]), i, j);
        }
        file.ignore(paddingAmount);
    }
    file.close();
    Utilities::printMessageInfo("The file was created.");
    return image;
}

vectorStructure<Color> Image::getColors() {
    return colors;
}




