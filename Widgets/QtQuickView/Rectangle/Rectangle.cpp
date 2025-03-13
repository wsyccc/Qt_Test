//
// Created by wsycc on 2025/3/13.
//

#include "Rectangle.h"
#include <QQmlContext>
#include <QDebug>
#include <utility>

Rectangle::Rectangle(int x, int y, int width, int height, QColor bgColor, QString text)
    : QuickWidget(x, y, width, height, bgColor, WidgetType::RECTANGLE, "qrc:/qml/Rectangle.qml"), text(std::move(text)) {
    qDebug() << "Creating RectangleWidget at (" << x << "," << y << ") with size (" << width << "," << height << ")";

    connect(this, &Rectangle::textChanged, this, &Rectangle::onTextChanged);
}

QString Rectangle::getText() const
{
    return text;
}

void Rectangle::setText(QString newText)
{
    if (text != newText)
    {
        text = newText;
        emit textChanged();
    }
}

void Rectangle::onTextChanged() const
{
    bool isNumber;
    text.toInt(&isNumber);
    if (isNumber)
    {
        qDebug() << "Text is a number!";
    }
    else
    {
        qDebug() << "Text is not a number!";
    }
}
