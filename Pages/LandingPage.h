#include "Dashboard.h"
#include "SplashScreen.h"

#define enter 13
int ID;
string password;

void login() {
    status = 0;
    top:
    uiLogin();
    coorPrint(67, 23, "Password");
    box(67, 21);
    box(67, 25);
    coorPrint(67, 19, "ID");
    coorPrint(68, 21, "KRY");
    coord(71, 21);
    getInt(&ID, 8);
    coord(68, 25);
    getPss(password, 12);
    if (ID == 0 && strcmp(password, "essasuperpic") == 0) {
        cleanRight();
        superPIC();
    } else {
        user = fopen("fileDat/Master/User.dat", "rb");
        while (fread(&Usr, sizeof(Usr), 1, user) == 1) {
            if (ID == Usr.id && strcmp(password, Usr.password) == 0) {
                status = 1;
                role = fopen("fileDat/Master/Role.dat", "rb");
                while (fread(&Role, sizeof(Role), 1, role) == 1) {
                    if (Usr.role == Role.KD) {
                        cleanRight();
                        Usr.role == 1 ? cleanRight(), PICMedical() :
                        Usr.role == 2 ? cleanRight(), PICHRD() :
                        Usr.role == 3 ? cleanRight(), HRD() :
                        Usr.role == 4 ? cleanRight(), kepalaDepartment() :
                        Usr.role == 5 ? cleanRight(), section() :
                        cleanRight(), staff();
                    }
                }
                fclose(role);
            }
        }
        fclose(user);
    }
    if (!status) {
        Beep(800, 500);
        MessageBox(NULL, "Password atau ID salah!!", "Attention", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        coorPrint(68, 21, "        ");
        coorPrint(68, 25, "            ");
        goto top;
    }
}

void landingPage() {
    splash();
    cleanRight();
    login();
}