/****************************************************************************
Fichero: casa4.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: la casa de tributos de Nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <nightday.h>

inherit SCHEDULER_ROOM;
inherit "/room/censo";
create () {
    ::create();
    SetLocate("la aldea de Nandor");
    SetCity("Nandor");
    SetIntBright(30);

    SetIntShort("la casa de tributos");
    SetIntLong("Te encuentras en el interior de la casa de tributos. Se trata de una "
    "estancia amplia y austera, de paredes de piedra vasta, suelo de tablas y techo "
    "a dos aguas de vigas ennegrecidas por el paso de los años.\n"
    "La habitación carece de mobiliario a excepción de un ancho mostrador y unas cuantas "
    "balanzas de distinto tamaño usadas para medir las cantidades de trigo y "
    "otros productos que los aldeanos de la villa traen para pagar sus tributos.\n"
    "Al fondo de la estancia puedes ver un montón de sacos, cestos y una serie de "
    "recipientes donde se guardan de forma provisional los bienes obtenidos antes de "
    "llevarlos al castillo o cambiarlos por mercancías de otras tierras.\n"
    "Sobre el mostrador hay un pesado libro en el cual se censan  los aldeanos del "
    "feudo, sus propiedades y la cantidad de bienes que deben aportar a "
    "las arcas de la familia Dhes-Bláin.\n");
    AddDetail("mostrador", "Es un armazón de madera de forma rectangular  cuyos "
    "extremos se apoyan en otros dos tablones verticales hundidos en el suelo.\n");
    AddDetail("balanzas", "media docena de balanzas de distintos tamaños, de latón  o "
    "bronce, en base a las cuales se calcula el tributo que cada campesino debe aportar, "
    "normalmente trucadas para obtener mas de lo debido. Los aldeanos son conscientes "
    "de ello pero nada pueden hacer contra las alabardas y espadas de los "
    "hombres de Rocher.\n");
    AddDetail(({"sacos", "cestos", "recipientes"}), "Están amontonados en el fondo de la "
    	"estancia, y aparecen llenos de productos: trigo, hortalizas, huevos, "
    	"embutidos, y algún que otro animal pequeño como gallinas o conejos.\n");
    SetIntSmell("Huele a cereales y hortalizas.\n");

    //AddExit("arriba","./censo");
    AddExit("sur", "../calle42n");
    AddDoor("sur", "la puerta de la calle", "Es la puerta que da a la plaza de Nandor.\n",
    ({"puerta", "puerta de la calle", "puerta del sur"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    SetLastDest("../calle42n");
    SetNotifyExits("sur");
    //SetAssociatedRooms("./censo");
    SetSchedulerID("recaudador");
    SetCloseTime(({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
    AddItem(PNJ("marhalt/conserje"),REFRESH_DESTRUCT);
    AddItem(PNJCASTILLO("hombre_armas2"), REFRESH_DESTRUCT,1);
    AddItem(PNJCASTILLO("hombre_armas2"), REFRESH_DESTRUCT,1);
    AddItem(PNJCASTILLO("hombre_armas1"), REFRESH_DESTRUCT,d2());
}
