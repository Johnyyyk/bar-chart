function recolorColumns(columnCount) {
    barChart.columnColors = [];

    for (var i = 0; i < columnCount; ++i)
    {
        barChart.columnColors[i] =
                Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    }
}

function updateColumnsSize() {
    var columns = barChart.rColumns;

    for (var i = 0; i < columns.children.length; ++i) {
        var child = columns.children[i];

        child.width = columns.width / columns.children.length - columns.spacing;
        child.height = columns.height;
        child.needCheckTruncateChanged();
    }
}

function fillBarChart(data) {
    if (data === undefined) return;

    clearBarChart();

    var column = Qt.createComponent(
                "qrc:/pages/mainPage/components/BarChartColumn.qml");

    for (var i = 0; i < data.columns.length; ++i) {
        var wordData = data.columns[i];

        column.createObject(barChart.rColumns,
                            {
                                text: wordData.word + " (" +
                                      wordData.count + ")",
                                value: wordData.count /
                                       data.maxWordRepetition,
                                color: columnColors[i]
                            });
    }
    updateColumnsSize();
}

function clearBarChart() {
    var columns = barChart.rColumns;

    for(var i = columns.children.length; i > 0; i--) {
        columns.children[i-1].destroy();
    }
    columns.children = []; // for fast clean array, because destroy remove
    // object not momentaly
}
