/*

================================================================

Copyright (c) 2025 Francesco Maresca @programmerhelloworld

Francesco Maresca's Calculator (C++ version 3.1)

This version handles expressions
================================================================

*/
#include <windows.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cctype>
#include <cmath>
#include <string>

#define CALC_FIELD 1001 // Textbox
#define ID_OK_BUTTON 1 // Id button "="
#define ID_ONE_BUTTON 2 // Id button "1"
#define ID_TWO_BUTTON 3 // Id button "2"
#define ID_THREE_BUTTON 4 // Id button "3"
#define ID_FOUR_BUTTON 5 // Id button "4"
#define ID_FIVE_BUTTON 6 // Id button "5"
#define ID_SIX_BUTTON 7 // Id button "6"
#define ID_SEVEN_BUTTON 8 // Id button "7"
#define ID_EIGHT_BUTTON 9 // Id button "8"
#define ID_NINE_BUTTON 10 // Id button "9"
#define ID_ZERO_BUTTON 11 // Id button "0"
#define ID_SUM_BUTTON 12 // Id button "+"
#define ID_SUB_BUTTON 13 // Id button "-"
#define ID_MULT_BUTTON 14 // Id button "*"
#define ID_DIV_BUTTON 15 // Id button "/"
#define ID_CANCEL_BUTTON 16 // Id button "CE"
#define ID_POINT_BUTTON 17 // Id button "."
#define ID_OPEN_PARENTHESIS_BUTTON 18
#define ID_CLOSE_PARENTHESIS_BUTTON 19
// Utility to check if the character is a digit
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to apply arithmetic operations
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Function to handle precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double evaluateExpression(const std::string &expression) {
    std::stack<double> values;  // Stack for numbers
    std::stack<char> ops;       // Stack for operators

    bool isNegative = false;    // Flag to handle negative numbers
    double decimalPlace = 0.1;  // Decimal place tracker for floating-point numbers

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // Skip whitespace
        if (isspace(c)) continue;

        // Handle negative numbers
        if (c == '-' && (i == 0 || expression[i - 1] == '(' || expression[i - 1] == '+' || expression[i - 1] == '-' || expression[i - 1] == '*' || expression[i - 1] == '/')) {
            isNegative = true;
            continue;  // Skip the current negative sign, it will be handled later
        }

        // If current character is a number or a decimal point
        if (isDigit(c) || c == '.') {
            double value = 0.0;

            // If it's a digit, build the integer part
            while (i < expression.length() && isDigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }

            // If a decimal point is found, handle fractional part
            if (i < expression.length() && expression[i] == '.') {
                i++;  // Skip the decimal point
                double decimalFactor = 1;

                while (i < expression.length() && isDigit(expression[i])) {
                    decimalFactor *= 10;
                    value += (expression[i] - '0') / decimalFactor;
                    i++;
                }
            }

            // Adjust for negative numbers
            if (isNegative) {
                value = -value;
                isNegative = false;
            }

            // Push the number onto the values stack
            values.push(value);

            i--; // Adjust for the extra increment inside the loop
        }
        // If current character is '('
        else if (c == '(') {
            ops.push(c);
        }
        // If current character is ')'
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op));
            }
            ops.pop(); // Pop '(' from stack
        }
        // If current character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op));
            }
            ops.push(c);
        }
    }

    // Apply remaining operators
    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(val1, val2, op));
    }

    return values.top();
}

