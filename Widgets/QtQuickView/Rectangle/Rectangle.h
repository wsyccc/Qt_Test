//
// Created by wsycc on 2025/3/13.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Model/QuickWidget/QuickWidget.h"


class Rectangle: public QuickWidget {
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
public:
    explicit Rectangle(int x, int y, int width, int height, QColor bgColor, const QString& text = "", QQuickWidget *canvas = nullptr);

    [[nodiscard]] QString text() const;
    void setText(QString text);

public slots:
    void onTextChanged() const;


signals:
    void textChanged();


private:
    QString localText;

};



#endif //RECTANGLE_H
