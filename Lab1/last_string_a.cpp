//DFA that accepts strings where the last character is 'a
#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
    string name;
    bool final = false;
    Node* a = NULL;
    Node* b = NULL;
} node;

class DFA {
public:
    node q0, q1;
    Node* current;

    DFA() {
        // Initialize states
        q0.name = "q0";
        q1.name = "q1";

        // Set transitions
        q0.a = &q1; // Transition from q0 to q1 on 'a'
        q0.b = &q0; // Transition from q0 to q0 on 'b'
        q1.a = &q1; // Transition from q1 to q1 on 'a'
        q1.b = &q0; // Transition from q1 to q0 on 'b'

        // Set final state
        q1.final = true;

        // Set initial state
        current = &q0;
    }

    bool test(string input) {
        // Reset to initial state for each test
        current = &q0;

        // Process each character in the input string
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (c == 'a') {
                current = current->a;
            } else if (c == 'b') {
                current = current->b;
            } else {
                // Invalid character
                return false;
            }
        }

        // Check if the final state is reached
        return current->final;
    }
};

int main() {
    DFA obj;
    string input;

    cout << "Enter an input: ";
    cin >> input;

    bool result = obj.test(input);
    if (result) {
        cout << input << " is accepted" << endl;
    } else {
        cout << input << " is not accepted" << endl;
    }

    return 0;
}
