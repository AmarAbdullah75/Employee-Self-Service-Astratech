void menuRole();

int L, T;
ROLE Role;

void CRole() {
    int c,id=0;
    role = fopen("fileDat/Master/Role.dat", "rb");
    while(fread(&Role, sizeof(Role), 1, role) == 1){
        id=Role.KD;
    }
    Role.KD=id+1;
    fclose(role);
    coorPrint(68, 2, "[=[=[=[=[  TAMBAH DATA ROLE  ]=]=]=]=]");
    role = fopen("fileDat/Master/Role.dat", "ab");
    coorPrint(100, 15, "Tekan \"Enter\" Untuk Input Data Baru");
    coorPrint(55,10,"Kode            :");
    coorPrint(55,13,"Nama            :");
    coorPrint(55,16,"Simpan         ->");
    coorPrint(55,19,"Kembali        ->");
    coord(72, 10);
    setInt(Role.KD);
    top:
    c = 10;
    coord(72, 10);
    do {
        choiceMenu3(10, 19, &c);
        if (c == 10 || c == 13 || c == 16 || c == 19)coord(72, c);
    } while ((sk == pgUp || sk == pgDn) && klik != enter);
    if (klik == enter) {
        switch (c) {
            case 10:
                MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto top;
            case 13:
                coorPrint(72, 13, "                     ");
                coord(72, 13);
                getAlphabet(Role.nama, 20);
                goto top;
            case 19:menuRole();
                break;
        }
        if(c == 16){
                fwrite(&Role, sizeof(Role), 1, role);
                MessageBox(NULL,"Data berhasil ditambahkan!!","Attention",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
    fclose(role);
}

void RRole(int type) {
    console(&L, &T);
    role = fopen("fileDat/Master/Role.dat", "rb");
    switch (type) {
        case 1:
            i = 0;
            coorPrint(L-20,5,"Role");
            coorPrint(L-32,7,"Kode");
            coorPrint(L-20, 7, "Nama");
            while (fread(&Role, sizeof(Role), 1, role) == 1){
                coord(L-30,8+i);
                setInt(Role.KD);
                coorPrint(L-25,8+i,Role.nama);
                i++;
            }
            break;
        case 2:
            tabelRole();
            i = 0;
            coorPrint(75, 2, "[=[=[=[=[  DATA ROLE  ]=]=]=]=]");
            coorPrint(L / 2 - 17, 8, "Kode");
            coorPrint(L / 2 + 17, 8, "Nama");
            while (fread(&Role, sizeof(Role), 1, role) == 1){
                coord(L / 2 - 19, 10 + i);
                setInt(Role.KD);
                coorPrint(L / 2 - 5, 10 + i, Role.nama);
                i++;
            }
            break;
    }
    fclose(role);
}

void URole() {
    status = 0;
    string roleName;
    coorPrint(75, 2, "[=[=[=[=[  UBAH DATA ROLE  ]=]=]=]=]");
    coorPrint(86, 5, "Masukkan Kode :");
    coorPrint(51, 15, "Kode Role          :");
    coorPrint(51, 18, "Nama Role          :");
    coorPrint(51, 21, "Simpan Perubahan  ->");
    coorPrint(51, 24, "Kembali           ->");
    coord(101, 5),getInt(&Kode, 6);
    role = fopen("fileDat/Master/Role.dat", "rb");
    roleTemp = fopen("fileDat/RoleTemp.dat", "wb");
    while (fread(&Role, sizeof(Role), 1, role) == 1) {
        if (Kode == Role.KD) {
            status = 1;
        } else {
            fwrite(&Role, sizeof(Role), 1, roleTemp);
        }
    }
    fclose(role);
    fclose(roleTemp);

    if (!status) {
        MessageBox(NULL, "Data tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        role = fopen("fileDat/Master/Role.dat", "rb");
        roleTemp = fopen("fileDat/RoleTemp.dat", "wb");
        while (fread(&Role, sizeof(Role), 1, role) == 1) {
            int c = 15;
            if (Kode == Role.KD) {
                coorPrint(100, 15, "Tekan \"Enter\" Untuk Input Data Baru");
                coord(71, 15);
                setInt(Role.KD);
                coorPrint(71, 18, Role.nama);
                top:
                coord(71, 15);
                do {
                    choiceMenu3(15, 24, &c);
                    if (c == 15 || c == 18 || c == 21 || c == 24) {
                        coord(71, c);
                    }
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if (klik == enter) {
                    switch (c) {
                        case 15:
                            MessageBox(NULL, "Kode tidak bisa diubah!!", "Peringatan",
                                       MB_OK | MB_DEFAULT_DESKTOP_ONLY | MB_ICONINFORMATION);
                            goto top;
                        case 18:
                            coorPrint(71, 18, "                    ");
                            coord(71, 18);
                            getAlphabet(roleName, 20);
                            strcpy(Role.nama, roleName);
                            goto top;
                        case 24:
                            menuRole();
                            break;
                    }
                    if (c == 21) {
                            fwrite(&Role, sizeof(Role), 1, roleTemp);
                            MessageBox(NULL, "Data berhasil diubah!!", "Attention",
                                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    }
                }
            } else {
                fwrite(&Role, sizeof(Role), 1, roleTemp);
            }
        }
        fclose(roleTemp);
        fclose(role);
    }
    role = fopen("fileDat/Master/Role.dat", "wb");
    roleTemp = fopen("fileDat/RoleTemp.dat", "rb");
    while (fread(&Role, sizeof(Role), 1, roleTemp) == 1) {
        fwrite(&Role, sizeof(Role), 1, role);
    }
    fclose(role);
    fclose(roleTemp);
}

void DRole() {
    status = 0;
    printFile(65,12, "fileTxt/Gambar/Tempat Sampah.txt");
    coorPrint(75, 2, "[=[=[=[=[  HAPUS DATA ROLE  ]=]=]=]=]");
    coorPrint(86, 5, "Masukkan Kode :");
    coord(101, 5),getInt(&Kode, 6);

    role = fopen("fileDat/Master/Role.dat", "rb");
    roleTemp = fopen("fileDat/RoleTemp.dat", "wb");
    while (fread(&Role, sizeof(Role), 1, role) == 1) {
        if (Kode == Role.KD) {
            status = 1;
        } else {
            fwrite(&Role, sizeof(Role), 1, roleTemp);
        }
    }
    fclose(role);
    fclose(roleTemp);

    if (!status) {
        MessageBox(NULL, "Data tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        role = fopen("fileDat/Master/Role.dat", "rb");
        roleTemp = fopen("fileDat/RoleTemp.dat", "wb");
        while (fread(&Role, sizeof(Role), 1, role) == 1) {
            if (Kode == Role.KD) {
                MessageBox(NULL, "Data berhasil dihapus!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            } else {
                fwrite(&Role, sizeof(Role), 1, roleTemp);
            }
        }
        fclose(role);
        fclose(roleTemp);
    }

    role = fopen("fileDat/Master/Role.dat", "wb");
    roleTemp = fopen("fileDat/RoleTemp.dat", "rb");
    while (fread(&Role, sizeof(Role), 1, roleTemp) == 1) {
        fwrite(&Role, sizeof(Role), 1, role);
    }
    fclose(role);
    fclose(roleTemp);
}