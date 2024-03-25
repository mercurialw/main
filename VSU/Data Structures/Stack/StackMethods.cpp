#include "Stack.h"

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    clear();
}

void Stack::push(int elem) {
    Node* p = new Node(elem);
    p->next = top;
    top = p;
}

void Stack::pop() {
    Node* p = top;
    top = top->next;

    p->next = nullptr;
    delete p;
}

int Stack::peak() {
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

int evalPostfixExpression(std::string const & expression) {
    Stack stack;
    bool is_only_space = 1;

    for (char c: expression) {

        if (std::isspace(c)) { // Случай с пробелом
            continue; 
        }
        else if (std::isdigit(c)) { // Случай с цифрой
            int number = 0;

            while (std::isdigit(c)) { // Если цифр несколько
                number = number * 10 + (c - '0');
                ++i;
                c = expression[i];
            }
            is_only_space = 0;
            stack.push(number);
        }
        else { // Случай с операцией
            if (stack.isEmpty()) {
                std::cout << "Expression error, change it. ";
                return 0;
            }
            int operand2 = stack.peak();
            stack.pop();
            if (stack.isEmpty()) {
                std::cout << "Expression error, change it. ";
                return 0;
            }
            int operand1 = stack.peak();
            stack.pop();

            switch (c) {
            case '+':
                stack.push(operand1 + operand2);
                break;
            case '-':
                stack.push(operand1 - operand2);
                break;
            case '*':
                stack.push(operand1 * operand2);
                break;
            default:
                std::cout << "Invalid character: " << c << std::endl;
                return 0;
            }
            is_only_space = 0;
        }
    }
    if (is_only_space) {
        std::cout << "There is only space. ";
        return 0;
    }
    else {
        int n = stack.peak();
        stack.pop();
        if (!stack.isEmpty())
            std::cout << "2+ numbers in stack, last is ";
        return n;
    }
}