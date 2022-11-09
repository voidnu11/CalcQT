#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

#include <string>

namespace Calc {
class DisplayText {
public:
    DisplayText();
    ~DisplayText();
    void clear() noexcept;
    void append(const char &alias) noexcept;
    void remove(const char &alias) noexcept;
    std::string getString() noexcept;

private:
    std::string m_displayStr;
};
}

#endif // DISPLAYTEXT_H
