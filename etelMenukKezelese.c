#include <stdio.h>
#include <string.h>
#include "adatokKezelese.h"
#include "etelMenukKezelese.h"

void menuModifyAtFood(FoodMenu* foodMenu,MenuPart menuPart, char* text)
{
    switch (menuPart) {
        case Appetizer:
            strcpy(foodMenu->appetizer,text);
            break;
        case MainCourse:
            strcpy(foodMenu->mainCourse,text);
            break;
        case Cake:
            strcpy(foodMenu->cake, text);
            break;
        default:
            return;
    }
}

void menuModifyAtPrice(FoodMenu* foodMenu, int price)
{
    foodMenu->cost = price;
}


