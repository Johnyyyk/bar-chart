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

        Label {
            id: lColumnCount

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            text: "Column count:"
        }
        TextField {
            id: tfColumnCount

            anchors.top: lColumnCount.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            validator: RegExpValidator { regExp: /[0-9]+/ }
            text: "15"
            selectByMouse: true
            onTextEdited: {
                frontBackProvider.setColumnCount(parseInt(text));
            }
        }
        Rectangle {
            id: rectLineFirst

            anchors.top: tfColumnCount.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            height: 1
            color: "black"
        }
        FileDialog {
            id: fdLoadFile

            title: "Load file"
            nameFilters: ["Text files (*.txt)", "All files (*)"]
            onAccepted: {
                frontBackProvider.loadFile(file);
            }
        }
        Button {
            id: btnLoadFile

            anchors.top: rectLineFirst.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            height: 50
            text: "Load file"
            onReleased: {
                fdLoadFile.open();
            }
        }
        Rectangle {
            id: rectLineSecond

            anchors.top: btnLoadFile.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            height: 1
            color: "black"
        }
        Button {
            id: btnLoadByText

            anchors.top: rectLineSecond.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            height: 50
            text: "Load by text"
            onReleased: {
                frontBackProvider.loadByText(taText.text);
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
