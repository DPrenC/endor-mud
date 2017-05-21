/*
DESCRIPCION  : Ivan, el cartero
FICHERO      : /d/limbo/comun/pnj/cartero.c
MODIFICACION : 03-10-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <messages.h>
inherit NPC;

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

create() {
  ::create();
  SetStandard("Ivan","gnomo",10,GENDER_MALE);
  SetShort("Ivan, el cartero");
  SetLong(
    "Ivan es un gnomo. Este ser de pequeña estatura lleva la vestimenta habitual de\n"
    "los siervos de los dioses. Se encarga de llevar la sucursal local de la\n"
    "Hermandad de los Mensajeros aquí en la isla Limbo. Es un tipo simpático y muy\n"
    "activo que pasa el día organizando cartas y cuidando a su querido ganso salvaje\n"
    "que emplea como medio para repartir el correo.\n");

  SetGoChance(0);

  SetAlign(0);
  SetAC(10);
  SetMaxHP(100);
  SetHP(100);

  SetLevel(10);

  Set(P_NOGET,"Ivan es demasiado escurridizo como para que lo atrapes.\n");
  SetIds(({"ivan","Ivan","cartero","gnomo"}));

  InitChats(10,({
     "Ivan organiza un monton de cartas y las coloca en uno de los archivadores.\n",
     "Llega un gnomo montado en un ganso. Aterriza y le da la bolsa con cartas que\n"
     "traia a Ivan. Tras dejar descansar un momento al ganso y charlar con Ivan, el\n"
     "gnomo coge otra bolsa con cartas y se vuelve a ir volando con el ganso.\n",
     "Ivan te dice: 'En los folletos encontrarás como utilizar el servicio de correos'.\n",
     "Ivan te mira curioso y te pregunta: '¿Querias alguna cosa?'.\n" }) );
  AddQuestion(({"angor","Angor"}),"Angor, Angor... Es un dios. No suele usar esta oficina de correos.\n");
  Set(P_CANT_FIGHT,1);
  Set(P_CANT_STEAL,1);

}

init() {
  ::init();
  add_action("matar_cmd","matar");
}


int matar_cmd(string str){
  object who;
  if (!id(str)) return 0;
  who=TP;
  if (present(str, environment(who)) != TO) return 0;
  who->StopHunting(TO);
  write(
     "Atacas a Ivan, pero el es tan escurridizo que te esquiva fácilmente. Repites la\n"
     "maniobra y vuelves a fallar. Ivan te dice:'Espero que pagues el destrozo que\n"
     "acabas de hacer en el mostrador. Este no es un lugar para buscar jaleo'.\n");
  tell_room(environment(TP), ({ MSG_SEE,
     NOMBRE+" ataca a Ivan un par de veces, pero falla debido a que el gnomo es muy\n"
     "escurridizo. "+NOMBRE+" solo ha conseguido destrozar parte del mostrador.\n"}), ({ TP }));
  return 1;
}