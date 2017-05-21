/*
DESCRIPCION  : Casa de la curandera el bosque de Talek
FICHERO      : cabanya.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
inherit SHOP;

create()
{
    ::create();
   SetIntShort("la cabaña de la curandera");
    SetIntLong("Te encuentras en la cabaña de la vieja curandera del bosque "
        "de Talek. En las paredes de la cabaña puedes observar estanterías "
        "en las que se apilan frascos y cajas con todo tipo de ingredientes: "
        "hierbas, setas, polvos y pociones.\nBajo una chimenea al fondo de "
        "la habitación, una marmita cuece a fuego lento.\nJunto a la puerta "
        "hay una nota colgada en la pared.\n");
    AddDetail(({"estanterias","estanteria","estanterías","estantería","paredes"}),
        "En las paredes de la cabaña hay varias estanterías. En ellas puedes "
        "ver innumerables frascos y cajas que contienen todo tipo de "
        "ingredientes que la curandera emplea en su trabajo así como "
        "pociones ya preparadas.\n");
    AddDetail(({"cajas"}),"La curandera emplea algunas pequeñas cajas para "
        "guardar ciertos componentes secos como hojas o cortezas de árbol.\n");
    AddDetail(({"frascos"}),"Las estanterías están llenas de ellos. En estos "
        "recipientes de cristal es donde la curandera suele guardar hierbas, "
        "hojas y otros muchos de los componentes que vende o emplea en su "
        "trabajo. Tiene unos frascos mas pequeños con pociones ya preparadas "
        "y listas para vender.\n");
    AddDetail(({"marmita"}),"La marmita es una especie de pequeño caldero de "
        "metal colgado sobre el fuego en la chimenea en la que la curandera "
        "prepara algunas pociones. En este momento se está cociendo algo en "
        "ella a fuego lento.\n");
    AddDetail(({"chimenea"}),"Al fondo de la habitación hay una chimenea. En "
        "ella arde un fuego que caldea el ambiente y sobre el que la "
        "curandera prepara algunas de sus pociones.\n");
    SetIntNoise("Oyes como hierve la marmita sobre el fuego.\n");
    SetIntSmell("Huele a hierbas y hojas resecas.\n");
    SetLocate("valle de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    CanSell(1);     //El cliente si puede vender a la tienda
    CanAppraise(0); //No se valoran objetos
    CanIdentify(0); //No se identifican objetos
    RemoveDustbin();
    SetShopkeeper(0,
        ([P_SHORT:"La ayudante de la curandera",
        P_LONG:"Lakka es una niña orca que ayuda a la curandera en su "
            "trabajo. Generalmente se encarga de atender a los clientes "
            "comprando ingredientes o vendiendo los productos que la "
            "curandera prepara. Ella es además la que adecenta y limpia esta "
            "vieja cabaña.\n",
        P_IDS:({"ayudante","joven","orca","Lakka","lakka"}),
        P_LEVEL:8,
        P_STR:10,
        P_CON:10,
        P_DEX:1,
        P_INT:1,
        P_GENDER:GENDER_FEMALE]));
    AddArticle(POCION("pocion_curativa"), REFRESH_REMOVE,2);
    AddExit("sur",BOSQUE_TALEK("claro01"));
    AddItem(QUEST+"curandera/curandera", REFRESH_DESTRUCT);
}

CheckTrade(obj)
{
    if (obj->id("hierba_id")) return 1;
    return 0;
}
