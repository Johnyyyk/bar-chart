import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: root

    //    property real value: 0.0
    property real value: Math.random()
    property alias text: lColumn.text

    Rectangle {
        id: rectColumn

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height * value
        color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    }
    Item {
        id: iColumnLabel

        anchors.top: rectColumn.top
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.left: parent.left
        anchors.right: parent.right
//        width: lColumn.height
//        height: lColumn.contentWidth

        Label {
            id: lColumn

            anchors.centerIn: parent
            width: parent.height
            height: parent.width
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            color: rectColumn.color.r + rectColumn.color.g +
                   rectColumn.color.b < 1.5 ? "white" : "black"
            wrapMode: Text.Wrap
            elide: Text.ElideRight
            rotation: -90
        }

        states: State {
            name: "OutColumn"
//            when: lColumn.contentWidth <= rectColumn.height
            when: lColumn.truncated

            PropertyChanges {
                target: iColumnLabel

                anchors.top: root.top
                anchors.bottom: root.bottom
//                height: rectColumn.height
//                width: root.width
//                anchors.fill: rectColumn
            }
            PropertyChanges {
                target: lColumn

                horizontalAlignment: Qt.AlignLeft
                color: "black"
            }
        }
    }
}
