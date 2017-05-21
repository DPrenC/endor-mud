/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Camisa Base
 MODIFICACION:	[z] Zomax: Unifico cada archivo de colores en 1 solo pantalón.
 *****************************************************************************/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit "std/armour";

create(){
  ::create();
  
  SetStandard(AT_TROUSERS,0,P_SIZE_LARGE, M_TELA);
  SetIds(({"pantalón","pantalon","pantalones"}));
  SetAds(({"de tela","unos","un"}));
  SetShort("unos pantalones de tela");
  SetLong("Son unos pantalones de tela confeccionados para el uso diario.\n");
  SetResetQuality(100);
  Set(P_MATERIAL,M_TELA);
  SetSize(P_SIZE_MEDIUM);
  Set(P_NUMBER, NUMBER_PLURAL);
  SetWeight(250);
  SetValue(300);
  SetColor(random(4));
}

public int SetColor(int valor){
  switch (valor){
  	case 0:
  		SetAds(({"de tela","unos","un","amarillo","amarillos"}));
		SetShort("unos pantalones amarillos");
		SetLong(W("Son unos bonitos pantalones amarillos confeccionados "
		"con una tela muy ligera.\n"));
		SetWeight(150);
		SetValue(600);
  		break;

  	case 1:
  		SetAds(({"de tela","unos","un","rojo","rojos"}));
		SetShort("unos pantalones rojos");
		SetLong(W("Son unos resistentes pantalones rojos tejidos para el "
		"uso diario.\n"));
		SetValue(400);
		break;
		
  	case 2:
  		SetAds(({"de tela","unos","un","verde","verdes"}));
		SetShort("unos pantalones verdes");
		SetLong(W("Son unos elegantes pantalones verdes cuya tela parece "
		"imitar los colores del bosque.\n"));
		SetValue(500);

  	default:break;
  }
  return 1;
}
