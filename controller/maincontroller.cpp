#include "maincontroller.h"

#include <QMessageBox>

#include "view/plotwindow.h"

Calc::MainController::MainController(CalculatorDisplay *display)
    : m_display(display), m_calc() {
  clear();
}

Calc::MainController::~MainController() { delete m_display; }

void Calc::MainController::clear() noexcept {
  m_calc.reset();
  m_display->reset();
}

void Calc::MainController::resultOnDisplay(const bool &hasX,
                                           const double &x) noexcept {
  if (hasX) {
    std::pair<double, double> pair_x({x, x});
    m_calc.setX(pair_x);
  }
  double result = m_calc.result().first.at(0);
  clear();
  update(QString::number(result, 'g', 11));
}

void Calc::MainController::resultOnPlot(const double &x1,
                                        const double &x2) noexcept {
  std::pair<double, double> pair_x({x1, x2});
  m_calc.setX(pair_x);
  auto result = m_calc.result();
  QVector<double> qDomain = QVector<double>::fromStdVector(result.first);
  QVector<double> qValue = QVector<double>::fromStdVector(result.second);
  auto normXY = m_calc.getX();
  QVector<double> XY({normXY.first, normXY.second});
  PlotWindow plot(std::make_pair(qDomain, qValue), XY);
  plot.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  plot.setModal(true);
  plot.exec();
  clear();
}

void Calc::MainController::result(const bool &isEquation, const QString &x1,
                                  const QString &x2) noexcept {
  if (!m_calc.canCalculate()) {
    QMessageBox::warning(m_display, "Input error", "Malformed expression.");
    return;
  }

  bool hasX = m_calc.hasX();
  std::pair<double, double> x({x1.toDouble(), x2.toDouble()});
  if (hasX) {
    if ((isEquation && x1.isEmpty()) ||
        (!isEquation && x1.isEmpty() && x2.isEmpty())) {
      QMessageBox::warning(m_display, "Input error",
                           "Variable X without value");
      return;
    } else if (!isEquation && x1.isEmpty()) {
      QMessageBox::warning(m_display, "Input error",
                           "Variable X1 without value");
      return;
    } else if (!isEquation && x2.isEmpty()) {
      QMessageBox::warning(m_display, "Input error",
                           "Variable X2 without value");
      return;
    } else if (!isEquation && x.first == x.second) {
      QMessageBox::warning(m_display, "Input error", "Variable X1 equal X2");
      return;
    }
  }
  if (!hasX && !isEquation) {
    QMessageBox::warning(m_display, "Incorect mode",
                         "Switch to equation mode.");
    return;
  }

  if (isEquation)
    resultOnDisplay(hasX, x.first);
  else
    resultOnPlot(x.first, x.second);
}

void Calc::MainController::remove() noexcept {
  if (!m_calc.remove()) return;
  update(m_calc.getDisplayString());
}

void Calc::MainController::append(const char &alias) noexcept {
  if (!m_calc.append(alias)) return;
  update(m_calc.getDisplayString());
}

void Calc::MainController::update(const std::string &str) noexcept {
  QString qStr = QString::fromStdString(str);
  m_display->updateText(qStr);
}

void Calc::MainController::update(const QString &str) noexcept {
  m_display->updateText(str);
}
