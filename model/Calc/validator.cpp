#include "validator.h"

#include "data.h"

Calc::Validator::Validator(std::string &aliasesStr)
    : m_aliasesString(aliasesStr),
      m_blackList(),
      m_brackets(0),
      m_operators(0),
      m_xCount(0) {}

Calc::Validator::~Validator() { m_blackList.clear(); }

bool Calc::Validator::isValid(const char &alias) {
  return isInitial(alias) || isAllowedChar(alias);
}

bool Calc::Validator::isInitial(const char &alias) {
  return m_aliasesString.empty() && contain(alias, Calc_AllowedString::CASE_4);
}

bool Calc::Validator::isAllowedChar(const char &alias) {
  return !m_aliasesString.empty() &&
         contain(alias, Calc_AllowedString::map.at(m_aliasesString.back())) &&
         !isBlacklisted(alias);
}

bool Calc::Validator::isBlacklisted(const char &alias) {
  return m_blackList.count(alias) != 0;
}

void Calc::Validator::clear() {
  m_brackets = 0;
  m_operators = 1;
  m_blackList.clear();
  m_blackList.insert(Calc_Alias::BRC);
}

void Calc::Validator::update(bool append) {
  const char alias = m_aliasesString.back();
  if (contain(alias, "(QLlCcSsTt")) {
    if (append) {
      m_operators = 1;
      m_brackets++;
      if (m_blackList.count(Calc_Alias::BRC) != 0)
        m_blackList.erase(Calc_Alias::BRC);
    } else {
      m_operators = 0;
      m_brackets--;
      if (m_brackets == 0) m_blackList.insert(Calc_Alias::BRC);
      findOperators();
    }
  } else if (alias == Calc_Alias::BRC) {
    if (append) {
      m_brackets--;
    } else {
      m_brackets++;
      if (m_blackList.count(Calc_Alias::BRC) >= 1)
        m_blackList.erase(Calc_Alias::BRC);
    }
  } else if (alias == Calc_Alias::E) {
    if (append) {
      if (m_blackList.count(Calc_Alias::DOT) == 0) {
        m_blackList.insert(Calc_Alias::DOT);
        m_blackList.insert(Calc_Alias::E);
      } else {
        m_blackList.insert(Calc_Alias::E);
      }
    } else {
      m_blackList.erase(Calc_Alias::E);
    }
  } else if (alias == Calc_Alias::DOT) {
    if (append) {
      m_blackList.insert(Calc_Alias::DOT);
    } else {
      m_blackList.erase(Calc_Alias::DOT);
      findOperators();
    }
  } else if (contain(alias, "*/%^pm")) {
    if (append) {
      m_blackList.erase(Calc_Alias::E);
      m_blackList.erase(Calc_Alias::DOT);
      m_operators++;
    } else {
      m_blackList.insert(Calc_Alias::DOT);
      m_operators--;
    }
  } else if (contain(alias, Calc_AllowedString::CASE_1)) {
    if (append)
      m_operators = 0;
    else
      findOperators();
  } else if (alias == Calc_Alias::X) {
    m_xCount += append ? 1 : -1;
  }

  if (m_operators < 1) {
    m_blackList.erase(Calc_Alias::ADD);
    m_blackList.erase(Calc_Alias::SUB);
  } else if (m_operators == 2) {
    m_blackList.insert({Calc_Alias::ADD, Calc_Alias::SUB});
  }
  if (m_brackets == 0) {
    m_blackList.insert(Calc_Alias::BRC);
  }
}

void Calc::Validator::findOperators() noexcept {
  std::string str(m_aliasesString), breaks("*/%^pmQLlCcSsTt");
  std::string::iterator it = str.end() - 2;
  while (m_operators < 2 && str.begin() != it && contain(*it, breaks)) {
    m_operators++;
    --it;
  }
}

bool Calc::Validator::isCorrectEnd() {
  return !m_aliasesString.empty() && m_brackets == 0 &&
         contain(m_aliasesString.back(), "0123456789xei)");
}

bool Calc::Validator::contain(const char &alias, std::string str) {
  return str.find(alias) != std::string::npos;
}

bool Calc::Validator::hasX() noexcept { return m_xCount > 0; }
