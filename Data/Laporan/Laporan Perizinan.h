//#include "../Transaksi/Perizinan.h"
//#include "../../SupportFunction/Time.h"
//#include "../../UI/box.h"
int i ;
PERIZINAN TPerizinan;
void formperizinan(){
    DesainDataperizinan();
}
void laporanPerizinan() {
    i = 0;
    int found = 0;
    string IDP;
    pinggiranperizinan();
    coorPrint(37, 2, "ID TRANSAKSI Perizinan");
    Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
    while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
        coorPrint(37, 4 + i, "PRZ");
        coorPrint(40, 4 + i, TPerizinan.ID);
        i++;
    }
    fclose(Tperizinan);

    coorPrint(80, 2, "Masukkan ID Transaksi Perizinan : ");
    coorPrint(113, 2, "PRZ");
    coord(116, 2);
    getStr(IDP, 10);
    Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
    TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "wb");
    while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
        if (strcmp(TPerizinan.ID, IDP) == 0) {
            found = 1;
            Tperizinan = fopen("fileDat/Transaksi/TPerizinan.dat", "rb");
            TperizinanTemp = fopen("fileDat/Transaksi/TPerizinanTemp.dat", "wb");
            while (fread(&TPerizinan, sizeof(TPerizinan), 1, Tperizinan) == 1) {
                if (strcmp(TPerizinan.ID, IDP) == 0) {
                    printFile(79, 16, "fileTxt/Menu/perizinan.txt");
                    formperizinan();
                    coorPrint(95, 18, "ID USER          : KRY");
                    coord(117, 18);
                    setInt(TPerizinan.IDUser);
                    coorPrint(95, 22, "Jenis Perizinan  :");
                    coorPrint(114, 22, TPerizinan.jenisIzin);
                    coorPrint(95, 26, "Departement      : ");
                    coorPrint(114, 26, TPerizinan.kdDep);
                    coorPrint(95, 30, "Lama             : ");
                    coord(114, 30);
                    setInt(TPerizinan.lama);
                    coorPrint(95, 34, "Tanggal          :");
                    coord(114, 34);
                    setInt(TPerizinan.tglAwl);
                    coorPrint(116, 34, "/");
                    coord(117, 34);
                    setInt(TPerizinan.blnAwl);
                    coorPrint(119, 34, "/");
                    coord(120, 34);
                    setInt(TPerizinan.thnAwl);
                }
            }
        }

    }
    if(!found){
        Beep(800, 500);
        MessageBox(NULL, "Kode Perizinan Salah !!!", "Attention",
                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    }
}