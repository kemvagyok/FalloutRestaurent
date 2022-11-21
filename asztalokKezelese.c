#include <stdio.h>
#include <stdbool.h>
#include "adatokKezelese.h"

void desktopReservation(DesktopArray* desktopArray, int ID, int countDayMenu, int countWeekMenu, int costDayMenu, int costWeekMenu)
{
    for (int i = 0; i < desktopArray->desktopsCount; ++i) {
        if(desktopArray->desktops[i].id == ID)
        {
            desktopArray->desktops[ID].available = busy;
            desktopArray->desktops[ID].countOrderDayMenu=countDayMenu;
            desktopArray->desktops[ID].countOrderWeekMenu=countWeekMenu;
            desktopArray->desktops[ID].costSummary = countDayMenu*countDayMenu+countWeekMenu*costWeekMenu;
            printf("Sikeres lefoglalás.\n");
            return;
        }
    }
    printf("NINCS TALÁLAT\n");
    return;

}
void desktopFree(DesktopArray* desktopArray, int ID)
{
    for (int i = 0; i < desktopArray->desktopsCount; ++i) {
        if(desktopArray->desktops[i].id == ID)
        {
            if(desktopArray->desktops[ID].available != empty)
            {
                desktopArray->desktops[ID].available = empty;
                desktopArray->desktops[ID].countOrderDayMenu = NULL;
                desktopArray->desktops[ID].countOrderWeekMenu = NULL;
                printf("Sikeres felszabadítás."\n);
                return;
            }
            else
            {
                printf("Üres asztalt nem kell felszabadítani.\n");
                return;
            }
        }
    }
    printf("NINCS TALÁLAT\n");
}
int chairCountOfGivenDesktop(DesktopArray* desktopArray, int ID)
{
    for (int i = 0; i < desktopArray->desktopsCount; ++i) {
        if(desktopArray->desktops[i].id == ID)
            return desktopArray->desktops[ID].chairCount;
    }
    printf("NINCS TALÁLAT\n");
    return  NULL;
}

bool isEmptyChosenDesktop(DesktopArray* desktopArray, int ID)
{

    for (int i = 0; i < desktopArray->desktopsCount; ++i) {
        if(desktopArray->desktops[i].id == ID)
        {
            if(desktopArray->desktops[ID].available == empty)
                return true;
            return false;
        }
    }
    printf("NINCS TALÁLAT\n");
    return  NULL;
}


