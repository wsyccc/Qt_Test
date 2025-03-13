//
// Created by king on 2025-03-12.
//

#include "BaseWidget.h"
#include <QUuid>

BaseWidget::BaseWidget(int x, int y, int width, int height, QColor bgColor,
                       WidgetType widgetType, BaseWidgetType baseWidgetType, QQuickWidget* canvas)
    : x(x), y(y), width(width), height(height), bgColor(bgColor),
      widgetType(widgetType), baseWidgetType(baseWidgetType), canvas(canvas), id(QUuid::createUuid())
{}


int BaseWidget::getX() const { return x; }
void BaseWidget::setX(const int newX)
{
    if (x != newX)
    {
        x = newX;
        emit positionChanged();
    }
}

int BaseWidget::getY() const { return y; }
void BaseWidget::setY(const int newY)
{
    if (y != newY)
    {
        y = newY;
        emit positionChanged();
    }
}

int BaseWidget::getWidth() const { return width; }
void BaseWidget::setWidth(const int newWidth)
{
    if (width != newWidth)
    {
        width = newWidth;
        emit sizeChanged();
    }
}

int BaseWidget::getHeight() const { return height; }
void BaseWidget::setHeight(const int newHeight)
{
    if (height != newHeight)
    {
        height = newHeight;
        emit sizeChanged();
    }
}

QColor BaseWidget::getBgColor() const { return bgColor; }
void BaseWidget::setBgColor(const QColor newBgColor) {
    if (bgColor != newBgColor)
    {
        bgColor = newBgColor;
        emit bgColorChanged();
    }
}

QQuickWidget *BaseWidget::getCanvas() const { return canvas; }
void BaseWidget::setCanvas(QQuickWidget *newCanvas) { canvas = newCanvas; }



BaseWidget::WidgetType BaseWidget::getWidgetType() const { return widgetType; }

BaseWidget::BaseWidgetType BaseWidget::getBaseWidgetType() const { return baseWidgetType; }

QUuid BaseWidget::getId() const { return id; }




