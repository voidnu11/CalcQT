#include "calculatordisplay.h"

#include <QMouseEvent>

#include "ui_calculatordisplay.h"

CalculatorDisplay::CalculatorDisplay(QWidget *parent)
    : QTextBrowser(parent), ui(new Ui::CalculatorDisplay) {
  ui->setupUi(this);
}

CalculatorDisplay::~CalculatorDisplay() { delete ui; }

void CalculatorDisplay::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    this->setFocus();
    _pCursor = event->globalPos() - window()->geometry().topLeft();
    event->accept();
  }
}

void CalculatorDisplay::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    window()->move(event->globalPos() - _pCursor);
    event->accept();
  }
}

void CalculatorDisplay::reset() noexcept {
  this->clear();
  m_lines = 0;
  this->setFixedHeight(63);
}

void CalculatorDisplay::increaseLine() noexcept {
  ++m_lines;
  resizeFont();
  updateCapacity();
  if (m_lines > 3) resizeGeometryToFit();
}

void CalculatorDisplay::decreaseLine() noexcept {
  --m_lines;
  resizeFont();
  updateCapacity();
  if (m_lines > 2) resizeGeometryToFit();
}

void CalculatorDisplay::updateCapacity() noexcept {
  switch (m_lines) {
    case 1:
      m_capacity = SC_LineCap::CASE_1;
      break;
    case 2:
      m_capacity = SC_LineCap::CASE_2;
      break;
    case 3:
      m_capacity = SC_LineCap::CASE_3;
      break;
    default:
      m_capacity = SC_LineCap::DEFAULT;
      break;
  }
}

void CalculatorDisplay::resizeFont() noexcept {
  QFont font(SC_Font::FAMILY);
  switch (m_lines) {
    case 1:
      font.setPointSize(SC_Font::SIZE_ONE);
      break;
    case 2:
      font.setPointSize(SC_Font::SIZE_TWO);
      break;
    default:
      font.setPointSize(SC_Font::SIZE_THREE);
      break;
  }
  this->setFont(font);
}

void CalculatorDisplay::resizeGeometryToFit() noexcept {
  QSize size = this->document()->size().toSize();
  this->setFixedHeight(size.height());
}

void CalculatorDisplay::updateText(const QString &str) noexcept {
  auto last_len = this->toPlainText().length(), curr_len = str.length();
  this->clear();
  this->setAlignment(Qt::AlignRight);
  this->insertPlainText(str);
  if (curr_len > last_len && curr_len > m_lines * m_capacity.first)
    this->increaseLine();
  else if (curr_len < last_len && curr_len <= (m_lines - 1) * m_capacity.second)
    this->decreaseLine();
}
