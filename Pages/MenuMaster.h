#include "../SupportFunction/pgUpPgDn.h"
#include "../Data/Master/Department.h"
#include "../Data/Master/Medical.h"
#include "../Data/Master/MenuMakanan.h"
#include "../Data/Master/Pengumuman.h"
#include "../Data/Master/Alasan.h"
#include "../Data/Master/Role.h"

void superPIC();
void menuPICMedical();
void menuPICHRD();
int c, a, pc;
void menuDepartemen() {
    do {
        coorPrint(27, pc, " ");
        a = 0;
        printFile(4, 10, "fileTxt/Menu/CRUDDepartemen.txt");
        for (int k = 0; k < 6; ++k) {
            box2(3, 10 + a);
            a+=3;
        }
        pc = 10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 25, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);

        if(klik == enter){
            switch (c) {
                case 10:cleanField(), CDepartment();
                    break;
                case 13:cleanField(), RDepartment(2);
                    break;
                case 16:cleanField(), UDepartment();
                    break;
                case 19:cleanField(), DDepartment();
                    break;
                case 22:cleanMenu(), cleanField(), superPIC();
                    break;
                case 25:exit(0);
            }
            coorPrint(27, pc, " ");
        }
    } while (c!=25&&c!=22);
}

void menuRole() {
    do {
        coorPrint(27, pc, " ");
        a = 0;
        printFile(4, 10, "fileTxt/Menu/CRUDRole.txt");
        for (int k = 0; k < 6; ++k) {
            box2(3, 10 + a);
            a+=3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 25, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if(klik == enter){
            switch (c) {
                case 10:cleanField(), CRole();
                    break;
                case 13:cleanField(), RRole(2);
                    break;
                case 16:cleanField(), URole();
                    break;
                case 19:cleanField(), DRole();
                    break;
                case 22:cleanMenu(), cleanField(), superPIC();
                    break;
                case 25:exit(0);
            }
            coorPrint(27, pc, " ");
        }
    } while (c!= 25 && c!= 22);
}

void menuAlasan(){
    do {
        coorPrint(27, pc, " ");
        a = 0;
        printFile(4, 10, "fileTxt/Menu/CRUDAlasan.txt");
        for (int k = 0; k < 6; ++k) {
            box2(3, 10 + a);
            a+=3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 25, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if(klik == enter){
            switch (c) {
                case 10:cleanField(), CAlasan();
                    break;
                case 13:cleanField(), RAlasan(1);
                    break;
                case 16:cleanField(), UAlasan();
                    break;
                case 19:cleanField(), DAlasan();
                    break;
                case 22:cleanMenu(), cleanField(), superPIC();
                    break;
                case 25:exit(0);
            }
            coorPrint(27, pc, " ");
        }
    } while (c != 22 && c != 25);
}

void menumakanan(){
    do{
        coorPrint(27, pc, " ");
        a = 0;
        printFile(4, 10, "fileTxt/Menu/CRUDMenuMakanan.txt");
        for (int k = 0; k < 6; ++k) {
            box2(3, 10 + a);
            a+=3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 25, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if(klik==enter){
            switch (c) {
                case 10:cleanField(), CMenuMakanan();
                    break;
                case 13:cleanField(), RMenuMakanan();
                    break;
                case 16:cleanField(), UMenuMakanan();
                    break;
                case 19:cleanField(), DMenuMakanan();
                    break;
                case 22:cleanMenu(), cleanField(), menuPICHRD();
                    break;
                case 25:exit(0);
            }
            coorPrint(27, pc, " ");
        }
    } while (c!=25 && c!=22);
}

void menuPengumuman(){
    do{
        coorPrint(27, pc, " ");
        a = 0;
        printFile(4, 10, "fileTxt/Menu/CRUDPengumuman.txt");
        for (int k = 0; k < 6; ++k) {
            box2(3, 10 + a);
            a+=3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 25, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if(klik==enter){
            switch (c) {
                case 10:cleanField(), CPengumuman();
                    break;
                case 13:cleanField(), RPengumuman();
                    break;
                case 16:cleanField(), UPengumuman();
                    break;
                case 19:cleanField(), DPengumuman();
                    break;
                case 22:cleanMenu(), cleanField(), menuPICHRD();
                    break;
                case 25:exit(0);
            }
            coorPrint(27, pc, " ");
        }
    } while (c!=25 && c!=22);
}

void menuMedical(){
    do{
        coorPrint(27, pc, " ");
        a = 0;
        printFile(4, 10, "fileTxt/Menu/CRUDMedical.txt");
        for (int k = 0; k < 6; ++k) {
            box2(3, 10 + a);
            a+=3;
        }
        pc=10;
        c = 10;
        coorPrint(27, 10, "<");
        do {
            choiceMenu3(10, 25, &c);
            coorPrint(27, pc, " ");
            if (c == 10 || c == 13 || c == 16 || c == 19 || c == 22 || c == 25) {
                coorPrint(27, c, "<");
            }
            pc=c;
        } while ((sk == pgUp || sk == pgDn) && klik != enter);
        if(klik == enter){
            switch (c) {
                case 10:cleanField(), CMedical();
                    break;
                case 13:cleanField(), RMedical();
                    break;
                case 16:cleanField(), UMedical();
                    break;
                case 19:cleanField(), DMedical();
                    break;
                case 22:cleanMenu(), cleanField(), menuPICMedical();
                    break;
                case 25:exit(0);
            }
            coorPrint(27, pc, " ");
        }
    } while (c!=25&&c!=22);
}