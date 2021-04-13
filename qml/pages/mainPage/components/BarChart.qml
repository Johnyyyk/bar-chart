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
            if (data === undefined) return;

            clearBarChart();

            var column = Qt.createComponent("BarChartColumn.qml");

            for (var i = 0; i < data.columns.length; ++i) {
                var wordData = data.columns[i];

                column.createObject(rColumns,
                                    {
                                        text: wordData.word + " (" +
                                              wordData.count + ")",
                                        value: wordData.count /
                                               data.maxWordRepetition
                                    });
            }
            updateColumnsSize();
        }

        function clearBarChart() {
            for(var i = children.length; i > 0; i--) {
                children[i-1].destroy();
            }
            children = []; // for fast clean array, because destroy remove
                           // object not momentaly
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
    }

    Connections {
        target: frontBackProvider

        onSetFrontBarChart: {
            rColumns.fillBarChart(data);
        }
    }
}