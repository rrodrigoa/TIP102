#pragma once

#include <iostream>
#include <stack>

extern int indent_level;

// Simple console print functions for debugging
#define INDENT std::string(indent_level * 2, ' ')
#define INDENT_MORE() indent_level++
#define INDENT_LESS() indent_level--
#define DEBUG_VAR(var) std::cout << INDENT << "[DEBUG] " << __func__ << " (line " << __LINE__ << "): " << #var << " = " << (var) << std::endl;
#define DEBUG_MSG(msg) std::cout << INDENT << "[DEBUG] " << __func__ << " (line " << __LINE__ << "): " << msg << std::endl;
//int indent_level = 0;

// Template << operator for stack<T>
// Print stack as [elements..]
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::stack<T> s) {
    std::stack<T> s_copy = s;
    os << "[";
    while (s_copy.empty() == false) {
        if constexpr (std::is_pointer_v<T>) {
            if (s_copy.top() != nullptr)
                os << *(s_copy.top());
            else
                os << "nullptr";
        }
        else {
            if (s_copy.top() != nullptr)
                os << s_copy.top();
            else
                os << "nullptr";
        }

        s_copy.pop();

        if (s_copy.empty() == false)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
