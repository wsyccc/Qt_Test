import QtQuick
import QtQuick.Controls

Rectangle {
    id: rectangle
    x: rectId.x ?? 0
    y: rectId.y ?? 0
    width: rectId.width ?? 500
    height: rectId.height ?? 500
    color: rectId.bgColor ?? "blue"

    TextInput {
        id: textInput
        text: rectId.text
        anchors.centerIn: rectId
        font.pixelSize: 16
        color: "white"
        horizontalAlignment: Text.AlignHCenter

        onTextChanged: {
            rectId.text = textInput.text;
        }
    }
}
