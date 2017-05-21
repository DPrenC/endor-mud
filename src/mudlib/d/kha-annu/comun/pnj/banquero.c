/****************************************************************************
Fichero: /d/kha-annu/comun/pnj/banquero.c
Autor: Lug y Yalin
Fecha: 06/05/2007
Descripci�n: banquero de la oficina de Kha-annu
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
#include <messages.h>
inherit KBASE;

#define AE      (TP->QueryGender()==GENDER_FEMALE?"a":"e")
#define AO      (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define A_      (TP->QueryGender()==GENDER_FEMALE?"a":"")
#define NOMBRE  (capitalize(TP->QueryName()))

create()
{
    ::create();
    SetStandard("Surian","enano",10,GENDER_MALE);
    SetShort("Surian, el banquero");
    SetLong("Surian es un enano encargado de llevar la "
    "sucursal de la Hermandad de los Banqueros en Kha-annu. Es un tipo "
    "seco y no muy hablador que pasa el d�a entregado a su trabajo. Su mirada es "
    "tan fr�a como la precisi�n matem�tica con la que realiza las operaciones "
    "bancarias. Sabes que con �l tu dinero estar� a salvo.\n");
    SetAlign(500);
    Set(P_NOGET,"Surian te da un manotazo y dice: 'No me molestes'.\n");
    SetIds(({"surian","Surian","banquero","empleado","enano"}));

    InitChats(10,({
    "Surian mira el libro de cuentas y anota alguna cosa en �l.\n",
    "Surian comenta para si: 'Vaya, este parece que se est� haciendo rico'.\n",
    "Surian te dice: 'En los folletos de la caja encontrar�s las condiciones del "
    "banco. Yo de ti coger�a uno y lo leer�a'.\n",
    "Surian murmura: 'Otro pr�stamo vencido, habr� que tomar medidas'.\n",
    "Surian te pregunta: �Quer�as alguna cosa?'\n" }) );
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
     "Surian alza la mano frente a ti y de repente una fuerza invisible te inmoviliza. "
     "Surian esboza una sonrisa mal�vola y comienza a cerrar su mano lentamente en el "
     "aire. Al mismo tiempo la fuerza invisible que te retiene aumenta su fuerza y te "
     "oprime m�s y m�s, de forma que apenas puedes respirar. Surian te dice:'Si lo "
     "que buscas es jaleo, vete a otro lugar'. Surian abre de nuevo su mano y la "
     "fuerza invisible que te apresaba desaparece Estas herid"+AO+".\n");
  tell_room(environment(TP), ({ MSG_SEE,
     NOMBRE+" ataca a Surian, pero es detenid"+AO+" por alguna fuerza invisible. Surian "
     "esboza una sonrisa mal�vola al tiempo que "+NOMBRE+" se retuerce de dolor. Poco "
     "despu�s, Surian libera a "+NOMBRE+", que parece herid"+AO+".\n"}), ({ TP }));

  hp=TP->QueryHP();
  if (hp>15) TP->SetHP(hp-10);
  return 1;
}
