#ifndef CANVASCONTROLLER_H
#define CANVASCONTROLLER_H

#include <QObject>

class CanvasController final : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int rectX READ rectX WRITE setRectX NOTIFY rectXChanged)
    Q_PROPERTY(int rectY READ rectY WRITE setRectY NOTIFY rectYChanged)
    Q_PROPERTY(int canvasWidth READ canvasWidth WRITE setCanvasWidth NOTIFY canvasWidthChanged)
    Q_PROPERTY(int canvasHeight READ canvasHeight WRITE setCanvasHeight NOTIFY canvasHeightChanged)
    Q_PROPERTY(int triangleX READ webTriangleX NOTIFY webTriangleXChanged)
    Q_PROPERTY(int triangleY READ webTriangleY NOTIFY webTriangleYChanged)

public:
    explicit CanvasController(QObject* parent = nullptr);

    [[nodiscard]] int rectX() const;
    void setRectX(int x);

    [[nodiscard]] int rectY() const;
    void setRectY(int y);

    [[nodiscard]] int canvasWidth() const;
    void setCanvasWidth(int width);

    [[nodiscard]] int canvasHeight() const;
    void setCanvasHeight(int height);

    [[nodiscard]] int webTriangleX() const;
    [[nodiscard]] int webTriangleY() const;

signals:
    void rectXChanged();
    void rectYChanged();
    void webTriangleXChanged();
    void webTriangleYChanged();
    void canvasWidthChanged();
    void canvasHeightChanged();

public slots:
    void move(int x, int y, int deltaX, int deltaY);

private:
    int m_rectX;
    int m_rectY;
    int m_canvasWidth;
    int m_canvasHeight;

    int m_triangleX{};
    int m_triangleY{};
};

#endif // CANVASCONTROLLER_H
