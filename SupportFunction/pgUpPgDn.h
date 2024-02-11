#define pgUp 72
#define pgDn 80
#define EK (-32)
#define enter 13
char klik, sk;
int j;

void choiceMenu3(int awal, int akhir, int *x){
    j = *x;
    klik = getch();

    if(klik == EK ){
        sk = getch();
        if (sk == pgUp){
            j-=3;
        }else if(sk == pgDn){
            j+=3;
        }
    }

    if(j > akhir){
        j-=3;
    }else if(j < awal){
        j+=3;
    }
    *x = j;
}

void choiceMenu2(int awal, int akhir, int *x){
    j = *x;
    klik = getch();

    if(klik == EK ){
        sk = getch();
        if (sk == pgUp){
            j-=2;
        }else if(sk == pgDn){
            j+=2;
        }
    }

    if(j > akhir){
        j-=2;
    }else if(j < awal){
        j+=2;
    }
    *x = j;
}

void choiceMenu1(int awal, int akhir, int *x){
    j = *x;
    klik = getch();

    if(klik == EK ){
        sk = getch();
        if (sk == pgUp){
            j-=1;
        }else if(sk == pgDn){
            j+=1;
        }
    }

    if(j > akhir){
        j-=1;
    }else if(j < awal){
        j+=1;
    }
    *x = j;
}