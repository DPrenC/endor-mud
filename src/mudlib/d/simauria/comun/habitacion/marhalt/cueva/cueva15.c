/********************************************
*    Nombre: cueva15.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 09-02-00                      *
*    Modificado:                            *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");


create () {
    ::create();
    SetIntShort("un derrumbe");
    SetIntLong("El t�nel parece que se haya undido en este lugar hace cientos de a�os, "
        "donde un mont�n de rocas y escombros hacen una peligrosa rampa que da acceso "
        "a una sala inferior, El suelo es muy inseguro e irregular, pero no debe de "
        "haber dificultad en bajar.\n");
    SetIntNoise("El eco de tus pasos son amortiguados por los escombros.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddDetail(({"escombros","rocas","derrumbe"}), "Los cimientos de esta sala "
        "dejan bastante que desear. El suelo se parti� hace ya mucho tiempo y las rocas "
        "se esparcen por doquier.\n");
    AddDetail(({"humedad","agua"}), "la humedad que cae por las paredes "
        "ayuda a que proliferen todo tipo de hongos.\n");
    AddDetail("rampa", "Un mont�n de rocas y escombros hacen funci�n de peligrosa "
    "rampa que baja a un nivel inferior de la gruta.\n");
    AddExit("abajo", "./cueva16");
    AddExit("sudeste", "./cueva14");
    AddItem(PNJ("marhalt/cueva/carronyero"),REFRESH_DESTRUCT,1);
}
