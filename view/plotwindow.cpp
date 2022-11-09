#include "plotwindow.h"

#include "calculatordisplay.h"
#include "ui_plotwindow.h"

PlotWindow::PlotWindow(std::pair<QVector<double>, QVector<double>> points,
                       QVector<double> x_range, QWidget *parent)
    : QDialog(parent), ui(new Ui::PlotWindow) {
  ui->setupUi(this);
  setAttribute(Qt::WA_TranslucentBackground, true);
  setAttribute(Qt::WA_NoSystemBackground, true);

  QPen pen;
  QFont font(SC_Font::FAMILY, 12);
  ui->plot->setFont(font);
  ui->plot->setBackground(QColor(0, 0, 0, 0));
  ui->plot->xAxis->setRange(x_range[0], x_range[1]);
  ui->plot->yAxis->setRange(x_range[0], x_range[1]);

  auto itV = points.first.begin(), itK = points.second.begin(),
       end = points.second.end();
  while (itK != end) {
    pen.setColor(QColor(26, 208, 238));
    pen.setWidth(2);
    ui->plot->addGraph()->setPen(pen);
    ui->plot->graph(ui->plot->graphCount() - 1)->setLineStyle(QCPGraph::lsLine);
    while (true) {
      if (itK == end) break;
      double absV = abs(*itV), currSign = *itV / absV, nextValue = *(itV + 1),
             absNV = abs(nextValue), nextSign = nextValue / absNV;
      ui->plot->graph(ui->plot->graphCount() - 1)->addData(*(itK++), *(itV++));
      if (absNV + absV > 1 && currSign != nextSign) {
        ui->plot->graph(ui->plot->graphCount() - 1)->addData(qQNaN(), qQNaN());
      }
    }
  }

  pen.setColor(QColor(210, 210, 210));
  pen.setWidth(1);
  ui->plot->setAntialiasedElements(QCP::aeAll);
  ui->plot->xAxis->setBasePen(pen);
  ui->plot->yAxis->setTickLabelFont(font);
  ui->plot->xAxis->setTickLabelFont(font);
  ui->plot->xAxis->setTickLabelColor(QColor(210, 210, 210));
  ui->plot->yAxis->setBasePen(pen);
  ui->plot->yAxis->setTickLabelColor(QColor(210, 210, 210));
  ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                            QCP::iSelectPlottables);
}

PlotWindow::~PlotWindow() { delete ui; }
