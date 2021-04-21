import QtQuick 2.9
import QtQuick.Controls 2.2
import "../../../js/barChart.js" as BarChartJS

Item {
    id: root

    property alias rColumns: rColumns

    property var columnColors: []

    Row {
        id: rColumns

        anchors.fill: parent
        anchors.leftMargin: 5
        spacing: 5
        onWidthChanged: {
            BarChartJS.updateColumnsSize();
        }
        onHeightChanged: {
            BarChartJS.updateColumnsSize();
        }
    }

    Connections {
        target: frontBackProvider

        onSetFrontBarChart: {
            BarChartJS.fillBarChart(data);
        }
    }
}
