int Lebar, Tinggi;
void box(int x, int y) {
    for (i = 0; i < 20; ++i) {
        ascPrint(x + i, y-1, 196);
        ascPrint(x + i, y+1, 196);
    }
    ascPrint(x, y+1, 192);//    Kiri bawah
    ascPrint(x+20, y+1, 217);//    Kanan bawah
    ascPrint(x, y-1, 218);//    Kiri atas
    ascPrint(x+20, y-1, 191);//    Kanan atas
    ascPrint(x, y, 179);//  Kiri tengah
    ascPrint(x+20, y, 179);//    Kanan tengah
}

void box2(int x, int y) {
    for (i = 0; i < 25; ++i) {
        ascPrint(x + i, y-1, 196);
        ascPrint(x + i, y+1, 196);
    }
    ascPrint(x, y+1, 192);//    Kiri bawah
    ascPrint(x+25, y+1, 217);//    Kanan bawah
    ascPrint(x, y-1, 218);//    Kiri atas
    ascPrint(x+25, y-1, 191);//    Kanan atas
    ascPrint(x, y, 179);//  Kiri tengah
    ascPrint(x+25, y, 179);//    Kanan tengah
}

void boxTabel(){
    console(&Lebar, &Tinggi);
    for(i = 32; i < Lebar-3; i++){
        ascPrint(i,2, 196);
        ascPrint(i,4, 196);
        ascPrint(i,Tinggi-2, 196);
    }
    for ( i = 3; i < Tinggi - 2; ++i) {
        ascPrint(32,i,179);
        ascPrint(44,i,179);
        ascPrint(66,i,179);
        ascPrint(108,i,179);
        ascPrint(123,i,179);
        ascPrint(142,i,179);
        ascPrint(Lebar-3,i,179);
    }
    ascPrint(32,2,218);//    Kiri atas
    ascPrint(Lebar - 3,2, 191);// Kanan atas
    ascPrint(32,Tinggi - 2, 192);// Kiri bawah
    ascPrint(Lebar - 3,Tinggi - 2, 217);// Kanan bawah
    ascPrint(32,4, 195);// Kiri tengah
    ascPrint(Lebar-3,4, 180);// Kiri tengah
    ascPrint(44,4, 197);
    ascPrint(66,4, 197);
    ascPrint(108,4, 197);
    ascPrint(123,4, 197);
    ascPrint(142,4, 197);

    ascPrint(44,Tinggi-2,193);
    ascPrint(66,Tinggi-2,193);
    ascPrint(108,Tinggi-2,193);
    ascPrint(123,Tinggi-2,193);
    ascPrint(142,Tinggi-2,193);

    ascPrint(44,2,194);
    ascPrint(66,2,194);
    ascPrint(108,2,194);
    ascPrint(123,2,194);
    ascPrint(142,2,194);
}
void dataApproval(){
    console(&Lebar, &Tinggi);
    for(i = 44; i < 133; i++){
        ascPrint(i,2, 196);
        ascPrint(i,4, 196);
        ascPrint(i,Tinggi-2, 196);
    }
    for ( i = 3; i < Tinggi - 2; ++i) {
        ascPrint(44,i,179);
        ascPrint(63,i,179);
        ascPrint(80,i,179);
        ascPrint(95,i,179);
        ascPrint(107,i,179);
        ascPrint(121,i,179);
        ascPrint(133,i,179);
    }
    ascPrint(44,2,218);//    Kiri atas
    ascPrint(133,2, 191);// Kanan atas
    ascPrint(44,Tinggi - 2, 192);// Kiri bawah
    ascPrint(133,Tinggi - 2, 217);// Kanan bawah
    ascPrint(44,4, 195);// Kiri tengah
    ascPrint(133,4, 180);// Kiri tengah
    ascPrint(63,4, 197);
    ascPrint(80,4, 197);
    ascPrint(95,4, 197);
    ascPrint(107,4, 197);
    ascPrint(121,4, 197);

    ascPrint(63,Tinggi-2,193);
    ascPrint(80,Tinggi-2,193);
    ascPrint(95,Tinggi-2,193);
    ascPrint(107,Tinggi-2,193);
    ascPrint(121,Tinggi-2,193);

    ascPrint(63,2,194);
    ascPrint(80,2,194);
    ascPrint(95,2,194);
    ascPrint(107,2,194);
    ascPrint(121,2,194);
}
void boxUpdate(){
    for(i = 1; i < Lebar - 51; i++){
        ascPrint(46+i,11, 196);
        ascPrint(46+i,13, 196);
        ascPrint(46+i,15, 196);
    }
    for(i = 1; i < 4; i++){
        ascPrint(46, 11+i,179);
        ascPrint(Lebar - 5, 11+i,179);
        ascPrint(60, 11+i,179);
        ascPrint(85, 11+i,179);
        ascPrint(119, 11+i,179);
    }

    ascPrint(60,13, 197);
    ascPrint(85 ,13, 197);
    ascPrint(119,13, 197);

    ascPrint(46,11,218);//    Kiri atas
    ascPrint(Lebar - 5,11, 191);// Kanan atas
    ascPrint(46,15, 192);// Kiri bawah
    ascPrint(Lebar - 5,15, 217);// Kanan bawah
    ascPrint(46,13, 195);// Kiri tengah
    ascPrint(Lebar-5,13, 180);// Kiri tengah

    ascPrint(60,15,193);
    ascPrint(85,15,193);
    ascPrint(119,15,193);

    ascPrint(60,11,194);
    ascPrint(85,11,194);
    ascPrint(119,11,194);
}

