/* DESCRIPCION    : ent maligno
FICHERO        : /d/lad-laurelin/comun/pnj/entm.c
CREACION       : 10-2-99 AluraU.
MODIFICACION :
*/
#include "path.h"
#include <properties.h>


inherit NPC;
create() {
::create();
SetStandard("un ent","arbol",30,GENDER_MALE);
SetShort("Ent maligno");
SetLong(  "Es un arbol un tanto extranyo. En su tronco hay dos ojos que te miran.\n"
"Tiene una boca enorme torcida en un cruel gesto. Da miedo ...\n");
SetIds(({"arbol","ent"}));
SetAds(({"un","maligno","horrible","salvaje"}));
SetAlign(-2000);
SetSize(P_SIZE_LARGE);
SetHands(({({"rama derecha",0,10}),({"rama izquierda",0,10}),({"rama superior",0,12})}));
SetDex(20);
SetInt(30);
SetCon(30);
SetStr(40);
SetAggressive(1);  // agresivo 1=si, 0=no
//SetHP(50+20*8);  //puntos de vida.
//SetMaxHP(50+20*8);   AddItem("/d/lad-laurelin/comun/objeto/arma/esp_plata",REFRESH_REMOVE,SF(wieldme));

/*AddQuestion(({"", "", ""}),  "\n"+        //entre comillas que preguntas, luego respuesta.  "\n");
AddQuestion(({""}),  "\n"+  "\n"+        // funciona, preguntar algo a alguien  "\n"+  "\n");
AddQuestion(({""}),  "\n"+   "\n"+  "\n"); */    }