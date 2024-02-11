//#include "../StructTransaksi.h"
//#include "../../Pages/Menu.h"
//#include "../../SupportFunction/IOVal.h"
//#include "../../SupportFunction/Transisi.h"
//#include "../../SupportFunction/pgUpPgDn.h"
//#include "../StructTransaksi.h"
//    void cleanRight();
    void boxpengaduan();
//    void waktu();
void UPerizinan(int type);
void choiceMenu(int awal, int akhir, int *x);
//void TPengaduan();

PENGADUAN pgdn;

void CPengaduan() {
    boxpengaduan();
    int p = 1;
    string b;
    Pengaduan = fopen("fileDat/Pengaduan.dat", "rb");
    while(fread(&pgdn, sizeof(pgdn), 1, Pengaduan) == 1){
        p++;
    }
    fclose(Pengaduan);

    Pengaduan = fopen("fileDat/Pengaduan.dat", "ab");
    if(p < 10){
        coorPrint(45, 24, "KD Pengaduan       :PGDN00");
        coord(71, 24);
        setInt(p);
        strcpy(pgdn.KD, "PGDN00");
        snprintf(b, sizeof(b), "%d", p);
        strcat(pgdn.KD, b);
    }else if(p < 100){
        coorPrint(45, 24, "KD Pengaduan             :PGDN0");
        coord(70, 24);
        setInt(p);
        strcpy(pgdn.KD, "PGDN0");
        snprintf(b, sizeof(b), "%d", p);
        strcat(pgdn.KD, b);
    }else{
        coorPrint(45, 24, "ID             :PGDN");
        coord(69, 24);
        setInt(p);
        strcpy(pgdn.KD, "PGDN");
        snprintf(b, sizeof(b), "%d", p);
        strcat(pgdn.KD, b);
    }
    string ngadu;
    Pengaduan = fopen("fileDat/Pengaduan.dat", "ab");
    coorPrint(45,26,"Jenis Pengaduan(No):");
    coorPrint(45,28,"Tanggal            :");
    coorPrint(45,30,"ID Karyawan        :KRY");
    coord(68,30), setInt(ID);
    coorPrint(45,32,"IDDepartemen_Tujuan:");
    coorPrint(45,34,"Deskripsi Singkat  :");
    coorPrint(45,36,"Status             :");
    coorPrint(65,36, "Pengaduan Diajukan");
    strcpy(ngadu, "Pengaduan Diajukan");
    waktu();
    pgdn.ID_User = ID;
    coorPrint(32,2,"RL012    Departemen Pelayanan Umum");
    coorPrint(32,5,"RL013    Departemen Pusat Sistem Informasi");
    printFile(90, 1, "fileTxt/Menu/Jenis Pengaduan.txt");

    coord(65,26);getInt(&pgdn.jenis, 3);
    coord(65,28);getStr(pgdn.tanggal,17);
    coord(65, 32); getStr(pgdn.ID_Role, 5);
    coord(65,34);getStr(pgdn.deskripsi, 30);
    MessageBox(NULL, "Pengaduan Berhasil Diajukan", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);


    fwrite(&pgdn, sizeof(pgdn), 1, Pengaduan);
    fclose(Pengaduan);
}

void RPengaduan() {
    cleanRight();
    int i = 0;
    boxURTable();

    Pengaduan = fopen("fileDat/Pengaduan.dat", "rb");
    coorPrint(75, 2, "Pengaduan");
    coorPrint(34, 5, "KD                 ");
    coorPrint(56, 5, "Jenis Pengaduan         ");
    coorPrint(98, 5, "Deskripsi          ");
    coorPrint(130, 5, "Status              ");

    while (fread(&pgdn, sizeof(pgdn), 1, Pengaduan) == 1) {
        coorPrint(32, 7 + i, pgdn.KD);

        if (pgdn.jenis == 001) {
            coorPrint(44, 7 + i, "Pengaduan Keluhan Aplikasi dan Web (PSI)");
        } else if (pgdn.jenis == 002) {
            coorPrint(44, 7 + i, "Pengaduan Kerusakan Fasilitas Gedung (DPU)");
        } else if (pgdn.jenis == 003) {
            coorPrint(44, 7 + i, "Pengaduan Layanan Desktop (PSI)");
        } else if (pgdn.jenis == 004) {
            coorPrint(44, 7 + i, "Pengaduan Layanan Jaringan (PSI)");
        } else if (pgdn.jenis == 005) {
            coorPrint(44, 7 + i, "Permintaan Akun dan Hak Akses (PSI)");
        } else if (pgdn.jenis == 006) {
            coorPrint(44, 7 + i, "Permintaan Fitur Aplikasi dan Web (PSI)");
        } else if (pgdn.jenis == 007) {
            coorPrint(44, 7 + i, "Permintaan Personil (Event) (PSI)");
        }
        coorPrint(87, 7 + i, pgdn.deskripsi);

        if (pgdn.StatusPengaduan == 0) {
            coorPrint(118, 7 + i, "Menunggu Approval Kepala Departemen");
        } else if (pgdn.StatusPengaduan == 1) {
            coorPrint(110, 7 + i, "Disetujui Kepala Departemen");
        } else if (pgdn.StatusPengaduan == 2)
            coorPrint(110, 7 + i, "Ditolak Kepala Departemen");
        i++;
    }
    fclose(Pengaduan);
}

