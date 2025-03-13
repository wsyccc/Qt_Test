//
// Created by wsycc on 2025/3/13.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Model/QuickWidget/QuickWidget.h"


class Rectangle: public QuickWidget {
public:
    Rectangle(int x, int y, int width, int height, QColor bg_color);

    void render() override;
};



#endif //RECTANGLE_H
