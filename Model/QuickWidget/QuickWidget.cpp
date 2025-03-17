//
// Created by king on 2025-03-12.
//

#include "QuickWidget.h"

#include <ostream>
#include <QDebug>
#include <utility>

QuickWidget::QuickWidget(int x, int y, int width, int height, QColor bgColor,
                         const WidgetType widgetType, const QString& qmlSource, QQuickWidget *canvas)
    : BaseWidget(x, y, width, height, bgColor, widgetType, BaseWidgetType::QUICK_WIDGET, canvas),
      qmlSource(qmlSource)
{
    qDebug() << QString("Rendering QML %1 from: %2").arg(static_cast<qlonglong>(widgetType)).arg(qmlSource) << Qt::endl;

    quickWidget = new QQuickWidget(QUrl(qmlSource), nullptr);
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidget->setGeometry(x, y, width, height);
    quickWidget->setClearColor(bgColor);
    quickWidget->show();

    connect(this, &BaseWidget::positionChanged, this, &BaseWidget::onPositionChanged);
    connect(this, &BaseWidget::sizeChanged, this, &BaseWidget::onSizeChanged);
    connect(this, &BaseWidget::bgColorChanged, this, &BaseWidget::onBgColorChanged);
}

void QuickWidget::reRender()
{
    qDebug() << QString::asprintf("Re-Rendering QML %d from: %s", widgetType(), qmlSource.toStdString().c_str()) << Qt::endl;
    quickWidget->update();
}

QString QuickWidget::getQmlSource() const { return qmlSource; }


void QuickWidget::onPositionChanged()
{
    if (!quickWidget) return;

    quickWidget->move(x(), y());
}

void QuickWidget::onSizeChanged()
{
    if (!quickWidget) return;

    quickWidget->resize(width(), height());
}

void QuickWidget::onBgColorChanged()
{
    if (!quickWidget) return;

    quickWidget->setClearColor(bgColor());

}

