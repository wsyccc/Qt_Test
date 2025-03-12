//
// Created by king on 2025-03-11.
//

#ifndef EDITOREVENTHANDLER_H
#define EDITOREVENTHANDLER_H

#include <QObject>
#include <QPointer>

class EditorEventHandler final : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* widget READ widget WRITE set_widget NOTIFY widget_changed)
    Q_PROPERTY(int x READ x WRITE set_x NOTIFY position_changed)
    Q_PROPERTY(int y READ y WRITE set_y NOTIFY position_changed)
    Q_PROPERTY(int width READ width WRITE set_width NOTIFY size_changed)
    Q_PROPERTY(int height READ height WRITE set_height NOTIFY size_changed)

public:
    explicit EditorEventHandler(QObject* parent = nullptr);

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


#endif //EDITOREVENTHANDLER_H
