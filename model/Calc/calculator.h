#ifndef SMARTCALC_H
#define SMARTCALC_H

#include "displaytext.h"
#include "validator.h"
#include <vector>

namespace Calc {
class Calculator {
public:
    Calculator();
    ~Calculator();
    void reset() noexcept;
    bool remove() noexcept;
    bool append(const char &alias) noexcept;
    std::pair<std::vector<double>, std::vector<double>>
    result() noexcept;
    bool canCalculate() noexcept;
    void setX(std::pair<double, double> &x) noexcept;
    std::pair<double, double> getX() noexcept;
    bool hasX() noexcept;
    bool insertAliasString(std::string str) noexcept;
    std::string getDisplayString() noexcept;

private:
    std::string m_aliasString;
    std::pair<double, double> m_X;
    Calc::DisplayText m_displayTexts;
    Calc::Validator m_validator;
};
}
#endif // SMARTCALC_H
