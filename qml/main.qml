import QtQuick 2.9
import QtQuick.Controls 2.2
import "pages/mainPage"

ApplicationWindow {
    id: mainWindow

    property int mainFontSize: 18
    property color mainDarkestGrey: "#111111"
    property color mainDarkGrey: "#222222"
    property color mainBrightGrey: "#EEEEEE"
    property color mainTransparentDarkGrey: "#EE222222"
    property color mainTransparentBlack: "#DD000000"

    visible: true
    minimumWidth: 1280
    minimumHeight: 720

    title: "BarChart"

    MainPage {
        id: mainPage

        anchors.fill: parent
    }
}
