#ifndef SC_VALIDATOR_H
#define SC_VALIDATOR_H

#include <map>
#include <set>

namespace Calc {
class Validator {
public:
    explicit Validator(std::string &aliasesStr);
    ~Validator();
    bool isValid(const char &alias);
    bool isCorrectEnd();
    void update(bool append);
    void clear();
    bool hasX() noexcept;

private:
    void findOperators() noexcept;
    bool isAllowedChar(const char &alias);
    bool isInitial(const char &alias);
    bool isBlacklisted(const char &alias);
    bool contain(const char &alias, std::string str);

    const std::string &m_aliasesString;
    std::set<char> m_blackList;
    int  m_brackets, m_operators, m_xCount;
};
}
#endif // SC_VALIDATOR_H
