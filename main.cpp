#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QFontDatabase>
#include <QGraphicsEffect>
#include <QScreen>

#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

  QFile styleFile(":/qss/style");
  if (!styleFile.open(QIODevice::ReadOnly)) {
    return 0;
  }
  QString stylesheet(styleFile.readAll());
  a.setStyleSheet(stylesheet);

  QFontDatabase::addApplicationFont(":/ttf/main");
  w.show();
  return a.exec();
}
