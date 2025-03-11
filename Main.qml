import QtQuick
import QtQuick.Controls
import QtWebEngine

Window {
    visible: true
    width: 1920
    height: 1080


    Rectangle {
        anchors.fill: parent
        color: "#f0f0f0"

        Rectangle {
            id: canvas
            width: canvasController ? canvasController.canvasWidth : width
            height: canvasController ? canvasController.canvasHeight : height
            color: "white"
            visible: typeof canvasController !== "undefined"

            Rectangle {
                id: draggableRect
                width: 100
                height: 100
                color: "red"
                radius: 10
                x: canvasController ? canvasController.rectX : 250
                y: canvasController ? canvasController.rectY : 250

                MouseArea {
                    id: dragArea
                    anchors.fill: parent
                    drag.target: null
                    onPositionChanged: {
                        let dx = mouseX - width / 2;
                        let dy = mouseY - height / 2;
                        canvasController.move(canvasController.rectX, canvasController.rectY, dx, dy);
                    }
                }
            }
        }
    }
}
