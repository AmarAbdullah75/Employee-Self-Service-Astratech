#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "SupportFunction/Time.h"
#include "SupportFunction/screen.h"
#include "Pages/LandingPage.h"
#include "Data/Transaksi/Perizinan.h"


int main(){
    display();
    landingPage();
    getch();
    return 0;
}