#include "adatokKezelese.h"
#include "debugmalloc.h"
#include <stdio.h>
#include <string.h>

static char* dynamicAllocationMemoryCharPointer(char* array, int size, char* c)
{
    char* newArray= (char*) malloc(sizeof(char*)*size);

    for (int i = 0; i < size-1; ++i)
        newArray[i] = array[i];
    newArray[size-1]=c;
    free(array);

    return newArray;
}


static void dynamicAllocationMemoryRawMaterial(RawMaterialArray *array, int size, RawMaterial rawMaterial)
{
    RawMaterial* newData= (RawMaterial*) malloc(sizeof(RawMaterial)*size);

    for (int i = 0; i < size-1; ++i)
        newData[i] = array->rawMaterials[i];
    newData[size-1]= rawMaterial;

    free(array->rawMaterials);
    array->rawMaterials = newData;
    array->count = size;

}
static void dynamicAllocationMemoryDesktop(DesktopArray *array, int size, Desktop desktop)
{
    Desktop* newData= (Desktop*) malloc(sizeof(Desktop)*size);

    for (int i = 0; i < size-1; ++i)
        newData[i] = array->desktops[i];
    newData[size-1]= desktop;

    free(array->desktops);
    array->desktops = newData;
    array->desktopsCount = size;
}

void getMenus(Menu* menuStart, char* filename)
{

    FILE* fp = fopen(filename,"r");
    menuStart->countSubmenus = 0;
    menuStart->countSubmenusMax = 10;
    menuStart->level=0;
    Menu* previousMenu = menuStart;


    char line[250];
    int count = 0;
    while(fgets(line,250,fp) != NULL)
    {
        Menu* menu = (Menu*) malloc(sizeof(Menu)*1);
        int level;
        char text[125];
        char command[125];


        sscanf(line,"%d %s %s\n", &level, &text, &command);

        int differentLevel =  (previousMenu->level) - level;

        if(differentLevel>0)
        {
            for (int i = 0; i < differentLevel+1; ++i)
                previousMenu = previousMenu->parentMenu;
            count--;

        }
        else if (differentLevel == 0)
        {
                previousMenu = previousMenu->parentMenu;
        }

        menu->parentMenu = previousMenu;
        menu->level = level;
        menu->countSubmenus = 0;
        menu->countSubmenusMax = 10;
        strcpy(menu->text,text);
        strcpy(menu->command,command);
        if(previousMenu->countSubmenus == 0)
            previousMenu->submenus = (Menu**) malloc(sizeof(Menu*)*10);


        previousMenu->submenus[previousMenu->countSubmenus] = menu;
        previousMenu->countSubmenus++;
        previousMenu = menu;


    }
    fclose(fp);

}


FoodMenus getFoodMenus(char *filenameDay, char *filenameWeek,char *filenameDayMaterials, char *filenameWeekMaterials)
{
    FoodMenus foodMenus;

    FILE* fpDay = fopen(filenameDay, "r");
    FILE* fpWeek = fopen(filenameWeek,"r");

    char text[100];
    int costDay;
    int costWeek;

    strcpy(foodMenus.DayMenu.name,"napi");

    fgets(text, 100, fpDay);
    strcpy(foodMenus.DayMenu.appetizer,text);

    fgets(text, 100, fpDay);
    strcpy(foodMenus.DayMenu.mainCourse,text);

    fgets(text, 100, fpDay);
    strcpy(foodMenus.DayMenu.cake,text);

    fgets(text, 100, fpDay);

    sscanf(text,"%d",&costDay);
    foodMenus.DayMenu.cost = costDay;

    fclose(fpDay);

    strcpy(foodMenus.WeekMenu.name,"heti");

    fgets(text, 100, fpWeek);
    strcpy(foodMenus.WeekMenu.appetizer,text);

    fgets(text, 100, fpWeek);
    strcpy(foodMenus.WeekMenu.mainCourse,text);

    fgets(text, 100, fpWeek);
    strcpy(foodMenus.WeekMenu.cake,text);

    fgets(text, 100, fpWeek);
    sscanf(text,"%d", &costWeek);
    foodMenus.WeekMenu.cost = costWeek;

    fclose(fpWeek);

    foodMenus.DayMenu.rawMaterialArray = getRawMaterials(filenameDayMaterials);
    foodMenus.WeekMenu.rawMaterialArray = getRawMaterials(filenameWeekMaterials);

    return foodMenus;
}

DesktopArray getDesktops(char *filename)
{
    DesktopArray desktopArray;
    FILE* fp = fopen(filename, "r");

    int count = 0;
    desktopArray.desktops = (RawMaterial*) malloc(sizeof(RawMaterial)*0);
    char line[50];
    while(fgets(line,50,fp) != 0)
    {
        int id,number;
        sscanf(line, "%d %d\n",&id,&number);
        Desktop desktop = {empty,id, number};
        dynamicAllocationMemoryDesktop(&desktopArray, ++count, desktop);
    }

    fclose(fp);
    return desktopArray;
}

