#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWebEngineView>
#include "canvasController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CanvasController canvasController;

    engine.rootContext()->setContextProperty("canvasController", &canvasController);
    engine.rootContext()->setContextProperty("canvasController", &canvasController);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("WebTest", "Main");

    return app.exec();
}
