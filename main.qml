import QtQuick 2.12
import QtQuick.Controls 2.12
import SceneGraphRendering 1.0

ApplicationWindow{
    visible: true
    width: 640
    height: 480
    color: 'black'
    title: qsTr("Hello World")

    Rectangle{
        id: top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: 40
        TextField{
            id: edit
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.right: combox.left
            anchors.bottom: parent.bottom
            anchors.margins: 5
            placeholderText: qsTr('请输入视频地址')
        }

        ComboBox{
            id: combox
            width: 90
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: button.left
            anchors.margins: 5
            model: ['cpu', 'cuda', 'cuda_plugin', 'qsv']
        }

        Button{
            id: button
            width: 60;
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 5
            text: qsTr('播放')
            onClicked: {
                if(edit.text != ""){
                    video.slotPlay(edit.text, combox.currentText)
                }
            }
        }
    }

    VideoItem{
        id: video
        anchors.top : top.bottom
        anchors.left: top.left
        anchors.right: top.right
        anchors.bottom: parent.bottom
        mirrorVertically: true
    }
}