void UPengaduan() {
    int i = 0,status = 0;
    int approve;
    string searchID;
    boxURTable();

//        coorPrint(80, 10, "Masukkan KD : ");
//        coord(96, 10);getStr(searchKD);

    coord(50,5);RPengaduan();
    coorPrint(44, 38, "KD              :");
    coorPrint(44, 39, "Jenis Pengaduan :");
    coorPrint(44, 40, "Role            :");
    coorPrint(44, 41, "Deskripsi       :");
    coorPrint(44, 42, "Ubah status     :");
    coorPrint(120, 39, "1 untuk setuju");
    coorPrint(120, 40, "0 untuk tolak");
    coorPrint(120, 41, "2 untuk kembali");

    coord(61, 38);getStr(searchID,10);
    Pengaduan = fopen("fileDat/Pengaduan.dat", "rb");
    pengaduanTemp = fopen("fileDat/PengaduanTemp.dat", "wb");
    while (fread(&pgdn, sizeof(pgdn), 1, Pengaduan) == 1) {
        if (strcmp(searchID, pgdn.KD) == 0) {
            coorPrint(62, 41, pgdn.deskripsi);
            status = 1;
            fwrite(&pgdn, sizeof(pgdn), 1, pengaduanTemp);
            break;
        }
    }
    fclose(Pengaduan);
    fclose(pengaduanTemp);

    if (!status) {
        Beep(800, 500);
        MessageBox(NULL, "Data tidak Ditemukan", "Attention",
                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        coord(62,42);getInt(&approve, 1);

        Pengaduan = fopen("fileDat/Pengaduan.dat", "rb");
        pengaduanTemp = fopen("fileDat/PengaduanTemp.dat", "wb");

        while (fread(&pgdn, sizeof(pgdn), 1, pengaduanTemp) == 1) {
            if (strcmp(searchID, pgdn.KD) == 0) {
                // Update status berdasarkan inputan dari user
                pgdn.StatusPengaduan = approve;

                // Salin rekaman yang sudah diupdate ke file sementara
                fwrite(&pgdn, sizeof(pgdn), 1, pengaduanTemp);
            } else {
                // Salin rekaman yang tidak berubah ke file sementara
                fwrite(&pgdn, sizeof(pgdn), 1, pengaduanTemp);
            }
        }

        fclose(Pengaduan);
        fclose(pengaduanTemp);
    }

    Pengaduan = fopen("fileDat/Pengaduan.dat", "wb");
    pengaduanTemp = fopen("fileDat/PengaduanTemp.dat", "rb");
    while (fread(&pgdn, sizeof(pgdn), 1, pengaduanTemp) == 1) {
        fwrite(&pgdn, sizeof(pgdn), 1, Pengaduan);
    }
    fclose(Pengaduan);
    fclose(pengaduanTemp);
}

//void TPengaduan(int type) {
//    int c = 15;
//    do {
//        a = 0;
//        printFile(4, 10, "fileTxt/Menu/PengaduanKaryawan.txt");
//        for (int k = 0; k < 2; ++k) {
//            box2(3, 10 + a);
//            a += 3;
//        }
//        c = 10;
//        coord(28, 10);
//        do {
//            choiceMenu(10, 13, &c);
//            if (c == 10 || c == 13) {
//                coord(28, c);
//            }
//        } while ((sk == pgUp || sk == pgDn) && klik != enter);
//        if (klik == enter) {
//            switch (c) {
//                case 1:
//                    switch (c) {
//                        case 10:
//                            cleanField(), CPengaduan();
//                            break;
//                        case 13:
//                            cleanField(), cleanMenu(), uiDashboard(), menuKaryawan();
//                            break;
//                    }
//                    break;
//                case 2:
//                    cleanField(), RPengaduan();
//                    break;
//                case 3://Kepala Departemen
//                    switch (c) {
//                        case 10:
//                            cleanField(), RPengaduan(), UPengaduan();
//                            break;
//                        case 13:
//                            cleanField(), cleanMenu(), uiDashboard(), menuKepalaDepartemen();
//                            break;
//                    }
//            }
//        }
//    } while (c != 19);
//}

//void dataPengajuanKaryawan() {
//    int c = 15;
//    //Kepala Departemen
//    do {
//        a = 0;
//        printFile(4, 10, "fileTxt/Menu/PengajuanKaryawan.txt");
//        for (int k = 0; k < 4; ++k) {
//            box2(3, 10 + a);
//            a += 3;
//        }
//        c = 10;
//        coord(28, 10);
//        do {
//            choiceMenu(10, 19, &c);
//            if (c == 10 || c == 13 || c == 16 || c == 19) {
//                coord(28, c);
//            }
//        } while ((sk == pgUp || sk == pgDn) && klik != enter);
//        if (klik == enter) {
//            switch (c) {
//                case 10:
//                    cleanField();
//                    break;
//                case 13:
//                    cleanMenu();
//                    break;
//                case 16:
//                    cleanField(),TPengaduan(3);
//                    break;
//                case 19:
//                    cleanField(), cleanMenu(), menuKepalaDepartemen();
//                    break;
//            }
//        }
//    } while (c != 19);
//}