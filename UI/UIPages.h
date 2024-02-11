#include "../SupportFunction/IOVal.h"
#include "../SupportFunction/Transisi.h"
int i, Lebar, Tinggi;

void uiLogin(){
    console(&Lebar, &Tinggi);
    for (i = 1; i < Lebar-1; ++i) {
        ascPrint(i, 0, 205);
        ascPrint(i, Tinggi-1, 205);
    }
    ascPrint(0, 0, 201);
    ascPrint(Lebar-1, 0, 187);

    for (i = 1; i < Tinggi-1; ++i) {
        ascPrint(0, i, 186);
        ascPrint(Lebar-1, i, 186);
    }
    ascPrint(0, Tinggi-1, 200);
    ascPrint(Lebar-1, Tinggi-1, 188);

    printFile(3, 3, "fileTxt/Gambar/Employee.txt");
    printFile(57, 10, "fileTxt/Gambar/Login.txt");
    printFile(105, 5, "fileTxt/Gambar/ess.txt");
    printFile(20, 30, "fileTxt/Gambar/TulisanESSA.txt");


    for (i = 1; i < 60; ++i) {
        ascPrint(i, Tinggi/2, 205);
    }
    for (i = 95; i < Lebar-1; ++i) {
        ascPrint(i, Tinggi/2, 205);
    }
    ascPrint(0,Tinggi/2,204);
    ascPrint(Lebar-1,Tinggi/2,185);
    for (i = 1; i < 35; i++) {
        ascPrint(60+i, 17, 196);
        ascPrint(60+i, 27, 196);
    }

    for (i = 1; i < 10; ++i) {
        ascPrint(60, 17+i, 186);
        ascPrint(95, 17+i, 186);
    }
    ascPrint(60, 17, 214);//  Kiri Atas
    ascPrint(60, 27, 211);//  Kiri Bawah
    ascPrint(95, 27, 189);//  Kanan Bawah
    ascPrint(95, 17, 183);//  Kanan Atas

    ascPrint(60,Tinggi/2,185);
    ascPrint(95,Tinggi/2,204);

}

void uiDashboard(){
    console(&Lebar, &Tinggi);
    for (i = 0; i < Tinggi; ++i) {
        ascPrint(30,0+i,186);
    }
    for (i = 1; i < Lebar-1; ++i) {
        ascPrint(i, 0, 205);
        ascPrint(i, Tinggi-1, 205);
    }
    ascPrint(0, 0, 201);
    ascPrint(Lebar-1, 0, 187);

    for (i = 1; i < Tinggi-1; ++i) {
        ascPrint(0, i, 186);
        ascPrint(Lebar-1, i, 186);
    }
    ascPrint(0, Tinggi-1, 200);
    ascPrint(Lebar-1, Tinggi-1, 188);

    ascPrint(30, 0, 203);
    ascPrint(30, Tinggi - 1, 202);

    for (i = 1; i < 30; ++i) {
        ascPrint(0+i, 4, 205);
    }
    ascPrint(30, 4, 185);
    ascPrint(0, 4, 204);

    for (i = 1; i < 30; ++i) {
        ascPrint(0+i, Tinggi - 4, 205);
    }
    ascPrint(30, Tinggi - 4, 185);
    ascPrint(0, Tinggi - 4, 204);
    coorPrint(8,Tinggi-6,"Tekan \"ENTER\"");
    coorPrint(5, Tinggi - 5,"untuk memilih menu!!");
}

