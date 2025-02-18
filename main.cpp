WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 160, 240, 50, 50, hwnd, (HMENU)ID_NINE_BUTTON, hInstance, NULL);
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
