/************************************************************************/
/*							                */
/*	Ogro estandar para las Cavernas del Caos	                */
/*							                */
/*	[k] Kintups (jobarmar@eui.upv.es)		                */
/*	[h] Nyh (nyh@simauria.org)			                */
/*							                */
/*	03-05-99: Creacion [k]				                */
/*	04-05-99: Añadidas las armas [k]		                */
/*	14-03-04: [h] Subo el nivel, antes era 15+random(5)             */
/*		  [h] Tb retoco un par de cosillas sin importancia      */
/*		  [h] Quito lo de que sigan a la gente                  */
/*							                */
/************************************************************************/
/***
18/01/2005 [kastwey]: uso el FriendFunction, simplifico un poco de código y lo adecento para que no pete mucho :)
***/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

int soy_amigo(object ob);
create(){
    ::create();
   seteuid(getuid());
    SetIVision(-100);
    SetUVision(100);
    AddId(({"ogro","Ogro","ogro de las cavernas"}));
    SetAggressive(2);
    // un 1000*1000 de posibilidades de que ataque a los de su raza
    SetAttackOwnRace(1000);
    // un 1000 * 1000 de que ataque a cualquiera
    // con esto consigo que siempre, siempre, siempre se ejecute la función FriendFunction
    SetAttackChance(1000);
    SetFriendFunction(SF(soy_amigo));
    AddWalkZones(CAOSHAB);
}

int soy_amigo(object pj){
	if (!pj->QueryIsPlayer()) return 1;
	// no se atacan entre ellos
	if (pj->QueryAlign() >-400)
	// eres más bueno que ellos, asin que te zurran
    {
        // El ogro da un grito de combate y se lanza contra el PJ
        tell_room(environment(),
        capitalize(QueryName())+" grita: ¡"+capitalize(pj->QueryName()) + ", muere para"
        " Khorni!\n");
        return 0;
    }
    else return 1;
}

public varargs void Die(int silent){
    object ancestro;
    if(random(40)==1){
        tell_room(environment(), CAP(QueryName())+ " comienza a sufrir horribles "
        "convulsiones mientras aulla de dolor y un maligno fulgor rojo aparece en "
        "sus ojos.\n  Finalmente se iergue en toda su estatura y lanza un poderoso "
        "bramido y te ataca con pasmosa ferocidad.\n ¡El ancestro de los ogros "
        "ha conseguido reencarnarse en este cuerpo!\n");
        ancestro=clone_object(PNJ("marhalt/caos/ancestro"));
        ancestro->move(environment(TP));
        ancestro->Kill(TP || PO);
        destruct(TO);
    }else{

    tell_room(environment(),
    capitalize(QueryName())+" grita agonizando: ¡Aaaaargh! ¡Muero para mi Dios, el gran Khorni!\n");
    // Guardamos cuantos ogros has eliminado para un posterior uso
    if (QueryKiller())
    {
  	    if (QueryKiller()->QueryIsPet() && QueryKiller()->QueryOwner())
  	    // es un ayudante del player.. elemental, familiar, mascota, ETC... y con dueño
        {
	        QueryKiller()->QueryOwner()->SetAttribute("matanza_ogros",
	        QueryKiller()->QueryOwner()->QueryAttribute("matanza_ogros")+1);
        }
        else if (QueryKiller()->QueryIsPlayer())
        // es el player
        {
	        QueryKiller()->SetAttribute("matanza_ogros",
	        QueryKiller()->QueryAttribute("matanza_ogros")+1);
        }
    }
    return ::Die(silent);
    }
}

public varargs int DoDamage (int dmg, int type, int gentle, mixed xtras){
    if (!environment()) return ::DoDamage(dmg, type, gentle, &xtras);
    filter(all_inventory(environment()),
        (: (living($1) && call_other($1,"QueryRace")=="ogro" && $1!=$2)?
        $1->AddEnemy($2) : 0
        :) , TP || PO );
    return ::DoDamage(dmg, type, gentle, &xtras);
}
