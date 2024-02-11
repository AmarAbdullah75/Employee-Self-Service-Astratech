void display(){
    system("color 4f");
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);

    DEVMODE dm;
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);

    dm.dmPelsWidth = 1920;  // Set your desired width
    dm.dmPelsHeight = 1080; // Set your desired height

    LONG result = ChangeDisplaySettings(&dm, 0);
    if (result != DISP_CHANGE_SUCCESSFUL) {
        fprintf(stderr, "Failed to change display settings\n");
    }
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Mengubah kursor menjadi panah
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    cursorInfo.dwSize = 100;  // ukuran kursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    printf("\\e[?25h");
    printf("\\e[?1c");
}