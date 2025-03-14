//
// Created by king on 2025-03-14.
//

#include "CanvasManager.h"
#include <QVBoxLayout>
#include <QDebug>

#include "Widgets/QtQuickView/Rectangle/Rectangle.h"

CanvasManager::CanvasManager(QWidget *parent)
    : QWidget(parent), guidelinesEnabled(false), snip2gridEnabled(false) {
    auto layout = new QVBoxLayout(this);
    canvas = new Canvas(this);
    layout->addWidget(canvas);
    setLayout(layout);
    const auto rect = new Rectangle(0, 0, 100, 100, QColor(255, 0, 0), "100");
    canvas->addWidget(rect);
}

CanvasManager::~CanvasManager() {
    delete canvas;
}

Canvas* CanvasManager::getCanvas() const
{
    return canvas;
}

void CanvasManager::resizeCanvas(const int width, const int height) const
{
    if (canvas) {
        canvas->setFixedSize(width, height);
        qDebug() << "Canvas resized to" << width << "x" << height;
    }
}

void CanvasManager::setGuidelines(const bool enable) {
    guidelinesEnabled = enable;
    qDebug() << "Alignment guides" << (enable ? "enabled" : "disabled");

    // TODO: Implement alignment guides sending disable or enable signal to canvas
}

void CanvasManager::setSnip2Grid(bool enable)
{
    snip2gridEnabled = enable;
    qDebug() << "Snip to grid" << (enable ? "enabled" : "disabled");
    // TODO: Implement snip to grid sending disable or enable signal to canvas
}