// Function to handle calculator input and perform calculations
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    static char currentInput[100] = "";

    switch (Message) {
        case WM_COMMAND:
            if (LOWORD(wParam) == ID_OK_BUTTON) {
            	std::cout << currentInput << " = ";
                // Evaluate the expression
                double result = evaluateExpression(currentInput);
                std::cout << result << "\n";
                sprintf(currentInput, "%g", result);
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            } else if (LOWORD(wParam) == ID_CANCEL_BUTTON) {
                strcpy(currentInput, "");
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            } else {
                // Button presses for numbers and operators
                char buttonChar = '\0';
                if (LOWORD(wParam) >= ID_ONE_BUTTON && LOWORD(wParam) <= ID_NINE_BUTTON) {
                    buttonChar = '0' + (LOWORD(wParam) - ID_ONE_BUTTON + 1);
                } else if (LOWORD(wParam) == ID_ZERO_BUTTON) {
                    buttonChar = '0';
                } else if (LOWORD(wParam) == ID_SUM_BUTTON) {
                    buttonChar = '+';
                } else if (LOWORD(wParam) == ID_SUB_BUTTON) {
                    buttonChar = '-';
                } else if (LOWORD(wParam) == ID_MULT_BUTTON) {
                    buttonChar = '*';
                } else if (LOWORD(wParam) == ID_DIV_BUTTON) {
                    buttonChar = '/';
                } else if (LOWORD(wParam) == ID_POINT_BUTTON) {
                    buttonChar = '.';
                } else if (LOWORD(wParam) == ID_OPEN_PARENTHESIS_BUTTON) {
                    buttonChar = '(';
                } else if (LOWORD(wParam) == ID_CLOSE_PARENTHESIS_BUTTON) {
                    buttonChar = ')';
                }

                if (buttonChar != '\0') {
                    strcat(currentInput, &buttonChar);
                    SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
                }
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}

// WINDOW
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = "WindowClass";
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	std::cout << "###################################################################\n";
	std::cout << "##                                                               ##\n";
	std::cout << "##            Francesco Maresca's Marescalc Calculator           ##\n";
	std::cout << "##                      Operations console                       ##\n";
	std::cout << "##            	Copyright (c) 2025, Francesco Maresca            ##\n";
	std::cout << "##                                                               ##\n";
	std::cout << "###################################################################\n\n\n";
	
	
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Window settings
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "Marescalc", WS_VISIBLE | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU,
                          CW_USEDEFAULT, CW_USEDEFAULT, 250, 470, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Creation of a text field
    CreateWindowExW(WS_EX_PALETTEWINDOW, L"Edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_LEFT | ES_AUTOVSCROLL, 20, 30, 115, 20, hwnd, (HMENU)CALC_FIELD, hInstance, NULL);


	// Creation of buttons , text ,                                                      , x , y , w, h
    CreateWindowW(L"BUTTON", L"=", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 165, 5, 40, 40, hwnd, (HMENU)ID_OK_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"CE", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 165, 50, 40, 40, hwnd, (HMENU)ID_CANCEL_BUTTON, hInstance, NULL);

    CreateWindowW(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 100, 50, 50, hwnd, (HMENU)ID_ONE_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 90, 100, 50, 50, hwnd, (HMENU)ID_TWO_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 160, 100, 50, 50, hwnd, (HMENU)ID_THREE_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 170, 50, 50, hwnd, (HMENU)ID_FOUR_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 90, 170, 50, 50, hwnd, (HMENU)ID_FIVE_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"6", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 160, 170, 50, 50, hwnd, (HMENU)ID_SIX_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"7", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 240, 50, 50, hwnd, (HMENU)ID_SEVEN_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"8", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 90, 240, 50, 50, hwnd, (HMENU)ID_EIGHT_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"9", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 160, 240, 50, 50, hwnd, (HMENU)ID_NINE_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"0", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 90, 310, 50, 50, hwnd, (HMENU)ID_ZERO_BUTTON, hInstance, NULL);

    CreateWindowW(L"BUTTON", L"+", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 28, 370, 35, 35, hwnd, (HMENU)ID_SUM_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"-", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 63, 370, 35, 35, hwnd, (HMENU)ID_SUB_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"*", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 98, 370, 35, 35, hwnd, (HMENU)ID_MULT_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"/", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 133, 370, 35, 35, hwnd, (HMENU)ID_DIV_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L".", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 168, 370, 35, 35, hwnd, (HMENU)ID_POINT_BUTTON, hInstance, NULL);

    // Create parentheses buttons
    CreateWindowW(L"BUTTON", L"(", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 310, 50, 50, hwnd, (HMENU)ID_OPEN_PARENTHESIS_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L")", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 160, 310, 50, 50, hwnd, (HMENU)ID_CLOSE_PARENTHESIS_BUTTON, hInstance, NULL);

    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
