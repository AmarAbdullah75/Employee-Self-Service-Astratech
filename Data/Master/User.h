USER Usr;
ROLE Role;

void akun();

int findId;

void CUser() {
    int id = 0;
    user = fopen("fileDat/Master/User.dat", "rb");
    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
        id = Usr.id;
    }
    Usr.id = id + 1;
    fclose(user);

    user = fopen("fileDat/Master/User.dat", "ab");
    coorPrint(57, 3, "[=[=[=[= TAMBAH AKUN KARYAWAN =]=]=]=]");
    coorPrint(45, 9, "ID                :KRY");
    coord(67, 9), setInt(Usr.id);
    coorPrint(45, 10, "Nama              :");
    coorPrint(45, 11, "Tanggal Lahir     :");
    coorPrint(45, 12, "Alamat            :");
    coorPrint(45, 13, "Nomor Telepon     :");
    coorPrint(45, 14, "Role              :");
    coorPrint(45, 15, "Departemen        :");
    coorPrint(45, 16, "Total Cuti        :");
    coorPrint(45, 17, "Plafon Pengobatan :10.000.000");
    coorPrint(45, 18, "Password          :");
    coorPrint(45, 19, "Simpan           ->");
    coorPrint(45, 20, "Kembali          ->");
    coorPrint(45, 25, "Tekan \"Enter\" Untuk Input Data!!");
    RRole(1), RDepartment(1);
    top:
    strcpy(Usr.kdDprtmn, "-");
    c = 9;
    coord(64, 9);
    do {
        choiceMenu1(9, 20, &c);
        if (c >= 9 && c <= 20)coord(64, c);
    } while ((sk == pgUp || sk == pgDn) && klik != enter);
    if (klik == enter) {
        switch (c) {
            case 9:
                Beep(800, 500);
                MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto top;
            case 10:
                coorPrint(64, 10, "                    ");
                coord(64, 10), getAlphabet(Usr.nama, 20);
                goto top;
            case 11:
                coorPrint(64, 11, "        ");
                coord(64, 11), getStr(Usr.lahir, 8);
                goto top;
            case 12:
                coorPrint(64, 12, "                                       ");
                coord(64, 12), getStr(Usr.alamat, 39);
                goto top;
            case 13:
                coorPrint(64, 13, "            ");
                coord(64, 13), getNum(Usr.telp, 12);
                goto top;
            case 14:
                coorPrint(64, 14, "  ");
                coord(64, 14), getInt(&Usr.role, 2);
                goto top;
            case 15:
                coorPrint(64, 15, "      ");
                coord(64, 15), getStr(Usr.kdDprtmn, 6);
                goto top;
            case 16:
                coorPrint(64, 16, "  ");
                coord(64, 16), getInt(&Usr.jmlhCuti, 2);
                goto top;
            case 17:
                Beep(800, 500);
                MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto top;
            case 18:
                coorPrint(64, 18, "        ");
                coord(64, 18), getStr(Usr.password, 20);
                if (strlen(Usr.password) > 8) {
                    Beep(800, 500),
                            MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                }
                goto top;
            case 20:
                akun();
                break;
        }
        if (c == 19) {
            Usr.plafonMedis = 10000000;
            fwrite(&Usr, sizeof(Usr), 1, user);
            Beep(800, 500);
            MessageBox(NULL, "Data berhasil ditambahkan!!", "Attention",
                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    }
    fclose(user);
    getch();
}


void RUser() {
    boxTabel();
    i = 0;
    coorPrint(75, 1, "[=[=[=[=[ DATA KARYAWAN ]=]=]=]=]");
    coorPrint(37, 3, "ID");
    coorPrint(53, 3, "Nama");
    coorPrint(85, 3, "Alamat");
    coorPrint(113, 3, "No Telp");
    coorPrint(131, 3, "Role");
    coorPrint(143, 3, "Departemen");
    user = fopen("fileDat/Master/User.dat", "rb");
    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
        coorPrint(34, 5 + i, "KRY");
        coord(37, 5 + i), setInt(Usr.id);
        coorPrint(46, 5 + i, Usr.nama);
        coorPrint(68, 5 + i, Usr.alamat);
        coorPrint(110, 5 + i, Usr.telp);
        role = fopen("fileDat/Master/Role.dat", "rb");
        while (fread(&Role, sizeof(Role), 1, role) == 1) {
            if (Usr.role == Role.KD)coorPrint(125, 5 + i, Role.nama);
        }
        fclose(role);
        departemen = fopen("fileDat/Master/Departemen.dat", "rb");
        while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
            if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                coorPrint(145, 5 + i, Departemen.nama);
            }
        }
        fclose(departemen);
        i++;
    }
    fclose(user);
}

