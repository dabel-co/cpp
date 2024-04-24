#include "RPN.hpp"

#include <stack>
#include <stdexcept>

int rpn(char *xpr) {
  std::stack<int> v;
  int a;
  int b;
  
  for (size_t i = 0; i < strlen(xpr); i++)
  {
        switch (xpr[i])
        {
        case '+':
        if (v.size() < 2)
            throw(std::out_of_range("invalid RPN expression : not enough operands for +"));
        a = v.top();
        v.pop();
        b = v.top();
        v.pop();
        v.push(b + a);
        break;

        case '-':
        if (v.size() < 2)
            throw(std::out_of_range("invalid RPN expression : not enough operands for -"));
        a = v.top();
        v.pop();
        b = v.top();
        v.pop();
        v.push(b - a);
        break;

        case '*':
        if (v.size() < 2)
            throw(std::out_of_range("invalid RPN expression : not enough operands for *"));
        a = v.top();
        v.pop();
        b = v.top();
        v.pop();
        v.push(b * a);
        break;

        case '/':
        if (v.size() < 2)
            throw(std::out_of_range("invalid RPN expression : not enough operands for /"));
        a = v.top();
        v.pop();
        b = v.top();
        v.pop();
        v.push(b / a);
        break;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        v.push(xpr[i] - '0');
        break;

        case ' ': {}
        break;

        default: {
            throw(std::runtime_error("invalid RPN expression : illegal character"));
        }
    }
  }
    if (v.size() != 1)
        throw(std::runtime_error("invalid RPN expression : values left in the stack"));
    return (v.top());
}
