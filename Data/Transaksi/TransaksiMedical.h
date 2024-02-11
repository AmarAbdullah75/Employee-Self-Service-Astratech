MEDIS medis;
void TMedis(int type);
void CMedis(int type) {
    int totaltagihan;
    string id;
    int b = 1, ct;
    boxMedis();
    Medis = fopen("filedat/Transaksi/Medis.dat", "rb");
    while (fread(&medis, sizeof(medis), 1, Medis) == 1) {
        b++;
    }
    fclose(Medis);

    medical = fopen("fileDat/Master/medical.dat", "rb");
    coorPrint(130,6,"ID");
    coorPrint(142,6,"Nama");
    while (fread(&Medical, sizeof(Medical), 1, medical) == 1){
        coorPrint(130, -17 + i, "MD");
        coord(132,-17+i), setInt(Medical.id);
        coorPrint(142,-17+i, Medical.nama);
        i++;
    }
    fclose(medical);

    snprintf(id, sizeof(id), "%d", b);
    strcat(medis.ID, id);
    Medis = fopen("fileDat/Transaksi/Medis.dat", "ab");
    medis.status = 0;
    medis.IDuser = ID;
    strcat(medis.ID, id);
    medis.IDuser = ID;
    if (ID == Usr.id) {
        coorPrint(72, 8, "<<<<< KLAIM MEDIS >>>>>");
        coorPrint(62, 12, "ID Transaksi Medis :TR");
        coorPrint(62, 14, "ID Karyawan        :KRY");
        coord(85, 14);
        setInt(Usr.id);
        coorPrint(84, 12, medis.ID);
        coorPrint(62, 16, "ID Medical         :");
        coorPrint(62, 18, "Tanggal            :");
        coorPrint(62, 20, "Tagihan            :");
        coorPrint(62, 22, "Perawatan          :");
        coorPrint(62, 24, "Status             : Diajukan");
        coorPrint(62, 28, "Simpan            ->");
        coorPrint(62, 30, "Kembali           ->");
        coorPrint(62, 32, "Tekan \" Enter\"Untuk Input Data!!");
        top:
        ct = 12;
        coord(84, 12);
        do {
            choiceMenu1(12, 28, &ct);
            if (ct == 12 || ct == 14 || ct == 16 || ct == 18 || ct == 20 || ct == 22 || ct == 24 || ct == 28 ||
                ct == 30) { coord(84, ct); }
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (ct) {
                case 16:
                    coorPrint(82, 16, "MD");coord(84, 16);getInt(&medis.IDMedical, 3);
                    goto top;
                case 18:
                    coorPrint(82, 18, "  ");coord(82, 18);getInt(&medis.tanggal, 8);
                    goto top;
                case 20:
                    coorPrint(82, 20, "Rp");coord(84, 20);getInt(&medis.tagihan, 10);
                    goto top;
                case 22:
                    coorPrint(82, 22, " ");coord(82, 22);getStr(medis.Perawatn, 30);
                    goto top;
                case 29:
                    TMedis(1);
                    break;
                case 12:
                case 14:
                case 24:
                    Beep(800, 500);
                    MessageBox(NULL, "Data Tidak Dapat Diubah!!", "Attention",
                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    goto top;
                case 30:
                    TMedis(1);
            }
            if (ct == 28) {
                if (klik == enter) {
                    if(Usr.plafonMedis >= medis.tagihan){
                        user = fopen("fileDat/Master/User.dat", "rb");
                        userTemp = fopen("fileDat/Master/UserTemp", "wb");
                        while (fread(&Usr, sizeof(Usr), 1, user)== 1){
                            if(Usr.id == ID){
                                Usr.plafonMedis -= medis.tagihan;
                                fwrite(&Usr, sizeof(Usr), 1, userTemp);
                            }else{
                                fwrite(&Usr, sizeof(Usr), 1, userTemp);
                            }
                        }
                        fclose(user);
                        fclose(userTemp);

                        user = fopen("fileDat/Master/User.dat", "wb");
                        userTemp = fopen("fileDat/UserTemp.dat", "rb");
                        while (fread(&Usr, sizeof(Usr), 1, userTemp) == 1) {
                            fwrite(&Usr, sizeof(Usr), 1, user);
                        }
                        fclose(user);
                        fclose(userTemp);
                        fwrite(&medis, sizeof(medis), 1, Medis);
                        Beep(800, 500);
                        MessageBox(NULL, "Data berhasil ditambah!!", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        fclose(user);
                    }else {
                        Beep(800, 500);
                        MessageBox(NULL, "Sisa Plafonmedis tidak mencukupi!!", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    }
                }
            }
        }
    }
    fclose(user);
    fclose(Medis);

}
void RMedis(int type) {
    switch (type) {
        case 1: // Karyawan
            coorPrint(75, 1, "<<<<< KLAIM MEDIS >>>>>");
            coorPrint(35, 3, "Id Transaksi");
            coorPrint(62, 3, "Nama Medical");
            coorPrint(86, 3, "Tanggal");
            coorPrint(102, 3, "Perawatan");
            coorPrint(122, 3, "Tagihan");
            coorPrint(147, 3, "Status");
            boxMedis2();
            i = 0;
            Medis = fopen("fileDat/Transaksi/Medis.dat", "rb");
            while (fread(&medis, sizeof(medis), 1, Medis) == 1) {
                if (medis.IDuser == ID) {
                    coorPrint(34, 5 + i, "TR");
                    coorPrint(36, 5 + i, medis.ID);
                    coorPrint(83, 5 + i, " ");
                    coord(83, 5 + i);setInt(medis.tanggal);
                    coorPrint(121, 5 + i, "Rp.");
                    coord(124, 5 + i);
                    setInt(medis.tagihan);
                    coorPrint(98, 5+i, medis.Perawatn);
                    medical = fopen("fileDat/Master/medical.dat", "rb");
                    while (fread(&Medical, sizeof(Medical), 1, medical) == 1) {
                        if (medis.IDMedical == 0) { coorPrint(58, 5 + i, "         "); }
                        else if (medis.IDMedical == Medical.id) { coorPrint(58, 5 + i, Medical.nama); }
                    }
                    fclose(medical);
                    if (medis.status == 0)coorPrint(136, 5 + i, "Menunggu Approval PIC Medical");
                    else if (medis.status == 1)coorPrint(110, 5 + i, "Disetujui PIC Medical");
                    else if (medis.status == 3)coorPrint(110, 5 + i, "Ditolak PIC medical");
                    i++;
                }
            }
            fclose(Medis);
            break;
        case 2:
            coorPrint(52, 1, "<<<<< DATA KLAIM MEDIS KARYAWAN >>>>>");
            coorPrint(35, 3, "ID Transaksi");
            coorPrint(52, 3, "ID Karyawan");
            coorPrint(70, 3, "ID Medical");
            coorPrint(85, 3, "Tanggal");
            coorPrint(105, 3, "Tagihan");
            coorPrint(121, 3, "Perawatan");
            coorPrint(145, 3, "Status");
            boxMedis3();
            Medis = fopen("fileDat/Transaksi/Medis.dat", "rb");
            while(fread(&medis, sizeof(medis), 1, Medis)==1){
                user = fopen("fileDat/Master/User.dat", "rb");
                while(fread(&Usr, sizeof(Usr), 1, user)==1){
                    if (Usr.id == ID){
                        if (medis.status == 0 && Usr.role == 1){
                            coorPrint(33, 4 + i, "TR");
                            coorPrint(35, 4 + i, medis.ID);
                            coorPrint(47, 4 + i, "KRY");
                            coord(50, 4 + i);setInt(medis.IDuser);
                            coorPrint(59, 6 + i, "   ");
                            coord(59, 6 + i), setInt(medis.tanggal);
                            i++;
                        }
                    }else if(medis.status == 1 && Usr.role == 1){
                        coorPrint(33, 4 + i, "TR");
                        coorPrint(35, 4 + i, medis.ID);
                        coorPrint(35, 4 + i, medis.ID);
                        coorPrint(47, 4 + i, "KRY");
                        coord(50, 4 + i);setInt(medis.IDuser);
                        coorPrint(59, 6 + i, "   ");
                        coord(59, 6 + i), setInt(medis.tanggal);
                        i++;
                    }
                }
            }
            fclose(user);
    }
}
void UMedis() {
    i = 0;
    status = 0;
    int approve;
    string IDtrnsksi;
    coorPrint(125, 7, "[=[=[=[= APPROVAL =]=]=]=]");
    coorPrint(120, 11, "ID              :TR");
    coorPrint(120, 12, "ID Karyawan     :KRY");
    coorPrint(120, 13, "Nama Medical    :");
    coorPrint(120, 14, "Tanggal         :");
    coorPrint(120, 15, "Perawatan       :");
    coorPrint(120, 16, "Tagihan         :");
    coorPrint(120, 17, "Ubah Status     :");
    coorPrint(120, 18, "1 untuk setuju");
    coorPrint(120, 19, "0 untuk tolak");
    coorPrint(120, 20, "2 untuk kembali");

    coord(139, 11);
    getStr(IDtrnsksi, 10);
    Medis = fopen("fileDat/Transaksi/Medis.dat", "rb");
    Medistemp = fopen("fileDat/Transaksi/Medistemp.dat", "wb");
    while (fread(&medis, sizeof(medis), 1, Medis) == 1) {
        if (strcmp(IDtrnsksi, medis.ID) == 0) { status = 1; }
        else {
            fwrite(&medis, sizeof(medis), 1, Medistemp);
        }
        fclose(Medis);
        fclose(Medistemp);

        if (!status) {
            Beep(800, 500);
            MessageBox(NULL, "Data tidak Ditemukan", "Attention",
                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        } else {
            Medis = fopen("fileDat/Transaksi/Medis.dat", "rb");
            Medistemp = fopen("fileDat/Transaksi/Medistemp.dat", "wb");
            while (fread(&medis, sizeof(medis), 1, Medis) == 1) {
                user = fopen("fileDat/Master/User.dat", "rb");
                while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                    if (ID, Usr.id) {
                        if (medis.status == 0 && Usr.role == 1) {
                            user = fopen("fileDat/Master/User.dat", "rb");
                            while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                if (medis.IDuser == Usr.id) {
                                    coord(136, 12);
                                    setInt(Usr.id);
                                    coord(133, 14);
                                    setInt(medis.tanggal);
                                    coord(133, 16);
                                    setInt(medis.tagihan);
                                    coorPrint(133, 15, medis.Perawatn);
                                    medical = fopen("fileDat/Master/medical.dat", "rb");
                                    while (fread(&Medical, sizeof(Medical), 1, medical) == 1) {
                                        if (Medical.id == medis.IDMedical) {
                                            coorPrint(133, 13, Medical.nama);
                                        }
                                        fclose(medical);
                                        top:
                                        coord(133, 17);
                                        getInt(&approve, 1);
                                    }
                                    fclose(user);
                                    switch (approve) {
                                        case 1:
                                            approve = 0;
                                            break;
                                        case 0:
                                            approve = 1;
                                            break;
                                        case 2:
                                            TMedis(3);
                                            break;
                                        default:
                                            MessageBox(NULL, "Inputan Anda Salah!!      ", "Attention",
                                                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                            goto top;
                                    }
                                    medis.status = approve;
                                    fwrite(&medis, sizeof(medis), 1, Medistemp);
                                } else {
                                    fwrite(&medis, sizeof(medis), 1, Medistemp);
                                }
                            }
                            fclose(Medis);
                            fclose(Medistemp);
                        }
                        Medis = fopen("fileDat/Transaksi/Medis.dat", "wb");
                        Medistemp = fopen("fileDat/Transaksi/Medistemp.dat", "rb");
                        while (fread(&medis, sizeof(medis), 1, Medistemp) == 1) {
                            fwrite(&medis, sizeof(medis), 1, Medis);
                        }
                        fclose(Medis);
                        fclose(Medistemp);
                    }
                }
            }
        }
    }
}

void TMedis(int type) {
    do {
        a = 0;
        printFile(4, 10, "fileTxt/Menu/PengajuanMedis.txt");
        for (int k = 0; k < 3; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 16, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13||c==16) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (type) {
                case 1:
                    switch (c) {
                        case 10:
                            cleanField(), CMedis(1);
                            break;
                        case 13:
                            cleanField(), RMedis(1);
                            break;
                        case 16:
                            cleanField(), cleanMenu(), uiDashboard(), menuStaff();
                            break;
                    }
                    break;
                case 2:
                    cleanField(), RMedis(1);
                    break;
                case 3:  // PIC MEDICAL
                    switch (c) {
                        case 10:
                            cleanField(), uiUpdatePrz(), RMedis(2), UMedis();
                            coorPrint(27, c, " ");
                        case 13:cleanField(), RMedis(2);
                            break;
                        case 16:
                            cleanField(), cleanMenu(), uiDashboard(), menuPICMedical();
                            break;
                    }
                    break;
            }
        }
    } while (c != 16);
}