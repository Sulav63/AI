#include <iostream>
#include <string>

using namespace std;  

// Function to recursively generate and print derivations
void derive(string current, int depth) {
    if (depth == 0) {
        cout << current << endl;
        return;
    }

    // Replace S with 'aSb'
    derive("a" + current + "b", depth - 1);

    // Replace S with epsilon (empty string)
    derive(current, depth - 1);
}

int main() {
    int depth;

    cout << "Enter the maximum depth of derivation: ";
    cin >> depth;

    cout << "Derivations:" << endl;
    derive("", depth);

    return 0;
}

