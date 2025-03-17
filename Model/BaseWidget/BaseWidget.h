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

    [[nodiscard]] int x() const;
    void setX(int newX);

    [[nodiscard]] int y() const;
    void setY(int newY);

    [[nodiscard]] int width() const;
    void setWidth(int width);

    [[nodiscard]] int height() const;
    void setHeight(int height);

    [[nodiscard]] QColor bgColor() const;
    void setBgColor(QColor bgColor);

    [[nodiscard]] QQuickWidget* canvas() const;

    [[nodiscard]] WidgetType widgetType() const;

    [[nodiscard]] BaseWidgetType baseWidgetType() const;

    [[nodiscard]] QUuid id() const;


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
    int localX, localY, localWidth, localHeight;
    QColor localBgColor;
    WidgetType localWidgetType;
    BaseWidgetType localBaseWidgetType;
    QQuickWidget* localCanvas;
    QUuid localId;
};


#endif //BASEWIDGET_H
