/********************************************
*    Nombre: cueva16.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 09-02-00                      *
*    Modificado:                            *
*********************************************/


#include "path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");


create () {
    ::create();
    SetIntShort("un derrumbe");
  SetIntLong("El túnel parece que se haya hundido en este lugar "
"y un montón de rocas y escombros han caido sobre esta sala. Parece como si "
"en este nivel inferior alguna mano humanoide hubiese escabado las salas. "
"El montón de escombros han formado una pequeña rampa que da al nivel superior.\n");
    SetIntNoise("El eco de tus pasos son amortiguados por los escombros.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddDetail(({"escombros","rocas","derrumbe"}), "Esta sala esta llena de "
    "escombros. El techo se partió hace ya mucho tiempo y las rocas se esparcen por "
    "doquier.\n");
    AddDetail(({"humedad","agua"}), "la humedad que cae por las paredes "
        "ayuda a que proliferen todo tipo de hongos.\n");
    AddDetail("rampa", "Un montón de rocas y escombros hacen función de peligrosa "
    "rampa que sube a un nivel superior de la gruta.\n");
    AddExit("arriba", "./cueva15");
    AddExit("oeste", "./cueva17");
}
