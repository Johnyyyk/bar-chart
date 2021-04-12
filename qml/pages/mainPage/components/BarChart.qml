import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: root

    Row {
        id: rColumns

        function updateColumnsSize() {
            for (var i = 0; i < children.length; ++i) {
                var child = children[i];

                child.width = width / children.length - spacing;
                child.height = height;
            }
        }

        function fillBarChart(data) {
            clearBarChart();

            var column = Qt.createComponent("BarChartColumn.qml");

            for (var i = 0; i <= 15; ++i) {
                column.createObject(rColumns,
                                    {text: "№" + i.toString()});
            }
        }

        function clearBarChart() {
            for(var i = children.length; i > 0 ; i--) {
                children[i-1].destroy();
            }
        }

        anchors.fill: parent
        anchors.leftMargin: 5
        spacing: 5
        onWidthChanged: {
            updateColumnsSize();
        }
        onHeightChanged: {
            updateColumnsSize();
        }

        Component.onCompleted: {
            fillBarChart();
        }
    }
}
