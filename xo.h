#ifndef XO_H
#define XO_H
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
class QPushButton;


class XO: public QWidget
{
public:
    XO(QWidget * parent = 0);
    void create();
    void Restart();
    bool Check();
private:
    int turn1;
    QLabel *turn;
    QLabel *label;
    QString origin;
    QList<QPushButton*> list;
signals:
public slots:
    void Move();
};

#endif // XO_H
