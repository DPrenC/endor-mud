/*
DESCRIPCION : trastero en la taberna de Sally la gorda
FICHERO     : /d/akallab/comun/habitación/akallab/
              azzor/taberna/sally/trastero.c
MODIFICACION: 10-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
inherit SCHEDULER_ROOM;

create()
{
    ::create();
    SetIntShort("un trastero");
    SetIntLong("Te encuentras en un pequeño cuarto que hace las veces de trastero de la "
        "vivienda. Las estanterías de sus paredes están llenas de todo tipo de trastos sin "
        "mucho valor y en el suelo se amontonan multitud de cajas.\nUna pequeña ventana en la "
        "pared Norte del cuarto proporciona algo de luz y ventilación.\n");
    AddDetail(({"ventana"}),"La pequeña ventana se halla en la parte superior del muro norte "
        "del cuarto. Permite que se ventile este cuarto y que entre algo de luz.\n");
    AddDetail(({"cajas"}),"Están por todo el suelo del cuarto.\n");
    AddDetail(({"estanterías","estanterias","trastos"}),"Las paredes del cuarto están "
        "cubiertas por estanterías en las que se acumulan todo tipo de trastos sin mucho valor.\n");
    SetIntNoise("Oyes lejano el ambiente de la taberna.\n");
    SetIntSmell("Huele a polvo.\n");
        SetLocate("ciudad de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    SetMainRoom("barra");
    SetLastDest(AZ_PUERTO("portico05"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Por el ruido que te llega desde el piso inferior, sospechas que están a "
        "punto de cerrar...\n");
    SetThrowOutMsg("Sally aparece viniendo desde el pasillo, te mira un momento y te dice: ¿Y "
        "bien? ¿Piensas quedarte a dormir conmigo? Me encantaría, pero hoy no es mi día, así "
        "que ya te estás largando.\nViendo la expresión de su cara, decides no hacértelo "
        "repetir, y a toda prisa, bajas la escalera y abandonas el local.\n");
    AddExit("sur","escalera1");
    AddDoor("sur","la puerta del trastero",
        "Apenas un tablón de madera, viejo y desvencijado.\n",
        ({"puerta","puerta trastero","puerta de trastero","puerta del trastero"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA]));
    AddItem(MUEBLE("caja_herramientas"),REFRESH_DESTRUCT,1);
    AddItem(MUEBLE("caja_vacia"),REFRESH_DESTRUCT,1);
    AddItem(OTRO("cubo"),REFRESH_DESTRUCT,1);
    AddItem(ARMA("escoba"),REFRESH_DESTRUCT,1);
}
