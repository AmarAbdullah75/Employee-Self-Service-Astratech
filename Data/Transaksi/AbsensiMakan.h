void menuabsensi();
void Rabsensimakan();
ABSENSIMAKAN makan;

void Cabsensimakan(){
    int Jam, Mnt, kd=0;
    do {
        a = 0;
        printFile(4, 10, "fileTxt/Menu/MENUCRABSENSIMAKAN.txt");
        for (int k = 0; k < 4; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 19, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16||c==19) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10:
                    amakan = fopen("fileDat/AbsensiMakan.dat", "rb");
                    while (fread(&makan, sizeof(makan), 1, amakan) == 1) {
                        kd=makan.kodeabsen;
                    }
                    makan.kodeabsen=kd+1;
                    fclose(amakan);

                    amakan = fopen("fileDat/AbsensiMakan.dat", "ab");
                    cleanField();
                    DesainData();
                    printFile(70, 15, "fileTxt/Menu/absensi.txt");
                    printFile(70, 7, "fileTxt/Menu/ASTRA.txt");
                    printFile(37, 1, "fileTxt/Menu/EMPLOYEE.txt");
                    coord(73, 23), hari();
                    coord(113, 23), jam();
                    coorPrint(77, 28, "Tanggal                   : ");
                    coord(104, 28),hari();
                    coorPrint(77, 30, "Masukan Jam Makan(00:00)  :  :");
                top:
                    coord(104, 30),getInt(&Jam, 2);
                    coord(107, 30),getInt(&Mnt, 2);
                    makan.hour = Jam;
                    makan.min = Mnt ;
                    coorPrint(80,38,"Masukkan Kode Menu        : ");
                    coord(108,38);
                    getInt(&makan.kode,10);
                    MenuMakanan = fopen("fileDat/MenuMakanan.dat", "rb");
                    if(makan.kode==menuMakanan.kd){
                        MessageBox(NULL, "KODE TIDAK DITEMUKAN", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        coorPrint(118, 35, "      ");
                        coorPrint(120, 35, ":");
                        coorPrint(118, 38, "          ");
                        goto top;
                    }else {
                        fwrite(&makan, sizeof(makan), 1, amakan);
                        MessageBox(NULL, "BERHASIL MELAKUKAN ABSENSI", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    }
                    fclose(MenuMakanan);
                    fclose(amakan);
                    break;
                case 13:cleanField(), Rabsensimakan();
                    break;
                case 16:menuabsensi();
                    break;
                case 19:
                    exit(0);
            }
        }
    }while (c != 16);
}

void Rabsensimakan() {
    boxabsensimakan();
    i = 0;
    amakan = fopen("fileDat/AbsensiMakan.dat", "rb");
    coorPrint(85, 1, "Tabel Absensi Makan");
    coorPrint(42, 3, "Kode Absensi Makan ");
    coorPrint(92, 3, "Menu Makanan");
    coorPrint(126, 3, "Jam Makan");
    while (fread(&makan, sizeof(makan), 1, amakan) == 1) {
        coorPrint(41, 6 + i,"MKN"), setInt(makan.kodeabsen);
        MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "rb");
        while(fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan) == 1){
            if(menuMakanan.kd==makan.kode){
                coorPrint(70, 6 + i, menuMakanan.makanan);
            }
        }
        fclose(MenuMakanan);
        coorPrint(128, 6 + i, ":");
        if (makan.hour < 10) {
            coorPrint(126, 6 + i, "0");
            coord(127, 6 + i);
            setInt(makan.hour);
        } else {
            coord(126, 6 + i);
            setInt(makan.hour);
        }
        if (makan.min < 10) {
            coorPrint(129, 6 + i, "0");
            coord(130, 6 + i);
            setInt(makan.min);
        } else {
            coord(120, 6 + i);
            setInt(makan.min);
        }
        i++;
    }
    fclose(amakan);
}

