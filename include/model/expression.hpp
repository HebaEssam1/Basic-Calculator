
#ifndef BS_EXPRESSION_HPP
#define BS_EXPRESSION_HPP

#include <string>
#include <vector>

namespace bs {
class Expression {
public:
  /**
   * @brief Default constructor.
   */
  Expression(std::string);
  /**
   * @brief Default destructor.
   */
  ~Expression() = default;

  void parse(std::string input);
  void evaluate();
  double GetResult();
  void AddtoHistory(std::string);
  std::vector<std::string> GetHistory();
  std::string error;
  bool double_operand;

private:
  std::string input;
  double result;
  std::vector<std::string> stack;
  static std::vector<std::string> history;
};
} // namespace bs

#endif