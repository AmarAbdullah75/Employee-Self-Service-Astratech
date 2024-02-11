#include "../Data/Master/User.h"
#include "../Data/Transaksi/Absensi.h"
#include "../Data/Laporan/Laporan Perizinan.h"
void daftarPengajuan();
void dataPengajuanKaryawan(int type);
void Pengajuan();
void approval(int type);

void profile(){
    uiProfile();
    user = fopen("fileDat/Master/User.dat", "rb");
    while(fread(&Usr, sizeof(Usr), 1, user) == 1){
        if(Usr.id==ID){
            coorPrint(70, 17, "ID            :KRY");
            coorPrint(70, 19, "Nama          :");
            coorPrint(70, 21, "Alamat        :");
            coorPrint(70, 23, "Tanggal Lahir :");
            coorPrint(70, 25, "No Telepon    :");
            coorPrint(70, 27, "Cuti          :");
            coorPrint(70, 29, "Plafon Medis  :");
            coord(88, 17);setInt(Usr.id);
            coorPrint(85, 19, Usr.nama);
            coorPrint(85, 21, Usr.alamat);
            coorPrint(85, 23, Usr.lahir);
            coorPrint(85, 25, Usr.telp);
            coord(85, 27);setInt(Usr.jmlhCuti);
            coord(85, 29);setInt(Usr.plafonMedis);
        }
    }
    fclose(user);
}
void menuHRD() {
    printFile(32, 10, "fileTxt/Gambar/AstraPolytechnic.txt");
    do {
        a = 0;
        coorPrint(14, 2, "HRD");
        printFile(4, 10, "fileTxt/Menu/MenuHRD.txt");
        for (int k = 0; k < 8; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 31, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25 || c == 28 || c == 31) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10:cleanField(), profile();
                    break;
                case 13:cleanField(); //Absensi
                    break;
                case 16:cleanField();  //Medical
                    break;
                case 19:cleanMenu(), dataPengajuanKaryawan(3);
                    break;
                case 22:cleanField(),laporanPerizinan();  //Rekap Absen  //Rekap Absen
                    break;
                case 25:cleanField(); //Rekap Transaksi Medical
                    break;
                case 28 :cleanField(), approval(3);
                    break;
                case 31 :cleanRight(), login();
                    break;
            }
            coorPrint(27, pc, " ");
        }
    } while (c != 31);
}
void menuStaff() {
    printFile(32, 10, "fileTxt/Gambar/AstraPolytechnic.txt");
    do {
        a = 0;
        coorPrint(11, 2, "Staff");
        printFile(4, 10, "fileTxt/Menu/MenuKaryawan.txt");
        for (int k = 0; k < 7; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 28, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25 || c==28) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10:cleanField(), profile();
                    break;
                case 13:cleanMenu(), menuabsensi();
                    break;
                case 16:cleanMenu(), Pengajuan();
                    break;
                case 19:cleanMenu(), daftarPengajuan();
                    break;
                case 22:cleanField(), RPengumuman();
                    break;
                case 25:cleanField(), RMenuMakanan();
                    break;
                case 28:cleanRight(), login();
                    break;
            }
            coorPrint(27, pc, " ");
        }
    } while (c != 31);
}

void akun() {
    do {
        coorPrint(27, pc, " ");
        a = 0;
        printFile(4, 10, "fileTxt/Register.txt");
        for (int k = 0; k < 6; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc = 10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 25, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25) {
                coorPrint(27,c,"<");
            }
            pc = c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);

        if (klik == enter) {
            switch (c) {
                case 10:cleanField(), UICreateUser(), CUser();
                    break;
                case 13:cleanField(), uiDashboard(), boxTabel(), RUser();
                    break;
                case 16:cleanField(), uiDashboard(), UUser();
                    break;
                case 19:cleanField(), uiDashboard(), DUser();
                    break;
                case 22:cleanMenu(), cleanField(), superPIC();
                    break;
                case 25:exit(0);
            }
            coorPrint(27, pc, " ");
        }
    } while (c != 25 && c != 22);
}


