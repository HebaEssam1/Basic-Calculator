
#include "model/expression.hpp"
#include <include/controller/CalculatorController.hpp>
#include <include/view/mainwindow.h>
#include <iostream>
#include <ui_Calculator.h>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }
// pressed brackets
void MainWindow::on_pushButton_14_clicked() {
  if (controller.GetFlag() == true) {
    controller.AddCharacter(')');
    controller.SetFlag(false);

  } else {
    controller.AddCharacter('(');
    controller.SetFlag(true);
  }
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed division
void MainWindow::on_pushButton_18_clicked() {
  controller.AddCharacter('/');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 9
void MainWindow::on_pushButton_5_clicked() {
  controller.AddCharacter('9');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 8
void MainWindow::on_pushButton_9_clicked() {
  controller.AddCharacter('8');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 7
void MainWindow::on_pushButton_11_clicked() {
  controller.AddCharacter('7');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed mod
void MainWindow::on_pushButton_13_clicked() {
  controller.AddCharacter('m');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed multiply
void MainWindow::on_pushButton_17_clicked() {
  controller.AddCharacter('*');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 6
void MainWindow::on_pushButton_4_clicked() {
  controller.AddCharacter('6');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 5
void MainWindow::on_pushButton_8_clicked() {
  controller.AddCharacter('5');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 4
void MainWindow::on_pushButton_clicked() {
  controller.AddCharacter('4');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed equal
void MainWindow::on_pushButton_20_clicked() {
  QTextEdit *historyEdits[] = {ui->textEdit_7, ui->textEdit_6, ui->textEdit_5,
                               ui->textEdit_4, ui->textEdit_3, ui->textEdit_2};
  std::vector<std::string> history = controller.Calculate();
  if (controller.error != "") {
    std::cout << controller.error << std::endl;
    ui->lineEdit->setText(QString::fromStdString(controller.error));
    return;
  }
  // std::cout << controller.GetDisplayExpression();
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  if (history.empty())
    return;
  for (int i = 0; i < history.size(); i++) {
    historyEdits[i]->setPlainText(
        QString::fromStdString(controller.GetDisplayExpression(history[i])));
  }
}
// pressed minuss
void MainWindow::on_pushButton_16_clicked() {
  controller.AddCharacter('-');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 3
void MainWindow::on_pushButton_3_clicked() {
  controller.AddCharacter('3');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 2
void MainWindow::on_pushButton_7_clicked() {
  controller.AddCharacter('2');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 1
void MainWindow::on_pushButton_12_clicked() {
  controller.AddCharacter('1');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed +
void MainWindow::on_pushButton_15_clicked() {
  controller.AddCharacter('+');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed %
void MainWindow::on_pushButton_2_clicked() {
  controller.AddCharacter('%');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed decimal
void MainWindow::on_pushButton_6_clicked() {
  controller.AddCharacter('.');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed 0
void MainWindow::on_pushButton_10_clicked() {
  controller.AddCharacter('0');
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
// pressed C
void MainWindow::on_pushButton_19_clicked() {
  controller.DeleteExpression();
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}

void MainWindow::on_textEdit_textChanged() {}

void MainWindow::on_textEdit_copyAvailable(bool b) {}

void MainWindow::on_commandLinkButton_clicked() {
  controller.RemoveCharacter();
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}

void MainWindow::on_pushButton_21_clicked() {
  controller.RemoveCharacter();
  ui->textEdit->setPlainText(
      QString::fromStdString(controller.GetDisplayExpression()));
  ui->lineEdit->setText(QString::fromStdString(""));
}
