#include "canvasController.h"

CanvasController::CanvasController(QObject *parent)
    : QObject(parent)
    , m_rectX(350)
    , m_rectY(250)
    , m_canvasWidth(1920)
    , m_canvasHeight(1080)
{}

int CanvasController::rectX() const
{
    return m_rectX;
}

void CanvasController::setRectX(int x)
{
    if (m_rectX != x) {
        m_rectX = x;
        emit rectXChanged();
    }
}

int CanvasController::rectY() const
{
    return m_rectY;
}

void CanvasController::setRectY(int y)
{
    if (m_rectY != y) {
        m_rectY = y;
        emit rectYChanged();
    }
}

int CanvasController::canvasWidth() const
{
    return m_canvasWidth;
}

void CanvasController::setCanvasWidth(int width)
{
    if (m_canvasWidth != width) {
        m_canvasWidth = width;
        emit canvasWidthChanged();
    }
}

int CanvasController::canvasHeight() const
{
    return m_canvasHeight;
}

void CanvasController::setCanvasHeight(int height)
{
    if (m_canvasHeight != height) {
        m_canvasHeight = height;
        emit canvasHeightChanged();
    }
}

void CanvasController::moveRectangle(int deltaX, int deltaY)
{
    int newX = m_rectX + deltaX;
    int newY = m_rectY + deltaY;

    // 限制边界
    if (newX < 0)
        newX = 0;
    if (newY < 0)
        newY = 0;
    if (newX + 100 > m_canvasWidth)
        newX = m_canvasWidth - 100;
    if (newY + 100 > m_canvasHeight)
        newY = m_canvasHeight - 100;

    setRectX(newX);
    setRectY(newY);
}
