#ifndef BS_CALCULATOR_CONTROLLER_HPP
#define BS_CALCULATOR_CONTROLLER_HPP
#include <string>
#include <vector>
namespace bs {
class CalculatorController {
public:
  /**
   * @brief Default constructor.
   */
  CalculatorController() = default;
  /**
   * @brief Default destructor.
   */
  ~CalculatorController() = default;

  void AddCharacter(char c);
  void RemoveCharacter();
  void DeleteExpression();
  std::vector<std::string> Calculate();
  void SetFlag(bool flag);
  bool GetFlag();
  std::string GetExpression();
  std::string GetDisplayExpression();
  std::string GetDisplayExpression(std::string);
  std::string error;

private:
  std::string expression;
  bool bFlag;
};
} // namespace bs
#endif