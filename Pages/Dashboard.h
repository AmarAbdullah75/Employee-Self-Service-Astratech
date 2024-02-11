#include "../UI/UIPages.h"
#include "../Data/StructMaster.h"
#include "MenuMaster.h"
void menuPICSuper();
void menuSection();
void menuHRD();
void menuStaff();
void menuKepalaDepartemen();
USER Usr;
void superPIC(){
    uiDashboard();
    waktu();
    menuPICSuper();
}

void PICHRD(){
    uiDashboard();
    waktu();
    menuPICHRD();
}

void PICMedical(){
    uiDashboard();
    waktu();
    menuPICMedical();
}

void HRD(){
    uiDashboard();
    waktu();
    menuHRD();
}

void kepalaDepartment(){
    uiDashboard();
    waktu();
    menuKepalaDepartemen();
}

void section(){
    uiDashboard();
    waktu();
    menuSection();
}

void staff(){
    uiDashboard();
    waktu();
    menuStaff();
}