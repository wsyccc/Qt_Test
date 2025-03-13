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
    WebWidget(int x, int y, int width, int height, QColor bg_color,
              WidgetType widget_type, QString web_url);

    void render() override;

    [[nodiscard]] QString get_web_url() const;
    void set_web_url(const QString &new_web_url);

private:
    QString web_url;
    std::unique_ptr<QWebEngineView> web_view;
};

#endif // WEBWIDGET_H

