#include "../../UI/box.h"

DEPARTEMEN Departemen;
string searchID;
int status;
void menuDepartemen();

void CDepartment() {
    t = 1;
    int c;
    string b;
    departemen = fopen("fileDat/Master/Departemen.dat", "rb");
    while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
        t++;
    }
    fclose(departemen);
    coorPrint(68, 2, "[=[=[=[=[  TAMBAH DATA DEPARTEMEN  ]=]=]=]=]");
    departemen = fopen("fileDat/Master/Departemen.dat", "ab");
    if (t < 10) {
        coorPrint(55, 10, "KD              :D00");
        coord(75, 10);
        strcpy(Departemen.ID, "D00");
    } else if (t < 100) {
        coorPrint(55, 10, "KD              :D0");
        coord(74, 10);
        strcpy(Departemen.ID, "RL0");
    } else {
        coorPrint(55, 10, "KD              :D");
        coord(73, 10);
        strcpy(Departemen.ID, "RL");
    }
    setInt(t);
    snprintf(b, sizeof(b), "%d", t);
    strcat(Departemen.ID, b);
    coorPrint(55, 13, "Nama            :");
    coorPrint(55, 16, "Simpan         ->");
    coorPrint(55, 19, "Kembali        ->");
    coorPrint(55, 22, "Tekan \"Enter\" Untuk Input Data Baru");
    top:
    c = 10;
    coord(72, 10);
    do {
        choiceMenu3(10, 19, &c);
        if (c == 10 || c == 13 || c == 16 || c == 19) {
            coord(72, c);
        }
    } while ((sk == pgUp || sk == pgDn) && klik != enter);
    if (klik == enter) {
        switch (c) {
            case 10:
                MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto top;
            case 13:coorPrint(72, 13, "          "),coord(72, 13),getStr(Departemen.nama, 10);goto top;
            case 19:menuDepartemen();break;
        }
        if (c == 16) {
                fwrite(&Departemen, sizeof(Departemen), 1, departemen);
                MessageBox(NULL, "Data berhasil ditambah!!", "Attention",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
        fclose(departemen);
    }
}

void RDepartment(int type) {
    console(&Lebar, &Tinggi);
    departemen = fopen("fileDat/Master/Departemen.dat", "rb");
    switch (type) {
        case 1:
            i = 0;
            coorPrint(Lebar-25,17,"Departemen");
            coorPrint(Lebar-30,19,"Kode");
            coorPrint(Lebar-22,19,"Nama");
            while (fread(&Departemen,sizeof(Departemen), 1, departemen) == 1) {
                coorPrint(Lebar-30,20+i,Departemen.ID);
                coorPrint(Lebar-22,20+i,Departemen.nama);
                i++;
            }
            break;
        case 2:
            boxDepart();
            i = 0;
            coorPrint(71, 2, "[=[=[=[=[  DATA DEPARTEMEN  ]=]=]=]=]");
            coorPrint(68,6,"KD");
            coorPrint(95,6,"Nama");
            while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
                coorPrint(65, 8 + i, Departemen.ID);
                coorPrint(75, 8 + i, Departemen.nama);
                i++;
            }
            break;
    }
    fclose(departemen);
}