void tabelRole(){
    console(&Lebar, &Tinggi);
    for(i = 1; i < 79; i++){
        ascPrint(54+i,7, 196);
        ascPrint(54+i,9, 196);
        ascPrint(54+i,Tinggi-10, 196);
    }
    for ( i = 0; i < Tinggi - 18; ++i) {
        ascPrint(54, 8+i, 179);
        ascPrint(69, 8+i, 179);
        ascPrint(133, 8+i, 179);
    }
    ascPrint(54,7,218);//    Kiri atas
    ascPrint(Lebar - 23,7, 191);// Kanan atas
    ascPrint(54,Tinggi - 10, 192);// Kiri bawah
    ascPrint(Lebar- 23,Tinggi - 10, 217);// Kanan bawah

    ascPrint(69,Tinggi-10,193);
    ascPrint(54,9,195);
    ascPrint(69,9,197);
    ascPrint(69,7,194);
    ascPrint(133,9,180);
}


void boxDepart(){
    console(&Lebar, &Tinggi);
    for(i = 1; i < 55; i++){
        ascPrint(63+i,5, 196);
        ascPrint(63+i,7, 196);
        ascPrint(63+i,25, 196);
    }
    for ( i = 0; i < 20; ++i) {
        ascPrint(63, 5+i, 179);
        ascPrint(74, 5+i, 179);
        ascPrint(118, 5+i, 179);
    }
    ascPrint(63,5,218);//    Kiri atas
    ascPrint(118,5,191);// Kanan atas
    ascPrint(63,25,192);// Kiri bawah
    ascPrint(118,25,217);// Kanan bawah

    ascPrint(74,5,194);
    ascPrint(74,25,193);
    ascPrint(63,7,195);
    ascPrint(118,7,180);
    ascPrint(74,7,197);
}

