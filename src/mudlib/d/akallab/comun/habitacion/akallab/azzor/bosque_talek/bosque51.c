/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque51.c
MODIFICACION : 12-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <messages.h>
#include AK_MACRO
inherit BOSQUE_TALEK("bosque");

int HayMiel;
int HayAbejas;

int ReponerMiel();
int AbejasVuelven();

create()
{
    ::create();
    reset();
    SetIntLong(QueryIntLong()+"Colgando de uno de los árboles ves un panal "
        "de abejas.\n");
    AddDetail(({"panal"}),"Colgando de uno de los árboles que ves ante ti "
        "hay un panal de abejas. Seguro que en su interior hay una deliciosa "
        "miel, pero con las abejas que oyes zumbando en su interior "
        "acercarse no es muy aconsejable si no quieres que te piquen. Piensas "
        "que tal vez haya alguna manera de expulsarlas de ahí...\n");
    SetIntNoise("Oyes el zumbido de las abejas.\n");
    AddExit("oeste",BOSQUE_TALEK("bosque50"));
    AddExit("este",BOSQUE_TALEK("bosque52"));
    AddRoomCmd("expulsar", "expulsar");
    AddRoomCmd("coger", "coger");
}

reset()
{
    ::reset();
    HayMiel=1;
    HayAbejas=1;
}

int ReponerMiel()
{
    HayMiel=1;
    return 1;
}

int AbejasVuelven()
{
    tell_room(TO, ({ MSG_SEE, "Las abejas retornan al panal del árbol.\n" }));
    HayAbejas=1;
    return 1;
}


expulsar(str)
{
    object ob;
    if ((str!="abejas")&&(str!="enjambre"))
    {
        write("Expulsar que??\n");
        return 1;
    }
    if (!HayAbejas) return notify_fail("No ves abejas por aquí cerca. "
        "Alguien las habrá expulsado.\n", NOTIFY_NOT_VALID);
    ob=present("palo",TP);
    if (!ob) ob=present("antorcha",TP);
    if (!ob) return notify_fail("Necesitarías un palo encendido para "
        "expulsar a las abejas, de otra forma te picarán.\n",NOTIFY_NOT_VALID);
    if (ob->QueryBurning()==0) return notify_fail("Si no enciendes el "
        "palo no asustarás a las abejas.\n",NOTIFY_NOT_VALID);
    write("Expulsas a las abejas del panal con un palo ardiente.\n");
    tell_room(TO, ({MSG_SEE, "Las abejas huyen del panal asustadas del fuego.\n"}), ({ TP }));
    HayAbejas=0;
    call_out("AbejasVuelven",120);
    return 1;
}

coger(string str)
{
    object ob;
    if (str!="miel") return 0;
    if (!HayMiel)
    {
        write("Miras en el panal y te das cuenta que alguien se te a "
            "adelantado y se ha llevado la miel.\n");
        return 1;
    }
    ob=present("frasco_vacio",TP);
    if (!ob) return notify_fail("Necesitarías un frasco vacío para "
        "poder llevarte la miel.\n",NOTIFY_NOT_VALID);
    write("Coges la miel del panal y la metes en el frasco.\n");
    HayMiel=0;
    call_out("ReponerMiel",120);
    ob->remove();
    ob=clone_object(COMIDA("miel"));
    ob->AddId("cur_quest_06");
    ob->move(TP);
    return 1;
}








