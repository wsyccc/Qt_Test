//
// Created by king on 2025-03-12.
//

#include "BaseWidget.h"
#include <QUuid>

BaseWidget::BaseWidget(int x, int y, int width, int height, QColor bg_color,
                       WidgetType widget_type, BaseWidgetType base_widget_type)
    : x(x), y(y), width(width), height(height),
      bg_color(bg_color), widget_type(widget_type), base_widget_type(base_widget_type)
{
    this->id = QUuid::createUuid();
}


int BaseWidget::get_x() const { return x; }
void BaseWidget::set_x(int new_x) { x = new_x; }

int BaseWidget::get_y() const { return y; }
void BaseWidget::set_y(int new_y) { y = new_y; }

int BaseWidget::get_width() const { return width; }
void BaseWidget::set_width(int new_width) { width = new_width; }

int BaseWidget::get_height() const { return height; }
void BaseWidget::set_height(int new_height) { height = new_height; }

QColor BaseWidget::get_bg_color() const { return bg_color; }
void BaseWidget::set_bg_color(QColor new_bg_color) { bg_color = new_bg_color; }

BaseWidget::WidgetType BaseWidget::get_widget_type() const { return widget_type; }
void BaseWidget::set_widget_type(WidgetType new_type) { widget_type = new_type; }

BaseWidget::BaseWidgetType BaseWidget::get_base_widget_type() const { return base_widget_type; }
void BaseWidget::set_base_widget_type(BaseWidgetType new_base_widget_type) { base_widget_type = new_base_widget_type; }

QUuid BaseWidget::get_id() const { return id; }
