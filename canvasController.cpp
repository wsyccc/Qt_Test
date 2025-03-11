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

void CanvasController::setRectX(const int x)
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

void CanvasController::setRectY(const int y)
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

void CanvasController::setCanvasWidth(const int width)
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

void CanvasController::setCanvasHeight(const int height)
{
    if (m_canvasHeight != height) {
        m_canvasHeight = height;
        emit canvasHeightChanged();
    }
}

void CanvasController::move(const int x, const int y, const int deltaX, const int deltaY)
{
    int newX = x + deltaX;
    int newY = y + deltaY;

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
