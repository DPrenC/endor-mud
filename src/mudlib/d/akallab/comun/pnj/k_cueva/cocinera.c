/*
DESCRIPCION  : una vieja cocinera troll
FICHERO      : /d/akallab/comun/pnj/k_cueva/cocinera.c
MODIFICACION : 19-11-99 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <living.h>
#include <combat.h>
inherit NPC;

#define NOM ({"Kalla","Knea","Aka","Nak","Krage","Teka"})

create() {
  string *nombres;
  string nom;

  ::create();
 nombres=NOM;
  nom=nombres[random(sizeof(NOM))];
  SetStandard(nom,"troll",5,GENDER_FEMALE);
  SetShort(nom+", una vieja cocinera troll");
  SetLong(
  nom+" es una vieja troll. Los anyos, las luchas y los hijos han dejado su "
    "huella en ella. Gana su lugar entre los troll de la tribu dedicandose a "
	"cocinar la comida que los mas jovenes y vigorosos cazan para la tribu.\n");

  SetWeight(70000);
  SetGoChance(0);

  SetAlign(-500);
  SetIds(({"troll",nom,lower_case(nom),"cocinera"}));

  InitChats(10,({
  nom+" ensarta un trozo de carne en una vara y lo coloca sobre las brasas.\n",
  "Ves como "+nom+" despelleja algun pequenyo animal.\n",
  nom+" asa un trozo de carne el fuego.\n",
  "Las brasas del fuego crepitan lentamente.\n",
  nom+", la cocinera, corta y sazona un poco de carne.\n",
  nom+" envuelve un trozo de carne en unas grandes hojas y lo coloca cerca de las brasas.\n",
  nom+" anyade un poco de lenya al fuego.\n"
  }) );
}
