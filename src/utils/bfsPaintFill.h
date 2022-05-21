//
// Created by joan on 21/05/22.
//

#ifndef PAINT_BFSPAINTFILL_H
#define PAINT_BFSPAINTFILL_H
#include "vectorStructure.h"
#include "model/point_image.h"
#include "model/image.h"
#include <queue>
class bfsPaintFill{
public:
    static auto paintFill(PointImage startPoint,Color newColor, Image *image)->Image*{
        Color color = image->getColor(startPoint.x,startPoint.y);
        Utilities::printMessageInfo("check x:" + to_string(color.g)  + "y: " + to_string(newColor.g));
        if(color.a != newColor.a || color.b != newColor.b || color.g != newColor.g || color.r != newColor.r)
            image = dfs(startPoint,color, newColor, image);
        return image;
    }
    static auto dfs(PointImage startPoint, Color color,
                                           Color newColor, Image* image)->Image*{
            Utilities::printMessageInfo("add x:" + to_string(startPoint.x)  + "y: " + to_string(startPoint.y));
            queue<PointImage> coords;
            int width = image->getWidth();
            int height = image->getHeight();
            coords.push(PointImage(startPoint.x, startPoint.y));
            Color startColor = image->getColor(startPoint.x,startPoint.y);
            int e[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
            image->setColor(newColor,startPoint.x,startPoint.y);
            while(!coords.empty()){
                int startCoordX = coords.front().x;
                int startCoordY = coords.front().y;
                coords.pop();
                for(int k =0;k<4;k++){
                    int x = startCoordX + e[k][0];
                    int y = startCoordY + e[k][1];
                    if (x >=0 && y >= 0 && x < width && y < height && (image->getColor(x, y).r == startColor.r && image->getColor(x, y).g == startColor.g && image->getColor(x, y).b == startColor.b && image->getColor(x, y).a == startColor.a)){
                        image->setColor(newColor,x,y);
                        coords.push(PointImage(x, y));
                    }
                }
            }
            return image;
    }

};

#endif //PAINT_BFSPAINTFILL_H
