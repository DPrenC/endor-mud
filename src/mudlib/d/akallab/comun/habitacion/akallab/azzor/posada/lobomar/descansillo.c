/*
DESCRIPCION : descansillo en la posada del Lobo de mar
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/descansillo.c
MODIFICACION:
06-12-05 [Riberales] Creacion
16-09-07 [Angor] Modificada la descripcion
*/

#include "path.h"
#include <moving.h>

inherit ROOM;

int ir_norte();
int ir_oeste();

public create()
{
    ::create();

    SetIntShort("un descansillo");
    SetIntLong(
    "Un pequeño rellano en la primera planta de la posada da acceso a las "
    "habitaciones que se alquilan. Junto a una sencilla barandilla, unas "
    "recias escaleras conducen a la planta baja. A través de una ventana "
    "puedes observar al este el puerto de Azzor y los barcos allí fondeados.\n");

    AddDetail(({"puerto","barcos"}),
    "Siempre hay una gran cantidad de barcos fondeados en el puerto de Azzor, "
    "desde mercantes a buques de guerra.\n");

    AddDetail(({"habitaciones","puerta","puertas"}),
    "Unas puertas corrientes de madera dan acceso a las habitaciones. Las "
    "puertas no parecen muy resistentes.\n");

    AddDetail(({"barandilla","escalera","escaleras"}),
    "La barandilla de la escalera no parece muy resistente. La escalera adosada "
    "a la pared atraviesa el hueco del suelo de madera para llegar a la planta baja.\n");

    SetIndoors(1);
    SetIntBright(45);

    SetLocate("ciudad de Azzor");
    AddExit("norte",SF(ir_norte));
    AddExit("oeste",SF(ir_oeste));
    AddExit("abajo",AZ_POSADA("lobomar/entrada"));

}


int no_hay_gente()
{
    if (   sizeof(filter(all_inventory(),(:living($1) && TP->CanSeeObject($1)
        && !$1->QueryIsPet():))) >1)
    {
        return notify_fail("Si quieres inmiscuirte en habitaciones ajenas, "
                       "mejor hacerlo cuando no haya nadie viéndote.\n",
               NOTIFY_NOT_VALID);
    }
    return 1;
}

int ir_norte()
{

    if (!no_hay_gente())
    // sí que hay gente
    {
        return 0;
    }
    write("Disimuladamente abres la puerta y te metes en la habitación "
          "cerrando a tus espaldas.\n");

    TP->move(AZ_POSADA("lobomar/habitacion01"),M_GO,"norte");
    return 1;
}


int ir_oeste()
{

    if (!no_hay_gente())
    // sí hay gente
    {
        return 0;
    }
    write("Sigilosamente abres la puerta y te metes en la habitación "
          "cerrando a tus espaldas.\n");

    TP->move(AZ_POSADA("lobomar/habitacion02"),M_GO,"oeste");
    return 1;
}
