//
// Created by wsycc on 2025/3/13.
//

#include "WebWidget.h"
#include <QDebug>
#include <utility>


WebWidget::WebWidget(int x, int y, int width, int height, QColor bgColor,
                     const WidgetType widgetType, QString webUrl)
    : BaseWidget(x, y, width, height, bgColor, widgetType, BaseWidgetType::WEB_WIDGET),
      webUrl(std::move(webUrl))
{
    webView = std::make_unique<QWebEngineView>();
    webView->setUrl(QUrl(webUrl));
    webView->setGeometry(x, y, width, height);
    webView->show();
}

void WebWidget::reRender() {
    qDebug() << "Rendering Web Widget from: " << webUrl;
    webView->reload();
}

QString WebWidget::getWebUrl() const { return webUrl; }

void WebWidget::setWebUrl(const QString &newWebUrl) {
    webUrl = newWebUrl;
    if (webView) {
        webView->setUrl(QUrl(webUrl));
    }
}