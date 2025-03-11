
#ifndef MOVE_RESIZE_WIDGET_H
#define MOVE_RESIZE_WIDGET_H

#include <QObject>
#include <QPointer>


class move_resize_widget final : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* widget READ widget WRITE setWidget NOTIFY widgetChanged)
    Q_PROPERTY(int x READ x WRITE setX NOTIFY positionChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY positionChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY sizeChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY sizeChanged)

public:
    explicit move_resize_widget(QObject* parent = nullptr);

    [[nodiscard]] QObject* widget() const;
    void set_widget(QObject* widget);

    [[nodiscard]] int x() const;
    void set_x(int x);

    [[nodiscard]] int y() const;
    void set_y(int y);

    [[nodiscard]] int width() const;
    void set_width(int width);

    [[nodiscard]] int height() const;
    void set_height(int height);


public slots:
    void move(int deltaX, int deltaY);
    void resize(int deltaWidth, int deltaHeight);

signals:
    void widget_changed();
    void position_changed();
    void size_changed();

private:
    QPointer<QObject> m_widget;

    void update_widget_position();
    void update_widget_size();

};



#endif //MOVE_RESIZE_WIDGET_H
