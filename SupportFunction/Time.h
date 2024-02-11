void console(int *lebar, int *tinggi);
time_t t;
struct tm *info;
void coord(int x, int y);

void waktu(){
    time(&t);
    int Tinggi, Lebar;
    console(&Lebar, &Tinggi);
    info = localtime(&t);
    coord(12, Tinggi-3);
    printf("%02d:%02d\n", info->tm_hour,info->tm_min);
    coord(10, Tinggi-2);
    printf("%02d/%02d/%04d", info->tm_mday, info->tm_mon +1, info->tm_year + 1900);
}
int trueDate(int hari, int bulan, int tahun) {
    int hariSbln[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)) {
        hariSbln[2] = 29;
    }
    if (bulan < 1 || bulan > 12 || hari < 1 || hari > hariSbln[bulan] || tahun < 1) {
        return 0;
    }
    return 1;
}
void lamahari(int tglmli,int blnmli,int thnmli,int tglakhr,int blnakhr,int thnakhr,int *hari){
    struct tm end_date = {0};
    struct tm start_date = {0};

    start_date.tm_year = thnmli - 1900;
    start_date.tm_mon = blnmli - 1;
    start_date.tm_mday = tglmli;

    end_date.tm_year = thnakhr - 1900;
    end_date.tm_mon = blnakhr - 1;
    end_date.tm_mday = tglakhr;

    // Mengubah struct tm menjadi time_t
    time_t start_time = mktime(&start_date);
    time_t end_time = mktime(&end_date);

    // Menghitung selisih waktu dalam detik
    double difference = difftime(end_time, start_time);

    // Menghitung jumlah hari
    *hari = difference / (60 * 60 * 24);
}
void rentangHari(int tglAwal,int blnAwal,int thnAwal,int *rentang){
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);

    // Mendapatkan tanggal saat ini
    int tglSekarang = info->tm_mday;
    int blnSekarang = info->tm_mon + 1; // tm_mon dimulai dari 0
    int thnSekarang = info->tm_year + 1900; // tm_year adalah tahun sejak 1900

    // Menghitung selisih hari antara tanggal izin dan tanggal sekarang
    *rentang = (tglAwal - tglSekarang) + (blnAwal - blnSekarang) * 30 + (thnAwal - thnSekarang) * 365;
}

void hari(){
    int Tinggi, Lebar;
    console(&Lebar,&Tinggi);
    time(&t);
    info = localtime(&t);
    printf("%02d/%02d/%04d", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);
}

void jam(){
    int Tinggi, Lebar;
    console(&Lebar,&Tinggi);
    time(&t);
    info = localtime(&t);
    printf("%02d:%02d:%02d\n", info->tm_hour,info->tm_min,info->tm_sec);
}