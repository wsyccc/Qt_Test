#include <QApplication>
#include <QMainWindow>

#include "Managers/CanvasManager/CanvasManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Canvas Manager Example");
    mainWindow.resize(1024, 768);

    auto *canvasManager = new CanvasManager(&mainWindow);
    mainWindow.setCentralWidget(canvasManager);

    mainWindow.show();

    return app.exec();
}
