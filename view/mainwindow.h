#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller/maincontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_x_input1_textChanged();
    void on_x_mode1_clicked();
    void on_x_mode2_clicked();
    void on_btn_ac_clicked();
    void on_rbtn_res_clicked();
    void on_hbtn_rm_clicked();
    void on_hbtn_pi_clicked();
    void on_hbtn_e_clicked();
    void on_btn_x_clicked();
    void on_btn_e_clicked();
    void on_pbtn_0_clicked();
    void on_pbtn_1_clicked();
    void on_pbtn_2_clicked();
    void on_pbtn_3_clicked();
    void on_pbtn_4_clicked();
    void on_pbtn_5_clicked();
    void on_pbtn_6_clicked();
    void on_pbtn_7_clicked();
    void on_pbtn_8_clicked();
    void on_pbtn_9_clicked();
    void on_pbtn_dot_clicked();
    void on_rbtn_add_clicked();
    void on_rbtn_sub_clicked();
    void on_rbtn_mul_clicked();
    void on_rbtn_div_clicked();
    void on_btn_brc_clicked();
    void on_btn_bro_clicked();
    void on_btn_mod_clicked();
    void on_btn_pow_clicked();
    void on_btn_ln_clicked();
    void on_btn_log_clicked();
    void on_btn_sqrt_clicked();
    void on_btn_cos_clicked();
    void on_btn_sin_clicked();
    void on_btn_tan_clicked();
    void on_btn_acos_clicked();
    void on_btn_asin_clicked();
    void on_btn_atan_clicked();

private:
    Ui::MainWindow *ui;
    Calc::MainController *m_mainmodel;
};

#endif // MAINWINDOW_H
