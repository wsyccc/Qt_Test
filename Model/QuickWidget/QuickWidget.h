//
// Created by king on 2025-03-12.
//

#ifndef QUICKWIDGET_H
#define QUICKWIDGET_H
#include "Model/BaseWidget/BaseWidget.h"
#include <QQuickWidget>
#include <Qstring>


class QuickWidget : public BaseWidget {

    Q_OBJECT
    Q_PROPERTY(int x READ getX WRITE setX NOTIFY onPositionChanged)
    Q_PROPERTY(int y READ getY WRITE setY NOTIFY onPositionChanged)
    Q_PROPERTY(int width READ getWidth WRITE setWidth NOTIFY onSizeChanged)
    Q_PROPERTY(int height READ getHeight WRITE setHeight NOTIFY onSizeChanged)
    Q_PROPERTY(QColor bColor READ getBgColor WRITE setBgColor NOTIFY onBgColorChanged)

public:
    QuickWidget(int x, int y, int width, int height, QColor bgColor, WidgetType widgetType, QString qmlSource, QQuickWidget *canvas = nullptr);

    void reRender() override;

    [[nodiscard]] QString getQmlSource() const;

    QQuickWidget *quickWidget{};



public slots:
    void onPositionChanged() override;
    void onSizeChanged() override;
    void onBgColorChanged() override;


private:
    QString qmlSource;
};


#endif //QUICKWIDGET_H
