// DFA that accepts strings with an even number of 1's and an even number of 0's
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    bool final;
    Node* zero;
    Node* one;

    Node(string n, bool f) : name(n), final(f), zero(nullptr), one(nullptr) {}
};

class DFA {
public:
    Node q0, q1, q2, q3;
    Node* current;

    DFA() : q0("q0", true), q1("q1", false), q2("q2", false), q3("q3", false) {
        q0.zero = &q1;
        q0.one = &q2;

        q1.zero = &q0;
        q1.one = &q3;

        q2.zero = &q3;
        q2.one = &q0;

        q3.zero = &q2;
        q3.one = &q1;

        current = &q0;
    }

    bool test(const string& input) {
        for (char c : input) {
            if (c == '0') {
                current = current->zero;
            } else if (c == '1') {
                current = current->one;
            }
        }
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
