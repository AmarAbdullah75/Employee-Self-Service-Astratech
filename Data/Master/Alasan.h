ALASAN Alasan;
int Kode;
void menuAlasan();
void CAlasan() {
    int c, kd=0;
    alasan = fopen("fileDat/Master/Alasan.dat", "rb");
    while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1){
        kd=Alasan.KD;
    }
    Alasan.KD = kd + 1;
    coorPrint(68, 2, "[=[=[=[=[  TAMBAH DATA ALASAN  ]=]=]=]=]");
    alasan = fopen("fileDat/Master/Alasan.dat", "ab");
    coorPrint(100, 15, "Tekan \"Enter\" Untuk Input Data Baru!!");
    coorPrint(55, 10, "Kode            :");
    coorPrint(55, 13, "Nama Alasan     :");
    coorPrint(55, 16, "Jenis           :");
    coorPrint(55, 19, "Simpan         ->");
    coorPrint(55, 22, "Kembali        ->");
    coord(72, 10);
    setInt(Alasan.KD);
    c = 10;
    top:
    coord(72, 10);
    do {
        choiceMenu3(10, 22, &c);
        if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22) {
            coord(72, c);
        }
    } while ((sk == pgUp || sk == pgDn) && klik != enter);
    if(klik == enter){
        switch (c) {
            case 10:MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                              MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto top;
            case 13:coorPrint(72, 13, "                             ");
                coord(72, 13);
                getStr(Alasan.nama, 50);
                goto top;
            case 16:
            coorPrint(72, 16, "                       ");
                coord(72, 16);
                getAlphabet(Alasan.jenis, 10);
                goto top;
            case 22:menuAlasan();
                break;
        }
        if(c==19){
                fwrite(&Alasan, sizeof(Alasan), 1, alasan);
                MessageBox(NULL, "Data berhasil ditambahkan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
    fclose(alasan);
}

void RAlasan(int type) {
    int i = 0;
    switch (type) {
        case 1:
            alasan = fopen("fileDat/Master/Alasan.dat", "rb");
            coorPrint(70, 2, "[=[=[=[=[  DATA ALASAN  ]=]=]=]=]");
            coorPrint(43, 4, "Kode");
            coorPrint(65, 4, "Nama");
            coorPrint(115, 4, "Jenis");
            while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                coord(45, 5 + i);
                setInt(Alasan.KD);
                coorPrint(55, 5 + i, Alasan.nama);
                coorPrint(115, 5 + i, Alasan.jenis);
                i++;
            }
            fclose(alasan);
            break;
        case 2:
            uiDashboard2();
            alasan = fopen("fileDat/Master/Alasan.dat", "rb");
            coorPrint(115, 2, "ALASAN");
            coorPrint(98, 4, "Kode");
            coorPrint(120, 4, "Nama");
            while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                if (strcmp(Alasan.jenis, "IMP") == 0) {
                    coord(99, 5 + i),setInt(Alasan.KD);
                    coorPrint(107, 5 + i, Alasan.nama);
                    i++;
                }
            }
            fclose(alasan);
            break;
        case 3:
            uiDashboard2();
            alasan = fopen("fileDat/Master/Alasan.dat", "rb");
            coorPrint(115, 2, "ALASAN");
            coorPrint(98, 4, "Kode");
            coorPrint(120, 4, "Nama");
            while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                if (strcmp(Alasan.jenis, "Cuti") == 0) {
                    coord(99, 5 + i),setInt(Alasan.KD);
                    coorPrint(107, 5 + i, Alasan.nama);
                    i++;
                }
            }
            fclose(alasan);
            break;
    }
}