void uiDashboard2(){
    console(&Lebar, &Tinggi);
    for (i = 0; i < Tinggi; ++i) {
        ascPrint(30,0+i,186);
    }
    for (i = 1; i < Lebar-1; ++i) {
        ascPrint(i, 0, 205);
        ascPrint(i, Tinggi-1, 205);
    }
    ascPrint(0, 0, 201);
    ascPrint(Lebar-1, 0, 187);

    for (i = 1; i < Tinggi-1; ++i) {
        ascPrint(0, i, 186);
        ascPrint(Lebar-1, i, 186);
        ascPrint(Lebar/2+10, i, 186);
    }
    ascPrint(0, Tinggi-1, 200);
    ascPrint(Lebar-1, Tinggi-1, 188);

    ascPrint(Lebar/2+10, 0, 203);
    ascPrint(30, 0, 203);
    ascPrint(30, Tinggi - 1, 202);
    ascPrint(Lebar/2+10, Tinggi - 1, 202);

    for (i = 1; i < 30; ++i) {
        ascPrint(0+i, 4, 205);
    }
    ascPrint(30, 4, 185);
    ascPrint(0, 4, 204);

    for (i = 1; i < 30; ++i) {
        ascPrint(0+i, Tinggi - 4, 205);
    }
    ascPrint(30, Tinggi - 4, 185);
    ascPrint(0, Tinggi - 4, 204);
    coorPrint(8,Tinggi-6,"Tekan \"ENTER\"");
    coorPrint(5, Tinggi - 5,"untuk memilih menu!!");
}
void uiUpdatePrz(){
    console(&Lebar, &Tinggi);

    for (i = 1; i < Lebar-1; ++i) {
        ascPrint(i, 0, 205);
        ascPrint(i, Tinggi-1, 205);
    }
    ascPrint(0, 0, 201);
    ascPrint(Lebar-1, 0, 187);

    for (i = 1; i < Tinggi-1; ++i) {
        ascPrint(0, i, 186);
        ascPrint(30,0+i,186);
        ascPrint(Lebar-38, i, 186);
        ascPrint(Lebar-1, i, 186);
    }
    ascPrint(0, Tinggi-1, 200);
    ascPrint(Lebar-1, Tinggi-1, 188);

    ascPrint(Lebar-38, 0, 203);
    ascPrint(30, 0, 203);
    ascPrint(30, Tinggi - 1, 202);
    ascPrint(Lebar-38, Tinggi - 1, 202);

    for (i = 1; i < 30; ++i) {
        ascPrint(0+i, 4, 205);
    }
    ascPrint(30, 4, 185);
    ascPrint(0, 4, 204);

    for (i = 1; i < 30; ++i) {
        ascPrint(0+i, Tinggi - 4, 205);
    }
    ascPrint(30, Tinggi - 4, 185);
    ascPrint(0, Tinggi - 4, 204);
    coorPrint(8,Tinggi-6,"Tekan \"ENTER\"");
    coorPrint(5, Tinggi - 5,"untuk memilih menu!!");
}
void uiCUser(){
    console(&Lebar, &Tinggi);
    for (i = 0; i < Tinggi; ++i) {
        ascPrint(30,0+i,186);
    }
    for (i = 1; i < Lebar-1; ++i) {
        ascPrint(i, 0, 205);
        ascPrint(i, Tinggi-1, 205);
    }
    ascPrint(0, 0, 201);
    ascPrint(Lebar-1, 0, 187);

    for (i = 1; i < Tinggi-1; ++i) {
        ascPrint(0, i, 186);
        ascPrint(Lebar-1, i, 186);
    }
    ascPrint(0, Tinggi-1, 200);
    ascPrint(Lebar-1, Tinggi-1, 188);

    ascPrint(30, 0, 203);
    ascPrint(30, Tinggi - 1, 202);

    ascPrint(30, 4, 185);
    ascPrint(0, 4, 204);

    for (int k = 0; k < Lebar - 32; ++k) {
        ascPrint(31+k, 18, 205);
    }
    ascPrint(30, 18, 204);
    ascPrint(Lebar-1, 18, 185);
    ascPrint(30, Tinggi - 4, 185);
    ascPrint(0, Tinggi - 4, 204);
    coorPrint(8,Tinggi-6,"Tekan \"ENTER\"");
    coorPrint(5, Tinggi - 5,"untuk memilih menu!!");
}
void UICreateUser() {
    for (i = 1; i < Lebar -1; ++i) {
        ascPrint(0 + i, 4, 205);
    }
    ascPrint(30, 4, 185);
    ascPrint(0, 4, 204);
    ascPrint(30, 4, 206);

    for (i = 0; i < Tinggi -1 ; ++i) {
        ascPrint(118 ,i,186);
    }
    ascPrint(118,4,206);
    ascPrint(118,0,203);
}

void uiProfile(){
    printFile(75, 3, "fileTxt/Gambar/iconProfile.txt");
}