import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: root

    //    property real value: 0.0
    property real value: Math.random()
    property alias text: lColumn.text
    property alias lColumn: lColumn
    property alias rectColumn: rectColumn

    Rectangle {
        id: rectColumn

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height * value
        width: 50
        color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    }
    Item {
        id: iColumnLabel

        rotation: -90
        anchors.bottom: rectColumn.top
        anchors.horizontalCenter: rectColumn.horizontalCenter
        anchors.bottomMargin: 10
        width: lColumn.height
        height: lColumn.contentWidth

        Label {
            id: lColumn

            anchors.centerIn: parent
            color: "black"
        }

        states: State {
            name: "InColumn"
            when: lColumn.contentWidth <= rectColumn.height

            PropertyChanges {
                target: iColumnLabel

                anchors.centerIn: rectColumn
            }
            PropertyChanges {
                target: lColumn

                color: rectColumn.color.r + rectColumn.color.g + rectColumn.color.b < 1.5 ? "white" : "black"
            }
        }
    }
}
