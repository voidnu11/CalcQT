#ifndef BASETITLEBAR_H
#define BASETITLEBAR_H

#include <QWidget>

namespace Ui { class BaseTitleBar; }

class BaseTitleBar : public QWidget {
    Q_OBJECT

public:
    explicit BaseTitleBar(QWidget *parent = nullptr);
    ~BaseTitleBar();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::BaseTitleBar *ui;
    QPoint _pCursor;
};

#endif // BASETITLEBAR_H
