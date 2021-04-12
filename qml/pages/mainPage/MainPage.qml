import QtQuick 2.9
import QtQuick.Controls 2.2
import "components"
import "../../custom"

Item {
    id: root

    LeftBar {
        id: leftBar

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 300
    }
    BarChartProgressBar {
        id: barChartLoadProgress

        anchors.bottom: parent.bottom
        anchors.left: leftBar.right
        anchors.right: parent.right
        height: 50
    }
    BarChart {
        id: barChart

        anchors.left: leftBar.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: barChartLoadProgress.top
    }
}
