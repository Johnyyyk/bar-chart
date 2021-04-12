import QtQuick 2.9
import "../../../custom"

Rectangle {
    id: root

    anchors.bottom: parent.bottom
    anchors.left: leftBar.right
    anchors.right: parent.right
    height: 50
    color: mainBackgroundColor

    ProgressBarCustom {
        id: pbLoadProgress

        anchors.fill: parent
        anchors.margins: 10
        value: 1
    }

    states: State {
        when: pbLoadProgress.value === 1

        PropertyChanges {
            target: root

            visible: false
            height: 0
        }
    }
}
