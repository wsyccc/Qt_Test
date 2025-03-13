//
// Created by wsycc on 2025/3/13.
//

#include "Rectangle.h"
#include <QQmlContext>
#include <QDebug>

Rectangle::Rectangle(int x, int y, int width, int height, QColor bg_color)
    : QuickWidget(x, y, width, height, bg_color, WidgetType::RECTANGLE, "qrc:/qml/Rectangle.qml") {
    qDebug() << "Creating RectangleWidget at (" << x << "," << y << ") with size (" << width << "," << height << ")";
}

void Rectangle::render() {
    QuickWidget::render();

    if (!quick_widget) return;

    QQmlContext *context = quick_widget->rootContext();
    context->setContextProperty("rectX", x);
    context->setContextProperty("rectY", y);
    context->setContextProperty("rectWidth", width);
    context->setContextProperty("rectHeight", height);
    context->setContextProperty("rectColor", bg_color);
}