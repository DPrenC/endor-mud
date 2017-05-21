 /*
DESCRIPCION : bajo el portico del meson del Negro en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/portico06.c
MODIFICACION: 28-09-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create()
{
    ::create();
    SetIntShort("el p�rtico del mes�n del Negro");
    SetIntLong("Te hallas bajo el p�rtico de un viejo y macizo edificio donde se encuentra el "
        "mes�n del Negro, un local bastante conocido en el puerto de Azzor especialmente por "
        "sus platos de pescado y sus precios ajustados. El Negro es un viejo orco algo "
        "cascarrabias nacido en las lejanas regiones del Sur y cuya oscura piel le ha valido "
        "el mote por el que todo el mundo lo conoce.\nLa puerta del mes�n queda justo al oeste "
        "de aqu�.\n");
#include "puerto_detail.h"
    AddDetail(({"meson","mes�n","edificio"}),"El mes�n del Negro se halla en el edificio que "
        "queda justo al oeste de aqu�. Es un edificio viejo y macizo. El mes�n es bastante "
        "conocido en la ciudad de Azzor por sus platos de pescado y unos precios ajustados.\n");
    SetIndoors(0);
    //SetIntBright(50);
    AddExit("este",AZ_PUERTO("muelle06"));
    AddExit("norte",AZ_PUERTO("portico05"));
    AddExit("oeste",AZ_TABERNA("negro/comedor"));
    AddExit("sur",AZ_PUERTO("portico07"));
    AddDoor("oeste");
}
