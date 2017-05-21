/*
DESCRIPCION : Meson del Negro
FICHERO     : posada/meson_negro/despensa.c
MODIFICACION:
16-09-07 [Angor] Creacion
*/

#include "path.h"
//#include <moving.h>
#include AK_MACRO
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("la despensa del mes�n del Negro");
    SetIntLong("Te encuentras en la despensa. Es una peque�a estancia llena de estanter�as "
        "repletas de los m�s diversos productos, necesarios para hacer las comidas que se "
        "sirven en este local.\n");
    AddDetail(({"estanter�as","estanterias","productos"}),"Por lo que ves, las estanter�as  "
        "contienen principalmente especias y plantas, ya que el pescado lo deben comprar fresco "
        "cada d�a en el puerto.\n");
    SetIntNoise("Oyes el t�pico ruido de cacharros proveniente de la cocina.\n");
    SetIntSmell("El aire es c�lido y el olor de los calderos tentador...\n");
    SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("comedor");
    SetLastDest(AZ_PUERTO("portico06"));
    SetNoSchedulerObject(1);
    SetThrowOutMsg("Oyes a El negro dar dos fuertes palmadas al este y gritar:\nVamos, fuera "
        "todo el mundo, que cerramos ya.\n");
    SetNotifyExits(({}));
    SetInformCloseMsg("Oyes a El negro gritar en la cocina:\n�Koen! �Ve recogiendo, que nos "
        "vamos!\n");
    AddExit("norte","cocina");
}
