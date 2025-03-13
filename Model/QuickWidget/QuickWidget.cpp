//
// Created by king on 2025-03-12.
//

#include "QuickWidget.h"
#include <QDebug>
#include <utility>

QuickWidget::QuickWidget(int x, int y, int width, int height, QColor bgColor,
                         const WidgetType widgetType, QString qmlSource)
    : BaseWidget(x, y, width, height, bgColor, widgetType, BaseWidgetType::QUICK_WIDGET),
      qmlSource(std::move(qmlSource))
{
    qDebug() << "Rendering QML Widget from: " << qmlSource;

    quickWidget = new QQuickWidget(QUrl::fromLocalFile(qmlSource), nullptr);
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidget->setGeometry(x, y, width, height);
    quickWidget->setClearColor(bgColor);
    quickWidget->show();

    connect(this, &BaseWidget::positionChanged, this, &QuickWidget::onPositionChanged);
    connect(this, &BaseWidget::sizeChanged, this, &QuickWidget::onSizeChanged);
    connect(this, &BaseWidget::bgColorChanged, this, &QuickWidget::onBgColorChanged);
}

void QuickWidget::reRender()
{
    qDebug() << "Re-rendering Widget from: " << qmlSource;
    quickWidget->update();
}

QString QuickWidget::getQmlSource() const { return qmlSource; }


void QuickWidget::onPositionChanged()
{
    if (!quickWidget) return;

    quickWidget->move(x, y);
}

void QuickWidget::onSizeChanged()
{
    if (!quickWidget) return;

    quickWidget->resize(width, height);
}

void QuickWidget::onBgColorChanged()
{
    if (!quickWidget) return;

    quickWidget->setClearColor(bgColor);

}

