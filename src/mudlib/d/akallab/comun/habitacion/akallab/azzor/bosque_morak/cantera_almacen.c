/*
DESCRIPCION  : cantera al norte del bosque de Morak
FICHERO      : cantera_almacen.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create()
{
    ::create();
   SetIntShort("un almac�n en la cantera del bosque de Morak");
    SetIntLong("Es �sta una peque�a y r�stica caba�a de madera que parece "
        "emplearse como almac�n. Hay un par de toscas estanter�as sobre las "
        "paredes y en el suelo se amontonan multitud de cajas. Por la "
        "cantidad de polvo de piedra que se acumula en este lugar supones "
        "que o bien esta caba�a pasa mucho tiempo abierta o, probablemente, "
        "es aqu� donde se guarden las herramientas que los canteros emplean "
        "en su trabajo.\n");
    AddDetail(({"cajas"}),"Est�n por todo el suelo del cuarto.\n");
    AddDetail(({"estanterias","estanter�as","trastos"}),"Hay un par de "
        "toscas estanter�as de madera contra las paredes de la caba�a en las "
        "que se acumulan todo tipo de trastos sin mucho valor.\n");
    SetIntSmell("Huele a polvo de la piedra.\n");
    SetIntNoise("No oyes nada en especial.\n");
    SetLocate("valle de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    AddExit("este",BOSQUE_MORAK("cantera3"));
    AddItem(MUEBLE("caja_herramientas"),REFRESH_DESTRUCT,1);
    AddItem(OTRO("cubo"),REFRESH_DESTRUCT,1);
    AddItem(MUEBLE("caja_vacia"),REFRESH_DESTRUCT,1);
}
