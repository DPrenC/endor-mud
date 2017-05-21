/*
DESCRIPCION    :
FICHERO        :
CREACION       :
U.MODIFICACION :
*/

#include <rooms.h> // solo para que pueda perseguir

#include "path.h"
#include <combat.h>
#include <colours.h>
#include <magia.h>
#include <spellmonster.h>
#include <properties.h>

inherit "/obj/monster/spellundead";


create() {
  ::create();
 SetStandard("un necrófago","no-muerto",27,GENDER_MALE);
  SetShort("un devorador de cadaveres");
  SetLong(
"Ves un ser de piel verdosa enmohecida, repleto de llagas supurantes y con una\n"
"hilera de dientes afilados deseosos de clavarse en tu carne. Se le llama ghoul.\n"
"- Este ser solo come cadaveres y tu estas vivo... habra que solucionarlo. -\n");
  SetIds(({"necrofago","ghoul","devorador"}));   //identificativos
  SetAds(({"el","un","asqueroso"}));   //adjetivos feo, alto...
  SetAlign(-500);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetHands(({({"garra izquierda",0,8}),({"garra derecha",0,5})}));  //manos o garras o ...
  SetDex(20);
  SetInt(3);
  SetCon(30);
  SetStr(27);
  SetAggressive(1);  // agresivo 1=si, 0=no 2=con otros mobs
  //SetHP(362);
  //SetXP(30000);
  InitChats(2,({
  "El necrofago roe un hueso.\n",
  "El necrofago termina de chupar los restos de un craneo.\n"}));

  InitAChats(2,({
  "El necrofago abre y cierra su boca ... - comidaaaa ..\n"}));

  AddSpell("toqueHelado",
           ([
             S_SP:20,
		 S_CHANCE:90,
             S_COMBAT_DELAY:0,
             S_DELAY:80,
             S_SIMULT:0,
             S_VICTIMS:-1,
             S_DAMTYPE:ST_COLD,
             S_MINDAM:12,
             S_MAXDAM:70,
             S_VICMSG:([
                      MSG_NORMAL:
                      (TC_BLUE" El ghoul te toca y sientes un doloroso frio recorriendo tu cuerpo.\n"TC_NORMAL)])
          ,])
  );

}
