/*
DESCRIPCION  : gorrion para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/gorrion.c
MODIFICACION : 10-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
 ::create();
 SetStandard("un gorrión","gorrion",([ GC_TORPE: 1]),GENDER_MALE);
 SetShort("un gorrión");
 SetLong(
 "Es un pequeño gorrion. Este gracioso pajaro de plumaje grisaceo se pasa el\n"
 "tiempo dando saltitos de un lugar a otro. Es una criatura inquieta.\n");
 AddId("gorrion");
 AddAdjective("pequenyo");
 AddAdjective("pequeño");
 AddAdjective("gracioso");
 SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
 SetInt(1);
 SetHands(({({"pico",TD_PENETRACION,1})}));
 SetWeight(500);
 SetGoChance(50);
 SetNoGet("El gorrión levanta el vuelo por un momento y se vuelve a posar lejos de ti.\n");
 InitChats(3,({"El gorrión mira nervioso a todos lados.\n",
                "El gorrión picotea alguna cosa.\n",
                "El gorrión alza el vuelo y se vuelve a posar un poco más tarde.\n",
                "El gorrión te mira curioso.\n"}));
 SetDesmembrableEn(({CABEZA,ALA,ALA}));
}
