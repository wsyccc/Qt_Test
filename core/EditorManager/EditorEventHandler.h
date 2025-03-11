//
// Created by king on 2025-03-11.
//

#ifndef EDITOREVENTHANDLER_H
#define EDITOREVENTHANDLER_H

#include <QObject>
#include <QPointer>

class EditorEventHandler final : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* widget READ widget WRITE setWidget NOTIFY widgetChanged)

};



#endif //EDITOREVENTHANDLER_H
