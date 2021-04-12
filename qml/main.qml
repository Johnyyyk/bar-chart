import QtQuick 2.9
import QtQuick.Controls 2.2
import "pages/mainPage"

ApplicationWindow {
    id: mainWindow

    property color mainBackgroundColor: "#eeeeee"

    visible: true
    minimumWidth: 1280
    minimumHeight: 720

    title: "BarChart"

    MainPage {
        id: mainPage

        anchors.fill: parent
    }
}
