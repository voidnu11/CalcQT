#ifndef SC_RPN_H
#define SC_RPN_H

#include <string>

namespace Calc {
class RPN {
public:
    RPN(const std::string &infix, const double &x);
    ~RPN();
    double calculate() noexcept;

private:
    void doMath(const char &op, double &a, const double &b) noexcept;
    void doMath(const char &op, double &a) noexcept;
    void parseInfix() noexcept;
    void appendPostfix(std::string &str) noexcept;
    void appendPostfix(const char &ch) noexcept;
    void normalize(std::string str, const double &x) noexcept;
    bool contain(const char &alias, std::string str);

    std::string m_infix, m_postfix;
};
}

#endif // SC_RPN_H
