//
// Created by wsycc on 2025/3/13.
//

#include "Canvas.h"

Canvas::Canvas(QWidget *parent)
    : QQuickWidget(QUrl("qrc:/qml/Canvas.qml"), parent) {
    setResizeMode(SizeRootObjectToView);
    setBaseSize(400, 300);
    setMinimumSize(400, 300);
}

void Canvas::addWidget(BaseWidget *widget) {
    if (!widget)
    {
        qDebug() << "Attempted to add a null widget.";
        return;
    }
    const QUuid id = widget->getId();
    if (widgets.contains(id))
    {
        qDebug() << "Widget with ID" << id << "already exists.";
        return;
    }
    widgets.insert(id, widget);
    widget->setParent(this);
    update();
    qDebug() << "Widget added with ID:" << id;
}

void Canvas::removeWidget(const QUuid id) {
    if (!widgets.contains(id)) {
        qDebug() << "Widget with ID" << id << "not found.";
        return;
    }
    BaseWidget *widget = widgets.value(id);
    widget->setParent(nullptr);
    delete widgets.take(id);
    qDebug() << "Widget removed with ID:" << id;
    update();
}

void Canvas::clearCanvas() {
    qDebug() << "Clearing canvas, removing" << widgets.size() << "widgets.";
    qDeleteAll(widgets);
    widgets.clear();
}

void Canvas::setCanvasSize(const int width, const int height)
{
    setBaseSize(width, height);
    qDebug() << "Canvas resized to" << width << "x" << height;
}

void Canvas::setSelectedWidget(const QUuid id)
{
    if (!widgets.contains(id))
    {
        qDebug() << "Widget with ID" << id << "not found.";
        return;
    }
    selectedWidgetId = id;
}

BaseWidget *Canvas::getSelectedWidget() const
{
    if (!selectedWidgetId.isNull())
    {
        return widgets.value(selectedWidgetId);
    }
    return nullptr;
}


BaseWidget *Canvas::getWidget(const QUuid id) const
{
    if (widgets.contains(id)) {
        return widgets.value(id);
    }
    return nullptr;
}

void Canvas::drawGuidelines()
{
    qDebug() << "Drawing guidelines.";
    // TODO: Add logic to draw guidelines.
}

void Canvas::snip2Grid()
{
    qDebug() << "Snapping widgets to grid.";
    // TODO: Add logic to snap widgets to grid.
}