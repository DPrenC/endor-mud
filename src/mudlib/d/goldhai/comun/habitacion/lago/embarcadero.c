/*=============================================================*
 |            << GOLDHAI.Lago [w] Woo@simauria >>              |
 *=============================================================*
 |               Creacion............ 24-02-99                 |
 |               Ultima Modificacion. 23-03-99                 |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <moving.h>
#include <gremios.h>


inherit PORT;

public int EntrarAlGremio()
{
    object pl;
    if (!pl = TP) return 0;
    if (pl->QueryGuild() != GC_KISALAS && !query_wiz_level(pl))
    {
        say(CAP(NNAME(pl)) + " intenta avanzar en dirección este. Sin embargo, ves "
            "como es retenid" + pl->QueryGenderEndString() + " por una fuerza "
            "invisible que no le deja pasar.\n");
        return notify_fail("Intentas pasar hacia el bosque... Sin embargo, una "
                           "especie de pared invisible te impide ir en esa dirección "
                           "por más que lo intentas.\n");
    }
    TP->move("/guilds/kisalas/habitacion/arena/arena2", M_GO, "este");
    return 1;
}

create()
{
 ::create();
 SetIntShort("un pequeño embarcadero");
 SetIntLong("\
Te encuentras al borde de un pequeño embarcadero en el lago Zinn. Todo es\n\
suciedad a tu alrededor, hasta el agua esta verde y llena de algas. Al Norte\n\
ves la entrada al gremio de las Kisalas, y al este comienza el bosque que les "
"sirve como zona de entrenamiento.\n");

 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Hay una extraña calma en este lugar.\n");
 SetIntSmell("Argghh.. huele bastante mal.\n");
 AddDetail("tabla","No ves ninguna tabla cerca.\n");
 AddRoomCmd("leer","room_leer");

 AddDetail(({"embarcadero","lugar","muelle"}),
"A este sitio no se le puede llamar embarcadero, es un criadero de suciedad.\n");
 AddDetail(({"algas","algas verdes"}),
"Puaajjj.. desde luego eso es bastante asqueroso.\n");

 AddShip(BOTE_FANTASMA("bote"));

 AddExit("norte","/guilds/kisalas/habitacion/entrada");
 AddExit("este",SF(EntrarAlGremio));


 SetLocate("isla del lago Zinn");
}

room_leer(string str)
{
 if (str=="tabla")
  return write("No ves ninguna tabla aquí.\n"),1;
 return 0;
}