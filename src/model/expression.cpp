#include <cmath>
#include <include/model/expression.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace bs {
std::vector<std::string> Expression::history;
Expression::Expression(std::string in) : input(in) {}
void Expression::parse(std::string input) {
  for (int i = 0; i < input.length(); i++) {
    char ch = input[i];
    if (i == input.length() - 1 && !isdigit(ch) && ch != '%') {
      error = "Malformed expression";
      cout << error << endl;
      return;
    }
    if (isdigit(ch)) {
      double_operand = false;
      string num;
      while (i < input.length() && (isdigit(input[i]) || input[i] == '.')) {
        num += input[i++];
      }
      i--;
      stack.push_back(num);
    }

    else {
      if (double_operand) {
        error = "Malformed expression";
        cout << error << endl;
        return;
      }
      double_operand = true;
      stack.push_back(std::string(1, ch));
    }
  }
}
int getPrecedence(char op) {
  if (op == '+' || op == '-') {
    return 1;
  }
  if (op == '*' || op == '/' || op == '%') {
    return 2;
  }
  return 0;
}
double applyOp(double a, double b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  case 'm':
    return std::fmod(a, b);
  default:
    return 0;
  }
}

void Expression::evaluate() {
  std::vector<double> values;
  std::vector<char> ops;
  // std::cout << "inside 2 " << input << std::endl;
  for (size_t i = 0; i < stack.size(); i++) {
    string token = stack[i];

    if (token == "(") {
      ops.push_back('(');

    } else if (token == ")") {
      while (ops.back() != '(') {
        double b = values.back();
        values.pop_back();
        double a = values.back();
        values.pop_back();
        char op = ops.back();
        ops.pop_back();
        if (op == '/' && b == 0) {
          error = "Division by zero is undefined";
          cout << "error" << endl;
        } else
          values.push_back(applyOp(a, b, op));
      }
      ops.pop_back();

    } else if (token == "+" || token == "-" || token == "*" || token == "/" ||
               token == "%") {
      char cur = token[0];
      while (!ops.empty() && getPrecedence(ops.back()) >= getPrecedence(cur)) {
        double b = values.back();
        values.pop_back();
        double a = values.back();
        values.pop_back();
        char op = ops.back();
        ops.pop_back();
        if (op == '/' && b == 0) {
          error = "Division by zero is undefined";
          cout << "error" << endl;
        } else
          values.push_back(applyOp(a, b, op));
      }
      ops.push_back(cur);

    } else {
      // it's a number
      values.push_back(std::stod(token));
    }
  }
  // apply remaining operators
  while (!ops.empty()) {
    double b = values.back();
    values.pop_back();
    double a = values.back();
    values.pop_back();
    char op = ops.back();
    ops.pop_back();
    if (op == '/' && b == 0) {
      error = "Division by zero is undefined";
      cout << "error" << endl;

    } else
      values.push_back(applyOp(a, b, op));
  }
  result = values.back();
}
double Expression::GetResult() { return result; }
void Expression::AddtoHistory(std::string in) {
  if (history.size() >= 6) {
    std::cout << history.size() << std::endl;
    for (int i = 5; i > 0; i--) {
      history[i] = history[i - 1];
    }
    history[0] = in;
  } else if (history.empty()) {
    std::cout << in << std::endl;
    history.push_back(in);
  } else {
    history.push_back(history[history.size() - 1]);
    for (int i = history.size() - 1; i > 0; i--) {
      history[i] = history[i - 1];
    }
    history[0] = in;
    // std::cout << "second" << in << std::endl;
  }
}
std::vector<string> Expression::GetHistory() { return history; }
} // namespace bs
