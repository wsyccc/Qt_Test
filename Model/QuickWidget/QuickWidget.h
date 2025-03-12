//
// Created by king on 2025-03-12.
//

#ifndef QUICKWIDGET_H
#define QUICKWIDGET_H
#include "Model/BaseWidget/BaseWidget.h"
#include <QQuickWidget>
#include <Qstring>
#include <Qcolor>
#include <utility>


class QuickWidget: public BaseWidget {
public:
    QuickWidget(int x, int y, int width, int height, QColor bg_color, const WidgetType widget_type, QString qml_source): BaseWidget(x, y, width, height, bg_color, widget_type, BaseWidgetType::QML_WIDGET), qml_source(std::move(qml_source)) {}

    void render() override
    {
        qDebug() << "Rendering QML Widget ";
        auto *quickWidget = new QQuickWidget();
    }

private:
    QString qml_source;
};



#endif //QUICKWIDGET_H
