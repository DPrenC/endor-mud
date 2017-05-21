/*
DESCRIPCION  : Entrada a la mina del parque de newbies
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/entrada.c
MODIFICACION : 16-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <wizlevels.h>
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SHOP;

#define NOMBRE capitalize(TP->QueryName())
#define GEN    (TP->QueryGenderEndString())

create()
{
    ::create();
    SetIntShort("la entrada de la mina");
    SetIntLong("La boca de lo que parece una mina abandonada est� excavada aqu�, en la base de una de las altas paredes "
        "rocosas que forman las monta�as de esta zona de la isla. En la peque�a planicie que hay junto a ella se halla un "
        "peque�o manantial de agua turbia y los restos de madera de lo que una vez fue el molino de mineral. Montones de "
        "rocas y cascotes se apilan a los lados de la planicie. Hay un letrero junto a la mina.\nUn sendero desciende "
        "serpenteando hasta el bosque que observas al sudeste.\n");

    AddDetail(({"mina","entrada"}),QueryIntLong());
    AddDetail(({"letrero"}),"En el letrero que hay junto a la boca de la mina est� escrito lo siguiente:\n'�NO ENTRAR! "
        "Esta mina est� abandonada y es un lugar peligroso.'\n");
    AddDetail(({"manantial"}),"Es un peque�o chorro de agua turbia que baja por las paredes de roca. No debe ser potable. "
        "En su d�a se debi� utilizar para lavar el mineral extra�do de la mina.'\n");
    AddDetail(({"molino"}),"No queda mucho de �l. Era una m�quina de madera accionada por mulas en la que se mol�an las "
        "rocas extra�das de la mina para separar los minerales del resto.'\n");
    AddDetail(({"rocas","montones","monton","mont�n"}),"Hay varios grandes montones de rocas a los lados de la planicie. "
        "Fueron extra�das al excavar las galer�as de la mina.\n");
    SetIntNoise("Oyes a los p�jaros trinar y al viento aullar.\n");
    SetIntSmell("Huele a polvo.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(0);
    SetShopkeeper(PNJ("minero"));
    AddArticle("/obj/torch", REFRESH_REMOVE,4);
    SetCloseTime(({ND_NO_STATES}));
    //SetCloseTime(({ND_NIGHT, ND_PREDAWN, ND_DAWN}));
    CanIdentify(0);
    CanAppraise(0);
    CanSell(0);
    AddExit("este",BOSQUE("c_mina00"));
    AddExit("oeste",MINA("cruce00"));
}

init()
{
    ::init();
    SkSay("�Hola! Si piensas entrar a la mina, necesitar�s una antorcha. Yo las vendo si te interesa...\n");
}
