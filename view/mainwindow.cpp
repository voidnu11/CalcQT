#include "mainwindow.h"

#include <QDoubleValidator>

#include "model/Calc/data.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setAttribute(Qt::WA_TranslucentBackground, true);
  setAttribute(Qt::WA_NoSystemBackground, true);
  m_mainmodel = new Calc::MainController(ui->display);
  ui->x_mode1->clicked();
  ui->x_input1->setValidator(new QDoubleValidator(-100, 100, 8, this));
  ui->x_input2->setValidator(new QDoubleValidator(-100, 100, 8, this));
}

MainWindow::~MainWindow() {
  delete ui;
  delete m_mainmodel;
}

void MainWindow::on_x_input1_textChanged() {
  if (ui->x_mode1->isChecked()) ui->x_input2->setText(ui->x_input1->text());
}

void MainWindow::on_x_mode1_clicked() {
  ui->x_mode1->setChecked(true);
  ui->x_label1->setVisible(true);
  ui->x_label2->setVisible(false);
  ui->x_input2->setVisible(false);
}

void MainWindow::on_x_mode2_clicked() {
  ui->x_mode2->setChecked(true);
  ui->x_label2->setVisible(true);
  ui->x_input2->setVisible(true);
  ui->x_label1->setVisible(false);
}

void MainWindow::on_rbtn_res_clicked() {
  m_mainmodel->result(ui->x_mode1->isChecked(), ui->x_input1->text(),
                      ui->x_input2->text());
}

void MainWindow::on_btn_ac_clicked() { m_mainmodel->clear(); }
void MainWindow::on_hbtn_rm_clicked() { m_mainmodel->remove(); }
void MainWindow::on_hbtn_pi_clicked() { m_mainmodel->append(Calc_Alias::PI); }
void MainWindow::on_hbtn_e_clicked() { m_mainmodel->append(Calc_Alias::E); }
void MainWindow::on_btn_x_clicked() { m_mainmodel->append(Calc_Alias::X); }
void MainWindow::on_btn_e_clicked() { m_mainmodel->append(Calc_Alias::EULER); }
void MainWindow::on_pbtn_0_clicked() { m_mainmodel->append(Calc_Alias::ZERO); }
void MainWindow::on_pbtn_1_clicked() { m_mainmodel->append(Calc_Alias::ONE); }
void MainWindow::on_pbtn_2_clicked() { m_mainmodel->append(Calc_Alias::TWO); }
void MainWindow::on_pbtn_3_clicked() { m_mainmodel->append(Calc_Alias::THREE); }
void MainWindow::on_pbtn_4_clicked() { m_mainmodel->append(Calc_Alias::FOUR); }
void MainWindow::on_pbtn_5_clicked() { m_mainmodel->append(Calc_Alias::FIVE); }
void MainWindow::on_pbtn_6_clicked() { m_mainmodel->append(Calc_Alias::SIX); }
void MainWindow::on_pbtn_7_clicked() { m_mainmodel->append(Calc_Alias::SEVEN); }
void MainWindow::on_pbtn_8_clicked() { m_mainmodel->append(Calc_Alias::EIGHT); }
void MainWindow::on_pbtn_9_clicked() { m_mainmodel->append(Calc_Alias::NINE); }
void MainWindow::on_pbtn_dot_clicked() { m_mainmodel->append(Calc_Alias::DOT); }
void MainWindow::on_rbtn_add_clicked() { m_mainmodel->append(Calc_Alias::ADD); }
void MainWindow::on_rbtn_sub_clicked() { m_mainmodel->append(Calc_Alias::SUB); }
void MainWindow::on_rbtn_mul_clicked() { m_mainmodel->append(Calc_Alias::MUL); }
void MainWindow::on_rbtn_div_clicked() { m_mainmodel->append(Calc_Alias::DIV); }
void MainWindow::on_btn_brc_clicked() { m_mainmodel->append(Calc_Alias::BRC); }
void MainWindow::on_btn_bro_clicked() { m_mainmodel->append(Calc_Alias::BRO); }
void MainWindow::on_btn_mod_clicked() { m_mainmodel->append(Calc_Alias::MOD); }
void MainWindow::on_btn_pow_clicked() { m_mainmodel->append(Calc_Alias::POW); }
void MainWindow::on_btn_ln_clicked() { m_mainmodel->append(Calc_Alias::LN); }
void MainWindow::on_btn_log_clicked() { m_mainmodel->append(Calc_Alias::LOG); }
void MainWindow::on_btn_sqrt_clicked() {
  m_mainmodel->append(Calc_Alias::SQRT);
}
void MainWindow::on_btn_cos_clicked() { m_mainmodel->append(Calc_Alias::COS); }
void MainWindow::on_btn_sin_clicked() { m_mainmodel->append(Calc_Alias::SIN); }
void MainWindow::on_btn_tan_clicked() { m_mainmodel->append(Calc_Alias::TAN); }
void MainWindow::on_btn_acos_clicked() {
  m_mainmodel->append(Calc_Alias::ACOS);
}
void MainWindow::on_btn_asin_clicked() {
  m_mainmodel->append(Calc_Alias::ASIN);
}
void MainWindow::on_btn_atan_clicked() {
  m_mainmodel->append(Calc_Alias::ATAN);
}
