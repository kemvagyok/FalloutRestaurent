#ifndef FALLOUTETTEREM_ETELMENUKKEZELESE_H
#define FALLOUTETTEREM_ETELMENUKKEZELESE_H
#include <stdbool.h>
#include "adatokKezelese.h"

void menuModifyAtFood(FoodMenu* foodMenu,MenuPart menuPart, char* text);
void menuModifyAtPrice(FoodMenu* foodMenu, int price);
bool isEnoughMenuFromRawMaterials(FoodMenu* foodMenu, RawMaterialArray* actaulRawMaterial);
#endif //FALLOUTETTEREM_ETELMENUKKEZELESE_H
