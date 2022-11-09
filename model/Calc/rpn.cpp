#include "rpn.h"

#include <cmath>
#include <cstring>
#include <stack>

#include "data.h"
#include "validator.h"

Calc::RPN::RPN(const std::string &infix, const double &x)
    : m_infix(), m_postfix() {
  normalize(infix, x);
  parseInfix();
}

Calc::RPN::~RPN() {}

double Calc::RPN::calculate() noexcept {
  setlocale(LC_ALL, "en_US");
  std::stack<double> operands;
  char *str = (char *)m_postfix.c_str();
  char *token = NULL, *context = NULL;
  token = strtok_r(str, " ", &context);
  while (token != NULL) {
    bool ch = strlen(token) == 1;
    if (ch && contain(*token, "pm*/^%")) {
      double a = operands.top();
      operands.pop();
      double b = operands.top();
      operands.pop();
      doMath(*token, a, b);
      operands.push(a);
    } else if (ch && contain(*token, "QLlCcSsTt")) {
      double a = operands.top();
      operands.pop();
      doMath(*token, a);
      operands.push(a);
    } else {
      operands.push(std::stod(token));
    }
    token = strtok_r(NULL, " ", &context);
  }
  double result = operands.top();
  operands.pop();
  return result;
}

void Calc::RPN::doMath(const char &op, double &a, const double &b) noexcept {
  switch (op) {
    case Calc_Alias::ADD:
      a = a + b;
      break;
    case Calc_Alias::SUB:
      a = b - a;
      break;
    case Calc_Alias::MUL:
      a = a * b;
      break;
    case Calc_Alias::DIV:
      a = b / a;
      break;
    case Calc_Alias::MOD:
      a = fmod(b, a);
      break;
    case Calc_Alias::POW:
      a = pow(b, a);
      break;
  }
}

void Calc::RPN::doMath(const char &op, double &a) noexcept {
  switch (op) {
    case Calc_Alias::SIN:
      a = sin(a);
      break;
    case Calc_Alias::COS:
      a = cos(a);
      break;
    case Calc_Alias::TAN:
      a = tan(a);
      break;
    case Calc_Alias::LN:
      a = log(a);
      break;
    case Calc_Alias::ACOS:
      a = acos(a);
      break;
    case Calc_Alias::ASIN:
      a = asin(a);
      break;
    case Calc_Alias::ATAN:
      a = atan(a);
      break;
    case Calc_Alias::SQRT:
      a = sqrt(a);
      break;
    case Calc_Alias::LOG:
      a = log10(a);
      break;
  }
}

void Calc::RPN::parseInfix() noexcept {
  std::stack<std::pair<char, int>> operators;
  std::string operand;
  std::string::iterator it = m_infix.begin();
  while (true) {
    while (contain(*it, "-0123456789.E")) operand += *it++;
    appendPostfix(operand);
    if (it == m_infix.end()) break;
    if (*it == Calc_Alias::BRC) {
      while (!operators.empty() && operators.top().first != Calc_Alias::BRO) {
        appendPostfix(operators.top().first);
        operators.pop();
      }
      operators.pop();
    } else {
      int mask = Calc_OperatorMask::map.at(*it);
      while (!operators.empty() && *it != Calc_Alias::BRO &&
             mask <= operators.top().second) {
        appendPostfix(operators.top().first);
        operators.pop();
      }
      operators.push(std::make_pair(*it, mask));
    }
    ++it;
  }
  while (!operators.empty()) {
    appendPostfix(operators.top().first);
    operators.pop();
  }
}

void Calc::RPN::appendPostfix(std::string &str) noexcept {
  if (str.empty()) return;
  if (!m_postfix.empty()) m_postfix.append(" ");
  m_postfix.append(str);
  str.clear();
}

void Calc::RPN::appendPostfix(const char &ch) noexcept {
  std::string str;
  str += ch;
  appendPostfix(str);
}

void Calc::RPN::normalize(std::string str, const double &x) noexcept {
  std::string::iterator it = str.begin();
  bool binary = true;
  for (; it != str.end(); ++it) {
    if (binary && contain(*it, "pm")) {
      m_infix.append(*it == Calc_Alias::SUB ? "-1*" : "");
    } else if (contain(*it, "QLlCcSsTt(*/^%pmE")) {
      m_infix += *it;
      if (contain(*it, "QLlCcSsTt")) m_infix += Calc_Alias::BRO;
      binary = true;
      continue;
    } else if (*it == Calc_Alias::PI) {
      m_infix.append(std::to_string(M_PI));
    } else if (*it == Calc_Alias::EULER) {
      m_infix.append(std::to_string(M_E));
    } else if (*it == Calc_Alias::X) {
      m_infix.append(std::to_string(x));
    } else {
      m_infix += *it;
    }
    binary = false;
  }
}

bool Calc::RPN::contain(const char &alias, std::string str) {
  return str.find(alias) != std::string::npos;
}
