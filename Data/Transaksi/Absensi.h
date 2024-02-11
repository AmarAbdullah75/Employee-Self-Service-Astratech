#include <stdio.h>
#include <windows.h>
#include "AbsensiMakan.h"

void menuabsensi();

ABSENSI absen;
//USER usr;

void Cabsensi() {
    int Jam, Mnt, id = 0;
    absensi = fopen("fileDat/Transaksi/Absensi.dat", "rb");
    while (fread(&absen, sizeof(absen), 1, absensi) == 1) {
        id = absen.kodeabsen;
    }
    absen.kodeabsen = id + 1;
    do {
        a = 0;
        printFile(4, 10, "fileTxt/Menu/MENUCRABSENSI.txt");
        for (int k = 0; k < 3; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc = 10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 16, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16) {
                coorPrint(27, c, "<");
            }
            pc = c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);

        if (klik == enter) {
            switch (c) {
                case 10:
                    cleanField();
                    DesainData();
                    printFile(70, 15, "fileTxt/Menu/absensi.txt");
                    printFile(70, 7, "fileTxt/Menu/ASTRA.txt");
                    printFile(37, 1, "fileTxt/Menu/EMPLOYEE.txt");
                    coord(73, 23), hari();
                    coord(113, 23), jam();
                    coorPrint(77, 28, "Tanggal                   :");
                    coord(104, 28), hari();
                    coorPrint(77, 30, "Masukan Jam Datang(00:00) :  :");
                top :
                    coord(104, 30), getInt(&Jam, 2);
                    coord(107, 30), getInt(&Mnt, 2);
                    if (Jam >= 12 && Mnt > 00) {
                        MessageBox(NULL, "SUDAH MELEWATI JAM ABSENSI", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        coorPrint(118, 35, "  ");
                        coorPrint(121, 35, "  ");
                        goto top;
                    } else {
//                        fwrite(&absen, sizeof(absen), 1, absensi);
                        MessageBox(NULL, "BERHASIL MELAKUKAN ABSENSI", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

                    }
                    break;
                case 13:

                    absensi = fopen("fileDat/Transaksi/Absensi.dat", "ab");
                    cleanField();
//                    pinggiran();
                    DesainData();
                    printFile(70, 15, "fileTxt/Menu/absensi.txt");
                    printFile(70, 7, "fileTxt/Menu/ASTRA.txt");
                    printFile(37, 1, "fileTxt/Menu/EMPLOYEE.txt");
                    coord(73, 23), hari();
                    coord(113, 23), jam();
                    coorPrint(77, 28, "Tanggal                   : ");
                    coord(104, 28), hari();
                    coorPrint(77, 30, "Jam Datang                :  :");
                    coord(104, 30), printf("%02d", Jam);
                    coord(107, 30), printf("%02d", Mnt);
                    absen.hour = Jam;
                    absen.min = Mnt;
                    absen.iduser = ID;
                    coorPrint(77, 32, "Masukan Jam Pulang(00:00) :  :");
                top2 :
                    coord(104, 32);
                    getInt(&absen.hourp, 2);
                    coord(107, 32);
                    getInt(&absen.minp, 2);
                    if (absen.hourp <= 16 && absen.minp < 30) {
                        MessageBox(NULL, "BELUM BISA MELAKUKAN ABSENSI", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        coorPrint(118, 38, "  ");
                        coorPrint(121, 38, "  ");
                        goto top2;
                    }
                    if (absen.jam >= 7) {
                        if (Jam == 7 && Mnt <= 30) {
                            strcpy(absen.status, "Tepat Waktu");
                        } else {
                            if (absen.jam > 7) {
                                strcpy(absen.status, "Terlambat");
                            }
                        }
                    } else {
                        strcpy(absen.status, "Tepat Waktu");
                    }
                    fwrite(&absen, sizeof(absen), 1, absensi);
                    MessageBox(NULL, "BERHASIL MELAKUKAN ABSENSI", "Attention",
                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    fclose(absensi);
                    break;
                case 16:
                    menuabsensi();
                    break;

            }
        }
    } while (c != 16);

}

void Rabsensi() {
    i = 0;
    absensi = fopen("fileDat/Transaksi/Absensi.dat", "rb");
    absnKehadiran();
    coorPrint(85, 1, "Tabel Absensi Kehadiran");
    coorPrint(38, 3, "Kode Absensi  ");
    coorPrint(78, 3, "Id User  ");
    coorPrint(116, 3, "Jam Datang  ");
    coorPrint(138, 3, "Jam Pulang ");
    while (fread(&absen, sizeof(absen), 1, absensi) == 1) {
        coorPrint(40, 5 + i, "ABS");
        coord(43, 5 + i), setInt(absen.kodeabsen);
        coorPrint(75, 5 + i, "KRY");
        coord(78, 5 + i), setInt(absen.iduser);
        coorPrint(118, 5 + i, ":");
        if (absen.hour < 10) {
            coorPrint(116, 5 + i, "0");
            coord(117, 5 + i), setInt(absen.hour);
        } else {
            coord(116, 5 + i), setInt(absen.hour);
        }
        if (absen.min < 10) {
            coorPrint(119, 5 + i, "0");
            coord(120, 5 + i), setInt(absen.min);
        } else {
            coord(119, 5 + i), setInt(absen.min);
        }
        coorPrint(145, 5 + i, ":");
        if (absen.hourp < 10) {
            coorPrint(143, 5 + i, "0");
            coord(144, 5 + i), setInt(absen.hourp);
        } else {
            coord(143, 5 + i), setInt(absen.hourp);
        }
        if (absen.minp < 10) {
            coorPrint(146, 5 + i, "0");
            coord(147, 5 + i), setInt(absen.minp);
        } else {
            coord(146, 5 + i), setInt(absen.minp);
        }

        i++;
    }
    fclose(absensi);
}

void menuabsensi() {
    do {
        a = 0;
        coorPrint(27, pc, " ");
        printFile(4, 10, "fileTxt/Menu/CRUDmenuabsensi.txt");
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
            if (c == 10 || c == 13 || c == 16||c==19) {
                coorPrint(27, c, "<");
            }
            pc = c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);

        if (klik == enter) {
            switch (c) {
                case 10:
                    cleanMenu(), Cabsensi();
                    break;
                case 13:
                    cleanMenu(), Cabsensimakan();
                    break;
                case 16:
                    cleanField(), cleanMenu(), menuStaff();
                    break;
                case 19:
                    exit(0);
            }
        }
    } while (c != 16 && c != 19);
}