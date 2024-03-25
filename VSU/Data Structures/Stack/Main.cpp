#include "Stack.h"
#include <vector>
using namespace std;

int main() {

    std::cout << evalPostfixExpression("1 2 + 5 *") << std::endl;
    std::cout << evalPostfixExpression("1 2 2") << std::endl;
    std::cout << evalPostfixExpression("  ") << std::endl;
    std::cout << evalPostfixExpression("") << std::endl;
    std::cout << evalPostfixExpression(" ") << std::endl;
    std::cout << evalPostfixExpression("+") << std::endl;
    std::cout << evalPostfixExpression("5 + 5 +") << std::endl;
    std::cout << evalPostfixExpression("()") << std::endl;
    return 0; 
}
