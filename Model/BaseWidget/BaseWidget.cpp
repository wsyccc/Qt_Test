//
// Created by king on 2025-03-12.
//

#include "BaseWidget.h"
#include <QUuid>

BaseWidget::BaseWidget(int x, int y, int width, int height, QColor bgColor,
                       WidgetType widgetType, BaseWidgetType baseWidgetType, QQuickWidget* canvas)
    : localX(x), localY(y), localWidth(width), localHeight(height), localBgColor(bgColor),
      localWidgetType(widgetType), localBaseWidgetType(baseWidgetType), localCanvas(canvas), localId(QUuid::createUuid())
{}


int BaseWidget::x() const { return localX; }
void BaseWidget::setX(const int newX)
{
    if (localX != newX)
    {
        localX = newX;
        emit positionChanged();
    }
}

int BaseWidget::y() const { return localY; }
void BaseWidget::setY(const int newY)
{
    if (localY != newY)
    {
        localY = newY;
        emit positionChanged();
    }
}

int BaseWidget::width() const { return localWidth; }
void BaseWidget::setWidth(const int newWidth)
{
    if (localWidth != newWidth)
    {
        localWidth = newWidth;
        emit sizeChanged();
    }
}

int BaseWidget::height() const { return localHeight; }
void BaseWidget::setHeight(const int newHeight)
{
    if (localHeight != newHeight)
    {
        localHeight = newHeight;
        emit sizeChanged();
    }
}

QColor BaseWidget::bgColor() const { return localBgColor; }
void BaseWidget::setBgColor(const QColor newBgColor) {
    if (localBgColor != newBgColor)
    {
        localBgColor = newBgColor;
        emit bgColorChanged();
    }
}

QQuickWidget *BaseWidget::canvas() const { return localCanvas; }
void BaseWidget::setCanvas(QQuickWidget *newCanvas)
{
    localCanvas = newCanvas;
}



BaseWidget::WidgetType BaseWidget::widgetType() const { return localWidgetType; }

BaseWidget::BaseWidgetType BaseWidget::baseWidgetType() const { return localBaseWidgetType; }

QUuid BaseWidget::id() const { return localId; }




