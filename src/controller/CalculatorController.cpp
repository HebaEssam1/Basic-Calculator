#include <iostream>

#include <include/controller/CalculatorController.hpp>
#include <include/model/expression.hpp>
#include <string>
#include <vector>

using namespace bs;

void CalculatorController::AddCharacter(char c) {
  if (expression.empty()) {
    expression = c;
  } else {
    expression += c;
  }
}

void CalculatorController::RemoveCharacter() {
  if (!expression.empty()) {
    expression.pop_back();
  }
}
void CalculatorController::DeleteExpression() { expression = ""; }

std::vector<std::string> CalculatorController::Calculate() {
  error = "";
  Expression exp = Expression(expression);
  exp.error = "";
  exp.double_operand = false;
  exp.parse(expression);
  if (exp.error != "") {
    error = exp.error;
    std::cout << error << std::endl;
    return exp.GetHistory();
  }
  exp.evaluate();
  if (exp.error != "") {
    error = exp.error;
    return exp.GetHistory();
  }
  exp.AddtoHistory(expression);
  double result = exp.GetResult();
  int temp = result;
  if (result - temp != 0) {
    expression = std::to_string(exp.GetResult());
  } else {
    expression = std::to_string(temp);
  }

  return exp.GetHistory();
  // std::cout << expression << std::endl;
}

void CalculatorController::SetFlag(bool flag) { bFlag = flag; }

bool CalculatorController::GetFlag() { return bFlag; }

std::string CalculatorController::GetDisplayExpression() {
  std::string display = expression;
  for (size_t i = 0; i < display.size(); i++) {
    if (display[i] == '/') {
      display.replace(i, 1, "÷");
    } else if (display[i] == '*') {
      display.replace(i, 1, "×");
    } else if (display[i] == 'm') {
      display.replace(i, 1, "mod");
    }
  }
  return display;
}
std::string CalculatorController::GetDisplayExpression(std::string input) {
  std::string display = input;
  for (size_t i = 0; i < display.size(); i++) {
    if (display[i] == '/') {
      display.replace(i, 1, "÷");
    } else if (display[i] == '*') {
      display.replace(i, 1, "×");
    } else if (display[i] == 'm') {
      display.replace(i, 1, "mod");
    }
  }
  return display;
}