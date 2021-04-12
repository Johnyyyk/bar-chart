import QtQuick 2.9
import QtQuick.Controls 2.2
import Qt.labs.platform 1.0

Rectangle {
    id: root

    color: mainBackgroundColor

    Item {
        id: iContent

        anchors.margins: 10
        anchors.fill: parent

        FileDialog {
            id: fdLoadFile

            title: "Load file"
            nameFilters: ["Text files (*.txt)", "All files (*)"]
            onAccepted: {
                // TODO send file path to back
            }
        }
        Button {
            id: btnLoadFile

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: 50
            text: "Load file"
            onReleased: {
                fdLoadFile.open();
            }
        }
        Rectangle {
            id: rectLine

            anchors.top: btnLoadFile.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            height: 1
            color: "black"
        }
        Button {
            id: btnLoadByText

            anchors.top: rectLine.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            height: 50
            text: "Load by text"
            onReleased: {
                // TODO send text to back
            }
        }
        TextArea {
            id: taText

            anchors.top: btnLoadByText.bottom
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            wrapMode: TextEdit.Wrap
            background: Rectangle {
                id: taBackground

                color: "white"
            }
        }
    }
}
