#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int current = 0;
    char inputstr[10], c;

    cout << "Enter a string: ";
    cin >> inputstr;

    int i = 0;
    while (i < strlen(inputstr)) {
        c = inputstr[i];
        switch (current) {
            case 0:
                if (c == '0') {
                    inputstr[i] = 'X';
                    i++;
                    current = 1;
                } else if (c == 'Y') {
                    i++;
                    current = 3;
                } else {
                    current = -1;  // Invalid character
                }
                break;

            case 1:
                if (c == '0') {
                    i++;
                    current = 1;
                } else if (c == 'Y') {
                    i++;
                    current = 1;
                } else if (c == '1') {
                    inputstr[i] = 'Y';
                    i--;
                    current = 2;
                }
                break;

            case 2:
                if (c == '0') {
                    i--;
                    current = 2;
                } else if (c == 'Y') {
                    i--;
                    current = 2;
                } else if (c == 'X') {
                    i++;
                    current = 0;
                } else {
                    current = -1;  // Invalid character
                }
                break;

            case 3:
                if (c == 'Y') {
                    i++;
                    current = 3;
                } else if (c == '\0') {
                    current = 4;  // Accepted state
                } else { 
                    current = -1;  // Invalid character
                }
                break;
        }

        if (current == -1) {
            cout << "Rejected string" << endl;
            return 0;
        }
    }

    // Check if final state is accepting (current == 4)
    if (current == 3 || current == 4) {
        cout << "Accepted string" << endl;
    } else {
        cout << "Rejected string" << endl;
    }

    return 0;
}

