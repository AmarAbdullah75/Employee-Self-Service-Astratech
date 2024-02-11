#include "../StructTransaksi.h"
#include "../../Pages/Menu.h"
#include "TransaksiMedical.h"
#include "Pengaduan.h"

void Perizinan(int tipe);

PERIZINAN TPerizinan;

void CPerizinan(int type) {
    string id, wkt;
    int b = 1, ct, rntg;
    Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
    while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
        b++;
    }
    fclose(Tperizinan);

    snprintf(wkt, sizeof(wkt), "%d%d", info->tm_year + 1900, info->tm_mon + 1);
    snprintf(id, sizeof(id), "%d", b);
    strcpy(TPerizinan.ID, wkt);
    strcat(TPerizinan.ID, id);
    Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "ab");
    TPerizinan.status = 0;
    TPerizinan.IDUser = ID;
    user = fopen("fileDat/Master/User.dat", "rb");
    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
        strcpy(TPerizinan.kdDep, Usr.kdDprtmn);
        if (ID == Usr.id) {
            switch (type) {
                case 1:
                    printFile(43, 2, "fileTxt/Gambar/IMP.txt");
                    strcpy(TPerizinan.jenisIzin, "IMP");
                    coorPrint(36, 10, "ID Transaksi     :PRZ");
                    coorPrint(36, 12, "ID Karyawan      :KRY");
                    coord(57, 12), setInt(Usr.id);
                    coorPrint(57, 10, TPerizinan.ID);
                    coorPrint(36, 14, "Alasan           :");
                    coorPrint(36, 16, "Tanggal          :  /  /");
                    coord(54, 16), printf("%02d", info->tm_mday);
                    coord(57, 16), printf("%02d", info->tm_mon + 1);
                    coord(60, 16), setInt(info->tm_year + 1900);
                    coorPrint(36, 18, "Lama Izin (Jam)  :");
                    coorPrint(36, 20, "Status           :Diajukan");
                    coorPrint(36, 22, "Simpan          ->");
                    coorPrint(36, 24, "Kembali         ->");
                    coorPrint(36, 26, "Tekan \"Enter\" Untuk Input Data!!");
                    RAlasan(2);
                    top:
                    ct = 10;
                    coord(54, 10);
                    do {
                        choiceMenu2(10, 24, &ct);
                        if (ct == 10 || ct == 12 || ct == 14 || ct == 16 || ct == 18 || ct == 20 || ct == 22 ||
                            ct == 24) {
                            coord(54, ct);
                        }
                    } while ((sk == pgUp || sk == pgDn) && klik != enter);
                    if (klik == enter) {
                        switch (ct) {
                            case 14:
                                coorPrint(54, 14, "  "), coord(54, 14), getInt(&TPerizinan.IDAlasan, 2);
                                goto top;
                            case 18:
                                coorPrint(54, 18, " "), coord(54, 18), getInt(&TPerizinan.lama, 1);
                                if (TPerizinan.lama > 4) {
                                    Beep(800, 500);
                                    MessageBox(NULL, "Maximal IMP adalah 4 jam!!", "Attention",
                                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                }
                                goto top;
                            case 10:
                            case 12:
                            case 16:
                            case 20:
                                Beep(800, 500);
                                MessageBox(NULL, "Data tidak dapat diubah!!", "Attention",
                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                goto top;
                            case 24:
                                Perizinan(1);
                                break;
                        }
                        if (ct == 22) {
                            if (klik == enter) {
                                TPerizinan.tglAwl = info->tm_mday;
                                TPerizinan.blnAwl = info->tm_mon + 1;
                                TPerizinan.thnAwl = info->tm_year + 1900;
                                fwrite(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan);
                                Beep(800, 500);
                                MessageBox(NULL, "Data berhasil ditambah!!", "Attention",
                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                            }
                        }
                    }
                    break;
                case 2:
                    printFile(37, 2, "fileTxt/Gambar/Cuti.txt");
                    strcpy(TPerizinan.jenisIzin, "Cuti");
                    coorPrint(36, 10, "ID Transaksi     :PRZ");
                    coorPrint(36, 12, "ID Karyawan      :KRY");
                    coord(57, 12), setInt(Usr.id);
                    coorPrint(57, 10, TPerizinan.ID);
                    coorPrint(36, 14, "Alasan           :");
                    coorPrint(36, 16, "Tanggal Awal     :  /  /    ");
                    coorPrint(36, 18, "Tanggal Akhir    :  /  /    ");
                    coorPrint(36, 20, "Sisa Cuti        :");
                    coorPrint(36, 22, "Status           :Diajukan");
                    coorPrint(36, 24, "Simpan          ->");
                    coorPrint(36, 26, "Kembali         ->");
                    coorPrint(36, 28, "Tekan \"Enter\" Untuk Input Data!!");
                    coord(54, 20), setInt(Usr.jmlhCuti);
                    RAlasan(3);
                top2:
                    ct = 10;
                    coord(54, 10);
                    do {
                        choiceMenu2(10, 26, &ct);
                        if (ct == 10 || ct == 12 || ct == 14 || ct == 16 || ct == 18 || ct == 20 || ct == 22 ||
                            ct == 24 || ct == 26) {
                            coord(54, ct);
                        }
                    } while ((sk == pgUp || sk == pgDn) && klik != enter);
                    if (klik == enter) {
                        switch (ct) {
                            case 14:
                                coorPrint(54, 14, "  "), coord(54, 14), getInt(&TPerizinan.IDAlasan, 2);
                                goto top2;
                            case 16:
                                coorPrint(54, 16, "  /  /    "), coord(54, 16), getInt(&TPerizinan.tglAwl, 2);
                                coord(57, 16), getInt(&TPerizinan.blnAwl, 2), coord(60, 16), getInt(&TPerizinan.thnAwl,
                                                                                                    4);
                                if (TPerizinan.blnAwl == 2) {
                                    if (TPerizinan.tglAwl > 29) {
                                        Beep(800, 500);
                                        MessageBox(NULL, "Tanggal tidak tersedia!!", "Attention",
                                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                        goto top2;
                                    }
                                }
                                if (trueDate(TPerizinan.tglAwl, TPerizinan.blnAwl, TPerizinan.thnAwl)) {
                                    rentangHari(TPerizinan.tglAwl, TPerizinan.blnAwl, TPerizinan.thnAwl, &rntg);
                                    if (rntg < 3) {
                                        Beep(800, 500);
                                        MessageBox(NULL, "Batas pengajuan minimal H-3!!", "Attention",
                                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                        coorPrint(54, 16, "  /  /    ");
                                    }
                                } else {
                                    Beep(800, 500);
                                    MessageBox(NULL, "Tanggal tidak sesuai!!", "Attention",
                                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                    coorPrint(54, 16, "  /  /    ");
                                }
                                goto top2;
                            case 18:
                                coorPrint(54, 18, "  /  /    "), coord(54, 18), getInt(&TPerizinan.tglAkhr, 2);
                                coord(57, 18), getInt(&TPerizinan.blnAkhr, 2), coord(60, 18), getInt(
                                        &TPerizinan.thnAkhr, 4);
                                goto top2;
                            case 10:
                            case 12:
                            case 20:
                            case 22:
                                Beep(800, 500);
                                MessageBox(NULL, "Data Tidak Dapat Diubah!!", "Attention",
                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                goto top2;
                            case 26:
                                Perizinan(1);
                                break;
                        }
                        if (ct == 24) {
                            if (klik == enter) {
                                lamahari(TPerizinan.tglAwl, TPerizinan.blnAwl, TPerizinan.thnAkhr, TPerizinan.tglAkhr,
                                         TPerizinan.blnAkhr, TPerizinan.thnAkhr, &TPerizinan.lama);
                                printf("Lama izin = %d", TPerizinan.lama);
                                if (Usr.jmlhCuti >= TPerizinan.lama) {
                                    user = fopen("fileDat/Master/User.dat", "rb");
                                    userTemp = fopen("fileDat/UserTemp.dat", "wb");
                                    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                        if (Usr.id == ID) {
                                            Usr.jmlhCuti -= TPerizinan.lama;
                                            fwrite(&Usr, sizeof(Usr), 1, userTemp);
                                        } else {
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
                                    fwrite(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan);
                                    Beep(800, 500);
                                    MessageBox(NULL, "Data berhasil ditambah!!", "Attention",
                                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                    fclose(user);
                                } else {
                                    Beep(800, 500);
                                    MessageBox(NULL, "Jumlah cuti tidak mencukupi!!", "Attention",
                                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                }
                            }
                        }
                    }
                    break;
                case 3:
                    printFile(70, 2, "fileTxt/Gambar/Sakit.txt");
                    strcpy(TPerizinan.jenisIzin, "Sakit");
                    coorPrint(77, 10, "ID Transaksi     :PRZ");
                    coorPrint(77, 12, "ID Karyawan      :KRY");
                    coord(98, 12), setInt(Usr.id);
                    coorPrint(98, 10, TPerizinan.ID);
                    coorPrint(77, 14, "Tanggal          :  /  /");
                    coord(95, 14), printf("%02d", info->tm_mday);
                    coord(98, 14), printf("%02d", info->tm_mon + 1);
                    coord(101, 14), setInt(info->tm_year + 1900);
                    coorPrint(77, 16, "Lama Izin (Hari) :");
                    coorPrint(77, 18, "Status           :Diajukan");
                    coorPrint(77, 20, "Simpan          ->");
                    coorPrint(77, 22, "Kembali         ->");
                    coorPrint(77, 25, "Tekan \"Enter\" Untuk Input Data!!");
                top3:
                    ct = 10;
                    coord(95, 10);
                    do {
                        choiceMenu2(10, 22, &ct);
                        if (ct == 10 || ct == 12 || ct == 14 || ct == 16 || ct == 18 || ct == 20 || ct == 22) {
                            coord(95, ct);
                        }
                    } while ((sk == pgUp || sk == pgDn) && klik != enter);
                    if (klik == enter) {
                        switch (ct) {
                            case 16:
                                coorPrint(95, 16, "  ");
                                coord(95, 16), getInt(&TPerizinan.lama, 2);
                                goto top3;
                            case 10:
                            case 12:
                            case 14:
                            case 18:
                                Beep(800, 500);
                                MessageBox(NULL, "Data Tidak Dapat Diubah;", "Attention",
                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                goto top3;
                            case 22:
                                Perizinan(1);
                                break;
                        }
                        if (ct == 20) {
                            if (klik == enter) {
                                TPerizinan.tglAwl = info->tm_mday;
                                TPerizinan.blnAwl = info->tm_mon + 1;
                                TPerizinan.thnAwl = info->tm_year + 1900;
                                TPerizinan.IDAlasan = 0;
                                fwrite(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan);
                                Beep(800, 500);
                                MessageBox(NULL, "Data berhasil ditambah!!", "Attention",
                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                            }
                        }
                    }
                    break;
            }
        }
    }
    fclose(user);
    fclose(Tperizinan);
}

void RPerizinan(int typeR) {
    switch (typeR) {
        case 1: // Staff
            coorPrint(75, 1, "[=[=[=[=[  PERIZINAN  ]=]=]=]=]");
            coorPrint(32, 3, "ID Perizinan");
            coorPrint(46, 3, "Lama");
            coorPrint(54, 3, "Jenis");
            coorPrint(64, 3, "Tanggal");
            coorPrint(95, 3, "Alasan");
            coorPrint(135, 3, "Status");
            boxPerizinan();
            i = 0;
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                if (TPerizinan.IDUser == ID) {
                    coorPrint(32, 5 + i, "PRZ");
                    coorPrint(35, 5 + i, TPerizinan.ID);
                    coord(46, 5 + i), setInt(TPerizinan.lama);
                    coorPrint(55, 5 + i, TPerizinan.jenisIzin);
                    coorPrint(62, 5 + i, "  /  /    ");
                    coord(62, 5 + i), printf("%02d", TPerizinan.tglAwl);
                    coord(65, 5 + i), printf("%02d", TPerizinan.blnAwl);
                    coord(68, 5 + i), setInt(TPerizinan.thnAwl);
                    strcmp(TPerizinan.jenisIzin, "IMP") == 0 ? coorPrint(48, 5 + i, "Jam") :
                    coorPrint(48, 5 + i, "Hari");
                    alasan = fopen("fileDat/Master/Alasan.dat", "rb");
                    while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                        if (TPerizinan.IDAlasan == 0) { coorPrint(75, 5 + i, "               -               "); }
                        else if (TPerizinan.IDAlasan == Alasan.KD) { coorPrint(75, 5 + i, Alasan.nama); }
                    }
                    fclose(alasan);
                    if (TPerizinan.status == 0)coorPrint(123, 5 + i, "Menunggu Approval Section");
                    else if (TPerizinan.status == 1)coorPrint(123, 5 + i, "Disetujui Section");
                    else if (TPerizinan.status == 2)coorPrint(123, 5 + i, "Disetujui Kepala Departemen");
                    else if (TPerizinan.status == 3)coorPrint(123, 5 + i, "Disetujui HRD");
                    else if (TPerizinan.status == 4)coorPrint(123, 5 + i, "Ditolak Section");
                    else if (TPerizinan.status == 5)coorPrint(123, 5 + i, "Ditolak Kepala Departemen");
                    else if (TPerizinan.status == 6)coorPrint(123, 5 + i, "Ditolak HRD");
                    i++;
                }
            }
            fclose(Tperizinan);
            break;
        case 2: //IMP
            i = 0;
            coorPrint(52, 3, "[=[=[=[=[  DATA IMP KARYAWAN  ]=]=]=]=]");
            coorPrint(32, 5, "ID Perizinan");
            coorPrint(47, 5, "ID Karyawan");
            coorPrint(59, 5, "Tanggal");
            coorPrint(85, 5, "Alasan");
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                    user = fopen("fileDat/Master/User.dat", "rb");
                    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                        if (Usr.id == ID) {
                            if ((TPerizinan.status == 0 && Usr.role == 5)) { //Section
                                if (strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0 && Usr.id == ID) {
                                    alasan = fopen("fileDat/Master/Alasan.dat", "rb");
                                    while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                                        if (TPerizinan.IDAlasan == Alasan.KD) { coorPrint(72, 6 + i, Alasan.nama); }
                                    }
                                    fclose(alasan);
                                    coorPrint(33, 6 + i, "PRZ");
                                    coorPrint(36, 6 + i, TPerizinan.ID);
                                    coorPrint(47, 6 + i, "KRY");
                                    coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                    coorPrint(59, 6 + i, "  /  /");
                                    coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                    coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                    coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                    i++;
                                }
                            } else if (TPerizinan.status == 1 && Usr.role == 4) {   //Kepala Departemen
                                if (strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0 && Usr.id == ID) {
                                    alasan = fopen("fileDat/Master/Alasan.dat", "rb");
                                    while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                                        if (TPerizinan.IDAlasan == Alasan.KD) { coorPrint(72, 6 + i, Alasan.nama); }
                                    }
                                    fclose(alasan);
                                    coorPrint(33, 6 + i, "PRZ");
                                    coorPrint(36, 6 + i, TPerizinan.ID);
                                    coorPrint(47, 6 + i, "KRY");
                                    coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                    coorPrint(59, 6 + i, "  /  /");
                                    coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                    coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                    coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                    i++;
                                }
                            } else if (TPerizinan.status == 2 && Usr.role == 3) {   //HRD
                                coorPrint(33, 6 + i, "PRZ");
                                coorPrint(36, 6 + i, TPerizinan.ID);
                                coorPrint(47, 6 + i, "KRY");
                                coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                coorPrint(59, 6 + i, "  /  /");
                                coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                alasan = fopen("fileDat/Master/Alasan.dat", "rb");
                                while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                                    if (TPerizinan.IDAlasan == Alasan.KD) { coorPrint(72, 6 + i, Alasan.nama); }
                                }
                                fclose(alasan);
                                i++;
                            }
                        }
                    }
                    fclose(user);
                }
            }
            fclose(Tperizinan);
            break;
        case 3:   //Cuti
            i = 0;
            coorPrint(51, 3, "[=[=[=[=[  DATA CUTI KARYAWAN  ]=]=]=]=]");
            coorPrint(32, 5, "ID Perizinan");
            coorPrint(47, 5, "ID Karyawan");
            coorPrint(59, 5, "Tanggal");
            coorPrint(85, 5, "Alasan");
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                if (strcmp(TPerizinan.jenisIzin, "Cuti") == 0) {
                    user = fopen("fileDat/Master/User.dat", "rb");
                    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                        if (Usr.id == ID) {
                            if (TPerizinan.status == 0 && Usr.role == 5) {  //Section
                                if ((strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) && Usr.id == ID) {
                                    alasan = fopen("fileDat/Master/Alasan.dat", "rb");
                                    while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                                        if (TPerizinan.IDAlasan == Alasan.KD) { coorPrint(72, 6 + i, Alasan.nama); }
                                    }
                                    fclose(alasan);
                                    coorPrint(33, 6 + i, "PRZ");
                                    coorPrint(36, 6 + i, TPerizinan.ID);
                                    coorPrint(47, 6 + i, "KRY");
                                    coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                    coorPrint(59, 6 + i, "  /  /");
                                    coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                    coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                    coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                    i++;
                                }
                            } else if (TPerizinan.status == 1 && Usr.role == 4) {   //Kepala Departemen
                                if ((strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) && Usr.id == ID) {
                                    alasan = fopen("fileDat/Master/Alasan.dat", "rb");
                                    while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                                        if (TPerizinan.IDAlasan == Alasan.KD) { coorPrint(72, 6 + i, Alasan.nama); }
                                    }
                                    fclose(alasan);
                                    coorPrint(33, 6 + i, "PRZ");
                                    coorPrint(36, 6 + i, TPerizinan.ID);
                                    coorPrint(47, 6 + i, "KRY");
                                    coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                    coorPrint(59, 6 + i, "  /  /");
                                    coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                    coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                    coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                    i++;
                                }
                            } else if (TPerizinan.status == 2 && Usr.role == 3) {  //HRD
                                coorPrint(33, 6 + i, "PRZ");
                                coorPrint(36, 6 + i, TPerizinan.ID);
                                coorPrint(47, 6 + i, "KRY");
                                coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                coorPrint(59, 6 + i, "  /  /");
                                coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                alasan = fopen("fileDat/Master/Alasan.dat", "rb");
                                while (fread(&Alasan, sizeof(Alasan), 1, alasan) == 1) {
                                    if (TPerizinan.IDAlasan == Alasan.KD) { coorPrint(72, 6 + i, Alasan.nama); }
                                }
                                fclose(alasan);
                                i++;
                            }
                        }
                    }
                    fclose(user);
                }
            }
            fclose(Tperizinan);
            break;
        case 4:    //Sakit
            i = 0;
            coorPrint(51, 3, "[=[=[=[=[  DATA SAKIT KARYAWAN  ]=]=]=]=]");
            coorPrint(33, 5, "ID Perizinan");
            coorPrint(47, 5, "ID Karyawan");
            coorPrint(59, 5, "Tanggal");
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                if (strcmp(TPerizinan.jenisIzin, "Sakit") == 0) {
                    user = fopen("fileDat/Master/User.dat", "rb");
                    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                        if (Usr.id == ID) {
                            if (TPerizinan.status == 0 && Usr.role == 5) {   //Section
                                if ((strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) && Usr.id == ID) {
                                    coorPrint(33, 6 + i, "PRZ");
                                    coorPrint(36, 6 + i, TPerizinan.ID);
                                    coorPrint(47, 6 + i, "KRY");
                                    coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                    coorPrint(59, 6 + i, "  /  /");
                                    coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                    coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                    coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                    i++;
                                }
                            } else if (TPerizinan.status == 1 && Usr.role == 4) {    //Kepala Departemen
                                if ((strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) && Usr.id == ID) {
                                    coorPrint(33, 6 + i, "PRZ");
                                    coorPrint(36, 6 + i, TPerizinan.ID);
                                    coorPrint(47, 6 + i, "KRY");
                                    coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                    coorPrint(59, 6 + i, "  /  /");
                                    coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                    coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                    coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                    i++;
                                }
                            } else if (TPerizinan.status == 2 && Usr.role == 3) {    //HRD
                                coorPrint(33, 6 + i, "PRZ");
                                coorPrint(36, 6 + i, TPerizinan.ID);
                                coorPrint(47, 6 + i, "KRY");
                                coord(50, 6 + i), setInt(TPerizinan.IDUser);
                                coorPrint(59, 6 + i, "  /  /");
                                coord(59, 6 + i), printf("%02d", TPerizinan.tglAwl);
                                coord(62, 6 + i), printf("%02d", TPerizinan.blnAwl);
                                coord(65, 6 + i), setInt(TPerizinan.thnAwl);
                                i++;
                            }
                        }
                    }
                    fclose(user);
                }
            }
            fclose(Tperizinan);
            break;
    }
}

