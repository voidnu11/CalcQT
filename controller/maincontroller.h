#ifndef SMARTCALCMAINMODEL_H
#define SMARTCALCMAINMODEL_H

#include <view/calculatordisplay.h>
#include "model/Calc/calculator.h"

namespace Calc {
class MainController {
public:
    explicit MainController(CalculatorDisplay *display);
    ~MainController();
    void clear() noexcept;
    void result(const bool &isEquation, const QString &x1, const QString &x2) noexcept;
    void remove() noexcept;
    void append(const char &alias) noexcept;

private:
    void update(const std::string &str) noexcept;
    void update(const QString &str) noexcept;
    void resultOnDisplay(const bool &hasX, const double &x) noexcept;
    void resultOnPlot(const double &x1, const double &x2) noexcept;

    CalculatorDisplay *m_display;
    Calc::Calculator m_calc;
};
}

#endif // SMARTCALCMAINMODEL_H
