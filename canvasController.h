#ifndef CANVASCONTROLLER_H
#define CANVASCONTROLLER_H

#include <QObject>

class CanvasController final : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int rectX READ rectX WRITE set_rect_x NOTIFY rect_x_changed)
    Q_PROPERTY(int rectY READ rectY WRITE set_rect_y NOTIFY rect_y_changed)
    Q_PROPERTY(int canvas_width READ canvas_width WRITE set_canvas_width NOTIFY canvas_width_changed)
    Q_PROPERTY(int canvas_height READ canvas_height WRITE set_canvas_height NOTIFY canvas_height_changed)
    Q_PROPERTY(int triangle_x READ web_triangle_x NOTIFY web_triangle_x_changed)
    Q_PROPERTY(int triangle_y READ web_triangle_y NOTIFY web_triangle_y_changed)

public:
    explicit CanvasController(QObject* parent = nullptr);

    [[nodiscard]] int rect_x() const;
    void set_rect_x(int x);

    [[nodiscard]] int rect_t() const;
    void set_recty(int y);

    [[nodiscard]] int canvas_wWidth() const;
    void set_canvas_width(int width);

    [[nodiscard]] int canvas_height() const;
    void set_canvas_height(int height);

    [[nodiscard]] int web_triangle_x() const;
    [[nodiscard]] int web_triangle_y() const;

signals:
    void rect_x_changed();
    void rect_y_changed();
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