void UPerizinan(int tipeU) {
    i = 0;
    status = 0;
    int approve = 0;
    string idPerizinan;
    coorPrint(125, 7, "[=[=[=[= APPROVAL =]=]=]=]");
    coorPrint(120, 11, "ID          :PRZ");
    coorPrint(120, 12, "ID Karyawan :KRY");
    coorPrint(120, 13, "Nama        :");
    coorPrint(120, 14, "No Telp     :");
    coorPrint(120, 15, "Lama Izin   :");
    coorPrint(120, 16, "Departemen  :");
    coorPrint(120, 17, "Ubah status :");
    coorPrint(120, 20, "1 untuk setuju");
    coorPrint(120, 21, "0 untuk tolak");
    coorPrint(120, 22, "2 untuk kembali");
    switch (tipeU) {
        case 1:
            coord(136, 11), getStr(idPerizinan, 10);
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
            TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "wb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                if (strcmp(idPerizinan, TPerizinan.ID) == 0) { status = 1; }
                else { fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp); }
            }
            fclose(Tperizinan);
            fclose(TperizinanTemp);

            if (!status) {
                Beep(800, 500);
                MessageBox(NULL, "Data tidak Ditemukan!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            } else {
                Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
                TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "wb");
                while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                    if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                        user = fopen("fileDat/Master/User.dat", "rb");
                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                            if (ID == Usr.id) {
                                if ((TPerizinan.status == 0 && Usr.role == 5) &&
                                    strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) {  // Section
                                    if (strcmp(idPerizinan, TPerizinan.ID) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 1;
                                                break;
                                            case 0:
                                                approve = 4;
                                                break;
                                            case 2:
                                                Perizinan(3);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else if ((TPerizinan.status == 1 && Usr.role == 4) &&
                                           strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) {  // Kepala Departemen
                                    if (strcmp(idPerizinan, TPerizinan.ID) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top2:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 2;
                                                break;
                                            case 0:
                                                approve = 5;
                                                break;
                                            case 2:
                                                Perizinan(4);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top2;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else if (TPerizinan.status == 2 && Usr.role == 3) {  // HRD
                                    if (strcmp(TPerizinan.ID, idPerizinan) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top3:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 3;
                                                break;
                                            case 0:
                                                approve = 6;
                                                break;
                                            case 2:
                                                Perizinan(5);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top3;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else {
                                    fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                }
                            }
                        }
                        fclose(user);
                    } else {
                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                    }
                }
                fclose(Tperizinan);
                fclose(TperizinanTemp);
            }
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "wb");
            TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "rb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp) == 1) {
                fwrite(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan);
            }
            fclose(Tperizinan);
            fclose(TperizinanTemp);
            break;
        case 2:
            coord(136, 11), getStr(idPerizinan, 10);
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
            TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "wb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                if (strcmp(idPerizinan, TPerizinan.ID) == 0) status = 1;
                else { fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp); }
            }
            fclose(Tperizinan);
            fclose(TperizinanTemp);

            if (!status) {
                Beep(800, 500);
                MessageBox(NULL, "Data tidak Ditemukan", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            } else {
                Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
                TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "wb");
                while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                    if (strcmp(TPerizinan.jenisIzin, "Cuti") == 0) {
                        user = fopen("fileDat/Master/User.dat", "rb");
                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                            if (Usr.id == ID) {
                                if ((TPerizinan.status == 0 && Usr.role == 5) &&
                                    strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) {  // Section
                                    if (strcmp(TPerizinan.ID, idPerizinan) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top4:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 1;
                                                break;
                                            case 0:
                                                approve = 4;
                                                break;
                                            case 2:
                                                Perizinan(3);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!      ", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top4;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else if ((TPerizinan.status == 1 && Usr.role == 4) &&
                                           strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) {  // Kepala Departemen
                                    if (strcmp(TPerizinan.ID, idPerizinan) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top5:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 2;
                                                break;
                                            case 0:
                                                approve = 5;
                                                break;
                                            case 2:
                                                Perizinan(4);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top5;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else if (TPerizinan.status == 2 && Usr.role == 3) {  // HRD
                                    if (strcmp(TPerizinan.ID, idPerizinan) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top6:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 3;
                                                break;
                                            case 0:
                                                approve = 6;
                                                break;
                                            case 2:
                                                Perizinan(5);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top6;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else {
                                    fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                }
                            }
                        }
                        fclose(user);
                    } else {
                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                    }
                }
                fclose(Tperizinan);
                fclose(TperizinanTemp);
            }
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "wb");
            TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "rb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp) == 1) {
                fwrite(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan);
            }
            fclose(Tperizinan);
            fclose(TperizinanTemp);
            break;
        case 3:
            coord(136, 11), getStr(idPerizinan, 10);
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
            TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "wb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                if (strcmp(idPerizinan, TPerizinan.ID) == 0) status = 1;
                else { fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp); }
            }
            fclose(Tperizinan);
            fclose(TperizinanTemp);

            if (!status) {
                Beep(800, 500);
                MessageBox(NULL, "Data tidak Ditemukan!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            } else {
                Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
                TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "wb");
                while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                    if (strcmp(TPerizinan.jenisIzin, "Sakit") == 0) {
                        user = fopen("fileDat/Master/User.dat", "rb");
                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                            if (Usr.id == ID) {
                                if ((TPerizinan.status == 0 && Usr.role == 5) &&
                                    strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) {  // Section
                                    if (strcmp(TPerizinan.ID, idPerizinan) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top7:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 1;
                                                break;
                                            case 0:
                                                approve = 4;
                                                break;
                                            case 2:
                                                Perizinan(3);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top7;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else if ((TPerizinan.status == 1 && Usr.role == 4) &&
                                           strcmp(Usr.kdDprtmn, TPerizinan.kdDep) == 0) {  // Kepala Departemen
                                    if (strcmp(TPerizinan.ID, idPerizinan) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top8:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 2;
                                                break;
                                            case 0:
                                                approve = 5;
                                                break;
                                            case 2:
                                                Perizinan(4);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top8;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else if (TPerizinan.status == 2 && Usr.role == 3) {  // HRD
                                    if (strcmp(TPerizinan.ID, idPerizinan) == 0) {
                                        user = fopen("fileDat/Master/User.dat", "rb");
                                        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                                            if (TPerizinan.IDUser == Usr.id) {
                                                coord(136, 12), setInt(Usr.id);
                                                coorPrint(133, 13, Usr.nama);
                                                coorPrint(133, 14, Usr.telp);
                                                coord(133, 15), setInt(TPerizinan.lama);
                                                if (strcmp(TPerizinan.jenisIzin, "IMP") == 0) {
                                                    coorPrint(135, 15, "Jam");
                                                } else {
                                                    coorPrint(136, 15, "Hari");
                                                }
                                                departemen = fopen("fileDat/Master/Departemen.dat", "rb");
                                                while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                                                    if (strcmp(Usr.kdDprtmn, Departemen.ID) == 0) {
                                                        coorPrint(133, 16, Departemen.nama);
                                                    }
                                                }
                                                fclose(departemen);
                                                top9:
                                                coord(133, 17), getInt(&approve, 1);
                                            }
                                        }
                                        fclose(user);
                                        switch (approve) {
                                            case 1:
                                                approve = 3;
                                                break;
                                            case 0:
                                                approve = 6;
                                                break;
                                            case 2:
                                                Perizinan(5);
                                                break;
                                            default:
                                                Beep(800, 500);
                                                MessageBox(NULL, "Inputan Anda Salah!!", "Attention",
                                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                                                goto top9;
                                        }
                                        TPerizinan.status = approve;
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    } else {
                                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                    }
                                } else {
                                    fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                                }
                            }
                        }
                        fclose(user);
                    } else {
                        fwrite(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp);
                    }
                }
                fclose(Tperizinan);
                fclose(TperizinanTemp);
            }
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "wb");
            TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "rb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, TperizinanTemp) == 1) {
                fwrite(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan);
            }
            fclose(Tperizinan);
            fclose(TperizinanTemp);
            break;
    }
}

