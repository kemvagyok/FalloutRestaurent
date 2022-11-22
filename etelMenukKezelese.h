#ifndef FALLOUTETTEREM_ETELMENUKKEZELESE_H
#define FALLOUTETTEREM_ETELMENUKKEZELESE_H
#include <stdbool.h>
#include "adatokKezelese.h"
///
/// \param foodMenu
/// \param menuPart
/// \param text
void menuModifyAtFood(FoodMenu* foodMenu,MenuPart menuPart, char* text);
///
/// \param foodMenu
/// \param price
void menuModifyAtPrice(FoodMenu* foodMenu, int price);
///
/// \param foodMenu
/// \param actaulRawMaterial
/// \return
bool isEnoughMenuFromRawMaterials(FoodMenu* foodMenu, RawMaterialArray* actaulRawMaterial);
#endif //FALLOUTETTEREM_ETELMENUKKEZELESE_H
