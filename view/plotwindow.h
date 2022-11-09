#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QDialog>

namespace Ui { class PlotWindow; }

class PlotWindow : public QDialog {
    Q_OBJECT

public:
    explicit PlotWindow(std::pair<QVector<double>, QVector<double>> points,
                        QVector<double> x_range,
                        QWidget *parent = nullptr);
    ~PlotWindow();

private:
    Ui::PlotWindow *ui;
};

#endif // PLOTWINDOW_H