void approval(int type) {
    coorPrint(75, 1, "[=[=[=[=[  APPROVAL PERIZINAN  ]=]=]=]=]");
    coorPrint(48, 3, "ID Perizinan");
    coorPrint(67, 3, "ID Karyawan");
    coorPrint(84, 3, "Lama Izin");
    coorPrint(99, 3, "Jenis");
    coorPrint(111, 3, "Tanggal");
    coorPrint(124, 3, "Status");
    dataApproval();
    i = 0;
    Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
    while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
        switch (type) {
            case 1: //Section
                user = fopen("fileDat/Master/User.dat", "rb");
                while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                    if (Usr.id == ID) {
                        if (Usr.role == 5 && strcmp(TPerizinan.kdDep, Usr.kdDprtmn) == 0) {
                            if (TPerizinan.status > 0) {
                                coorPrint(47, 5 + i, "PRZ");
                                coorPrint(50, 5 + i, TPerizinan.ID);
                                coorPrint(68, 5 + i, "KRY");
                                coord(71, 5 + i), setInt(TPerizinan.IDUser);
                                coord(85, 5 + i), setInt(TPerizinan.lama);
                                coorPrint(99, 5 + i, TPerizinan.jenisIzin);
                                strcmp(TPerizinan.jenisIzin, "IMP") == 0 ? coorPrint(88, 5 + i, "Jam") :
                                coorPrint(88, 5 + i, "Hari");
                                coorPrint(108, 5 + i, "  /  /    ");
                                coord(109, 5 + i), printf("%02d", TPerizinan.tglAwl);
                                coord(112, 5 + i), printf("%02d", TPerizinan.blnAwl);
                                coord(115, 5 + i), setInt(TPerizinan.thnAwl);
                                if (TPerizinan.status > 0 && TPerizinan.status != 4)coorPrint(123, 5 + i, "Disetujui");
                                else if (TPerizinan.status == 4)coorPrint(123, 5 + i, "Ditolak");
                                i++;
                            }
                        }
                    }
                }
                fclose(user);
                break;
            case 2: // Kepala Departemen
                user = fopen("fileDat/Master/User.dat", "rb");
                while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                    if (Usr.id == ID) {
                        if (Usr.role == 4 && strcmp(TPerizinan.kdDep, Usr.kdDprtmn) == 0) {
                            if ((TPerizinan.status > 1 && TPerizinan.status < 4) ||
                                (TPerizinan.status == 5 || TPerizinan.status == 6)) {
                                coorPrint(47, 5 + i, "PRZ");
                                coorPrint(50, 5 + i, TPerizinan.ID);
                                coorPrint(68, 5 + i, "KRY");
                                coord(71, 5 + i), setInt(TPerizinan.IDUser);
                                coord(85, 5 + i), setInt(TPerizinan.lama);
                                coorPrint(99, 5 + i, TPerizinan.jenisIzin);
                                strcmp(TPerizinan.jenisIzin, "IMP") == 0 ? coorPrint(88, 5 + i, "Jam") :
                                coorPrint(88, 5 + i, "Hari");
                                coorPrint(108, 5 + i, "  /  /    ");
                                coord(109, 5 + i), printf("%02d", TPerizinan.tglAwl);
                                coord(112, 5 + i), printf("%02d", TPerizinan.blnAwl);
                                coord(115, 5 + i), setInt(TPerizinan.thnAwl);
                                if (TPerizinan.status == 2 || TPerizinan.status == 3 || TPerizinan.status == 6)
                                    coorPrint(123, 5 + i, "Disetujui");
                                else coorPrint(123, 5 + i, "Ditolak");
                                i++;
                            }
                        }
                    }
                }
                fclose(user);
                break;
            case 3: //HRD
                user = fopen("fileDat/Master/User.dat", "rb");
                while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                    if (Usr.id == ID) {
                        if (Usr.role == 3 && (TPerizinan.status == 3 || TPerizinan.status == 6)) {
                            coorPrint(47, 5 + i, "PRZ");
                            coorPrint(50, 5 + i, TPerizinan.ID);
                            coorPrint(68, 5 + i, "KRY");
                            coord(71, 5 + i), setInt(TPerizinan.IDUser);
                            coord(85, 5 + i), setInt(TPerizinan.lama);
                            coorPrint(99, 5 + i, TPerizinan.jenisIzin);
                            strcmp(TPerizinan.jenisIzin, "IMP") == 0 ? coorPrint(88, 5 + i, "Jam") :
                            coorPrint(88, 5 + i, "Hari");
                            coorPrint(108, 5 + i, "  /  /    ");
                            coord(109, 5 + i), printf("%02d", TPerizinan.tglAwl);
                            coord(112, 5 + i), printf("%02d", TPerizinan.blnAwl);
                            coord(115, 5 + i), setInt(TPerizinan.thnAwl);
                            if (TPerizinan.status == 3)coorPrint(123, 5 + i, "Disetujui");
                            else coorPrint(123, 5 + i, "Ditolak");
                            i++;
                        }
                    }
                }
                fclose(user);
                break;
        }
    }
    fclose(Tperizinan);
}

