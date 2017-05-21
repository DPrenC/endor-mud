/*
DESCRIPCION  : pequenya cueva al pie de las montanyas
FICHERO      : cueva.c
MODIFICACION : 24-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create()
{
    ::create();
   SetIntShort("una pequeña cueva");
    SetIntLong("Te encuentras en el interior de una pequeña cueva al pie de "
        "las montañas. El suelo está lleno de hojarasca que cruje bajo tus "
        "pies.\nNotas un olor muy fuerte a animal, por lo que piensas que la "
        "cueva tal vez sea la guarida de alguno.\nLa boca de la cueva queda "
        "al sur y conduce al bosque.\n");
    AddDetail(({"hojarasca","suelo"}),"El suelo está cubierto de una "
        "crujiente capa de hojarasca.\n");
    AddDetail(({"bosque","bosque de Talek"}),"Es un inmenso bosque que se "
        "extiende en la parte suroeste del valle de Azzor, hasta el mismo "
        "pie de las montañas. Es un bosque denso y algo sombrío. El Camino "
        "del Este lo atraviesa de este a oeste.\n");
    SetIntNoise("Oyes el sonido del bosque.\n");
    SetIntSmell("Hay un fuerte olor a oso...\n");
    SetLocate("valle de Azzor");
    SetIndoors(0);
    AddExit("sur",BOSQUE_TALEK("bosque14"));
    AddItem(QUEST+"curandera/oso_gris",REFRESH_DESTRUCT,1);
}