void boxPerizinan(){//All
    console(&Lebar, &Tinggi);
    for(i = 31; i < Lebar-3; i++){
        ascPrint(i,2, 196);
        ascPrint(i,4, 196);
        ascPrint(i,Tinggi-2, 196);
    }
    for ( i = 3; i < Tinggi - 2; ++i) {
        ascPrint(31,i,179);
        ascPrint(44,i,179);
        ascPrint(52,i,179);
        ascPrint(60,i,179);
        ascPrint(73,i,179);
        ascPrint(122,i,179);
        ascPrint(Lebar-3,i,179);
    }
    ascPrint(31,2,218);//    Kiri atas
    ascPrint(Lebar - 3,2, 191);// Kanan atas
    ascPrint(31,Tinggi - 2, 192);// Kiri bawah
    ascPrint(Lebar - 3,Tinggi - 2, 217);// Kanan bawah
    ascPrint(31,4, 195);// Kiri tengah
    ascPrint(Lebar-3,4, 180);// Kiri tengah
    ascPrint(44,4, 197);
    ascPrint(52,4, 197);
    ascPrint(60,4, 197);
    ascPrint(73,4, 197);
    ascPrint(122,4, 197);

    ascPrint(44,Tinggi-2,193);
    ascPrint(52,Tinggi-2,193);
    ascPrint(60,Tinggi-2,193);
    ascPrint(73,Tinggi-2,193);
    ascPrint(122,Tinggi-2,193);

    ascPrint(44,2,194);
    ascPrint(52,2,194);
    ascPrint(60,2,194);
    ascPrint(73,2,194);
    ascPrint(122,2,194);
}
void absnKehadiran(){
    console(&Lebar, &Tinggi);
    int i;
    for(i = 1; i < Lebar - 40; i++){
        ascPrint(35+i,2, 196);
        ascPrint(35+i,4, 196);
        ascPrint(35+i,Tinggi-2, 196);
    }
    for ( i = 0; i < Tinggi - 5; ++i) {
        ascPrint(35, 3+i, 179);
        ascPrint(Lebar - 5, 3+i, 179);
        ascPrint(54, 3+i, 179);
        ascPrint(109, 3+i, 179);
        ascPrint(135, 3+i, 179);
    }
    ascPrint(35,2,218);//    Kiri atas
    ascPrint(Lebar - 5,2, 191);// Kanan atas
    ascPrint(35,Tinggi - 2, 192);// Kiri bawah
    ascPrint(Lebar - 5,Tinggi - 2, 217);// Kanan bawah
    ascPrint(35,4, 195);// Kiri tengah
    ascPrint(Lebar-5,4, 180);// Kiri tengah
    ascPrint(54,4, 197);
    ascPrint(109,4, 197);
    ascPrint(135,4, 197);

    ascPrint(54,Tinggi-2,193);
    ascPrint(109,Tinggi-2,193);
    ascPrint(135,Tinggi-2,193);

    ascPrint(54,2,194);
    ascPrint(109,2,194);
    ascPrint(135,2,194);
}
void DesainData() {
    int x, y;
    // GARIS HORIZONTAL
    for (x = 1; x <= 60; x++) {
        ascPrint(65+x, 14,205); //garis atas dalam horizontal
        ascPrint(65+x, 21,205); //garis tengah dalam horizontal
        ascPrint(65+x, 40,205);//garis bawah dalam horizontal
    }

    for (x = 1; x <= 62; x++) {
        ascPrint(64+x, 13,219); //garis atas luar horizontal +2
        ascPrint(64+x, 41,219); // garis bawah luar horizontal
    }

    // GARIS VERTIKAL
    for (y = 1; y <= 25; y++) {
        ascPrint(65, 14+y,186); //garis atas kiri tengah dalam vertikal
        ascPrint(126, 14+y,186);  //Garis atas kanan tengah dalam vertikal
    }

    for (y = 1; y <= 29; y++) {
        ascPrint(64, 12+y,219);  //garis kiri luar vertikal
        ascPrint(127, 12+y,219); //garis kanan luar vertikal
    }
    // PENUTUP GARIS
    coord(65, 21);
    printf("%c", 204); // TENGAH KIRI
    coord(126, 21);
    printf("%c", 185); // TENGAH KANAN
    coord(65, 14);
    printf("%c", 201); // ATAS KIRI
    coord(126, 14);
    printf("%c", 187); // ATAS KANAN
    coord(126, 40);
    printf("%c", 188); // BAWAH KANAN
    coord(65, 40);
    printf("%c", 200); // BAWAH KIRI
}
void pinggiran(){
    int y ,x ;
    for (y=1;y <= 100; y++){
        coord(30,y); printf("%c", 219);
    }

    for(x=30; x<=167; x++) // Garis tengah horizontal
    {
        coord(x,14); printf("%c",219);
    }
}

void boxabsensimakan(){
    console(&Lebar, &Tinggi);
    i = 0;
    for(i = 1; i < Lebar - 55; i++){
        ascPrint(35+i,2, 196);
        ascPrint(35+i,4, 196);
        ascPrint(35+i,Tinggi-2, 196);
    }
    for ( i = 0; i < Tinggi - 5; ++i) {
        ascPrint(35, 3+i, 179);
        ascPrint(Lebar - 20, 3+i, 179);
        ascPrint(67, 3+i, 179);
        ascPrint(125, 3+i, 179);
    }
    ascPrint(35,2,218);//    Kiri atas
    ascPrint(Lebar - 20,2, 191);// Kanan atas
    ascPrint(35,Tinggi - 2, 192);// Kiri bawah
    ascPrint(Lebar - 20,Tinggi - 2, 217);// Kanan bawah
    ascPrint(35,4, 195);// Kiri tengah
    ascPrint(Lebar-20,4, 180);// Kiri tengah
    ascPrint(67,4, 197);
    ascPrint(125,4, 197);

    ascPrint(67,Tinggi-2,193);
    ascPrint(125,Tinggi-2,193);

    ascPrint(67,2,194);
    ascPrint(125,2,194);
}