void Perizinan(int tipe) {
    do {
        a = 0;
        coorPrint(27, pc, " ");
        printFile(4, 10, "fileTxt/Menu/PerizinanKaryawan.txt");
        for (int k = 0; k < 4; ++k) {
            box2(3, 10 + a), a += 3;
        }
        t:
        pc = 10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 19, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19) {
                coorPrint(27, c, "<");
            }
            pc = c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (tipe) {
                case 1:
                    switch (c) {
                        case 10:
                            cleanField(), CPerizinan(1);
                            break;
                        case 13:
                            cleanField(), CPerizinan(2);
                            break;
                        case 16:
                            cleanField(), uiDashboard(), CPerizinan(3);
                            break;
                        case 19:
                            cleanField(), cleanMenu(), uiDashboard(), menuStaff();
                            break;
                    }
                    break;
                case 2:
                    cleanField(), RPerizinan(1);
                    break;
                case 3:  // Section
                    user = fopen("fileDat/Master/User.dat", "rb");
                    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                        if (Usr.role == 5) {
                            switch (c) {
                                case 10:
                                    cleanField(), uiUpdatePrz(), RPerizinan(2), UPerizinan(1);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 13:
                                    cleanField(), uiUpdatePrz(), RPerizinan(3), UPerizinan(2);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 16:
                                    cleanField(), uiUpdatePrz(), RPerizinan(4), UPerizinan(3);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 19:
                                    cleanField(), cleanMenu(), uiDashboard(), menuSection();
                                    break;
                            }
                        }
                    }
                    fclose(user);
                    break;
                case 4:  //Kepala Departemen
                    user = fopen("fileDat/Master/User.dat", "rb");
                    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                        if (Usr.role == 4) {
                            switch (c) {
                                case 10:
                                    cleanField(), uiUpdatePrz(), RPerizinan(2), UPerizinan(1);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 13:
                                    cleanField(), uiUpdatePrz(), RPerizinan(3), UPerizinan(2);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 16:
                                    cleanField(), uiUpdatePrz(), RPerizinan(4), UPerizinan(3);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 19:
                                    cleanField(), cleanMenu(), uiDashboard(), menuKepalaDepartemen();
                                    break;
                            }
                        }
                    }
                    fclose(user);
                    break;
                case 5:  //HRD
                    user = fopen("fileDat/Master/User.dat", "rb");
                    while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
                        if (Usr.role == 3) {
                            switch (c) {
                                case 10:
                                    cleanField(), uiUpdatePrz(), RPerizinan(2), UPerizinan(1);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 13:
                                    cleanField(), uiUpdatePrz(), RPerizinan(3), UPerizinan(2);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 16:
                                    cleanField(), uiUpdatePrz(), RPerizinan(4), UPerizinan(3);
                                    coorPrint(27, c, " ");
                                    goto t;
                                case 19:
                                    cleanField(), cleanMenu(), uiDashboard(), menuHRD();
                                    break;
                            }
                        }
                    }
                    fclose(user);
                    break;
            }
        }
    } while (c != 19);
}

