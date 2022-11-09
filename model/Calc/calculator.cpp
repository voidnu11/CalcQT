#include "calculator.h"

#include <cmath>

#include "data.h"
#include "rpn.h"

Calc::Calculator::Calculator()
    : m_aliasString(),
      m_X({0, 0}),
      m_displayTexts(),
      m_validator(m_aliasString) {}

Calc::Calculator::~Calculator() {}

void Calc::Calculator::reset() noexcept {
  m_aliasString.clear();
  m_displayTexts.clear();
  m_validator.clear();
  m_X = std::make_pair(0, 0);
}

std::pair<std::vector<double>, std::vector<double>>
Calc::Calculator::result() noexcept {
  std::vector<double> domain, value;
  if (m_X.first == m_X.second) {
    Calc::RPN rpn(m_aliasString, m_X.first);
    value.push_back(rpn.calculate());
    domain.push_back(m_X.first);
  } else {
    double step = 0.025;
    for (double x = m_X.first; x <= m_X.second; x += step) {
      Calc::RPN rpn(m_aliasString, x);
      value.push_back(rpn.calculate());
      domain.push_back(x);
    }
  }
  return std::make_pair(value, domain);
}

bool Calc::Calculator::remove() noexcept {
  if (m_aliasString.empty()) return false;
  m_displayTexts.remove(m_aliasString.back());
  m_validator.update(false);
  m_aliasString.pop_back();
  return true;
}

bool Calc::Calculator::append(const char &alias) noexcept {
  if (!m_validator.isValid(alias)) return false;
  m_aliasString.push_back(alias);
  m_validator.update(true);
  m_displayTexts.append(alias);
  return true;
}

bool Calc::Calculator::insertAliasString(std::string str) noexcept {
  std::string::iterator it = str.begin();
  bool state = true;
  while (it != str.end() && state) state = append(*it++);
  return state;
}

bool Calc::Calculator::canCalculate() noexcept {
  return m_validator.isCorrectEnd();
}

std::string Calc::Calculator::getDisplayString() noexcept {
  return m_displayTexts.getString();
}

void Calc::Calculator::setX(std::pair<double, double> &x) noexcept {
  if (x.first != x.second) {
    double max = std::max<double>(x.first, x.second);
    double min = std::min<double>(x.first, x.second);
    x = std::make_pair(min, max);
  }
  m_X = x;
}

std::pair<double, double> Calc::Calculator::getX() noexcept { return m_X; }

bool Calc::Calculator::hasX() noexcept { return m_validator.hasX(); }
