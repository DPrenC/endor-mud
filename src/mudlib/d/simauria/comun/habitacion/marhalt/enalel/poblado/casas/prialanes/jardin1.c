/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <materials.h>
inherit SIM_ROOM;

create() {
    ::create();

    SetIndoors(0);
    SetLocate("Casa Prialanes");
    SetIntShort("el jardín experimental");
    SetIntLong("Estás en un jardín extraño protegido del exterior por unos "
    "grandes cristales. Los manzanos parecen ser el único cultivo de este jardín. "
    "Aquí es donde la familia Prialane experimenta con nuevas generaciones de "
    "manzanas.\n El jardín continúa hacia el sur. La salida del jardín está hacia "
    "el noroeste.\n");
    SetIntNoise("Los sonidos de la naturaleza llegan amortiguados por los cristales.\n");
    SetIntSmell("El aroma de extrañas manzanas flota en el lugar.\n");
    AddDetail(({"cristal","critstales"}),"Son unas enormes paredes de cristal "
    "que protegen a los manzanos de las inclemencias del exterior.\n");
    AddDetail(({"manzano","manzanos","árbol","arbol","árboles","arboles"}),"Son "
    "unos enormes y frondosos manzanos de troncos oscuros y hojas doradas. Parece "
    "que en estos momentos no hay manzanas en sus copas.\n");

    AddExit("noroeste",ENALHAB"poblado/casas/prialanes/hall");
    AddExit("sur",ENALHAB"poblado/casas/prialanes/jardin2");
    AddDoor("noroeste", "la puerta del hall",
    "Una puerta transparente para volver al hall de la mansión.\n",
    ({"puerta", "puerta transparente", "puerta del hall", "puerta del noroeste"}),
    ([P_DOOR_TRANSPARENCY:1, P_MATERIAL: M_CRISTAL,
        P_DOOR_KNOCK_SOUND: SND_SUCESOS("llamar_puerta_cristal")]));
}
