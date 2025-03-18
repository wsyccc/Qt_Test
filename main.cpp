#include <QApplication>
#include <QMainWindow>
#include <QDir>

#include "Managers/CanvasManager/CanvasManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Canvas Manager Example");
    mainWindow.resize(1920, 1080);

    const auto *canvasManager = new CanvasManager(&mainWindow);
    mainWindow.setCentralWidget(canvasManager->getCanvas());


    mainWindow.show();

    return app.exec();
}
