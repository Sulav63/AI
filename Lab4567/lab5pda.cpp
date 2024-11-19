#include <iostream>
#include <stack>
#include <cstring> // For C-style string functions

using namespace std;

class PDA {
public:
    bool processString(const char* input) {
        stack<char> stack;
        bool seenB = false;

        int len = strlen(input); // Get the length of the C-style string
        for (int i = 0; i < len; ++i) {
            char ch = input[i];
            if (ch == 'a') {
                if (seenB) {
                    // If we've started seeing 'b', we should not see 'a' again (e.g., "abab")
                    return false;
                }
                // Push 'a' onto the stack
                stack.push(ch);
            } else if (ch == 'b') {
                seenB = true;
                // Pop 'a' from the stack if there is one
                if (stack.empty() || stack.top() != 'a') {
                    return false; // More 'b's than 'a's or unmatched 'b' (e.g., "abbb" or "baba")
                }
                stack.pop();
            } else {
                // Invalid character
                return false;
            }
        }

        // The string is accepted if the stack is empty
        return stack.empty();
    }
};

int main() {
    PDA pda;
    char input[100]; // Character array for C-style input strings
    
    cout << "Enter a string of 'a's followed by 'b's: ";
    cin >> input; // Use cin to read the C-style string
    
    if (pda.processString(input)) {
        cout << "The string is of the form a^n b^n.\n";
    } else {
        cout << "The string is not of the form a^n b^n.\n";
    }
    
    return 0;
}

