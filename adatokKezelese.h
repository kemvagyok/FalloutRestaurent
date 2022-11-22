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


/// Betölti a menüket Menus típussal
/// \param menuStart Menu típusó pointerbe berakaj a beolvasott menüket
/// \param filename A menük adatait tartalmazó fájl neve
void getMenus(Menu* menuStart, char* filename);
///Betölti az ételmenüket FoodMenus típussal (alapanyagokkal együtt)
/// \param filenameDay A napi ételmenü adatait tartalmazó fájl neve
/// \param filenameWeek A heti ételmenü  tartalmazó fájl neve
/// \param filenameDayMaterials A napi ételmenü alapanyagainak adatait tartalmazó fájl neve
/// \param filenameWeekMaterials A heti ételmenü alapanyagainak adatait tartalmazó fájl neve
/// \return FoodMenus típusú változót ad vissza
FoodMenus getFoodMenus(char *filenameDay, char *filenameWeek,char *filenameDayMaterials, char *filenameWeekMaterials);
///Betölti az étterem asztalait
/// \param filename A napi ételmenü adatait tartalmazó fájl neve
/// \return DesktopArray típusú változót ad vissza
DesktopArray getDesktops(char *filename);
///Betölti az alapnyagok adatait RawMaterialArray-jal
/// \param filename Az adott alapanyagok adatait tartalmazó fájl neve
/// \return RawMaterialArray típusú változót ad vissza
RawMaterialArray getRawMaterials(char *filename);
///Betölti az üzleti dolgok adatait DataProceeds-sel
/// \param filename Az üzleti dolgok adatait tartalmazó fájl neve
/// \return DataProceeds típusú változót ad vissza
DataProceeds getDataProfit(char *filename);
///Elmenti a napi és a heti menü adatait
/// \param foodMenus A foodMenus típusú pointer
/// \param filenameDay A napi ételmenü adatait tartalmazó fájl neve
/// \param filenameWeek A heti ételmenü adatait tartalmazó fájl neve
/// \param filenameDayMaterials A napi ételmenü alapanyagainak adatait tartalmazó fájl neve
/// \param filenameWeekMaterials A heti ételmenü alapanyagainak adatait tartalmazó fájl neve
void saveFoodMenus(FoodMenus* const foodMenus, char const *filenameDay, char const *filenameWeek,char const *filenameDayMaterials, char const *filenameWeekMaterials);

//void saveDesktops(DesktopArray const *desktopArray, char *filename);
///Elmenti az adott alapanyagok adatait
/// \param rawMaterialArray RawMaterialArray típusú pointer
/// \param filename Az adott alapanyagok adatait tartalmazó fájl neve
void saveRawMaterials(RawMaterialArray* rawMaterialArray, char *filename);
///Elmenti az üzleti dolgok adatait
/// \param dataProceeds A DataProceeeds típusú pointer
/// \param filename Az üzleti dolgok adatait tartalmazó fájl neve
void saveDataProfit(DataProceeds const *dataProceeds, char const *filename);
///Felszabadítja a dinamikusan kezelt adatokat
/// \param menuStart Menu típusú pointer (fa-struktúra)
/// \param foodMenus foodMenus típusú pointer
/// \param desktopArray desktopArray típusú pointer
/// \param rawMaterialArray rawMaterialArray típusú pointer
void freeAllDynamicAllocationMemory(Menu* menuStart, FoodMenus* foodMenus, DesktopArray* desktopArray, RawMaterialArray* rawMaterialArray);

#endif //FALLOUTETTEREM_ADATOKKEZELESE_H
