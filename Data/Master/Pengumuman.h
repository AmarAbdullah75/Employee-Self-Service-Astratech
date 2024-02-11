PENGUMUMAN Pengumuman;

void CPengumuman(){
    int id,c;
    pengumuman = fopen("fileDat/Master/Pengumuman.dat", "rb");
    while (fread(&Pengumuman, sizeof(Pengumuman), 1, pengumuman) == 1){
        id=Pengumuman.kd;
    }
    Pengumuman.kd=id+1;

    coorPrint(68, 2, "[=[=[=[=[  TAMBAH PENGUMUMAN  ]=]=]=]=]");
    pengumuman = fopen("fileDat/Master/Pengumuman.dat", "ab");
    coorPrint(55,10,"Kode          :P");
    coorPrint(55,13,"Tanggal       :");
    coorPrint(55,16,"Judul         :");
    coorPrint(55,19,"Isi           :");
    coorPrint(55,22,"Simpan       ->");
    coorPrint(55,25,"Kembali      ->");
    coorPrint(55, 28, "Tekan \"Enter\" Untuk Input Data Baru");
    top:
    c = 10;
    coord(70, 10);
    do {
        choiceMenu3(10, 19, &c);
        if (c == 10 || c == 13 || c == 16 || c == 19) {
            coord(70, c);
        }
    } while ((sk == pgUp || sk == pgDn) && klik != enter);
    if(klik==enter){
        switch (c) {
            case 10:MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto top;
            case 13:coorPrint(70,13,"        ");
                coord(70,13),getStr(Pengumuman.tanggal,8);
                goto top;
            case 16:coorPrint(70,16,"                              ");
                coord(70,16),getStr(Pengumuman.judul,30);
                goto top;
        }
    }
    coord(67,7);getStr(Pengumuman.isi,50);
    fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumuman);
    MessageBox(NULL, "Data Berhasil Ditambahkan","Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    fclose(pengumuman);
}
void RPengumuman(){
    int ID;
    boxPengumuman();
    boxPengumuman2();
    coorPrint(60, 1,"Tabel Pengumuman");
    coorPrint(43, 3,"Kode");
    coorPrint(63, 3,"Tanggal");
    coorPrint(88,3,"Judul");
    pengumuman = fopen("fileDat/Master/pengumuman.dat", "rb");
    while (fread(&Pengumuman, sizeof(Pengumuman), 1, pengumuman) == 1){
        coorPrint(39, 6 + i, "P");
        coord(40, 6 + i);
        setInt(Pengumuman.kd);
        coorPrint(59,6+i, Pengumuman.tanggal);
        coorPrint(82,6+i, Pengumuman.judul);
        i++;
    }
    fclose(pengumuman);
    coorPrint(115,3, "Masukkan kode :P");
    coord(131,3);getInt(&ID, 3);
    pengumuman = fopen("fileDat/Master/Pengumuman.dat", "rb");
    pengumumanTemp = fopen("fileDat/Master/PengumumanTemp.dat", "wb");
    while (fread(&Pengumuman, sizeof(Pengumuman), 1, pengumuman) == 1) {
        if (ID == Pengumuman.kd) status = 1;
        else fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp);
    }
    fclose(pengumuman);
    fclose(pengumumanTemp);
    if (!status) {
        MessageBox(NULL, "Kode tidak ditemukan","Warning", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    }else {
        pengumuman = fopen("fileDat/Master/Pengumuman.dat", "rb");
        pengumumanTemp = fopen("fileDat/Master/PengumumanTemp.dat", "wb");
        while (fread(&Pengumuman, sizeof(Pengumuman), 1, pengumuman) == 1) {
            if (ID == Pengumuman.kd)
            {status = 1;
                coorPrint(131, 8, Pengumuman.judul);
                coorPrint(125, 10, Pengumuman.isi);
                fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp);
            } else {
                fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp);
            }
        }
        fclose(pengumuman);
        fclose(pengumumanTemp);
    }
}

