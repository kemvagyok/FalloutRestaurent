#include <stdio.h>
#include "adatokKezelese.h"
void menusWriting(Menu menu)
{
    if(menu.countSubmenus>0)
    {
        for (int i = 0; i < menu.countSubmenus; ++i)
            printf("%d: %s\n", (i+1), menu.submenus[i]->text);
    }
    else
    {
        printf("PARANCSSOR:\n");
    }
}

void foodMenuWriting(FoodMenu* const foodMenu)
{
    printf("Előétel: %s\nFőétel: %s\nSütemény: %s\nÁr: %d Rossz Magyar Forint\n",foodMenu->appetizer,foodMenu->mainCourse,foodMenu->cake, foodMenu->cost);
}

void rawMaterialWriting(RawMaterial* rawMaterial)
{
    printf("Alapanyag: %s\n\tMennyiség: %d\n",rawMaterial->name,rawMaterial->quantity);
}
void dataProfitWriting(DataProceeds* const dataProceeds)
{
    printf("Ennyi vevő vette igénybe a napi menüt: %d\nEnnyi vevő vette igénybe a heti menüt: %d\nBevétel: %d\n",dataProceeds->consumerCountDay,dataProceeds->consumerCountWeek,dataProceeds->proceeds);
}

void billWriting(Desktop* desktop)
{
    if(desktop->available == busy)
        printf("%d.asztal:\n\tNapi menü: %d db\n\tHeti menü: %d db\n\tÖsszeg: %d rossz magyar forint\n", desktop->id,desktop->countOrderDayMenu, desktop->countOrderWeekMenu, desktop->costSummary);
    else
        printf("Ez az asztal üres.\n");
}

void desktopMapWriting()
{
    char map[12][40] = {
            "\n|-----------------------------------|\n",
            "|                                   |\n",
            "|          2        3         4     |\n",
            "|                                   |\n",
            "|                                   |\n",
            "=>     1                            |\n",
            "|                              5    |\n",
            "|                                   |\n",
            "|                                   |\n",
            "|   8            7             6    |\n",
            "|                                   |\n",
            "|-----------------------------------|\n"
    };

    for(int i = 0; i < 12; ++i) {
        printf("%37s",map[i]);
    }
    printf("\n");
}



