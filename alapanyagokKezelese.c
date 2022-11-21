#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "adatokKezelese.h"
#include "alapanyagokKezelese.h"

int checkRawMaterial(RawMaterialArray* actualRawMaterials, RawMaterial rawMaterial)
{
    for (int i = 0; i < actualRawMaterials->count; ++i)
        if(strcmp(actualRawMaterials->rawMaterials[i].name,rawMaterial.name)==0)
            return i;
    return -1;
}
void reductionRawMaterial(RawMaterialArray* actualRawMaterials, RawMaterial rawMaterial, int count)
{
    int index = checkRawMaterial(actualRawMaterials, rawMaterial);
    if(index != NULL)
        actualRawMaterials->rawMaterials[index].quantity-=rawMaterial.quantity*count;
}

bool isEnoughChosenMenuFromRawMaterials(FoodMenu* foodMenu, RawMaterialArray* actualRawMaterial, int count)
{
    for (int i = 0; i < foodMenu->rawMaterialArray.count; ++i) {
        int index = checkRawMaterial(actualRawMaterial,foodMenu->rawMaterialArray.rawMaterials[i]);
        if(index != -1)
        {
            if(foodMenu->rawMaterialArray.rawMaterials[i].quantity*count > actualRawMaterial->rawMaterials[i].quantity)
                return false;
        }
        else
        {
            printf("A %s menü %s nevű alapanyaga nincs meg a raktárban.\n",foodMenu->name,actualRawMaterial->rawMaterials[i].name);
        }
    }
    return true;
}
