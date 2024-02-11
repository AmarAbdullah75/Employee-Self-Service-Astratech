void console(int *lebar, int *tinggi){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);

    *lebar = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *tinggi = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int lebar, tinggi;

void cleanRight(){
    console(&lebar, &tinggi);
    for (int i = 0; i < lebar; ++i) {
        for (int j = 0; j < tinggi; ++j) {
            coorPrint(i, j, " ");
        }
    }
}

void cleanLeft(){
    console(&lebar, &tinggi);
    for(int i = lebar - 1; i >= 0; i--){
        for(int j = tinggi - 1; j >= 0; j --){
            coorPrint(i, j, " ");
        }
    }
}

void cleanField(){
    console(&lebar, &tinggi);
    for (int i = 31; i < lebar-1; ++i) {
        for (int j = 1; j < tinggi-1; ++j) {
            coorPrint(i, j, " ");
        }
    }
}

void cleanMenu(){
    console(&lebar, &tinggi);
    for (int i = 2; i < 30; ++i) {
        for (int j = 5; j < tinggi-6; ++j) {
            coorPrint(i, j, " ");
        }
    }
}