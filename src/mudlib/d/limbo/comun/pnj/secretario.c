/*
DESCRIPCION  : Akkron, el secretario del ayuntamiento
FICHERO      : /d/limbo/comun/pnj/farero.c
MODIFICACION : 16-09-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <messages.h>
inherit NPC;

#define AE      (TP->QueryGender()==2?"a":"e")
#define AO      (TP->QueryGenderEndString())
#define A_      (TP->QueryGender()==2?"a":"")
#define NOMBRE  (capitalize(TP->QueryName()))

create() {
  ::create();
  SetStandard("Akkron","orco",10,GENDER_MALE);
  SetShort("Akkron, el secretario");
  SetLong(
 "Akkron es un orco que trabaja como siervo de los dioses aquí en la isla Limbo. "
 "Actualmente está empleado como secretario del ayuntamiento lo cual supones que "
 "debe ser algún castigo ya que Akkron es claramente un tipo al que el cuerpo le "
 "pide acción. Quizá se excedió en su antigua ocupación. Su gesto no es muy amable "
 "y pasa el tiempo maldeciendo entre dientes al tiempo que gestiona el papeleo.\n");

  AddQuestion(({"gremio","gremio de aventureros"}),
  "¿Pero es que no tienes ojos en la cara? Es en la sala de al lado.\n");

  AddQuestion(({"angor","Angor"}),
  "Angor es un dios que ha ayudado mucho a los de mi raza. Un día de estos tengo "
  "que hablar con él a ver si le convenzo para que me cambie de puesto de trabajo.\n");

  SetGoChance(0);

  SetAlign(-200);
  SetAC(10);
  SetMaxHP(100);
  SetHP(100);

  SetIds(({"akkron","Akkron","secretario","orco"}));


  InitChats(10,({
//--------------------------------------------------------------------------------
  "Akkron exclama: '¡Papeles, papeles y mas papeles!'\n",
  "Akkron murmura para si: 'Vaya, otro que no ha rellenado todo el impreso. Pues "
  "a la basura por torpe y ya vendrá a quejarse si quiere. Así aprenderán...\n",
  "Akkron saca punta a un lápiz y continua repasando papeles.\n",
  "Akkron para un momento, te observa y dice: '¿Y tu que demonios miras?'\n",
  "Akkron se va al archivador y guarda allí varias carpetas. "
}) );
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
   "Akkron esquiva tu golpe escondiéndose bajo el mostrador. Al momento sale armado "
   "con un inmenso garrote y dice: 'Vaya parece que tenemos aquí "+TP->QueryArtIndString()+
   " alborotador"+A_+"'. "
   "Sin mediar mas palabra te golpea con él en el pecho de tal forma que por unos "
   "momentos te quedas sin respiración. Akkron agita el garrote delante de tu cara "
   "y te dice:' Sigue así y te partiré la cara'. Herid"+AO+" desistes de tu ataque.\n");

   tell_room(environment(TP), ({ MSG_SEE,
   NOMBRE+" ataca a Akkron, pero este se refugia tras el mostrador para luego "
   "aparecer de nuevo con un garrote con el que golpea a "+NOMBRE+" en el pecho que por "
   "un momento se queda sin respiracion. Akkron advierte a "+NOMBRE+" que la proxima "
   "vez le pegara en serio y est"+AE+", herid"+AO+", desiste en su ataque.\n"}), ({ TP }));

   hp=TP->QueryHP();
   if (hp>15) TP->SetHP(hp-10);
  return 1;
}
