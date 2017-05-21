/***************************************************************************************
 ARCHIVO:	pantalones.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Pantalones de los Patrulleros de Koek
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_PANTALONES,1,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"pantalones","pantalones negros"}));
  SetShort("unos pantalones negros");
  SetLong("Son unos pantalones negros con el escudo de Koek bordado en hilo de plata.\n");
  AddSubDetail(({"bordado","escudo","escudo bordado"}),W("Los pantalones tienen bordado "
  	"en hilo de plata el escudo de Koek.\n"));
}