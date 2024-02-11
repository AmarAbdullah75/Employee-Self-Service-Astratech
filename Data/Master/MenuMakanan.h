MENUMAKANAN menuMakanan;
string searchkode;
void menumakanan();
void CMenuMakanan(){
    int kd=0,c;
    MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "rb");
    while (fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan) == 1){
        kd=menuMakanan.kd;
    }
    menuMakanan.kd=kd+1;
    fclose(MenuMakanan);
    coorPrint(65, 2, "[=[=[=[=[  TAMBAH  MENU MAKANAN  ]=]=]=]=]");
    MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "ab");
    coorPrint(55,10,"Kode Menu         :");
    coorPrint(55,13,"Tanggal(dd/mm/yy) :");
    coorPrint(55,16,"Deskripsi         :");
    coorPrint(55,19,"Simpan           ->");
    coorPrint(55,22,"Kembali          ->");
    coorPrint(55, 24, "Tekan \"Enter\" Untuk Input Data Baru");
    coord(74,10);setInt(menuMakanan.kd);
    top:
    c = 10;
    coord(74, 10);
    do {
        choiceMenu3(10, 22, &c);
        if (c == 10 || c == 13 || c == 16 || c == 19 ||c==22) {
            coord(74, c);
        }
    } while ((sk == pgUp || sk == pgDn) && klik != enter);
    if(klik==enter){
        switch (c) {
            case 10:MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto top;
            case 13:
                coorPrint(74, 13, "          ");
                coord(74,13);getStr(menuMakanan.tanggal, 8);
                goto top;
            case 16:
                coorPrint(74, 16, "                                                                     ");
                coord(74,16);getStr(menuMakanan.makanan, 50);
                goto top;
            case 22:menumakanan();
                break;
        }
        if(c==19){
            fwrite(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan);
            MessageBox(NULL, "Data berhasil ditambahkan!!","Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
        fclose(MenuMakanan);
    }
}

void RMenuMakanan(){
    i = 0;
    boxmm();
    coorPrint(70, 1, "[=[=[=[=[  DATA MENU MAKANAN  ]=]=]=]=]");
    MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "rb");
    coorPrint(40,3,"Kode Menu");
    coorPrint(58,3,"Tanggal");
    coorPrint(105,3,"Deskripsi");
    while (fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan) == 1){
        coord(45,5+i),setInt(menuMakanan.kd);
        coorPrint(58,5+i, menuMakanan.tanggal);
        coorPrint(75,5+i, menuMakanan.makanan);
        i++;
    }
    fclose(MenuMakanan);
}

void UMenuMakanan(){
    status = 0;
    int kode,c;
    string desk,tgl;
    coorPrint(70, 2, "[=[=[=[=[  UBAH DATA MENU MAKANAN  ]=]=]=]=]");
    coorPrint(84,5, "Masukkan Kode :");
    coorPrint(51, 10, "Kode Menu         :");
    coorPrint(51, 13, "Tanggal(dd/mm/yy) :");
    coorPrint(51, 16, "Deskripsi         :");
    coorPrint(51, 19, "Simpan Perubahan ->");
    coorPrint(51, 22, "Kembali          ->");
    coord(99,5);getInt(&kode,6);
    MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "rb");
    MenuMakananTemp = fopen("fileDat/MenuMakananTemp.dat", "wb");
    while(fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan) == 1){
        if(kode==menuMakanan.kd){
            status = 1;
        }else{
            fwrite(&menuMakanan, sizeof(menuMakanan), 1, MenuMakananTemp);
        }
    }
    fclose(MenuMakanan);
    fclose(MenuMakananTemp);

    if(!status){
        MessageBox(NULL, "Data tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    }else{
        MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "rb");
        MenuMakananTemp = fopen("fileDat/MenuMakananTemp.dat", "wb");
        while(fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan) == 1){
            if(menuMakanan.kd==kode){
                coorPrint(50, 24, "Tekan \"Enter\" Untuk Input Data Baru");
                coord(70, 10),setInt(menuMakanan.kd);
                coorPrint(70, 13, menuMakanan.tanggal);
                coorPrint(70, 16, menuMakanan.makanan);
                top:
                c=10;
                coord(70, 10);
                do {
                    choiceMenu3(10, 22, &c);
                    if (c==10||c == 13 || c == 16 || c == 19 || c == 22){coord(70, c);}
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if(klik==enter){
                    switch (c) {
                        case 10:MessageBox(NULL, "Kode tidak bisa diubah!!", "Peringatan",
                                           MB_OK | MB_DEFAULT_DESKTOP_ONLY | MB_ICONINFORMATION);
                            goto top;
                        case 13:coorPrint(70, 13,"        ");
                            coord(70, 13),getStr(tgl,8);
                            strcpy(menuMakanan.tanggal, tgl);
                            goto top;
                        case 16:coorPrint(70, 16, "                                                        ");
                            coord(70,16),getStr(desk,50);
                            strcpy(menuMakanan.makanan, desk);
                            goto top;
                        case 22:menumakanan();
                            break;
                    }
                    if(c==19){
                        fwrite(&menuMakanan, sizeof(menuMakanan), 1, MenuMakananTemp);
                        MessageBox(NULL, "Data berhasil diubah!!", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    }
                }
            }else{
                fwrite(&menuMakanan, sizeof(menuMakanan), 1, MenuMakananTemp);
            }
        }
        fclose(MenuMakanan);
        fclose(MenuMakananTemp);
    }

    MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "wb");
    MenuMakananTemp = fopen("fileDat/MenuMakananTemp.dat", "rb");
    while(fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakananTemp) == 1){
        fwrite(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan);
    }
    fclose(MenuMakanan);
    fclose(MenuMakananTemp);
}

void DMenuMakanan(){
    status = 0;
    int kode;
    printFile(65,12, "fileTxt/Gambar/Tempat Sampah.txt");
    coorPrint(70, 2, "[=[=[=[=[  HAPUS DATA MENU MAKANAN  ]=]=]=]=]");
    coorPrint(86,5, "Masukkan Kode :");
    coord(101,5);getInt(&kode, 6);

    MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "rb");
    MenuMakananTemp = fopen("fileDat/MenuMakananTemp.dat", "wb");
    while(fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan) == 1){
        if(kode == menuMakanan.kd){
            status = 1;
        }else{
            fwrite(&menuMakanan, sizeof(menuMakanan), 1, MenuMakananTemp);
        }
    }
    fclose(MenuMakanan);
    fclose(MenuMakananTemp);

    if(!status){
        MessageBox(NULL, "Kode tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    }else{
        MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "rb");
        MenuMakananTemp = fopen("fileDat/MenuMakananTemp.dat", "wb");
        while(fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan) == 1){
            if(kode == menuMakanan.kd){
                MessageBox(NULL, "Data berhasil dihapus!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            }else{
                fwrite(&menuMakanan, sizeof(menuMakanan), 1, MenuMakananTemp);
            }
        }
        fclose(MenuMakanan);
        fclose(MenuMakananTemp);
    }

    MenuMakanan = fopen("fileDat/Master/MenuMakanan.dat", "wb");
    MenuMakananTemp = fopen("fileDat/MenuMakananTemp.dat", "rb");
    while(fread(&menuMakanan, sizeof(menuMakanan), 1, MenuMakananTemp) == 1){
        fwrite(&menuMakanan, sizeof(menuMakanan), 1, MenuMakanan);
    }
    fclose(MenuMakanan);
    fclose(MenuMakananTemp);
}