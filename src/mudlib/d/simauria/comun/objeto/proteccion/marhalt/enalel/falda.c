/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Blusa Base
 MODIFICACION:	[z] Zomax: Unifico cada archivo de colores en 1 sola falda.
 *****************************************************************************/

#include "path.h"

#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit "std/armour";

create(){
  ::create();
  
  SetStandard(AT_TROUSERS,0, P_SIZE_LARGE, M_TELA);
  SetIds(({"falda"}));
  SetAds(({"de tela","una"}));
  SetShort("una falda de tela");
  SetLong("Es una falda de tela confeccionada para el uso diario.\n");
  SetResetQuality(100);
  Set(P_MATERIAL,M_TELA);
  SetSize(P_SIZE_MEDIUM);
  Set(P_NUMBER, NUMBER_SINGULAR);
  Set(P_GENDER, GENDER_FEMALE);
  SetWeight(450);
  SetValue(600);
  SetColor(random(4));
}

public int SetColor(int valor){
  switch (valor){
  	case 0:
  		SetAds(({"de tela","una","amarilla"}));
		SetShort("una falda amarilla");
		SetLong(W("Es una ligera falda de tela amarilla que parece muy "
		"cómoda. Tiene bordado unos motivos naturistas.\n"));
		SetWeight(250);
		SetValue(1200);
  		break;

  	case 1:
  		SetAds(({"de tela","una","roja"}));
		SetShort("una falda roja");
		SetLong(W("Es una resistente falda roja muy abrigada. Tiene bordado "
		"unos motivos naturistas.\n"));
		SetValue(800);
		break;
		
  	case 2:
  		SetAds(({"de tela","una","verde"}));
		SetShort("una falda verde");
		SetLong(W("Es una elegante falda verde cuya tela imita los colores "
		"del bosque.\n"));
		SetValue(1000);
  	
  	default:break;
  }
  return 1;
}
