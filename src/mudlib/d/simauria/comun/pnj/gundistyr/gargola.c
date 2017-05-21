/* gargola.c
Autor: [a] Articman
Descripción: La gargola que debe morir pa conseguir dedo de quest.

Modificado: 04-Feb2002 [a] Creación
	    10-03-2003 [z] Cambio hands por pHands porque lo han cambiado en el combat.c y si no peta.
*/


#include <combat.h>
#include <properties.h>
#include "path.h"
#include <colours.h>
#include <moving.h>
#include <gremios.h>

inherit NPC;
object ob;

create() {
  ::create();
 SetStandard("una gárgola","gárgola",([GC_LUCHADOR:25]),GENERO_FEMENINO);
  SetName("la gárgola");
  SetShort("algo");
  SetShort("la gárgola");
  SetLong(W("Es una enorme gárgola, de tamaño bastante mayor que un humano. "
  "Tiene unas largas y afiladas garras capaces de cortar cualquier cosa y una "
  "fiera expresión de odio en su rostro. Después de haber sido devuelta a "
  "la vida tiene enormes ansias de sangre y de muerte. Su cuerpo es de color "
  "azul muy oscuro y es bien fornido y duro. Tan sólo tiene un ala, la "
  "derecha. Donde debería estar la otra observas una larga cicatriz.\n"));
  SetIds(({"gargola","gárgola"}));
  SetAds(({"una"}));
  SetSize(3);
  SetWhimpy(0);
  SetMaxHP(600);
  SetHP(600);
  SetAlign(-15000);
  SetHands(({({"garra derecha",TD_CORTE,12}),({"garra izquierda",TD_CORTE,12})/*,({"ala",1,7})*/}));
  SetAC(8);
  SetAggressive(1);
  InitAChats(5,({
    "La gárgola te mira con ojos de odio.\n",
    "La gárgola pega un gran grito.\n",
    }) );
  }

public varargs void Die(mixed silent){
    RemoveId(({"gárgola"}));
    RemoveId(({"gargola"}));
    tell_object(TP,W("La gárgola cae muerta al suelo y uno de sus dedos se rompe.\n"
    	"Te apresuras a recogerlo.\n"));
    tell_room(environment(TP),W("La gárgola cae muerta al suelo y uno de sus dedos se rompe.\n"
    	+TP->QueryName()+" se apresura a recogerlo.\n"));
    ob=clone_object(GOBJETO("otro/gundistyr/dedogar"));
    if (ob->move(TP,M_NOCHECK) !=ME_OK ) {
        tell_object(TP,"Sin embargo no eres capaz de cargarlo y lo dejas en el suelo.\n");
        tell_room(environment(TP),"Sin embargo no es capaz de cargarlo y lo deja en el suelo.\n.\n");
        ob->move(environment(TP),M_NOCHECK);
    }
    ::Die(1); //el 1 para que sea una muerte silenciosa
}


mixed SetCombatDelay(int time, string s) {
  say("La gárgola sonríe al ver tu patético intento por impresionarla.\n");
  return 0;
}