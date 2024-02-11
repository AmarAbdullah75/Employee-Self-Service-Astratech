#define backspace 8
#define enter 13
#define pgUp 72


COORD Coord = {0, 0};

void coord(int x, int y) {
    Coord.X = x;
    Coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
}

//  Mengambil Inputan Usr
void getStr(char text[], int max) {
    char press;
    int i = 0;
    while (1) {
        press = getch();
        if (press == backspace) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (press == enter) {
            if (i != 0) {
                break;
            }
        } else {
            if (i < max) {
                printf("%c", press);
                text[i++] = press;
            }
        }
        text[i] = '\0';
    }
}

void getAlphabet(char text[], int max) {
    char press;
    int i = 0;
    while (1) {
        press = getch();
        if (isalpha(press) || press == ' ') {
            if (i < max) {
                printf("%c", press);
                text[i++] = press;
            }
        } else if (press == backspace) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (press == enter) {
            if (i != 0) {
                break;
            }
        }
    }
    text[i] = '\0';
}

void getInt(int *num, int max) {
    char input[max], press;
    int i = 0;
    while (1) {
        press = getch();
        if (isdigit(press)) {
            if (i < max) {
                printf("%c", press);
                input[i++] = press;
            }
        } else if (press == backspace) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (press == enter) {
            if (i != 0) {
                break;
            }
        }
    }
    input[i] = '\0';
    *num = atoi(input);
}

void getNum(char text[], int max) {
    char press;
    int i = 0;
    while (1) {
        press = getch();
        if (isdigit(press)) {
            if (i < max) {
                printf("%c", press);
                text[i++] = press;
            }
        } else if (press == backspace) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (press == enter) {
            if (i != 0) {
                break;
            }
        }
    }
    text[i] = '\0';
}
//  Mengambil Inputan Usr


//  Menampilkan Output Value
void setChr(char kar) {
    printf("%c", kar);
}

void setFlt(float dcml) {
    printf("%.2f", dcml);
}

void setInt(int num) {
    printf("%d", num);
}
//  Menampilkan Output


//  Mengambil Password
void getPss(char pass[], int max) {
    char press;
    int num = 0;

    while (1) {
        press = getch();
        if (press == backspace) {
            if (num > 0) {
                printf("\b \b");
                num--;
            }
        } else if (press == enter) {
            if (num != 0) {
                break;
            }
        } else {
            if (num < max) {
                pass[num++] = press;
                printf("*");
            }
        }
    }
    pass[num] = '\0';
}
//  Mengambil Password

//  Print Coord
void coorPrint(int x, int y, char klmt[]) {
    coord(x, y);
    printf("%s", klmt);
}
//  Print Coord

//  Print ASCII
void ascPrint(int x, int y, int code) {
    coord(x, y);
    printf("%c", code);
}
//  Print ASCII

//  Print File
void printFile(int x, int y, char file[]) {
    FILE *emp;
    char n[200];
    int i = 0;
    emp = fopen(file, "r");

    while (fgets(n, sizeof(n), emp) != NULL) {
        coorPrint(x, y + i, n);
        i++;
    }
    fclose(emp);
}
//  Print File

//  Print File Menu
void printMenu(int x, int y, char file[], int c) {
    FILE *emp;
    char n[200];
    int i = 10;
    emp = fopen(file, "r");

    while (fgets(n, sizeof(n), emp) != NULL) {
        if (c) {
            coorPrint(x, y, n);
        }
//        i+=3;
    }
    fclose(emp);
}

void HPrintUI(int HLOOP, int HCODE, int Hx, int Hy) {
    for (int Hi = 1; Hi < HLOOP; Hi++) {
        coord(Hx + Hi, Hy);
        printf("%c", HCODE);
    }
}