//
// Created by wsycc on 2025/3/13.
//

#include "Rectangle.h"
#include <QQmlContext>
#include <QDebug>
#include <utility>

Rectangle::Rectangle(int x, int y, int width, int height, QColor bgColor, const QString& text, QQuickWidget *canvas)
    : QuickWidget(x, y, width, height, bgColor, WidgetType::RECTANGLE, "qrc:Widgets/QtQuickView/Rectangle/rectangle.qml", canvas), localText(text) {
    qDebug() << "Creating RectangleWidget at (" << this->x() << "," << this->y() << ") with size (" << this->width() << "," << this->height() << ")" << Qt::endl;
    qDebug() << "Text: " << localText << "parent text: " << this->text() << Qt::endl;
    qDebug() << "id: " << this->id() << Qt::endl;

    connect(this, &Rectangle::textChanged, this, &Rectangle::onTextChanged);
}

QString Rectangle::text() const
{
    return localText;
}

void Rectangle::setText(QString newText)
{
    if (localText != newText)
    {
        localText = newText;
        emit textChanged();
    }
}

void Rectangle::onTextChanged() const
{
    bool isNumber;
    localText.toInt(&isNumber);
    if (!isNumber)
    {
        qDebug() << "Text is not a number!";
        return;
    }
    qDebug() << "Text is a valid number!";
}
