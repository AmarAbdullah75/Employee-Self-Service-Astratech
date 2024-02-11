MEDICAL Medical;
void menuMedical();
void CMedical(){
    int id = 0,c;
    medical = fopen("fileDat/Master/Medical.dat", "rb");
    while (fread(&Medical, sizeof(Medical), 1, medical) == 1) {
        id = Medical.id;
    }
    Medical.id = id + 1;
    fclose(user);
    coorPrint(65, 2, "[=[=[=[=[  TAMBAH DATA MEDICAL  ]=]=]=]=]");
    medical = fopen("fileDat/Master/Medical.dat", "ab");
    coorPrint(55,10,"ID            :MD");
    coord(72,10);setInt(Medical.id);
    coorPrint(55,13,"Nama          :");
    coorPrint(55,16,"Alamat        :");
    coorPrint(55,19,"No Telepon    :");
    coorPrint(55,22,"Simpan       ->");
    coorPrint(55,25,"Kembali      ->");
    coorPrint(55,27,"Tekan \"Enter\" Untuk Input Data Baru");
    top:
    c = 10;
    coord(70, 10);
    do {
        choiceMenu3(10, 25, &c);
        if (c == 10 || c == 13 || c == 16 || c == 19 ||c==22||c==25) {
            coord(70, c);
        }
    } while ((sk == pgUp || sk == pgDn) && klik != enter);
    if(klik == enter){
        switch (c) {
            case 10:MessageBox(NULL, "Data sudah ditentukan!!", "Attention",
                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto top;
            case 13:
                coorPrint(70, 13, "                         ");
                coord(70,13);getAlphabet(Medical.nama, 25);
                goto top;
            case 16:
                coorPrint(70, 16, "                                             ");
                coord(70,16);getStr(Medical.alamat, 45);
                goto top;
            case 19:
                coorPrint(70, 19, "              ");
                coord(70,19);getStr(Medical.notlp, 14);
                goto top;
            case 25:menuMedical();
                break;
        }
        if(c==22){
            fwrite(&Medical, sizeof(Medical), 1, medical);
            MessageBox(NULL, "Data berhasil ditambahkan!!","Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
        fclose(medical);
    }
}
void RMedical(){
    i=0;
    coorPrint(65, 2, "[=[=[=[=[  DATA MEDICAL  ]=]=]=]=]");
    medical = fopen("fileDat/Master/Medical.dat", "rb");
    coorPrint(65,4,"ID");
    coorPrint(55,4,"Nama");
    coorPrint(85,4,"No Telepon");
    coorPrint(105,4,"Alamat");
    while (fread(&Medical, sizeof(Medical), 1, medical) == 1){
        coorPrint(65,5+i,"MD");
        coord(67,5+i), setInt(Medical.id);
        coorPrint(85,5+i, Medical.nama);
        coorPrint(105,5+i, Medical.alamat);
        i++;
    }
    fclose(medical);
}

void UMedical(){
    int idsearch;
    status = 0;
    string alamatmedical;
    string medicalName;
    string tlp;
    coorPrint(71, 2, "[=[=[=[=[  UBAH DATA MEDICAL  ]=]=]=]=]");
    coorPrint(82,5, "Masukkan ID :MD");
    coorPrint(51, 10, "ID Medical         :MD");
    coorPrint(51, 13, "Nama Medical       :");
    coorPrint(51, 16, "Alamat             :");
    coorPrint(51, 19, "No Telepon         :");
    coorPrint(51, 22, "Simpan Perubahan  ->");
    coorPrint(51, 25, "Kembali           ->");
    coord(97,5);getInt(&idsearch,6);
    medical = fopen("fileDat/Master/Medical.dat", "rb");
    medicalTemp = fopen("fileDat/MedicalTemp.dat", "wb");
    while(fread(&Medical    , sizeof(Medical), 1, medical) == 1){
        if(idsearch==Medical.id){
            status = 1;
        }else{
            fwrite(&Medical, sizeof(Medical), 1, medicalTemp);
        }
    }
    fclose(medical);
    fclose(medicalTemp);

    if(!status){
        MessageBox(NULL, "Data tidak ditemukan!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    }else{
        medical = fopen("fileDat/Master/Medical.dat", "rb");
        medicalTemp = fopen("fileDat/MedicalTemp.dat", "wb");
        while(fread(&Medical, sizeof(Medical), 1, medical) == 1){
            int c = 10;
            if(Medical.id==idsearch){
                coorPrint(100, 15, "Tekan \"Enter\" Untuk Input Data Baru");
                coord(73, 10), setInt( Medical.id);
                coorPrint(71, 13, Medical.nama);
                coorPrint(71, 16, Medical.alamat);
                coorPrint(71, 19, Medical.notlp);
                top:
                coord(71, 10);
                do {
                    choiceMenu3(10, 25, &c);
                    if (c==10||c == 13 || c == 16 || c == 19 || c == 22||c==25){coord(71, c);}
                } while ((sk == pgUp || sk == pgDn) && klik != enter);
                if(klik==enter){
                    switch (c) {
                        case 10:MessageBox(NULL, "Kode tidak bisa diubah!!", "Peringatan",
                                           MB_OK | MB_DEFAULT_DESKTOP_ONLY | MB_ICONINFORMATION);
                            goto top;
                        case 13:coorPrint(71, 13,"                         ");
                            coord(71, 13),getAlphabet(medicalName,25);
                            strcpy(Medical.nama, medicalName);
                            goto top;
                        case 16:coorPrint(71, 16, "                                             ");
                            coord(71,16),getStr(alamatmedical,45);
                            strcpy(Medical.alamat, alamatmedical);
                            goto top;
                        case 19:coorPrint(71, 19, "             ");
                            coord(71,19),getStr(tlp,45);
                            strcpy(Medical.notlp, tlp);
                            goto top;
                        case 25:menuMedical();
                            break;
                    }
                    if(c==22){
                        fwrite(&Medical, sizeof(Medical), 1, medicalTemp);
                        MessageBox(NULL, "Data berhasil diubah!!", "Attention",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    }
                }
            }else{
                fwrite(&Medical, sizeof(Medical), 1, medicalTemp);
            }
        }
        fclose(medical);
        fclose(medicalTemp);
    }

    medical = fopen("fileDat/Master/Medical.dat", "wb");
    medicalTemp = fopen("fileDat/MedicalTemp.dat", "rb");
    while(fread(&Medical, sizeof(Medical), 1, medicalTemp) == 1){
        fwrite(&Medical, sizeof(Medical), 1, medical);
    }
    fclose(medical);
    fclose(medicalTemp);
}

void DMedical(){
    int idsearch;
    status = 0;
    printFile(65,12, "fileTxt/Gambar/Tempat Sampah.txt");
    coorPrint(70, 2, "[=[=[=[=[  HAPUS DATA MEDICAL  ]=]=]=]=]");
    coorPrint(82,5, "Masukkan ID :MD");
    coord(97,5);getInt(&idsearch,6);

    medical = fopen("fileDat/Master/Medical.dat", "rb");
    medicalTemp = fopen("fileDat/MedicalTemp.dat", "wb");
    while(fread(&Medical    , sizeof(Medical), 1, medical) == 1){
        if(idsearch==Medical.id){
            status = 1;
        }else{
            fwrite(&Medical, sizeof(Medical), 1, medicalTemp);
        }
    }
    fclose(medical);
    fclose(medicalTemp);

    if(!status){
        MessageBox(NULL, "Data tidak ditemukan!!","Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    }else{
        medical = fopen("fileDat/Master/Medical.dat", "rb");
        medicalTemp = fopen("fileDat/MedicalTemp.dat", "wb");
        while(fread(&Medical, sizeof(Medical), 1, medical) == 1){
            if(Medical.id==idsearch){
                MessageBox(NULL, "Data berhasil dihapus!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            }else{
                fwrite(&Medical, sizeof(Medical), 1, medicalTemp);
            }
        }
        fclose(medical);
        fclose(medicalTemp);
    }

    medical = fopen("fileDat/Master/Medical.dat", "wb");
    medicalTemp = fopen("fileDat/MedicalTemp.dat", "rb");
    while(fread(&Medical, sizeof(Medical), 1, medicalTemp) == 1){
        fwrite(&Medical, sizeof(Medical), 1, medical);
    }
    fclose(medical);
    fclose(medicalTemp);
}