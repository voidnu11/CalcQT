#ifndef CALCULATORDISPLAY_H
#define CALCULATORDISPLAY_H

#include <QTextBrowser>

namespace SC_LineCap {
//                                    ++, -- lines
const std::pair<int, int> CASE_1  = { 17, 0  };
const std::pair<int, int> CASE_2  = { 36, 17 };
const std::pair<int, int> CASE_3  = { 52, 36 };
const std::pair<int, int> DEFAULT = { 52, 52 };
}

namespace SC_Font {
const QString FAMILY     = "Share Tech Mono";
const int     SIZE_ONE   = 36;
const int     SIZE_TWO   = 17;
const int     SIZE_THREE = 12;
}

namespace Ui { class CalculatorDisplay; }

class CalculatorDisplay : public QTextBrowser {
    Q_OBJECT

public:
    explicit CalculatorDisplay(QWidget *parent = nullptr);
    ~CalculatorDisplay();
    void updateText(const QString &str) noexcept;
    void reset() noexcept;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void increaseLine() noexcept;
    void decreaseLine() noexcept;
    void updateCapacity() noexcept;
    void resizeGeometryToFit() noexcept;
    void resizeFont() noexcept;

    Ui::CalculatorDisplay *ui;
    QPoint _pCursor;
    int m_lines;
    std::pair<int, int> m_capacity;
};

#endif // CALCULATORDISPLAY_H
