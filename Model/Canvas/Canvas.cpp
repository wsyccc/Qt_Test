//
// Created by wsycc on 2025/3/13.
//

#include "Canvas.h"

Canvas::Canvas(QWidget *parent)
    : QQuickWidget(QUrl("qrc:/qml/Canvas.qml"), parent) {
    setResizeMode(SizeRootObjectToView);
}

void Canvas::addWidget(BaseWidget *widget) {
    widgets.append(widget);
    widget->setParent(this);
    update();
}

void Canvas::removeWidget(BaseWidget *widget) {
    widgets.removeOne(widget);
    widget->setParent(nullptr);
    delete widget;
    update();
}

void Canvas::clearCanvas() {
    qDeleteAll(widgets);
    widgets.clear();
    update();
}