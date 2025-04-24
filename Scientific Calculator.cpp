#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

void show_calculator() {
    cout << "-----------------------------------------\n";
    cout << "-            SCIENTIFIC CALCULATOR      -\n";
    cout << "-----------------------------------------\n";
    cout << "-   + : Add       |  - : Subtract       -\n";
    cout << "-   * : Multiply  |  / : Divide         -\n";
    cout << "-   m : Modulo    |  L : Logarithm      -\n";
    cout << "-   S : Square    |  C : Cube           -\n";
    cout << "-   p : Power     |  s : Sin            -\n";
    cout << "-   c : Cos       |  t : Tan            -\n";
    cout << "-   r : Root      |  k : Clear          -\n";
    cout << "-   . : Exit                             -\n";
    cout << "-----------------------------------------\n";
}

void display_output(double answer) {
    cout << "-----------------------------------------\n";
    cout << "-          CURRENT OUTPUT IS: " << answer << "         -\n";
    cout << "-----------------------------------------\n";
    show_calculator();
}

int main() {
    double num1 = 0.0, num2 = 0.0, answer = 0.0;
    char inp = '\n';
    bool converter = false;

    while (inp != '.') {
        if (converter) {
            display_output(answer);
            cout << "Enter operation: ";
            cin >> inp;

            if (inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'p') {
                num1 = answer;
                cout << "Enter num2: ";
                cin >> num2;
            } else if (inp == 'k' || inp == '.') {

            } else {
                num1 = answer;
            }

        } else {
            show_calculator();
            cout << "Enter operation: ";
            cin >> inp;

            if (inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'p') {
                cout << "Enter num1: ";
                cin >> num1;
                cout << "Enter num2: ";
                cin >> num2;
            } else if (inp == 'k' || inp == '.') {
                // No extra input needed
            } else {
                cout << "Enter num1: ";
                cin >> num1;
            }

            converter = true;
        }

        switch (inp) {
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero!\n";
                    answer = 0;
                } else {
                    answer = num1 / num2;
                }
                break;
            case 'm':
                answer = int(num1) % int(num2);
                break;
            case 'L':
                if (num1 <= 0) {
                    cout << "Error: Logarithm of non-positive number!\n";
                    answer = 0;
                } else {
                    answer = log10(num1);
                }
                break;
            case 'S':
                answer = num1 * num1;
                break;
            case 'C':
                answer = num1 * num1 * num1;
                break;
            case 'p':
                answer = pow(num1, num2);
                break;
            case 's':
                answer = sin(num1);
                break;
            case 'c':
                answer = cos(num1);
                break;
            case 't':
                answer = tan(num1);
                break;
            case 'r':
                if (num1 < 0) {
                    cout << "Error: Cannot take square root of negative number!\n";
                    answer = 0;
                } else {
                    answer = sqrt(num1);
                }
                break;
            case 'k':
                converter = false;
                break;
            case '.':
                break;
            default:
                cout << "~~~~ You Entered Invalid Operation! ~~~~\n";
        }

        system("cls");
    }

    return 0;
}