void UDepartment() {
    string departmentName,kd;
    status = 0;
    coorPrint(71, 2, "[=[=[=[=[  UBAH DATA DEPARTEMEN  ]=]=]=]=]");
    coorPrint(82, 5, "Masukkan Kode :D");
    coorPrint(51, 15, "Kode Departemen    :");
    coorPrint(51, 18, "Nama Departemen    :");
    coorPrint(51, 21, "Simpan Perubahan  ->");
    coorPrint(51, 24, "Kembali           ->");
    coord(98, 5);
    getNum(searchID, 6);
    strcpy(kd,"D");
    strcat(kd,searchID);
    departemen = fopen("fileDat/Master/Departemen.dat", "rb");
    departemenTemp = fopen("fileDat/DepartemenTemp.dat", "wb");
    while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
        if (strcmp(kd, Departemen.ID) == 0) {
            status = 1;
        } else {
            fwrite(&Departemen, sizeof(Departemen), 1, departemenTemp);
        }
    }
    fclose(departemen);
    fclose(departemenTemp);

    if (!status) {
        MessageBox(NULL, "Data tidak ditemukan", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        departemen = fopen("fileDat/Master/Departemen.dat", "rb");
        departemenTemp = fopen("fileDat/DepartemenTemp.dat", "wb");
        while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
            int c = 15;
            if (strcmp(Departemen.ID, kd) == 0) {
                coorPrint(100, 15, "Tekan \"Enter\" Untuk Input Data Baru");
                coorPrint(71, 15, Departemen.ID);
                coorPrint(71, 18, Departemen.nama);
                top:
                coord(71, 15);
                do {
                    choiceMenu3(15, 24, &c);
                    if (c == 15 || c == 18 || c == 21 || c == 24){coord(71, c);}
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if (klik == enter) {
                    switch (c) {
                        case 15:
                            MessageBox(NULL, "Kode tidak bisa diubah!!", "Peringatan",
                                       MB_OK | MB_DEFAULT_DESKTOP_ONLY | MB_ICONINFORMATION);
                            goto top;
                        case 18:
                            coorPrint(71, 18, "          ");
                            coord(71, 18),getStr(departmentName, 10);
                            strcpy(Departemen.nama, departmentName);
                            goto top;
                        case 24:
                            menuDepartemen();
                            break;
                    }
                    if (c == 21) {
                            fwrite(&Departemen, sizeof(Departemen), 1, departemenTemp);
                            MessageBox(NULL, "Data berhasil diubah!!", "Attention",
                                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    }
                }
            } else {
                fwrite(&Departemen, sizeof(Departemen), 1, departemenTemp);
            }
        }
        fclose(departemen);
        fclose(departemenTemp);
    }

    departemen = fopen("fileDat/Master/Departemen.dat", "wb");
    departemenTemp = fopen("fileDat/DepartemenTemp.dat", "rb");
    while (fread(&Departemen, sizeof(Departemen), 1, departemenTemp) == 1) {
        fwrite(&Departemen, sizeof(Departemen), 1, departemen);
    }
    fclose(departemen);
    fclose(departemenTemp);
}

void DDepartment() {
    status = 0;
    string kd;
    printFile(65,12, "fileTxt/Gambar/Tempat Sampah.txt");
    coorPrint(70, 2, "[=[=[=[=[  HAPUS DATA DEPARTEMEN  ]=]=]=]=]");
    coorPrint(82, 5, "Masukkan Kode :D");
    coord(98, 5);
    getNum(searchID, 6);
    strcpy(kd,"D");
    strcat(kd,searchID);
    departemen = fopen("fileDat/Master/Departemen.dat", "rb");
    departemenTemp = fopen("fileDat/DepartemenTemp.dat", "wb");
    while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
        if (strcmp(searchID, Departemen.ID) == 0) {
            status = 1;
        } else {
            fwrite(&Departemen, sizeof(Departemen), 1, departemenTemp);
        }
    }
    fclose(departemen);
    fclose(departemenTemp);

    if (!status) {
        MessageBox(NULL, "Kode tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        departemen = fopen("fileDat/Master/Departemen.dat", "rb");
        departemenTemp = fopen("fileDat/DepartemenTemp.dat", "wb");
        while (fread(&Departemen, sizeof(Departemen), 1, departemen) == 1) {
            if (strcmp(Departemen.ID, searchID) == 0) {
                MessageBox(NULL, "Data berhasil dihapus!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            } else {
                fwrite(&Departemen, sizeof(Departemen), 1, departemenTemp);
            }
        }
        fclose(departemen);
        fclose(departemenTemp);
    }

    departemen = fopen("fileDat/Master/Departemen.dat", "wb");
    departemenTemp = fopen("fileDat/DepartemenTemp.dat", "rb");
    while (fread(&Departemen, sizeof(Departemen), 1, departemenTemp) == 1) {
        fwrite(&Departemen, sizeof(Departemen), 1, departemen);
    }
    fclose(departemen);
    fclose(departemenTemp);
}