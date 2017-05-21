/*
DESCRIPCION  : Worthe, el banquero
FICHERO      : /d/limbo/comun/pnj/banquero.c
MODIFICACION : 02-10-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
Modificaci�n 02/05/2007, [Y] yalin, cambio la raza.
*/

#include "./path.h"
#include <messages.h>
#include <properties.h>

inherit NPC;

#define AE      (TP->QueryGender()==GENDER_FEMALE?"a":"e")
#define AO      (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define A_      (TP->QueryGender()==GENDER_FEMALE?"a":"")
#define NOMBRE  (capitalize(TP->QueryName()))

create() {
  ::create();
  SetStandard("Worthe","humano",10,GENDER_MALE);
  SetShort("Worthe, el banquero");
  SetLong(
    "Worthe es el humano siervo de los dioses que se encarga de llevar la "
    "sucursal local de la Hermandad de los Banqueros aqu� en la isla. Es un tipo "
    "seco y no muy hablador que pasa el d�a entregado a su trabajo. Su mirada es "
    "tan fr�a como la precisi�n matematica con la que realiza las operaciones "
    "bancarias. Sabes que con �l tu dinero estara a salvo.\n");

     SetAlign(500);
    SetAC(10);
    SetMaxHP(100);
     SetHP(100);

     Set(P_NOGET,"Worthe te da un manotazo y dice: 'No me molestes'.\n");
    SetIds(({"worthe","Worthe","banquero","humano"}));

  InitChats(10,({
     "Worthe mira el libro de cuentas y anota alguna cosa en �l.\n",
     "Worthe comenta para si: 'Vaya, este parece que se est� haciendo rico'.\n",
     "Worthe te dice: 'En los folletos de la caja encontrar�s las condiciones del "
     "banco. Yo de ti cogeria uno y lo leer�a'.\n",
     "Worthe murmura: 'Otro pr�stamo vencido, habr� que tomar medidas'.\n",
     "Worthe te pregunta: �Querias alguna cosa?'\n" }) );

    AddQuestion(({"angor","Angor"}),"Angor es un dios poderoso, aunque francamente no se mucho m�s.\n");
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
     "Worthe alza la mano frente a ti y de repente una fuerza invisible te inmoviliza. "
     "Worthe esboza una sonrisa mal�vola y comienza a cerrar su mano lentamente en el "
     "aire. Al mismo tiempo la fuerza invisible que te retiene aumenta su fuerza y te "
     "oprime m�s y m�s, de forma que apenas puedes respirar. Worthe te dice:'Si lo "
     "que buscas es jaleo, vete a otro lugar'. Worthe abre de nuevo su mano y la "
     "fuerza invisible que te apresaba desaparece Estas herid"+AO+".\n");
  tell_room(environment(TP), ({ MSG_SEE,
     NOMBRE+" ataca a Worthe, pero es detenid"+AO+" por alguna fuerza invisible. Worthe "
     "esboza una sonrisa mal�vola al tiempo que "+NOMBRE+" se retuerce de dolor. Poco "
     "despu�s, Worthe libera a "+NOMBRE+", que parece herid"+AO+".\n"}), ({ TP }));

  hp=TP->QueryHP();
  if (hp>15) TP->SetHP(hp-10);
  return 1;
}
