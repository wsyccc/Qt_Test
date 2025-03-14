//
// Created by king on 2025-03-12.
//

#ifndef BASEWIDGET_H
#define BASEWIDGET_H
#include <qpainter.h>
#include <QUuid>
#include <QQuickWidget>

class BaseWidget : public QObject
{
    Q_OBJECT

public:
    enum class BaseWidgetType
    {
        QUICK_WIDGET,
        WEB_WIDGET,
    };

    enum class WidgetType
    {
        RECTANGLE,
        TRIANGLE,
        CIRCLE,
        TEXT,
        IMAGE,
        VIDEO,
        AUDIO,
    };


    BaseWidget(int x, int y, int width, int height, QColor bgColor, WidgetType widgetType,
               BaseWidgetType baseWidgetType, QQuickWidget* canvas = nullptr);

    virtual ~BaseWidget() = default;

    [[nodiscard]] int getX() const;
    void setX(int newX);

    [[nodiscard]] int getY() const;
    void setY(int newY);

    [[nodiscard]] int getWidth() const;
    void setWidth(int width);

    [[nodiscard]] int getHeight() const;
    void setHeight(int height);

    [[nodiscard]] QColor getBgColor() const;
    void setBgColor(QColor bgColor);

    [[nodiscard]] QQuickWidget* getCanvas() const;

    [[nodiscard]] WidgetType getWidgetType() const;

    [[nodiscard]] BaseWidgetType getBaseWidgetType() const;

    [[nodiscard]] QUuid getId() const;


    void setCanvas(QQuickWidget* newCanvas);

    virtual void reRender() = 0;

public slots:
    virtual void onPositionChanged() = 0;
    virtual void onSizeChanged() = 0;
    virtual void onBgColorChanged() = 0;


signals:
    void positionChanged();
    void sizeChanged();
    void bgColorChanged();

protected:
    int x, y, width, height;
    QColor bgColor;
    WidgetType widgetType;
    BaseWidgetType baseWidgetType;
    QQuickWidget* canvas;
    QUuid id;
};


#endif //BASEWIDGET_H