void UAlasan() {
    string alasanDesk, jenis;
    status = 0;
    coorPrint(72, 2, "[=[=[=[=[  UBAH DATA ALASAN  ]=]=]=]=]");
    coorPrint(84, 5, "Masukkan Kode :");
    coorPrint(100,15,"Tekan \"Enter\" Untuk Input Data Baru");
    coorPrint(55,15,"Kode            :");
    coorPrint(55,18,"Nama Alasan     :");
    coorPrint(55,21,"Jenis           :");
    coorPrint(55,24,"Simpan         ->");
    coorPrint(55,27,"Kembali        ->");
    coord(99, 5),getInt(&Kode, 6);
    alasan = fopen("fileDat/Master/Alasan.dat", "rb");
    alasanTemp = fopen("fileDat/AlasanTemp.dat", "wb");
    while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
        if (Kode ==  Alasan.KD) {
            status = 1;
        } else {
            fwrite(&Alasan, sizeof(Alasan), 1, alasanTemp);
        }
    }
    fclose(alasan);
    fclose(alasanTemp);

    if (!status) {
        coord(65, 20);
        MessageBox(NULL, "Kode tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        alasan = fopen("fileDat/Master/Alasan.dat", "rb");
        alasanTemp = fopen("fileDat/AlasanTemp.dat", "wb");
        while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
            int c = 15;
            if (Kode ==  Alasan.KD) {
                coord(72,15),setInt(Alasan.KD);
                coorPrint(72,18,Alasan.nama);
                coorPrint(72,21,Alasan.jenis);\
                top:
                coord(72, 15);
                do {
                    choiceMenu3(15, 27, &c);
                    if (c == 15 || c == 18 || c == 21 || c == 24 ||c==27) {
                        coord(72, c);
                    }
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if(klik == enter){
                    switch (c) {
                        case 15:MessageBox(NULL, "Kode tidak bisa diubah!!", "Peringatan",
                                           MB_OK | MB_DEFAULT_DESKTOP_ONLY | MB_ICONINFORMATION);
                            goto top;
                        case 18:
                            coorPrint(72, 18, "                                              ");
                            coord(72, 18);
                            getStr(alasanDesk, 50);
                            strcpy(Alasan.nama, alasanDesk);
                            goto top;
                        case 21:coorPrint(72, 21, "          ");
                            coord(72, 21);
                            getAlphabet(jenis, 10);
                            strcpy(Alasan.jenis, jenis);
                            goto top;
                        case 27:menuAlasan();
                            break;
                    }
                    if(c==24){
                        fwrite(&Alasan, sizeof(Alasan), 1, alasanTemp);
                        MessageBox(NULL, "Data berhasil diubah!!", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    }
                }
            } else {
                fwrite(&Alasan, sizeof(Alasan), 1, alasanTemp);
            }
        }
        fclose(alasan);
        fclose(alasanTemp);
    }

    alasan = fopen("fileDat/Master/Alasan.dat", "wb");
    alasanTemp = fopen("fileDat/AlasanTemp.dat", "rb");
    while (fread(&Alasan, sizeof(Alasan), 1, alasanTemp) == 1) {
        fwrite(&Alasan, sizeof(Alasan), 1, alasan);
    }
    fclose(alasan);
    fclose(alasanTemp);
}

void DAlasan() {
    status = 0;
    printFile(65,12, "fileTxt/Gambar/Tempat Sampah.txt");
    coorPrint(72, 2, "[=[=[=[=[  HAPUS DATA ALASAN  ]=]=]=]=]");
    coorPrint(84, 5, "Masukkan Kode :");
    coord(99, 5);
    getInt(&Kode, 6);
    alasan = fopen("fileDat/Master/Alasan.dat", "rb");
    alasanTemp = fopen("fileDat/AlasanTemp.dat", "wb");
    while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
        if (Kode == Alasan.KD) {
            status = 1;
        } else {
            fwrite(&Alasan, sizeof(Alasan), 1, alasanTemp);
        }
    }
    fclose(alasan);
    fclose(alasanTemp);

    if (!status) {
        coord(65, 20);
        MessageBox(NULL, "Kode tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        alasan = fopen("fileDat/Master/Alasan.dat", "rb");
        alasanTemp = fopen("fileDat/AlasanTemp.dat", "wb");
        while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
            if (Kode == Alasan.KD) {
                MessageBox(NULL, "Data berhasil di hapus!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            } else {
                fwrite(&Alasan, sizeof(Alasan), 1, alasanTemp);
            }
        }
        fclose(alasan);
        fclose(alasanTemp);
    }

    alasan = fopen("fileDat/Master/Alasan.dat", "wb");
    alasanTemp = fopen("fileDat/AlasanTemp.dat", "rb");
    while (fread(&Alasan, sizeof(Alasan), 1, alasanTemp) == 1) {
        fwrite(&Alasan, sizeof(Alasan), 1, alasan);
    }
    fclose(alasan);
    fclose(alasanTemp);
}