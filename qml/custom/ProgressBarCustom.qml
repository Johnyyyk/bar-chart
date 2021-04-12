import QtQuick 2.9
import QtQuick.Controls 2.2

ProgressBar {
    id: root

    background: Rectangle {
        id: rectBackground

        width: parent.width
        height: parent.height
        color: "#cccccc"
    }
    contentItem: Item {
        id: iContent

        Rectangle {
            id: rectContent

            width: root.visualPosition * parent.width
            height: parent.height
            radius: 2
            color: "#17a81a"
        }
    }

    Label {
        id: lProgressValue

        anchors.centerIn: parent
        text: (value * 100).toFixed(0) + "%"
    }
}
