#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QLineEdit)
QT_FORWARD_DECLARE_CLASS(QPushButton)
QT_FORWARD_DECLARE_CLASS(VideoWidget)
QT_FORWARD_DECLARE_CLASS(QComboBox)
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void slotPtnClicked();

private:
    QLineEdit *edit_;
    QPushButton *ptn_;
    VideoWidget *video_wid_;
    QComboBox *device_combox_;
};

#endif // WIDGET_H
