//
// Created by wsycc on 2025/3/13.
//

#ifndef CANVAS_H
#define CANVAS_H

#include "Model/BaseWidget/BaseWidget.h"

class Canvas final : public QQuickWidget {
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas() override = default;

    void addWidget(BaseWidget *widget);
    void removeWidget(QUuid id);
    void clearCanvas();

    void setCanvasSize(int width, int height);
    void setSelectedWidget(QUuid id);

    BaseWidget *getSelectedWidget() const;

    void drawGuidelines();
    void snip2Grid();

    BaseWidget *getWidget(QUuid id) const;

private:
    QMap<QUuid, BaseWidget *> widgets;
    QUuid selectedWidgetId;
};



#endif //CANVAS_H
