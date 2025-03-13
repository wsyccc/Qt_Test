//
// Created by king on 2025-03-12.
//

#ifndef BASEWIDGET_H
#define BASEWIDGET_H
#include <QObject>
#include <qpainter.h>
#include <QUuid>


class BaseWidget : public QObject
{
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


    BaseWidget(int x, int y, int width, int height, QColor bg_color, WidgetType widget_type,
               BaseWidgetType base_widget_type);

    virtual ~BaseWidget() = default;

    [[nodiscard]] int get_x() const;
    void set_x(int x);

    [[nodiscard]] int get_y() const;
    void set_y(int y);

    [[nodiscard]] int get_width() const;
    void set_width(int width);

    [[nodiscard]] int get_height() const;
    void set_height(int height);

    [[nodiscard]] QColor get_bg_color() const;
    void set_bg_color(QColor bg_color);

    [[nodiscard]] WidgetType get_widget_type() const;
    void set_widget_type(WidgetType type);

    [[nodiscard]] BaseWidgetType get_base_widget_type() const;
    void set_base_widget_type(BaseWidgetType base_widget_type);

    [[nodiscard]] QUuid get_id() const;

    virtual void render() = 0;

protected:
    int x, y, width, height;
    QColor bg_color;
    WidgetType widget_type;
    BaseWidgetType base_widget_type;
    QUuid id;
};


#endif //BASEWIDGET_H