RawMaterialArray getRawMaterials(char *filename)
{
    RawMaterialArray rawMaterialArray;
    rawMaterialArray.rawMaterials = (RawMaterial*) malloc(sizeof(RawMaterial));
    FILE* fp = fopen(filename, "r");

    int count = 0;
    char line[100];

    while(fgets(line,100,fp) != NULL)
    {
        char name[50];
        int quantity;
        sscanf(line, "%s %d\n", &name, &quantity);
        RawMaterial rawMaterial;
        strcpy(rawMaterial.name,name);
        rawMaterial.quantity = quantity;
        dynamicAllocationMemoryRawMaterial(&rawMaterialArray, ++count, rawMaterial);
    }
    return rawMaterialArray;
}

DataProceeds getDataProfit(char *filename)
{
    DataProceeds dataProceeds;
    FILE* fp = fopen(filename, "r");
    char line[150];
    if(fgets(line,100,fp) != NULL)
    {
        int consumerCountDay,consumerCountWeek,proceeds;
        sscanf(line,"%d %d %d\n",&consumerCountDay, &consumerCountWeek, &proceeds);
        dataProceeds.consumerCountDay = consumerCountDay ;
        dataProceeds.consumerCountWeek = consumerCountWeek;
        dataProceeds.proceeds = proceeds;
    }

    fclose(fp);

    return dataProceeds;
}

void saveFoodMenus(FoodMenus* const foodMenus, char const *filenameDay, char const *filenameWeek,char const *filenameDayMaterials, char const *filenameWeekMaterials)
{
    FILE* fpDay = fopen(filenameDay, "w");
    FILE* fpWeek = fopen(filenameWeek,"w");

    fprintf( fpDay,"%s", foodMenus->DayMenu.appetizer);
    fprintf(fpDay, "%s", foodMenus->DayMenu.mainCourse);
    fprintf(fpDay, "%s", foodMenus->DayMenu.cake);
    fprintf(fpDay, "%d", foodMenus->DayMenu.cost);
    fclose(fpDay);
    saveRawMaterials(&foodMenus->DayMenu.rawMaterialArray, filenameDayMaterials);

    fprintf(fpWeek, "%s", foodMenus->WeekMenu.appetizer);
    fprintf(fpWeek, "%s", foodMenus->WeekMenu.mainCourse);
    fprintf(fpWeek, "%s", foodMenus->WeekMenu.cake);
    fprintf(fpWeek, "%d", foodMenus->WeekMenu.cost);
    fclose(fpWeek);
    saveRawMaterials(&foodMenus->WeekMenu.rawMaterialArray, filenameWeekMaterials);
}
/**
void saveDesktops(DesktopArray const *desktopArray, char *filename)
{
    FILE* fp = fopen(filename, "w");

    for (int i = 0; i < desktopArray->desktopsCount; ++i) {
        fprintf(fp,"%d\n", desktopArray->desktops[0].chairCount);
    }

    fclose(fp);
    
}
**/
void saveRawMaterials(RawMaterialArray* rawMaterialArray, char *filename)
{
    FILE* fp = fopen(filename, "w");

    for (int i = 0; i < rawMaterialArray->count-1; ++i)
        fprintf(fp,"%s %d\n", rawMaterialArray->rawMaterials[i].name, rawMaterialArray->rawMaterials[i].quantity);
    fprintf(fp,"%s %d", rawMaterialArray->rawMaterials[rawMaterialArray->count-1].name, rawMaterialArray->rawMaterials[rawMaterialArray->count-1].quantity);

    fclose(fp);
}

void saveDataProfit(DataProceeds const *dataProceeds, char const *filename)
{
    FILE* fp = fopen(filename, "r");

    fprintf(fp, "%d %d %d",dataProceeds->consumerCountDay,dataProceeds->consumerCountWeek,dataProceeds->proceeds);

    fclose(fp);
}

static void freeMenu(Menu* menu)
{
        for (int i = 0; i < menu->countSubmenus; ++i)
        {
            if(menu->submenus[i]->countSubmenus>0)
                freeMenu(menu->submenus[i]);
            free(menu->submenus[i]);
        }
        free(menu->submenus);


}

static void freeFoodMenus(FoodMenus* foodMenus)
{
    free(foodMenus->DayMenu.rawMaterialArray.rawMaterials);
    free(foodMenus->WeekMenu.rawMaterialArray.rawMaterials);
}


void freeAllDynamicAllocationMemory(Menu* menuStart, FoodMenus* foodMenus, DesktopArray* desktopArray, RawMaterialArray* rawMaterialArray)
{
   freeMenu(menuStart);
   freeFoodMenus(foodMenus);
   free(desktopArray->desktops);
   free(rawMaterialArray->rawMaterials);
}


