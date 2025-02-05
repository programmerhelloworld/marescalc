/*
================================================================
Copyright (c) 2025 Francesco Maresca @programmerhelloworld

Francesco Maresca's Calculator (C++ version 1)

================================================================
*/
#include <windows.h>
#include <cstdio>
#include <cstring>


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

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    static double n1 = 0, n2 = 0, result = 0;
    static char currentInput[100] = "";
    static bool isOperatorClicked = false;
    static char operatorClicked = '\0';

    switch (Message) {
        case WM_COMMAND:
       
        // Button "1"
            if (LOWORD(wParam) == ID_ONE_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "1");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "1");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
            // Button "2"
            else if (LOWORD(wParam) == ID_TWO_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "2");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "2");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "3"
            else if (LOWORD(wParam) == ID_THREE_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "3");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "3");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "4"
            else if (LOWORD(wParam) == ID_FOUR_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "4");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "4");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "5"
            else if (LOWORD(wParam) == ID_FIVE_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "5");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "5");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "6"
            else if (LOWORD(wParam) == ID_SIX_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "6");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "6");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "7"
            else if (LOWORD(wParam) == ID_SEVEN_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "7");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "7");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "8"
            else if (LOWORD(wParam) == ID_EIGHT_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "8");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "8");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "9"
            else if (LOWORD(wParam) == ID_NINE_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "9");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "9");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "0"
            else if (LOWORD(wParam) == ID_ZERO_BUTTON) {
                if (isOperatorClicked) {
                    strcpy(currentInput, "0");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, "0");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
            }
           
            // Button "+"
            else if (LOWORD(wParam) == ID_SUM_BUTTON) {
                n1 = atof(currentInput);
                operatorClicked = '+';
                currentInput[0] = '\0';
                isOperatorClicked = true;
            }
           
            // Button "-"
            else if (LOWORD(wParam) == ID_SUB_BUTTON) {
                n1 = atof(currentInput);
                operatorClicked = '-';
                currentInput[0] = '\0';
                isOperatorClicked = true;
            }
           
            // Button "*"
            else if (LOWORD(wParam) == ID_MULT_BUTTON) {
                n1 = atof(currentInput);
                operatorClicked = '*';
                currentInput[0] = '\0';
                isOperatorClicked = true;
            }
           
            // Button "/"
            else if (LOWORD(wParam) == ID_DIV_BUTTON) {
                n1 = atof(currentInput);
                operatorClicked = '/';
                currentInput[0] = '\0';
                isOperatorClicked = true;
            }
           
            // Button "="
            else if (LOWORD(wParam) == ID_OK_BUTTON) {
                n2 = atof(currentInput);
                switch (operatorClicked) {
                    case '+':
                        result = n1 + n2;
                        break;
                    case '-':
                        result = n1 - n2;
                        break;
                    case '*':
                        result = n1 * n2;
                        break;
                    case '/':
                        if (n2 != 0)
                            result = n1 / n2;
                        else
                            MessageBox(hwnd, "Cannot divide by zero", "Error", MB_ICONEXCLAMATION | MB_OK);
                        break;
                }
                sprintf(currentInput, "%f", result);
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
                n1 = result; // Store result for further operations
                operatorClicked = '\0'; // Reset operator
            }
           
            // Button "CE"
            else if (LOWORD(wParam) == ID_CANCEL_BUTTON) {
                strcpy(currentInput, "");
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
                n1 = n2 = result = 0; // Reset all values
                operatorClicked = '\0';
            }
           
            // Button "."
else if (LOWORD(wParam) == ID_POINT_BUTTON){
if (isOperatorClicked) {
                    strcpy(currentInput, ".");
                    isOperatorClicked = false;
                } else {
                    strcat(currentInput, ".");
                }
                SetWindowText(GetDlgItem(hwnd, CALC_FIELD), currentInput);
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

    CreateWindowW(L"BUTTON", L"+", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 370, 40, 40, hwnd, (HMENU)ID_SUM_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"-", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 70, 370, 40, 40, hwnd, (HMENU)ID_SUB_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"*", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 120, 370, 40, 40, hwnd, (HMENU)ID_MULT_BUTTON, hInstance, NULL);
    CreateWindowW(L"BUTTON", L"/", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 170, 370, 40, 40, hwnd, (HMENU)ID_DIV_BUTTON, hInstance, NULL);
CreateWindowW(L"BUTTON", L".", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 170, 320, 40, 40, hwnd, (HMENU)ID_POINT_BUTTON, hInstance, NULL);
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
