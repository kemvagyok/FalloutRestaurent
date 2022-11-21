#ifndef FALLOUTETTEREM_ALAPANYAGOKKEZELESE_H
#define FALLOUTETTEREM_ALAPANYAGOKKEZELESE_H
#include "adatokKezelese.h"
#include <stdbool.h>
void reductionRawMaterial(RawMaterialArray* actualRawMaterials, RawMaterial rawMaterial, int quantity);
int checkRawMaterial(RawMaterialArray* actualRawMaterials, RawMaterial rawMaterial);
bool isEnoughChosenMenuFromRawMaterials(FoodMenu* foodMenu, RawMaterialArray* actualRawMaterial, int count);
#endif //FALLOUTETTEREM_ALAPANYAGOKKEZELESE_H
