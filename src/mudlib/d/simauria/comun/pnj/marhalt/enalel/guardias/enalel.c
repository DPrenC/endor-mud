/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "./path.h"
#include <guild.h>
#include <combat.h>
#include <properties.h>

inherit ENALPNJ"guardia_base";

create(){
    ::create();
    SetStandard("un guardia","humano",([GC_LUCHADOR: 18+random(5)]),GENERO_MASCULINO);
    SetShort("un guardia de Enalel");
    SetLong("Es un hombre fornido y de aspecto sereno. Parece observar "
    "disimuladamente cada uno de tus movimientos.\n");
    SetIds(({"humano","guardia","guardia de enalel"}));
    SetAlign(300);
    SetStr(QueryStr()+2);
    SetDex(QueryDex()+2);
    SetIVision(0);
    AddWalkZones(ENALHAB);
    /*
  AddWalkZones(ENALHAB"poblado/calles");
  AddWalkZones(ENALHAB"poblado/manzanal");
  AddWalkZones(ENALHAB"poblado/posada");
  AddWalkZones(ENALHAB"poblado/varios");
  */
    SetGoChance(90);
    AddItem(ARMAS("espada_ancha"),REFRESH_REMOVE,SF(wieldme));
    AddItem("/std/armour", REFRESH_REMOVE,([
	P_SHORT: "una armadura",
	P_LONG: "Es una armadura de cuero. En su centro está el emblema de Enalel, "
	"una manzana rodeada de rayos del sol.\n",
	P_GENDER: GENERO_FEMENINO,
	P_AC: 4,
	P_ARMOUR_TYPE: AT_CORAZA,
	P_MATERIAL: M_CUERO,
	P_SIZE: P_SIZE_MEDIUM,
	P_VALUE: 200
  ]),SF(wearme));
}
