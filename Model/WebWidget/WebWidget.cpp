//
// Created by wsycc on 2025/3/13.
//

#include "WebWidget.h"
#include <QDebug>
#include <utility>


WebWidget::WebWidget(int x, int y, int width, int height, QColor bg_color,
                     const WidgetType widget_type, QString web_url)
    : BaseWidget(x, y, width, height, bg_color, widget_type, BaseWidgetType::WEB_WIDGET),
      web_url(std::move(web_url)) {}

void WebWidget::render() {
    qDebug() << "Rendering Web Widget from: " << web_url;

    web_view = std::make_unique<QWebEngineView>();
    web_view->setUrl(QUrl(web_url));
    web_view->setGeometry(x, y, width, height);
    web_view->show();
}

QString WebWidget::get_web_url() const { return web_url; }

void WebWidget::set_web_url(const QString &new_web_url) {
    web_url = new_web_url;
    if (web_view) {
        web_view->setUrl(QUrl(web_url));
    }
}