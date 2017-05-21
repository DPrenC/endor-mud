/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 22-01-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>#define ASESINOS DOM_STD "asesinos"
#include DOM_SYS "crowiano.h"

inherit PNJ_CROWY("crowiano_civil_base");

create()
{
    ::create();
    SetStandard("xdhum","humano",([GC_LUCHADOR:22]),GENERO_MASCULINO);
    SetIds(({"contrabandista","xdhum","Xdhum"}));
    SetShort("Xdhum el contrabandista");
    SetLong("Xdhum es un humano de estatura media, de cintura y vientre amplios, "
        "y de cara aparentemente afable, aunque el sus ojos de mirada calculadora  se "
        "percibe que no es un simple mercader, sino alguien muy familiarizado con el "
        "mundo de las transacciones turbias y los negocios sucios.\n");

    SetEdad(MEDIANA);
    SetAlign(-150);

    AddItem(ARMA("espada_larga"),REFRESH_REMOVE,SF(wieldme));
    AddItem("/obj/money",REFRESH_REMOVE,
        (["Money":(["plata":random(6),"oro":random(20)])]));
    AddItem(PROT("camisa_cuero"),REFRESH_REMOVE,SF(wearme));

    InitChats(3,({"Xdhum te escupe a los pies.\n",
        "Xdhum dice: Pues ayer logré venderle un caballo cojo a una vieja.\n",
        "Xdhum se rie: Jajajaja...\n",
        "Se ha caído una moneda al suelo, pero Xdhum se agacha y la recoge.\n"}));
    InitAChats(6,({"Xdhum tropieza y se vuelve a levantar.\n",
        "Xdhum te dice: Lárgate mamarracho de mierda!!!\n"}));
}