void UUser() {
    string namabaru;
    string alamatbaru;
    string telpbaru;
    string depbaru;
    int rolebaru;
    status = 0;
    coorPrint(72, 2, "[=[=[=[=[ UBAH DATA KARYAWAN ]=]=]=]=]");
    coorPrint(51, 13, "ID                :KRY");
    coorPrint(51, 15, "Nama              :");
    coorPrint(51, 17, "Tanggal Lahir     :");
    coorPrint(51, 19, "Alamat            :");
    coorPrint(51, 21, "Nomor Telepon     :");
    coorPrint(51, 23, "Role              :");
    coorPrint(51, 25, "Departemen        :");
    coorPrint(51, 27, "Total Cuti        :");
    coorPrint(51, 29, "Plafon Pengobatan :");
    coorPrint(51, 31, "Simpan           ->");
    coorPrint(51, 33, "Kembali          ->");
    coorPrint(82, 10, "Masukkan ID :KRY");
    coord(98, 10), getInt(&findId, 6);

    user = fopen("fileDat/Master/User.dat", "rb");
    userTemp = fopen("fileDat/UserTemp.dat", "wb");
    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
        if (findId == Usr.id)status = 1;
        else fwrite(&Usr, sizeof(Usr), 1, userTemp);
    }
    fclose(user);
    fclose(userTemp);

    if (!status) {
        Beep(800, 500);
        MessageBox(NULL, "Data tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        user = fopen("fileDat/Master/User.dat", "rb");
        userTemp = fopen("fileDat/UserTemp.dat", "wb");
        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
            if (findId == Usr.id) {
                coorPrint(100, 15, "Tekan \"Enter\" Untuk Input Data Baru");
                coord(73, 13), setInt(Usr.id);
                coorPrint(70, 15, Usr.nama);
                coorPrint(70, 17, Usr.lahir);
                coorPrint(70, 19, Usr.alamat);
                coorPrint(70, 21, Usr.telp);
                coord(70, 23), setInt(Usr.role);
                coorPrint(70, 25, Usr.kdDprtmn);
                coord(70, 27), setInt(Usr.jmlhCuti);
                coord(70, 29), setInt(Usr.plafonMedis);
                top:
                c = 13;
                coord(70, 13);
                do {
                    choiceMenu2(13, 33, &c);
                    if (c == 13 || c == 15 || c == 17 || c == 19 || c == 21 || c == 23 || c == 25 || c == 27 ||
                        c == 29 || c == 31 || c == 33) { coord(70, c); }
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if (klik == enter) {
                    switch (c) {
                        case 15:
                            coorPrint(70, 15, "                    ");
                            coord(70, 15), getAlphabet(namabaru, 20), strcpy(Usr.nama, namabaru);
                            goto top;
                        case 19:
                            coorPrint(70, 19, "                                       ");
                            coord(70, 19), getStr(alamatbaru, 39);
                            strcpy(Usr.alamat, alamatbaru);
                            goto top;
                        case 21:
                            coorPrint(70, 21, "             ");
                            coord(70, 21), getNum(telpbaru, 13);
                            strcpy(Usr.telp, telpbaru);
                            goto top;
                        case 23:
                            coorPrint(70, 23, "                    ");
                            coord(70, 23), getInt(&rolebaru, 20);
                            Usr.role = rolebaru;
                            goto top;
                        case 25:
                            coorPrint(70, 25, "          ");
                            coord(70, 25), getStr(depbaru, 10);
                            strcpy(Usr.kdDprtmn, depbaru);
                        case 13:
                        case 17:
                        case 27:
                        case 29:
                            Beep(800, 500);
                            MessageBox(NULL, "Data tidak dapat diubah!!", "Attention",
                                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                            goto top;
                        case 33:
                            akun();
                            break;
                    }
                    if (c == 31) {
                        if (klik == enter)fwrite(&Usr, sizeof(Usr), 1, userTemp);
                        Beep(800, 500);
                        MessageBox(NULL, "Data berhasil diubah", "Attention",
                                   MB_OK | MB_ICONINFORMATION |
                                   MB_DEFAULT_DESKTOP_ONLY);
                    }
                }
            } else {
                fwrite(&Usr, sizeof(Usr), 1, userTemp);
            }
        }
        fclose(user);
        fclose(userTemp);
    }
    user = fopen("fileDat/Master/User.dat", "wb");
    userTemp = fopen("fileDat/UserTemp.dat", "rb");
    while (fread(&Usr, sizeof(Usr), 1, userTemp) == 1) {
        fwrite(&Usr, sizeof(Usr), 1, user);
    }
    fclose(user);
    fclose(userTemp);

}


void DUser() {
    status = 0;
    printFile(65, 12, "fileTxt/Gambar/Tempat Sampah.txt");
    coorPrint(70, 2, "[=[=[=[=[  HAPUS DATA MEDICAL  ]=]=]=]=]");
    coorPrint(82, 5, "Masukkan ID :KRY");
    coord(98, 5), getInt(&findId, 6);

    user = fopen("fileDat/Master/User.dat", "rb");
    userTemp = fopen("fileDat/UserTemp.dat", "wb");
    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
        if (findId == Usr.id)status = 1;
        else fwrite(&Usr, sizeof(Usr), 1, userTemp);
    }
    fclose(user);
    fclose(userTemp);

    if (!status) {
        coord(65, 20), Beep(800, 500);
        MessageBox(NULL, "ID tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        user = fopen("fileDat/Master/User.dat", "rb");
        userTemp = fopen("fileDat/UserTemp.dat", "wb");
        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
            if (findId == Usr.id) {
                Beep(800, 500);
                MessageBox(NULL, "Data berhasil dihapus!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            } else {
                fwrite(&Usr, sizeof(Usr), 1, userTemp);
            }
        }
        fclose(user);
        fclose(userTemp);
    }

    user = fopen("fileDat/Master/User.dat", "wb");
    userTemp = fopen("fileDat/UserTemp.dat", "rb");
    while (fread(&Usr, sizeof(Usr), 1, userTemp) == 1) {
        fwrite(&Usr, sizeof(Usr), 1, user);
    }
    fclose(user);
    fclose(userTemp);
}