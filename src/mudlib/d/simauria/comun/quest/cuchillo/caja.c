/*
DESCRIPCION  : caja que contiene el cuchillo de Malmabeth
FICHERO      : /d/simauria/comun/quest/cuchillo/caja.c
MODIFICACION : 14-6-00 [Maler] Creacion.
--------------------------------------------------------------------------------
*/


#include "./path.h"
#include <properties.h>
#include <messages.h>
inherit THING;
#define CAJA_ROTA "caja_rota_suelo"
public int cmd_abrir(string str)
{
    string a,b;
    object ob,ob2;
    if (!str) return 0;
    sscanf(str,"%s con %s",a,b);
    if (a!="caja" || b!="palanca")
        return notify_fail("¿Abrir qué con cualo?\n", NOTIFY_NOT_VALID);

    ob  =  present(b,TP);
	if (!ob) return notify_fail("Tu no tienes "+b+".\n",NOTIFY_NOT_VALID)&&0;

	if (member(ob->QueryIds(), "quest_palanca_berat")!=-1)
	{
	    ob->remove();
	    write("Forcejeas con la caja intentándola abrir con la palanca, pero de "
	    "tanta fuerza que haces se te destroza la caja en multitud de trozos y se "
	    "te parte la palanca. Entre los restos de la caja rota descubres un viejo "
	    "cuchillo para curtir.\n");
	    tell_room(environment(TP), ({ MSG_SEE, capitalize(TP->QueryName())+" destroza "
	        "la caja intentándola abrir con una palanca que también se le ha partido."
	        " De entre los trozos de madera de la caja sale un viejo cuchillo para "
	        "curtir.\n"}), ({ TP }));
        if (environment(TP)->Query(CAJA_ROTA) !=1){
            environment(TP)->SetIntLong(environment(TP)->QueryIntLong()+
            " Hay distintos trozos de los restos de una caja de madera esparcidos por "
            "todo el suelo.\n");
            environment(TP)->AddDetail(({"caja", "trozos de madera", "distintos trozos",
            "restos"}), "Son los restos de lo que antes fué una caja de madera.\n");
            environment(TP)->Set(CAJA_ROTA,1);
        }
        ob2=clone_object(QUEST "/cuchillo/cuchillo");
	    ob2->move(environment(TP));
        return remove();
    }
}

create() {
    ::create();
    seteuid(getuid());
    AddId(({"caja", "quest_caja_berat"}));
    SetShort("una caja de madera");
    SetLong("Es una caja, está sellada mediante clavos, y parece bastante "
    "difícil de abrir sin las herramientas adecuadas.\n");
    SetWeight(50000);
    SetNoGet(1);
}

init()
{
    ::init();

    add_action("cmd_abrir","abrir");

}
