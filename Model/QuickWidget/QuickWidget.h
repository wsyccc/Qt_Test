//
// Created by king on 2025-03-12.
//

#ifndef QUICKWIDGET_H
#define QUICKWIDGET_H
#include "Model/BaseWidget/BaseWidget.h"
#include <QQuickWidget>
#include <Qstring>


class QuickWidget : public BaseWidget {
public:
    QuickWidget(int x, int y, int width, int height, QColor bg_color, const WidgetType widget_type, QString qml_source);

    void render() override;

    [[nodiscard]] QString get_qml_source() const;

    void set_qml_source(const QString &new_qml_source);

    std::unique_ptr<QQuickWidget> quick_widget;

private:
    QString qml_source;
};


#endif //QUICKWIDGET_H
