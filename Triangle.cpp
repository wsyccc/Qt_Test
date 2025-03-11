#include <QApplication>
#include <QGraphicsPolygonItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>

class TriangleItem : public QGraphicsPolygonItem
{
public:
    TriangleItem()
    {
        QPolygonF triangle;
        triangle << QPointF(0, 0) << QPointF(-50, 100) << QPointF(50, 100);
        setPolygon(triangle);
        setBrush(Qt::red);
        setFlags(QGraphicsItem::ItemIsMovable);
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    TriangleItem *triangle = new TriangleItem();
    scene.addItem(triangle);

    QGraphicsView view(&scene);
    view.setFixedSize(800, 600);
    view.show();

    return app.exec();
}
