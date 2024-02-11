FILE *Tperizinan, *TperizinanTemp;
FILE *absensi;
FILE *amakan , *amakantemp;
FILE *Medis, *Medistemp;
FILE *Pengaduan, *pengaduanTemp;

typedef char string[100];
typedef struct {
    string ID;
    int IDUser;
    int IDAlasan;
    string kdDep;
    string jenisIzin;
    int lama;
    int tglAwl;
    int blnAwl;
    int thnAwl;
    int tglAkhr;
    int blnAkhr;
    int thnAkhr;
    int status;
}PERIZINAN;

typedef struct{
    int kodeabsen;
    int iduser;
    string jamdatang;
    string jampulang;
    int jam;
    int menit;
    int hari ;
    int hour;
    int min ;
    int hourp ;
    int minp ;
    string tanggal;
    string status;
}ABSENSI;

typedef struct{
    int kodeabsen;
    string iduser;
    int kode;
    int jam;
    int menit;
    int hari ;
    int hour;
    int min ;
    int hourp ;
    int minp ;
    string tanggal;
    string status;
}ABSENSIMAKAN;

typedef struct{
    string ID;
    int IDuser;
    int IDMedical;
    int tanggal;
    int tagihan;
    string Perawatn;
    int status;
}MEDIS;

typedef struct{
    string KD;
    int ID_User;
    string ID_Role;
    string tanggal;
    string deskripsi;
    int StatusPengaduan;
    int jenis;
}PENGADUAN;