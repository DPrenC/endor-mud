/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Blusa Base
 MODIFICACION:	[z] Zomax: Unifico cada archivo de colores en 1 sola blusa.
 *****************************************************************************/

#include "path.h"

#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit "std/armour";

create(){
  ::create();

  SetStandard(AT_TUNICA,0, P_SIZE_LARGE, M_TELA);
  SetIds(({"blusa"}));
  SetAds(({"de tela","una"}));
  SetShort("una blusa");
  SetLong("Es una bonita blusa de tela.\n");
  SetResetQuality(100);
  Set(P_MATERIAL,M_TELA);
  SetSize(P_SIZE_MEDIUM);
  Set(P_NUMBER, NUMBER_SINGULAR);
  Set(P_GENDER, GENDER_FEMALE);
  SetWeight(200);
  SetValue(400);
  SetColor(random(4));
}

public int SetColor(int valor){
  switch (valor){
  	case 0:
  		SetAds(({"de tela","una","amarilla","amarillenta"}));
  		SetShort("una blusa amarillenta");
  		SetLong(W("Es una ligera blusa de tela amarillenta que parece "
  		"muy cómoda. Tiene bordados, de tonos rojizos y verdosos, imitando "
  		"motivos naturistas.\n"));
  		SetWeight(100);
  		SetValue(800);
  		break;

  	case 1:
  		SetAds(({"de tela","una","roja","rojiza"}));
		SetShort("una blusa rojiza");
		SetLong(W("Es una resistente blusa roja muy abrigada. Tiene "
		"bordados de tonos oscuros imitando motivos naturistas.\n"));
		SetValue(600);
		break;
		
  	case 2:
  		SetAds(({"de tela","una","verde","verdosa"}));
		SetShort("una blusa verdosa");
		SetLong(W("Es una elegante y bonita blusa verde cuya tela imita "
		"los colores del bosque.\n"));
		SetValue(500);
  	
  	default:break;
  }
  return 1;
}
