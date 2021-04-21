import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: root

    property alias text: lColumn.text

    property real value: Math.random()

    function needCheckTruncateChanged() {
        iColumnLabel.state = ""

        if (lColumn.truncated)
            iColumnLabel.state = "OutColumn";
    }

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

            PropertyChanges {
                target: iColumnLabel

                anchors.top: root.top
                anchors.bottom: rectColumn.top
            }
            PropertyChanges {
                target: lColumn

                horizontalAlignment: Qt.AlignLeft
                color: "black"
            }
        }
    }
}
