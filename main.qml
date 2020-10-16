import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window {
    width: 480
    height: 800
    visible: true

    Rectangle {
        anchors.fill: parent
        color: "black"
    }

    Text {
        width: list.width
        height: 20
        anchors.bottom: list.top
        horizontalAlignment: Text.AlignHCenter
        color: "white"
        text: (list.currentIndex + 1) + " / " + pagesModel.rowCount()
    }

    ListView {
        id: list

        onCurrentIndexChanged: pagesModel.currentPage = currentIndex
        width: parent.width
        height: width
        cacheBuffer: 0
        snapMode: ListView.SnapToItem
        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        model: pagesModel
        orientation: ListView.Horizontal
        highlightRangeMode: ListView.StrictlyEnforceRange
        spacing: 10
        delegate: Grid {
            rows: 3
            columns: 3
            Repeater {
                model: pagesModel.itemsForPage
                Item {
                    width: list.width / 3
                    height: width

                    Rectangle {
                        width: parent.width * .95
                        height: parent.height * .95
                        anchors.centerIn: parent
                        radius: height * .2
                        color: Qt.rgba(Math.random(), Math.random(),
                                       Math.random(), 1)

                        Text {
                            anchors.centerIn: parent
                            width: parent.width * .5
                            height: parent.height * .5
                            text: nameRole
                        }
                    }
                }
            }
        }
    }
}
