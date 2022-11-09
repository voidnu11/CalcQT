#include "displaytext.h"

#include "data.h"

Calc::DisplayText::DisplayText() : m_displayStr() {}

Calc::DisplayText::~DisplayText() {}

void Calc::DisplayText::clear() noexcept { m_displayStr.clear(); }

void Calc::DisplayText::append(const char &alias) noexcept {
  m_displayStr.append(Calc_DText::map.at(alias));
}

void Calc::DisplayText::remove(const char &alias) noexcept {
  int dtLen = Calc_DText::map.at(alias).length();
  int dsLen = m_displayStr.length();
  m_displayStr.erase(dsLen - dtLen, dtLen);
}

std::string Calc::DisplayText::getString() noexcept { return m_displayStr; }
