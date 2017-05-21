/*
DESCRIPCION  : Asiur, el farero
FICHERO      : /d/limbo/comun/pnj/farero.c
MODIFICACION : 16-09-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <messages.h>
inherit NPC;

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

create() {
  ::create();
  SetStandard("Asiur","gigante",10,GENDER_MALE);
  SetShort("Asiur, el farero");
  SetLong(
 "Asiur es un gigante adulto. Trabaja como farero del faro que hay en el poblado "
 "de pescadores de la isla Limbo. Durante la noche se encarga de a�adir madera al "
 "fuego del faro para que su luz se mantenga y as� las barcas puedan volver a "
 "puerto. Lleva la tipica vestimenta que lo identifica como uno de los siervos de "
 "los dioses que viven en esta isla. Asiur es un aficionado a la talla de madera, "
 "lo cual es su entretenimiento en las largas y solitarias noches aqu� en el faro.\n");

  SetGoChance(0);

  SetAlign(-100);
  SetAC(10);
  SetMaxHP(100);
  SetHP(100);

  SetIds(({"asiur","Asiur","farero","gigante"}));

  InitChats(10,({
//--------------------------------------------------------------------------------
  "Asiur saca una peque�a talla de un caballo de su t�nica y la mira satisfecho. "
  "Asiur se levanta, coge un tronco y lo arroja al fuego. A continuaci�n se sienta "
  "de nuevo y continua tallando la figura de madera en la que actualmente trabaja.\n",
  "El fuego del faro crepita. Su calor es agradable.\n",
  "Asiur usa su navaja con cuidado para perfilar algunos detalles de su talla.\n",
  "Asiur deja por un momento su talla y mira al horizonte.\n",
  "Asiur mira la talla que tiene entre las manos pensativo.\n"}) );
Set(P_CANT_FIGHT,1);
Set(P_CANT_STEAL,1);

}

init() {
  ::init();
  add_action("matar_cmd","matar");
}


int matar_cmd(string str){
  object who;
  int hp;

  who=TP;
  if (present(str, environment(who)) != TO) return 0;
  who->StopHunting(TO);

  write(
   "Asiur exclama: '�Pero bueno! �C�mo te atreves a atarcame mocos"+AO+"?' "
   "Asiur para tu golpe y con uno de sus poderosos brazos te coge del cuello y te "
   "eleva hasta que tus pies no tocan el suelo. No puedes respirar y sientes que te "
   "est�s ahogando, por lo que forcejeas con todas tus fuerzas pero es in�til. "
   "Asiur dice: 'Tienes suerte que sea un siervo de los dioses'. "
   "A continuaci�n te arroja con desden al suelo. Puedes respirar de nuevo, pero "
   "aun sientes la presi�n en tu cuello... Estas herid"+AO+".\n");

   tell_room(environment(TP), ({ MSG_SEE,
  NOMBRE+" ataca a Asiur, pero este detiene el ataque con facilidad. Asiur coge "
  "del cuello a "+NOMBRE+" elev�ndol"+AO+" del suelo. "+NOMBRE+" forcejea inutilmente hasta "
  "que finalmente Asiur decide soltarl"+AO+".\n"}), ({ TP }));

   hp=TP->QueryHP();
   if (hp>15) TP->SetHP(hp-10);
  return 1;
}
