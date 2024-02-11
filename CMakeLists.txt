cmake_minimum_required(VERSION 3.26)
project(Employee_Self_Service_Astratech C)

set(CMAKE_C_STANDARD 11)

add_executable(Employee_Self_Service_Astratech
        main.c
        Data/Master/Alasan.h
        Data/Master/Medical.h
        Data/Master/MenuMakanan.h
        Data/Master/Pengumuman.h
        Data/Master/Role.h
        Data/Master/User.h
        Data/Transaksi/Absensi.h
        Data/Transaksi/AbsensiMakan.h
        Data/Transaksi/Pengaduan.h
        Data/Transaksi/Perizinan.h
        Data/Transaksi/TransaksiMedical.h
        Pages/Dashboard.h
        Pages/LandingPage.h
        Pages/Menu.h
        Pages/MenuMaster.h
        Pages/SplashScreen.h
        SupportFunction/Colors.h
        SupportFunction/IOVal.h
        SupportFunction/pgUpPgDn.h
        SupportFunction/screen.h
        SupportFunction/Time.h
        SupportFunction/Transisi.h
        UI/box.h
        UI/UIPages.h
        Data/StructMaster.h
        Data/StructTransaksi.h
        Data/Master/Department.h
        "Data/Laporan/Laporan Perizinan.h")