void menuPICSuper() {
    printFile(32, 10, "fileTxt/Gambar/AstraPolytechnic.txt");
    do {
        a = 0;
        coorPrint(10, 2, "Super PIC");
        printFile(4, 10, "fileTxt/Menu/MenuSuperAdmin.txt");
        for (int k = 0; k < 6; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc = 10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 25, &c);
            coorPrint(26, pc, "  ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c==25) {
                coorPrint(27, c, "<");
            }
            pc = c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10 :cleanField(), profile();
                    break;
                case 13 :cleanMenu(), akun();
                    break;
                case 16:cleanMenu(), menuRole();
                    break;
                case 19:cleanMenu(), menuAlasan();
                    break;
                case 22:cleanMenu(), menuDepartemen();
                    break;
                case 25 :cleanRight(), login();
                    break;
            }
            coorPrint(27, pc, " ");
        }
    } while (c != 22);
}

void menuPICHRD() {
    printFile(32, 10, "fileTxt/Gambar/AstraPolytechnic.txt");
    do {
        a = 0;
        coorPrint(10, 2, "PIC HRD");
        printFile(4, 10, "fileTxt/Menu/MenuPICHRD.txt");
        for (int k = 0; k < 7; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc = 10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 28, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25 || c == 28) {
                coorPrint(27, c, "<");
            }
            pc = c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10:cleanField(), profile();
                    break;
                case 13:cleanMenu(), menuPengumuman();
                    break;
                case 16:cleanMenu(), menumakanan();
                    break;
                case 19:cleanField(), Rabsensi();
                    break;
                case 22:cleanField();
                    break;
                case 25:cleanMenu();
                    break;
                case 28:cleanRight(), login();
                    break;
            }
            coorPrint(27, pc, " ");
        }
    } while (c != 28);
}

void menuPICMedical() {
    printFile(32, 10, "fileTxt/Gambar/AstraPolytechnic.txt");
    do {
        a = 0;
        coorPrint(10, 2, "PIC Medical");
        printFile(5, 10, "fileTxt/Menu/MenuPICMedical.txt");
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
            if (c == 10 || c == 13 || c == 16 || c==19) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10:cleanField(), profile();
                    break;
                case 13:cleanMenu(), menuMedical();
                    break;
                case 16:cleanField(), dataPengajuanKaryawan(2);
                    break;
                case 19:cleanLeft(), login();
                    break;
            }
            coorPrint(27, pc, " ");
        }
    } while (c != 16);
}

void menuKepalaDepartemen(){
    printFile(32, 10, "fileTxt/Gambar/AstraPolytechnic.txt");
    do {
        a = 0;
        coorPrint(8, 2, "Kepala Departemen");
        printFile(4, 10, "fileTxt/Menu/MenuKepalaDepartemen.txt");
        for (int k = 0; k < 7; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 28, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25 || c == 28) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if(klik == enter){
            switch (c) {
                case 10:cleanField(), profile();
                    break;
                case 13:cleanField(); //Absensi
                    break;
                case 16:cleanField();  //Pengajuan
                    break;
                case 19:cleanMenu(); //Daftar Pengajuan
                    break;
                case 22:cleanMenu(), dataPengajuanKaryawan(2);
                    break;
                case 25:cleanField(), approval(2);
                    break;
                case 28:cleanRight(), login();
                    break;
            }
            coorPrint(27, pc, " ");
        }
    }while(c!=28);
}

void menuSection() {
    printFile(32, 10, "fileTxt/Gambar/AstraPolytechnic.txt");
    do {
        a = 0;
        coorPrint(10, 2, "Section");
        printFile(4, 10, "fileTxt/Menu/MenuSection.txt");
        for (int k = 0; k < 7; ++k) {
            box2(3, 10 + a);
            a += 3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 28, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25 || c==28) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if (klik == enter) {
            switch (c) {
                case 10:cleanField(), profile();
                    break;
                case 13:cleanField(); //Absen
                    break;
                case 16:cleanField(); //Pengajuan
                    break;
                case 19:cleanMenu();  //Daftar Pengajuan;
                    break;
                case 22:cleanMenu(); dataPengajuanKaryawan(1);
                    break;
                case 25:cleanField(), approval(1);
                    break;
                case 28:cleanRight(), login();
                    break;
            }
            coorPrint(27, pc, " ");
        }
    } while (c != 28);
}