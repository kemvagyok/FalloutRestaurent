//
// Created by 0322s on 2022. 11. 10..
//

#ifndef FALLOUTETTEREM_ADATOKKEZELESE_H
#define FALLOUTETTEREM_ADATOKKEZELESE_H


//Enum-ok
typedef enum Available {
    busy, empty
} Available;
typedef enum UserType {
    Owner, Waiter
} UserType;
typedef enum MenuPart {
    Appetizer, MainCourse, Cake
} MenuPart;

//strukturálisi típusok felsorolása


typedef struct Menu {
    int level;
    char text[300];
    char command[100];
    struct Menu *parentMenu;
    int countSubmenus;
    int countSubmenusMax;
    struct Menu **submenus;
    void* fun_ptr;
} Menu;


typedef struct RawMaterial {
    char name[50];
    int quantity;
} RawMaterial;

typedef struct RawMaterialArray {
    int count;
    RawMaterial* rawMaterials;
} RawMaterialArray;

typedef struct FoodMenu {
    char name[50];
    char appetizer[100];
    char mainCourse[100];
    char cake[100];
    int cost;
    RawMaterialArray rawMaterialArray;
} FoodMenu;

typedef struct FoodMenus {
    FoodMenu DayMenu;
    FoodMenu WeekMenu;
}FoodMenus;

typedef struct DataProceeds {
    int consumerCountDay;
    int consumerCountWeek;
    int proceeds; //dynamically allocate a 2D array
} DataProceeds;

typedef struct Desktop {
    Available available;
    int id;
    int chairCount;
    int countOrderDayMenu;
    int countOrderWeekMenu;
    int costSummary;
} Desktop;

typedef struct DesktopArray {
    int desktopsCount;
    Desktop* desktops;
} DesktopArray;



void getMenus(Menu* menuStart, char* filename);

FoodMenus getFoodMenus(char *filenameDay, char *filenameWeek,char *filenameDayMaterials, char *filenameWeekMaterials);

DesktopArray getDesktops(char *filename);

RawMaterialArray getRawMaterials(char *filename);

DataProceeds getDataProfit(char *filename);

void saveFoodMenus(FoodMenus* const foodMenus, char const *filenameDay, char const *filenameWeek,char const *filenameDayMaterials, char const *filenameWeekMaterials);

//void saveDesktops(DesktopArray const *desktopArray, char *filename);

void saveRawMaterials(RawMaterialArray* rawMaterialArray, char *filename);

void saveDataProfit(DataProceeds const *dataProceeds, char const *filename);

void freeAllDynamicAllocationMemory(Menu* menuStart, FoodMenus* foodMenus, DesktopArray* desktopArray, RawMaterialArray* rawMaterialArray);

#endif //FALLOUTETTEREM_ADATOKKEZELESE_H
