/***************************************************************************************
 ARCHIVO:	pantalones_gruesos.c
 AUTOR:		aule
 FECHA:		30/01/2015
 COMENTARIOS:	Pantalones del herrero de bree
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_PANTALONES,2,P_SIZE_LARGE,M_CUERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"pantalones","pantalón", "pantalon"}));
  AddAdjective(({"gruesos"}));
  SetShort("unos gruesos pantalones de cuero");
  SetLong(
  "Son unos pantalones de dos capas de cuero fuerte pero flexible, aptos para proteger a "
  "su portador del calor o las espinas.\n");
  SetWeight(300);
  }