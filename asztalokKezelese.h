#ifndef FALLOUTETTEREM_ASZTALOKKEZELESE_H
#define FALLOUTETTEREM_ASZTALOKKEZELESE_H
#include "adatokKezelese.h"
void desktopReservation(DesktopArray* desktopArray, int ID, int countDayMenu, int countWeekMenu, int costDayMenu, int costWeekMenu);
void desktopFree(DesktopArray* desktopArray, int ID);
int chairCountOfGivenDesktop(DesktopArray* desktopArray, int ID);
bool isEmptyChosenDesktop(DesktopArray* desktopArray, int ID);
#endif //FALLOUTETTEREM_ASZTALOKKEZELESE_H
