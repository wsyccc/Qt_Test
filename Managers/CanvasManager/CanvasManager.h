//
// Created by king on 2025-03-14.
//

#ifndef CANVASMANAGER_H
#define CANVASMANAGER_H

#include "../../Model/Canvas/Canvas.h"
#include <QWidget>

class CanvasManager final : public QWidget {
    Q_OBJECT
public:
    explicit CanvasManager(QWidget *parent = nullptr);
    ~CanvasManager() override;

    Canvas *getCanvas() const;

    void resizeCanvas(int width, int height) const;
    void setGuidelines(bool enable);
    void setSnip2Grid(bool enable);

private:
    Canvas *canvas;
    bool guidelinesEnabled;
    bool snip2gridEnabled;
};

#endif // CANVASMANAGER_H