void UPengumuman() {
    status = 0;
    int searchkd;
    string tanggalbaru;
    string Pengumumanbaru;
    coorPrint(72, 2, "[=[=[=[=[  UBAH PENGUMUMAN  ]=]=]=]=]");
    coorPrint(82, 5, "Masukkan Kode :P");
    coord(98, 5); getInt(&searchkd,6);
    pengumuman = fopen("fileDat/Master/Pengumuman.dat", "rb");
    pengumumanTemp = fopen("fileDat/PengumumanTemp.dat", "wb");
    while (fread(&Pengumuman, sizeof(Pengumuman), 1, pengumuman) == 1) {
        if (searchkd== Pengumuman.kd) {
            status = 1;
        }else{
            fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp);
        }
    }
    fclose(pengumuman);
    fclose(pengumumanTemp);

    if (!status) {
        MessageBox(NULL, "Data tidak ditemukan!!","Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        pengumuman = fopen("fileDat/Master/Pengumuman.dat", "rb");
        pengumumanTemp = fopen("fileDat/PengumumanTemp.dat", "wb");
        while (fread(&Pengumuman, sizeof(Pengumuman), 1, pengumuman) == 1){
            if(Pengumuman.kd==searchkd){
                coord(65, 4), setInt(Pengumuman.kd);
                coorPrint(85, 4, Pengumuman.tanggal);
                coorPrint(85, 4, Pengumuman.isi);
                coorPrint(46, 6, "Masukkan tanggal baru  :");
                coord(85, 6);
                getStr(tanggalbaru,8);
                strcpy(Pengumuman.tanggal, tanggalbaru);
                coorPrint(46,8,"Masukkan Pengumuman baru :");
                coord(87,8);
                getStr(Pengumumanbaru,50);
                strcpy(Pengumuman.isi, Pengumumanbaru);
                fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp);
                MessageBox(NULL, "Data berhasil diubah!!","Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            }else{
                fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp);
            }
        }
        fclose(pengumuman);
        fclose(pengumumanTemp);
    }
    pengumuman = fopen("fileDat/Master/Pengumuman.dat", "wb");
    pengumumanTemp = fopen("fileDat/PengumumanTemp.dat", "rb");
    while(fread(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp) == 1){
        fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumuman);
    }
    fclose(pengumuman);
    fclose(pengumumanTemp);
}

void DPengumuman(){
    status = 0;
    int kdsearch;
    printFile(65,12, "fileTxt/Gambar/Tempat Sampah.txt");
    coorPrint(72, 2, "[=[=[=[=[  HAPUS PENGUMUMAN  ]=]=]=]=]");
    coorPrint(82,5, "Masukkan Kode :P");
    coord(98,5);getInt(&kdsearch,6);

    pengumuman = fopen("fileDat/Master/Pengumuman.dat", "rb");
    pengumumanTemp = fopen("fileDat/PengumumanTemp.dat", "wb");
    while (fread(&Pengumuman, sizeof(Pengumuman), 1, pengumuman) == 1) {
        if (kdsearch==Pengumuman.kd) {
            status = 1;
        }else{
            fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp);
        }
    }
    fclose(pengumuman);
    fclose(pengumumanTemp);

    if(!status){
        MessageBox(NULL, "Data tidak ditemukan!!","Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    }else{
        pengumuman = fopen("fileDat/Master/Pengumuman.dat", "rb");
        pengumumanTemp = fopen("fileDat/PengumumanTemp.dat", "wb");
        while(fread(&Pengumuman, sizeof(Pengumuman), 1, pengumuman) == 1){
            if(Pengumuman.kd==kdsearch){
                MessageBox(NULL, "Data berhasil dihapus!!","Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            }else{
                fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp);
            }
        }
        fclose(pengumuman);
        fclose(pengumumanTemp);
    }

    pengumuman = fopen("fileDat/Master/Pengumuman.dat", "wb");
    pengumumanTemp = fopen("fileDat/PengumumanTemp.dat", "rb");
    while(fread(&Pengumuman, sizeof(Pengumuman), 1, pengumumanTemp) == 1){
        fwrite(&Pengumuman, sizeof(Pengumuman), 1, pengumuman);
    }
    fclose(pengumuman);
    fclose(pengumumanTemp);
}