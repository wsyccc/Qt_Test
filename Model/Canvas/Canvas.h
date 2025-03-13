//
// Created by wsycc on 2025/3/13.
//

#ifndef CANVAS_H
#define CANVAS_H

#include <QQmlContext>
#include "Model/BaseWidget/BaseWidget.h"

class Canvas final : public QQuickWidget {
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas() override = default;

    void addWidget(BaseWidget *widget);
    void removeWidget(BaseWidget *widget);
    void clearCanvas();

private:
    QList<BaseWidget *> widgets;
};



#endif //CANVAS_H
