/*

    Nombre      : calle18
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de las cosechas

*/
#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <materials.h>
#include <scheduler.h>
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("el final de la calle de las cosechas");
    SetIntLong("Estás al final de  la calle de las cosechas. Las estatuillas y postes "
    "que aquí se encuentran son los más antiguos y deteriorados. Hacia el norte se alza "
    "el gran risco donde se sitúa el templo de la diosa Deiene. Al sur, un edificio de "
    "madera parece ocupar un amplio terreno, mientras que al oeste se encuentra la puerta "
    "de la tienda del feliz Bertur. Hacia el este, la calle de las cosechas continúa.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddDetail(({"postes","poste","estatuillas","estatuilla"}),"Son los símbolos "
    "que recuerdan algunas cosechas de gran calidad, o hazañas de algunos héroes locales.\n");
    AddExit("este",ENALHAB"poblado/calles/calle17");
    AddExit("oeste",ENALHAB"poblado/tiendas/bertur");
    AddExit("norte",ENALHAB"templo/hall");
    AddExit("sur",ENALHAB"poblado/tiendas/bodega");
    AddDoor("oeste", "la puerta de la tienda",
    "Una puerta para entrar a la tienda del feliz Bertur.\n",
    ({"puerta", "puerta de la tienda", "puerta del oeste"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddDoor("sur", "la puerta de la bodega",
    "La puerta para entrar a la bodega.\n",
    ({"puerta", "puerta de la bodega", "puerta del sur"}));
    AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,d2());
}
