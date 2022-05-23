//
// Created by joan on 22/05/22.
//

#ifndef PAINT_MAGICSELECT_H
#define PAINT_MAGICSELECT_H
#include "vectorStructure.h"
#include "model/point_image.h"
#include "model/image.h"
#include <queue>

class MagicSelect{
public:
    static auto magicSelect(PointImage startPoint, Image *image)->Image*{
        Color newColor = Color(255,255,255,255);
        Color color = image->getColor(startPoint.x,startPoint.y);
        Utilities::printMessageInfo("check x:" + to_string(color.g)  + "y: " + to_string(newColor.g));
        image = dfs(startPoint, image);
        return image;
    }
private:
    static auto dfs(PointImage startPoint, Image *image) -> Image * {
        Utilities::printMessageInfo("add x:" + to_string(startPoint.x)  + "y: " + to_string(startPoint.y));
        queue<PointImage> coords;
        Color newColor = Color(255,255,255,255);
        int diferenceSelect = 70;
        int width = image->getWidth();
        int height = image->getHeight();
        coords.push(PointImage(startPoint.x, startPoint.y));
        Color startColor = image->getColor(startPoint.x,startPoint.y);
        int e[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
        image->setColor(newColor,startPoint.x,startPoint.y);
        while(!coords.empty()) {
            int startCoordX = coords.front().x;
            int startCoordY = coords.front().y;
            coords.pop();
            for (int k = 0; k < 4; k++) {
                int x = startCoordX + e[k][0];
                int y = startCoordY + e[k][1];
                if (x >= 0 && y >= 0 && x < width && y < height &&
                    ((startColor.r - diferenceSelect < (image->getColor(x, y).r) &&
                      image->getColor(x, y).r < startColor.r + diferenceSelect)
                     && (startColor.g - diferenceSelect < (image->getColor(x, y).g) &&
                         image->getColor(x, y).g < startColor.g + diferenceSelect)
                     && (startColor.b - diferenceSelect < image->getColor(x, y).b &&
                         image->getColor(x, y).b < startColor.b + diferenceSelect)
                     && (startColor.a - diferenceSelect < image->getColor(x, y).a &&
                         image->getColor(x, y).a < startColor.a + diferenceSelect))) {
                    image->setColor(newColor, x, y);
                    coords.push(PointImage(x, y));
                }
            }
        }
        return image;
    }

};
#endif //PAINT_MAGICSELECT_H