void boxMedis(){
    console(&Lebar, &Tinggi);
    i=0;
    for(i = 1; i < Lebar - 65; i++){
        ascPrint(55+i,6, 219);
        ascPrint(55+i,Tinggi-6, 219);
        ascPrint(55+i, 6,219);
    }
    for ( i = 0; i < Tinggi-12; ++i) {
        ascPrint(55,6+i,178);
        ascPrint(110, 6+i, 178);
    }
    ascPrint(55,6,219);//    Kiri atas jangan dihapus 1
    ascPrint(Lebar - 10,6, 219);// Kanan atas
    ascPrint(55,Tinggi-6, 219);// Kiri bawah jangan dihapus 1
    ascPrint(Lebar - 10,Tinggi-6, 219);// Kanan bawah jangan dihapus
}
void boxURTable(){
    console(&Lebar, &Tinggi);
    i=0;
    for(i = 1; i < Lebar - 30; i++){
        ascPrint(28+i,4, 196);
        ascPrint(28+i,6, 196);
        ascPrint(28+i,Tinggi-8, 196);
    }
    for ( i = 0; i < Tinggi -12; ++i) {
        ascPrint(28, 5+i, 179);
        ascPrint(Lebar -3, 5+i, 179);
        ascPrint(42, 5+i, 179);
        ascPrint(86, 5+i, 179);
        ascPrint(116, 5+i, 179);
    }
    ascPrint(28,4,218);//    Kiri atas
    ascPrint(28,Tinggi - 8, 192);// Kiri bawah
    ascPrint(Lebar - 3,4, 191);// Kanan atas
    ascPrint(Lebar - 3,Tinggi - 8, 217);// Kanan bawah
    ascPrint(28,6, 195);// Kiri tengah
    ascPrint(Lebar-3,6, 180);// Kiri tengah
    ascPrint(28,6, 197);
    ascPrint(86,6, 197);
    ascPrint(116,4, 197);

    ascPrint(42,Tinggi-8,193);
    ascPrint(86,Tinggi-8,193);
    ascPrint(116,Tinggi-8,193);

    ascPrint(42,4,194);
    ascPrint(86,4,194);
    ascPrint(116,4,194);

}
void boxpengaduan() {
    int x, y;
    // PENUTUP GARIS
    coord(41, 20);printf("%c", 204); // TENGAH KIRI
    coord(109, 20);printf("%c", 185); // TENGAH KANAN
    coord(41, 15);printf("%c", 201); // ATAS KIRI
    coord(109, 15);printf("%c", 187); // ATAS KANAN
    coord(109, 38);printf("%c", 188); // BAWAH KANAN
    coord(41   , 38);printf("%c", 200); // BAWAH KIRI

    // GARIS HORIZONTAL
    for (x = 42; x <= 108; x++) {
        coord(x, 15);
        printf("%c", 205);
        coord(x, 20);
        printf("%c", 205);
        coord(x, 38);
        printf("%c", 205);
    }
    for (x = 40; x <= 110; x++) {
        coord(x, 14 );
        printf("%c", 219);
        coord(x, 39);
        printf("%c", 219);
    }
    // GARIS VERTIKAL
    for (y = 16; y <= 19; y++) {
        coord(41, y);
        printf("%c", 186);
        coord(109, y);
        printf("%c", 186);
    }
    for (y = 21; y <= 37; y++) {
        coord(41, y);
        printf("%c", 186);
        coord(109, y);
        printf("%c", 186);
    }
    for (y = 14; y <= 38; y++) {
        coord(40, y);
        printf("%c", 219);
        coord(110, y);
        printf("%c", 219);
    }
    for (y = 0; y <= 43; y++) {
        coord(30, y);
        printf("%c", 219);
    }
    for (x = 30; x <= 155; x++) {       //Garis Tengah Atas
        coord(x, 10);
        printf("%c", 219);
    }
    for (y = 0; y <= 10; y++) {
        coord(77, y);
        printf("%c", 219);
    }
}

