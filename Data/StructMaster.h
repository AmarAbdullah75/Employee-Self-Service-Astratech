FILE *user, *userTemp;
FILE *role, *roleTemp;
FILE *departemen, *departemenTemp;
FILE *alasan, *alasanTemp;
FILE *MenuMakanan, *MenuMakananTemp;
FILE *pengumuman, *pengumumanTemp;
FILE *medical, *medicalTemp;

typedef char string[100];


typedef struct {
    string ID;
    string nama;
}DEPARTEMEN;


typedef struct {
    int KD;
    string nama;
}ROLE;


typedef struct {
    int id;
    string kdDprtmn;
    string password;
    string nama;
    string lahir;
    string alamat;
    string telp;
    int plafonMedis;
    int jmlhCuti;
    int role;
}USER;


typedef struct {
    int KD;
    string nama;
    string jenis;
}ALASAN;


typedef struct {
    int kd;
    string tanggal;
    string makanan;
}MENUMAKANAN;


typedef struct {
    int kd;
    string isi;
    string judul;
    string tanggal;
}PENGUMUMAN;


typedef struct {
    int id;
    string nama;
    string alamat;
    string notlp;
}MEDICAL;