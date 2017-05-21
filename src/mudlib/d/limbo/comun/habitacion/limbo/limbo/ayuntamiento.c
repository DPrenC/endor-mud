/*
DESCRIPCION  : Ayuntamiento del poblado de pescadores
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/ayuntamiento.c
MODIFICACION : 26-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit "/room/censo";

create() {
    ::create();
    SetCity("Limbo");
    SetIntShort("el ayuntamiento del poblado de pescadores");
    SetIntLong(
"Estás en el ayuntamiento del poblado de pescadores. Frente a ti se halla un "
"mostrador y un libro de censo sobre él. Al norte de esta habitación se halla "
"la sala de reuniones y al oeste la sede del Gremio de Aventureros.\n");

    AddDetail(({"mostrador"}),
 "El mostrador es una especie de mesa alta y estrecha de madera. Tras ella "
 "rodeado de papeles y archivos se encuentra el secretario del ayuntamiento.\n");

    AddDetail(({"sala"}),"Al norte de aqui se halla una amplia sala de reunión.\n");

    AddDetail(({"gremio","Gremio"}),
 "En la habitacion que queda al oeste se halla el Gremio de Aventureros. Si "
 "tienes interés o quieres informarte deberias entrar.\n");

    AddDetail(({"censo","libro"}),
 "En este libro esta una copia del censo actual en este mundo. Pasa censarte en "
 "este lugar o cambiar el lugar en el que estas censado utiliza 'censar' y "
 "si quieres saber donde estás censado, usa 'consultar'.\n");

    SetIntNoise("El secretario orco no para de maldecir entre dientes.\n");
    SetIntSmell("El olor del campo se confunde con el del mar.\n");
    SetLocate("isla Limbo");
    SetIndoors(1);
    SetIntBright(50);

    AddExit("sur",LIMBO("calle01"));
    AddExit("oeste","/guilds/aventurero/sede/limbo/aventurero");
    AddExit("norte",LIMBO("salon_ayto"));
    AddItem(PNJ("secretario"));
}
