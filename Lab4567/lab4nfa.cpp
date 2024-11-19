#include <iostream>
#include <string>
using namespace std;

// Function to simulate the NFA
bool isAccepted(string str) {
    int state = 0; // Start at q0

    // Traverse the string
    for (int i = 0; i < str.length(); i++) {
        char input = str[i];

        switch (state) {
            case 0: // State q0
                if (input == '0') {
                    state = 0; // Stay at q0 on 0
                } else if (input == '1') {
                    state = 1; // Move to q1 on 1
                }
                break;

            case 1: // State q1
                if (input == '0' || input == '1') {
                    state = 2; // Move to q2 on any input
                }
                break;

            case 2: // State q2 (final state)
                if (input == '0' || input == '1') {
                    state = 2; // Stay at q2
                }
                break;
        }
    }

    // Accept if in state q2
    return state == 2;
}

int main() {
    string input;

    // Input the binary string
    cout << "Enter a binary string: ";
    cin >> input;

    // Check if the string is accepted by the NFA
    if (isAccepted(input)) {
        cout << "The string is accepted by the NFA." << endl;
    } else {
        cout << "The string is rejected by the NFA." << endl;
    }

    return 0;
}

