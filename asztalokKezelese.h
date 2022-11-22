#ifndef FALLOUTETTEREM_ASZTALOKKEZELESE_H
#define FALLOUTETTEREM_ASZTALOKKEZELESE_H
#include "adatokKezelese.h"
///Lefoglalja az adott asztalt, és hozzárendeli a rendelést.
/// \param desktopArray DesktopArray típusú pointer az étterem asztalairól
/// \param ID Integer típusú változó az adott asztal azonosítójáról
/// \param countDayMenu Integer típusú változó a napi menü mennyiségéről
/// \param countWeekMenu Integer típusú változó a heti menü mennyiségéről
/// \param costDayMenu Integer típusú változó a napi menü áráról
/// \param costWeekMenu Integer típusú változó a heti menü áráról
void desktopReservation(DesktopArray* desktopArray, int ID, int countDayMenu, int countWeekMenu, int costDayMenu, int costWeekMenu);
///Felszabadítj az adott asztalt.
/// \param desktopArray DesktopArray típusú pointer az étterem asztalairól
/// \param ID Integer típusú változó az adott asztal azonosítójáról
void desktopFree(DesktopArray* desktopArray, int ID);
///Visszaadja az adott asztal székeinek az összeségét.
/// \param desktopArray DesktopArray típusú pointer az étterem asztalairól
/// \param ID Integer típusú változó az adott asztal azonosítójáról
/// \return Integer típusú változó a székek összeségéről
int chairCountOfGivenDesktop(DesktopArray* desktopArray, int ID);
///Az adott asztal üres-e.
/// \param desktopArray DesktopArray típusú pointer az étterem asztalairól
/// \param ID Integer típusú változó az adott asztal azonosítójáról
/// \return Boolean típusú változó. True, ha az adott asztal üres, False, ha nem.
bool isEmptyChosenDesktop(DesktopArray* desktopArray, int ID);
#endif //FALLOUTETTEREM_ASZTALOKKEZELESE_H
