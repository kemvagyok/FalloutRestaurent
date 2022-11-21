#include <stdio.h>
#include "debugmalloc.h"
#include "adatokKezelese.h"
#include "etelMenukKezelese.h"
#include "alapanyagokKezelese.h"
#include "asztalokKezelese.h"
#include "kinezetKezeles.h"

void initailize(UserType userType,Menu* menuStart,FoodMenus* foodMenus, DesktopArray* desktopArray, RawMaterialArray* rawMaterialArray, DataProceeds* dataProceeds);
void execute(UserType userType,char* mainCommand, char* arguments,  FoodMenus* foodMenus, DesktopArray* desktopArray, RawMaterialArray* rawMaterialArray, DataProceeds* dataProceeds);
void login(UserType* userType);
int main() {
    UserType userType;
    Menu startMenu;
    Menu actualMenu;
    FoodMenus foodMenus;
    DesktopArray desktopArray;
    RawMaterialArray actualRawMaterials;
    DataProceeds dataProceeds;


    login(&userType);
    initailize(userType,&startMenu,&foodMenus, &desktopArray, &actualRawMaterials,&dataProceeds);
    actualMenu = startMenu;
    menusWriting(actualMenu);

    char command[100];
    while(scanf("%s",&command)>0)
    {
        int nextMenu;
        sscanf(command,"%d", &nextMenu);
        if(actualMenu.countSubmenus>=nextMenu)
        {
            if(nextMenu == 0)
                actualMenu = *actualMenu.parentMenu;
            else
                actualMenu = actualMenu.submenus[nextMenu-1][0];
            menusWriting(actualMenu);
        }
        else if(actualMenu.countSubmenus == 0)
        {
            char argumentsPart[50];
            char* arguments;
            scanf("%[^\n]",argumentsPart);
            arguments = strcat(command,argumentsPart);
            execute(userType,actualMenu.command, arguments,    &foodMenus,  &desktopArray,  &actualRawMaterials,  &dataProceeds);
            actualMenu = *actualMenu.parentMenu;
            menusWriting(actualMenu);

        }

    }

    freeAllDynamicAllocationMemory(&actualMenu,&foodMenus,&desktopArray,&actualRawMaterials);
    return 0;
}

void login(UserType* userType)
{
    printf("Bejelentkezés\nTulajdonos (Login O)\nDolgozó (Login W)\n");
    char type;
    scanf("Login %c", &type);
    if(type == 'O')
        *userType = Owner;
    else
        *userType = Waiter;
}

void initailize(UserType userType,Menu* menuStart,FoodMenus* foodMenus, DesktopArray* desktopArray, RawMaterialArray* rawMaterialArray, DataProceeds* dataProceeds)
{
    if(userType == Owner)
        getMenus(menuStart, "menuk_Owner.txt");
    else
        getMenus(menuStart, "menuk_Waiter.txt");
    *foodMenus = getFoodMenus( "menuByDay.txt", "menuByWeek.txt", "menuByDayMaterials.txt", "menuByWeekMaterials.txt");
    *desktopArray = getDesktops( "desktopData.txt");
    *rawMaterialArray = getRawMaterials( "actualRawMaterials.txt");
    *dataProceeds = getDataProfit("dataProceeds.txt");
}

