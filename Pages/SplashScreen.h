void loading() {
    console(&Lebar, &Tinggi);
    for (i = 0; i < Lebar - 1; ++i) {
        ascPrint(i, Tinggi - 3, 196);
        ascPrint(i, Tinggi - 1, 196);
    }
    ascPrint(0, Tinggi - 1, 192);//    Kiri bawah
    ascPrint(Lebar - 1, Tinggi - 1, 217);//    Kanan bawah
    ascPrint(0, Tinggi - 3, 218);//    Kiri atas
    ascPrint(Lebar - 1, Tinggi - 3, 191);//    Kanan atas
    ascPrint(0, Tinggi - 2, 179);//  Kiri tengah
    ascPrint(Lebar - 1, Tinggi - 2, 179);//    Kanan tengah
    for (i = 1; i < Lebar-1; ++i) {
        ascPrint(0 + i,Tinggi-2,219);

        Sleep(30);
        i < 10 ? coorPrint(Lebar-4,Tinggi-4,"5%") :
        i < 25 ? coorPrint(Lebar-4,Tinggi-4,"10%"):
        i < 50 ? coorPrint(Lebar-4,Tinggi-4,"25%"):
        i < 75 ? coorPrint(Lebar-4,Tinggi-4,"40%"):
        i < 85 ? coorPrint(Lebar-4,Tinggi-4,"50%"):
        i < 100 ? coorPrint(Lebar-4,Tinggi-4,"75%") :
        i < 125 ? coorPrint(Lebar-4,Tinggi-4,"88%") :
        i < 135 ? coorPrint(Lebar-4,Tinggi-4,"93%") :
        i < 140 ? coorPrint(Lebar-4,Tinggi-4,"96%") :
        i < Lebar - 2 ? coorPrint(Lebar-4,Tinggi-4,"99%") :
        coorPrint(Lebar-4,Tinggi-4,"100%");
    }
}

void splash() {
    console(&Lebar,&Tinggi);
    cleanRight();
    cleanRight();
    printFile(58, 3, "fileTxt/Gambar/ESSA.txt");
    printFile(30, 10, "fileTxt/Gambar/Employee3.txt");
    coorPrint(82, 32, "Amar Abdullah");
    coorPrint(84, 33, "0320230090");
    coorPrint(57, 32, "Muhamad Farrel");
    coorPrint(57, 33, "0320230122");
    coorPrint(35, 32, "Yuzmi Zakya");
    coorPrint(35, 33, "0320230128");
    coorPrint(108, 32, "Marchell Aditya");
    coorPrint(110, 33, "0320230117");
//    printFile(110, 34, "fileTxt/Gambar/saidaosdikaos.txt");
//    loading();
//getch();
}