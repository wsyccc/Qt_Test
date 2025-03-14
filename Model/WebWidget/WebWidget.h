//
// Created by wsycc on 2025/3/13.
//

#ifndef WEBWIDGET_H
#define WEBWIDGET_H

#include "Model/BaseWidget/BaseWidget.h"
#include <QWebEngineView>
#include <QString>
#include <QColor>
#include <memory>

class WebWidget: public BaseWidget {
public:
    WebWidget(int x, int y, int width, int height, QColor bgColor,
              WidgetType widgetType, QString webUrl);

    void reRender() override;

    [[nodiscard]] QString getWebUrl() const;
    void setWebUrl(const QString &newWebUrl);

private:
    QString webUrl;
    std::unique_ptr<QWebEngineView> webView;
};

#endif // WEBWIDGET_H

