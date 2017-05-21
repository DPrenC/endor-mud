/*
DESCRIPCION  : un guardia entranandose en la lucha
FICHERO      : /d/akallab/comun/pnj/z_castillo/luchador.c
MODIFICACION : 02-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <gremios.h>


inherit PNJ("z_castillo/guardia");

create() {
  ::create();
  SetLong(
     "Es un"+AO2+" de los guardias orcos que hay en el castillo, un"+AO2+" orc"+AO2+" fuerte y robust"+AO2+" "
     "cuya mision es la de proteger este lugar. En este momento se esta entrenando en "
     "la lucha cuerpo a cuerpo. Es bastante bueno.\n");

  SetStr(QueryStr()+2);
  SetGuild(GC_LUCHADOR);

  InitChats(20,({
  //         --------------------------------------------------------------------------------
    MAY(UNA_2)+" guardia ataca a su oponente con un fuerte golpe de hacha.\n",
    "Los guardias ruedan por el suelo forcejeando entre ellos.\n",
    MAY(UNA_2)+" guardia se defiende con el escudo de un golpe.\n",
    MAY(UNA_2)+" guardia se detiene un momento, grita y se lanza contra su adversario.\n",
    MAY(UNA_2)+" guardia se pasa la mano por la comisura de la boca limpiandose un hilillo de "
          "sangre que le chorrea fruto de un golpe anterior en la lucha.\n",
    MAY(UNA_2)+" guardia grita a su oponente:'Es eso lo unico que sabes hacer?'.\n",
    MAY(UNA_2)+" guardia le dice al adversario:'Levantate ya del suelo y lucha si es que "
          "tienes sangre en las venas!'. Su oponente se levanta y sigue el combate.\n",
    MAY(ART2)+" guardia jadea exhaust"+AO2+".\n"}));
}