void dataPengajuanKaryawan(int type) {
    switch (type) {
        case 1: // Section
            do {
                a = 0;
                coorPrint(27, pc, " ");
                printFile(4, 10, "fileTxt/Menu/PengajuanKaryawan.txt");
                for (int k = 0; k < 4; ++k) {
                    box2(3, 10 + a);
                    a += 3;
                }
                pc = 10;
                c = 10;
                coorPrint(27, 10, "<");
                do {
                    choiceMenu3(10, 19, &c);
                    coorPrint(27, pc, " ");
                    if (c == 10 || c == 13 || c == 16 || c == 19) {
                        coorPrint(27, c, "<");
                    }
                    pc = c;
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if (klik == enter) {
                    switch (c) {
                        case 10:
                            cleanField();
                            break;
                        case 13:
                            cleanMenu(), Perizinan(3);
                            break;
                        case 16:
                            cleanField();
                            break;
                        case 19:
                            cleanField(), cleanMenu(), menuSection();
                            break;
                    }
                }
            } while (c != 19);
            break;
        case 2:  //Kepala Departemen
            do {
                a = 0;
                coorPrint(27, pc, " ");
                printFile(4, 10, "fileTxt/Menu/PengajuanKaryawan.txt");
                for (int k = 0; k < 4; ++k) {
                    box2(3, 10 + a);
                    a += 3;
                }
                pc = 10;
                c = 10;
                coorPrint(27, 10, "<");
                do {
                    choiceMenu3(10, 19, &c);
                    coorPrint(27, pc, " ");
                    if (c == 10 || c == 13 || c == 16 || c == 19) {
                        coorPrint(27, c, "<");
                    }
                    pc = c;
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if (klik == enter) {
                    switch (c) {
                        case 10:
                            cleanField();
                            break;
                        case 13:
                            cleanMenu(), Perizinan(4);
                            break;
                        case 16:
                            cleanField();
                            break;
                        case 19:
                            cleanField(), cleanMenu(), menuKepalaDepartemen();
                            break;
                    }
                }
            } while (c != 19);
            break;
        case 3:  //HRD
            do {
                a = 0;
                coorPrint(27, pc, " ");
                printFile(4, 10, "fileTxt/Menu/PengajuanKaryawan.txt");
                for (int k = 0; k < 4; ++k) {
                    box2(3, 10 + a);
                    a += 3;
                }
                pc = 10;
                c = 10;
                coorPrint(27, 10, "<");
                do {
                    choiceMenu3(10, 19, &c);
                    coorPrint(27, pc, " ");
                    if (c == 10 || c == 13 || c == 16 || c == 19) {
                        coorPrint(27, c, "<");
                    }
                    pc = c;
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if (klik == enter) {
                    switch (c) {
                        case 10:
                            cleanField();
                            break;
                        case 13:
                            cleanMenu(), Perizinan(5);
                            break;
                        case 16:
                            cleanField();
                            break;
                        case 19:
                            cleanField(), cleanMenu(), menuHRD();
                            break;
                    }
                }
            } while (c != 19);
            break;
    }
}

void Pengajuan() {
    do {
        a = 0;
        coorPrint(27, pc, " ");
        printFile(4, 10, "fileTxt/Menu/PengajuanKaryawan.txt");
        for (int k = 0; k < 4; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc = 10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 19, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19) {
                coorPrint(27, c, "<");
            }
            pc = c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10:
                    cleanMenu(), TMedis(1);
                    break;
                case 13:
                    cleanMenu(), Perizinan(1);
                    break;
                case 16:
                    cleanField(), CPengaduan();
                    break;
                case 19:
                    cleanField(), cleanMenu(), menuStaff();
                    break;
            }
        }
    } while (c != 19);
}

void daftarPengajuan() {
    do {
        a = 0;
        coorPrint(27, pc, " ");
        printFile(4, 10, "fileTxt/Menu/PengajuanKaryawan.txt");
        for (int k = 0; k < 4; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc = 10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 19, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19) {
                coorPrint(27, c, "<");
            }
            pc = c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10:
                    cleanField(), RMedis(2);
                    break;
                case 13:
                    cleanField(), RPerizinan(1);
                    break;
                case 16:
                    cleanField(), RPengaduan();
                    break;
                case 19:
                    cleanField(), cleanMenu(), menuStaff();
                    break;
            }
        }
    } while (c != 19);
}