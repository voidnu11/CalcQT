#include "basetitlebar.h"

#include <QMouseEvent>

#include "ui_basetitlebar.h"

BaseTitleBar::BaseTitleBar(QWidget *parent)
    : QWidget(parent), ui(new Ui::BaseTitleBar) {
  ui->setupUi(this);
  connect(ui->close_window, SIGNAL(clicked()), window(), SLOT(close()));
  connect(ui->minimize_window, SIGNAL(clicked()), window(),
          SLOT(showMinimized()));
}

void BaseTitleBar::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    _pCursor = event->globalPos() - window()->geometry().topLeft();
    event->accept();
  }
}

void BaseTitleBar::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    window()->move(event->globalPos() - _pCursor);
    event->accept();
  }
}

BaseTitleBar::~BaseTitleBar() { delete ui; }