void DesainDataperizinan() {
    int x, y;
    // PENUTUP GARIS
    coord(78, 11);
    printf("%c", 204); // TENGAH KIRI
    coord(148, 11);
    printf("%c", 185); // TENGAH KANAN
    coord(78, 4);
    printf("%c", 201); // ATAS KIRI
    coord(148, 4);
    printf("%c", 187); // ATAS KANAN
    coord(148, 39);
    printf("%c", 188); // BAWAH KANAN
    coord(78, 39);
    printf("%c", 200); // BAWAH KIRI

    // GARIS HORIZONTAL
    for (x = 79; x <= 147; x++) {
        coord(x, 4); //garis atas dalam horizontal
        printf("%c", 205);
        coord(x, 11); //garis tengah dalam horizontal
        printf("%c", 205);
        coord(x, 39);//garis bawah dalam horizontal
        printf("%c",205 );
    }

    for (x = 75; x <= 100; x++) {
        coord(x, 3); //garis atas luar horizontal +2
        coord(x, Tinggi-4); // garis bawah luar horizontal
        printf("%c", 219);
    }
    // GARIS VERTIKAL
    for (y = 5; y <= 10; y++) {
        coord(78, y); //garis atas kiri  dalam vertikal
        printf("%c", 186);
        coord(148, y);  //Garis atas kanan  dalam vertikal
        printf("%c", 186);
    }
    for (y = 4; y <= 40; y++) {
        coord(77, y);  //garis kiri luar vertikal
        printf("%c", 219);
        coord(149, y); //garis kanan luar vertikal
        printf("%c", 219);
    }
}

