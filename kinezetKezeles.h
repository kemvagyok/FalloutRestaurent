#ifndef FALLOUTETTEREM_KINEZETKEZELES_H
#define FALLOUTETTEREM_KINEZETKEZELES_H
#include "adatokKezelese.h"
///Kiiírja az asztalok elhelyezkedését konzolra.
void desktopMapWriting();
///Kiírja az adott menüsornak az adatait.
/// \param menu Menu típusú változó
void menusWriting(Menu menu);
///Kiírja az adott ételmenü adatait.
/// \param foodMenu FoodMenu típusú pointer
void foodMenuWriting(FoodMenu* foodMenu);
///Kiírja az alapanyagokat összesítő adatot.
/// \param rawMaterial
void rawMaterialWriting(RawMaterial* rawMaterial);
///Kiírja az adott asztalnak a számláját.
/// \param desktop Desktop típusú pointer
void billWriting(Desktop* desktop);
///Kiírja az üzleti dolgokat összeítő adatot.
/// \param dataProceeds DataProceeds típusú pointer
void dataProfitWriting(DataProceeds* const dataProceeds);
#endif //FALLOUTETTEREM_KINEZETKEZELES_H
