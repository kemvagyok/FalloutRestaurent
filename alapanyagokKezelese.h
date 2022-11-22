#ifndef FALLOUTETTEREM_ALAPANYAGOKKEZELESE_H
#define FALLOUTETTEREM_ALAPANYAGOKKEZELESE_H
#include "adatokKezelese.h"
#include <stdbool.h>
/// Az aktuális alapanyagokból az adott alapanyagot az adott mennyiséggel csökkenti.
/// \param actualRawMaterials RawMaterialArray típusú pointer az aktuális alapanyagokról
/// \param rawMaterial RawMaterail típusú változó az adott alapanyagról
/// \param quantity Intger típusú változó az adott alapanyag mennyiségéről
void reductionRawMaterial(RawMaterialArray* actualRawMaterials, RawMaterial rawMaterial, int quantity);
///Ellenőrzi, hogy az adott alapanyag megvan-e az aktuális alapanyagok között
/// \param actualRawMaterials RawMaterialArray típusú pointer
/// \param rawMaterial RawMaterial típusú változó
/// \return Intenger változó, ha talált 0 vagy több, ha nem talált -1
int checkRawMaterial(RawMaterialArray* actualRawMaterials, RawMaterial rawMaterial);
/// Az adott mennyiségű adott ételmenü készítéséhez elengedőek-e a szükséges alapanyagok az aktuális alapanyagok alapján
/// \param foodMenu foodMenu típusú pointer
/// \param actualRawMaterial RawMaterialArray típusú pointer
/// \param count Integer típusú változó
/// \return Visszadja a bool típusú változót. True, ha az adott menü elkészíthető. False, ha nem.
bool isEnoughChosenMenuFromRawMaterials(FoodMenu* foodMenu, RawMaterialArray* actualRawMaterial, int count);
#endif //FALLOUTETTEREM_ALAPANYAGOKKEZELESE_H