void pinggiranperizinan() {
    int y, x;
    for (y = 0  ; y <= 100; y++){
        coord(30, y);
        printf("%c", 186);
        coord(64,y); printf("%c", 186);
    }
    for (x = 30; x <= 64; x++)//garis horizontal id trsaksi perizinan
    {
        coord(x, 3);
        printf("%c", 186);
    }
}
void boxPengumuman(){
    console(&Lebar, &Tinggi);
    int i;
    for(i = 1; i < 70; i++){
        ascPrint(35+i,2, 196);
        ascPrint(35+i,4, 196);
        ascPrint(35+i,Tinggi-3, 196);
    }
    for ( i = 0; i < Tinggi-5; ++i) {
        ascPrint(35, 3+i, 179);
        ascPrint(55, 3+i, 179);
        ascPrint(77,3+i,179);
        ascPrint(105, 3+i, 179);
    }
    ascPrint(35,2,218);//    Kiri atas 1
    ascPrint(105,2, 191);// Kanan atas 2
    ascPrint(35,Tinggi-3, 192);// Kiri bawah jangan dihapus 3
    ascPrint(105,Tinggi-3, 217);// Kanan bawah jangan dihapus 4
    ascPrint(35,4, 195);// Kiri tengah jangan dihapus 5
    ascPrint(105,4, 180);// Kiri tengah jangan dihapus 6
    ascPrint(77,4,197); //7
    ascPrint(55,4, 197);

    ascPrint(55,Tinggi-3,193);
    ascPrint(77,Tinggi-3,193);

    ascPrint(55,2,194);
    ascPrint(77,2,194);
}
void boxPengumuman2(){
    console(&Lebar, &Tinggi);
    int i;
    for(i = 1; i < Lebar - 127; i++){
        ascPrint(118+i,6, 219);
        ascPrint(118+i,Tinggi-6, 219);
    }
    for ( i = 0; i < Tinggi-12; ++i) {
        ascPrint(118,6+i,178);
        ascPrint(162, 6+i, 178);
    }
    ascPrint(118,6,219);//    Kiri atas jangan dihapus 1
    ascPrint(Lebar - 10,6, 219);// Kanan atas
    ascPrint(118,Tinggi-6, 219);// Kiri bawah jangan dihapus 1
    ascPrint(Lebar - 10,Tinggi-6, 219);// Kanan bawah jangan dihapus
}
void boxMedis2(){//All
    console(&Lebar, &Tinggi);
    for(i = 31; i < Lebar-3; i++){
        ascPrint(i,2, 196);
        ascPrint(i,4, 196);
        ascPrint(i,Tinggi-2, 196);
    }
    for ( i = 3; i < Tinggi - 2; ++i) {
        ascPrint(31,i,179);
        ascPrint(55,i,179);
        ascPrint(96,i,179);
        ascPrint(81,i,179);
        ascPrint(118,i,179);
        ascPrint(134,i,179);
        ascPrint(Lebar-3,i,179);
    }
    ascPrint(31,2,218);//    Kiri atas
    ascPrint(Lebar - 3,2, 191);// Kanan atas
    ascPrint(31,Tinggi - 2, 192);// Kiri bawah
    ascPrint(Lebar - 3,Tinggi - 2, 217);// Kanan bawah
    ascPrint(31,4, 195);// Kiri tengah
    ascPrint(Lebar-3,4, 180);// Kiri tengah
    ascPrint(96,4,197);
    ascPrint(55,4, 197);
    ascPrint(118,4, 197);
    ascPrint(81,4, 197);
    ascPrint(134,4, 197);

    ascPrint(55,Tinggi-2,193);
    ascPrint(96,Tinggi-2,193);
    ascPrint(81,Tinggi-2,193);
    ascPrint(134,Tinggi-2,193);
    ascPrint(118,Tinggi-2,193);

    ascPrint(55,2,194);
    ascPrint(96,2,194);
    ascPrint(81,2,194);
    ascPrint(134,2,194);
    ascPrint(118,2,194);
}
void boxMedis3(){//All
    console(&Lebar, &Tinggi);
    for(i = 31; i < Lebar-3; i++){
        ascPrint(i,2, 196);
        ascPrint(i,4, 196);
        ascPrint(i,Tinggi-2, 196);
    }
    for ( i = 3; i < Tinggi - 2; ++i) {
        ascPrint(31,i,179);
        ascPrint(50,i,179);
        ascPrint(66,i,179);
        ascPrint(96,i,179);
        ascPrint(81,i,179);
        ascPrint(118,i,179);
        ascPrint(134,i,179);
        ascPrint(Lebar-3,i,179);
    }
    ascPrint(31,2,218);//    Kiri atas
    ascPrint(Lebar - 3,2, 191);// Kanan atas
    ascPrint(31,Tinggi - 2, 192);// Kiri bawah
    ascPrint(Lebar - 3,Tinggi - 2, 217);// Kanan bawah
    ascPrint(31,4, 195);// Kiri tengah
    ascPrint(Lebar-3,4, 180);// Kiri tengah
    ascPrint(96,4,197);
    ascPrint(50,4, 197);
    ascPrint(118,4, 197);
    ascPrint(66,4, 197);
    ascPrint(81,4, 197);
    ascPrint(134,4, 197);

    ascPrint(50,Tinggi-2,193);
    ascPrint(96,Tinggi-2,193);
    ascPrint(66,Tinggi-2,193);
    ascPrint(81,Tinggi-2,193);
    ascPrint(134,Tinggi-2,193);
    ascPrint(118,Tinggi-2,193);

    ascPrint(50,2,194);
    ascPrint(96,2,194);
    ascPrint(66,2,194);
    ascPrint(81,2,194);
    ascPrint(134,2,194);
    ascPrint(118,2,194);
}
void boxmm(){
    console(&Lebar, &Tinggi);
    int i;
    for(i = 1; i < Lebar - 40; i++){
        ascPrint(35+i,2, 196);
        ascPrint(35+i,4, 196);
        ascPrint(35+i,Tinggi-2, 196);
    }
    for ( i = 0; i < Tinggi - 5; ++i) {
        ascPrint(35, 3+i, 179);
        ascPrint(Lebar - 5, 3+i, 179);
        ascPrint(54, 3+i, 179);
        ascPrint(69, 3+i, 179);
//        ascPrint(109, 3+i, 179);
//        ascPrint(129, 3+i, 179);
    }
    ascPrint(35,2,218);//    Kiri atas
    ascPrint(Lebar - 5,2, 191);// Kanan atas
    ascPrint(35,Tinggi - 2, 192);// Kiri bawah
    ascPrint(Lebar - 5,Tinggi - 2, 217);// Kanan bawah
    ascPrint(35,4, 195);// Kiri tengah
    ascPrint(Lebar-5,4, 180);// Kiri tengah
    ascPrint(54,4, 197);
    ascPrint(69,4, 197);
//    ascPrint(109,4, 197);
//    ascPrint(129,4, 197);

    ascPrint(54,Tinggi-2,193);
    ascPrint(69,Tinggi-2,193);
//    ascPrint(109,Tinggi-2,193);
//    ascPrint(129,Tinggi-2,193);

    ascPrint(54,2,194);
    ascPrint(69,2,194);
//    ascPrint(109,2,194);
//    ascPrint(129,2,194);
}