void execute(UserType userType,char* mainCommand, char* arguments,FoodMenus* foodMenus, DesktopArray* desktopArray, RawMaterialArray* actualRawMaterials, DataProceeds* dataProceeds)
{
    char firstCommand[20];
    int secondCommand;
    sscanf(mainCommand,"%[^#]#%d",&firstCommand,&secondCommand);
    if(userType == Owner)
    {
        if(strcmp(firstCommand, "MDS") == 0)
        {
            foodMenuWriting(&foodMenus->DayMenu);
        }
        else if(strcmp(firstCommand, "MWS") == 0)
        {
            foodMenuWriting(&foodMenus->WeekMenu);
        }
        else if(strcmp(firstCommand, "MDM") == 0)
        {
            switch (secondCommand) {
                case 1:  menuModifyAtFood(&foodMenus->DayMenu,Appetizer, arguments);
                    printf("%s", foodMenus->DayMenu.appetizer);break;
                case 2:  menuModifyAtFood(&foodMenus->DayMenu,MainCourse, arguments);break;
                case 3:  menuModifyAtFood(&foodMenus->DayMenu,Cake, arguments);break;
                case 4:  menuModifyAtPrice(&foodMenus->DayMenu,arguments);break;
            }

        }
        else if(strcmp(firstCommand, "MWM") == 0)
        {
            switch (secondCommand) {
                case 1:  menuModifyAtFood(&foodMenus->WeekMenu,Appetizer, arguments);break;
                case 2:  menuModifyAtFood(&foodMenus->WeekMenu,MainCourse, arguments);break;
                case 3:  menuModifyAtFood(&foodMenus->WeekMenu,Cake, arguments);break;
                case 4:  menuModifyAtPrice(&foodMenus->WeekMenu,(int)arguments);break;
            }
        }
        else if(strcmp(firstCommand, "PM") == 0)
        {
            dataProfitWriting(dataProceeds);
        }
    }
    else
    {
        if(strcmp(firstCommand, "DS") == 0)
        {
            desktopMapWriting();
        }
        else if(strcmp(firstCommand, "DW") == 0)
        {
            int id;
            sscanf(arguments,"%d",&id);
            printf("Az %d.asztal %s.\n",id,isEmptyChosenDesktop(desktopArray,id)? "elérhető" : "foglalt");
        }
        else if(strcmp(firstCommand, "DR") == 0)
        {
            int id, day, week;
            sscanf(arguments,"%d %d %d",&id,&day,&week);
            bool isEnoughDay = isEnoughChosenMenuFromRawMaterials(&foodMenus->DayMenu,actualRawMaterials,day);
            bool isEnoughWeek = isEnoughChosenMenuFromRawMaterials(&foodMenus->WeekMenu,actualRawMaterials,week);
            if(!isEnoughDay && !isEnoughWeek)
            {
                printf("Sem %d db napi menüből, sem a %d db heti menülből nincs megfelelő mennyiségű alapanyag\n");
                return;
            }
            else if (!isEnoughDay)
            {
                printf(" %d db napi menüből nincs megfelelő mennyiségű alapanyag\n");
                return;
            }
            else if (!isEnoughWeek)
            {
                printf(" %d db heti menüből nincs megfelelő mennyiségű alapanyag\n");
                return;
            }
            desktopReservation(desktopArray,id,day,week, foodMenus->DayMenu.cost,foodMenus->WeekMenu.cost);
            for (int i = 0; i < foodMenus->DayMenu.rawMaterialArray.count; ++i)
                reductionRawMaterial(actualRawMaterials, foodMenus->DayMenu.rawMaterialArray.rawMaterials[i],day);
            for (int i = 0; i < foodMenus->WeekMenu.rawMaterialArray.count; ++i)
                reductionRawMaterial(actualRawMaterials, foodMenus->WeekMenu.rawMaterialArray.rawMaterials[i],week);

            dataProceeds->consumerCountWeek+=week;
            dataProceeds->consumerCountDay+=day;
            dataProceeds->proceeds=day+week;

        }
        else if(strcmp(firstCommand, "DF") == 0)
        {
            int id;
            sscanf(arguments,"%d",&id);
            desktopFree(desktopArray,id);
        }
        else if(strcmp(firstCommand, "RS") == 0)
        {
            for (int i = 0; i < actualRawMaterials->count; ++i)
                rawMaterialWriting(&actualRawMaterials->rawMaterials[i]);
        }
        else if(strcmp(firstCommand, "OW") == 0)
        {
            int index;
            sscanf(arguments,"%d",&index);
            if(index<desktopArray->desktopsCount)
            {
                billWriting(&(desktopArray->desktops[index]));
            }
            else
            {
                printf("Az adott számú asztal nem létezik.");
            }
        }
    }



}

