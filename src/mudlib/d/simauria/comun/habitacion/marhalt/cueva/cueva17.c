/********************************************
*    Nombre: cueva17.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 09-02-00                      *
*    Modificado: 16-11-01 [Theuzifan] Typo -> escaBada
*    Modificado: 19-11-01 [Nemesis] Typo -> eXcaVada
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");


create () {
    ::create();
    SetIntShort("la antesala a una sala circular");
    SetIntLong("Esta es una sala un poco más grande de lo normal, y notablemente "
    "más trabajada. Las paredes, techo y suelo no están tan escarpadas como es lo "
    "habitual en  una cueva como esta.\n Hacia el oeste empieza una gran sala circular.\n");
    AddDetail(({"pilar", "columna", "columna blanca"}), "Es una enorme columna de "
    "mármol blanco, que preside el centro de esta estancia circular.\n");
    SetIntNoise("El eco de tus pasos resuena por las pulidas paredes.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddExit("este", "./cueva16");
    AddExit("oeste", "./cueva18");
    AddItem(PNJ("marhalt/cueva/troll"), REFRESH_DESTRUCT, d3());
}
