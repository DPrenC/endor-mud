/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Guante Base
 MODIFICACION:	[z] Zomax: Unifico cada archivo de colores en 1 solo guante.
 *****************************************************************************/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit "std/armour";

create(){
  ::create();

  SetStandard(AT_GLOVES,0,P_SIZE_LARGE,M_TELA);
  SetIds(({"guante","guantes"}));
  SetAds(({"de tela","unos","un"}));
  SetShort("unos guantes de tela");
  SetLong(W("Son unos guantes de tela confeccionados para el uso diario. Parecen "
  "abrigar mucho.\n"));
  SetResetQuality(100);
  Set(P_MATERIAL,M_TELA);
  SetSize(P_SIZE_MEDIUM);
  Set(P_NUMBER, NUMBER_PLURAL);
  SetWeight(50);
  SetValue(300);
  SetColor(random(4));
}

public int SetColor(int valor){
  switch (valor){
  	case 0:
  		SetAds(({"de tela","unos","un","amarillo","amarillos"}));
		SetShort("unos guantes amarillos");
		SetLong(W("Son unos bonitos guantes amarillos confeccionados con "
		"una tela muy ligera.\n"));
		SetWeight(30);
		SetValue(600);
  		break;

  	case 1:
  		SetAds(({"de tela","unos","un","rojo","rojos"}));
		SetShort("unos guantes rojos");
		SetLong(W("Son unos resistentes guantes rojos tejidos para el uso "
		"diario.\n"));
		SetValue(400);
		break;
		
  	case 2:
  		SetAds(({"de tela","unos","un","verde","verdes"}));
		SetShort("unos guantes verdes");
		SetLong(W("Son unos elegantes guantes verdes cuya tela parece imitar "
		"los colores del bosque.\n"));
		SetValue(500);

  	default:break;
  }
  return 1;
}
