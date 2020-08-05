#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "VideoWidget/videowidget.h"
#include "widget.h"

#pragma execution_character_set("utf-8")
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    video_wid_ = new VideoWidget;
    ptn_ = new QPushButton(tr("播放"));
    edit_ = new QLineEdit("rtsp://192.168.2.66/person.avi");
    device_combox_ = new QComboBox;
    device_combox_->addItems(QStringList() << tr("cpu") << tr("cuda") << tr("cuda_plugin") << tr("qsv"));

    QFormLayout *formLay = new QFormLayout;
    formLay->addRow(tr("URL"), edit_);
    QHBoxLayout *hlay = new QHBoxLayout;
    hlay->addLayout(formLay);
    hlay->addWidget(device_combox_);
    hlay->addWidget(ptn_);

    QVBoxLayout *mainLay = new QVBoxLayout;
    mainLay->addLayout(hlay);
    mainLay->addWidget(video_wid_);
    setLayout(mainLay);

    connect(ptn_, SIGNAL(clicked()), this, SLOT(slotPtnClicked()));
}

Widget::~Widget()
{

}

void Widget::slotPtnClicked()
{
    video_wid_->slotPlay(edit_->text(), device_combox_->currentText());
}
