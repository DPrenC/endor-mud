/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Camisa Base
 MODIFICACION:	[z] Zomax: Unifico cada archivo de colores en 1 sola camisa.
 *****************************************************************************/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit "std/armour";

create(){
  ::create();
  
  SetStandard(AT_TUNICA,0, P_SIZE_LARGE, M_TELA);
  SetIds(({"camisa"}));
  SetAds(({"de tela","una"}));
  SetShort("una camisa de tela");
  SetLong("Es una camisa de tela confeccionada para el uso diario.\n");
  SetResetQuality(100);
  Set(P_MATERIAL,M_TELA);
  SetSize(P_SIZE_MEDIUM);
  Set(P_NUMBER, NUMBER_SINGULAR);
  Set(P_GENDER, GENDER_FEMALE);
  SetWeight(250);
  SetValue(300);
  SetColor(random(4));
}

public int SetColor(int valor){
  switch (valor){
  	case 0:
  		SetAds(({"de tela","una","amarilla"}));
		SetShort("una camisa amarilla");
		SetLong(W("Es una ligera camisa de tela amarilla que parece muy "
		"cómoda. Tiene bordados unos motivos naturistas.\n"));
		SetWeight(150);
		SetValue(700);
  		break;

  	case 1:
  		SetAds(({"de tela","una","roja"}));
		SetShort("una camisa roja");
		SetLong(W("Es una resistente camisa roja muy abrigada. Tiene bordados "
		"unos motivos naturistas.\n"));
		SetValue(500);
		break;
		
  	case 2:
  		SetAds(({"de tela","una","verde"}));
		SetShort("una camisa verde");
		SetLong(W("Es una elegante camisa verde cuya tela imita los colores "
		"del bosque.\n"));
		SetValue(300);
  	
  	default:break;
  }
  return 1;
}
