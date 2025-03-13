import QtQuick
import QtQuick.Controls

Rectangle {
    id: rect
    x: parent.x ?? 0
    y: parent.y ?? 0
    width: parent.width ?? 500
    height: parent.height ?? 500
    color: parent.bgColor ?? "blue"

    TextInput {
        id: textInput
        text: rectangleWidget.text
        anchors.centerIn: parent
        font.pixelSize: 16
        color: "white"
        horizontalAlignment: Text.AlignHCenter

        onTextChanged: {
            rectangleWidget.text = textInput.text;
        }
    }
}
