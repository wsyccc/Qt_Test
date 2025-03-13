//
// Created by king on 2025-03-12.
//

#include "QuickWidget.h"
#include <QDebug>
#include <utility>

QuickWidget::QuickWidget(int x, int y, int width, int height, QColor bg_color,
                         const WidgetType widget_type, QString qml_source)
    : BaseWidget(x, y, width, height, bg_color, widget_type, BaseWidgetType::QUICK_WIDGET), qml_source(std::move(qml_source)) {}

void QuickWidget::render() {
    qDebug() << "Rendering QML Widget from: " << qml_source;

    quick_widget = std::make_unique<QQuickWidget>();
    quick_widget->setSource(QUrl(qml_source));
    quick_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quick_widget->setGeometry(x, y, width, height);
    quick_widget->show();
}

QString QuickWidget::get_qml_source() const { return qml_source; }

void QuickWidget::set_qml_source(const QString &new_qml_source) { qml_source = new_qml_source; }

