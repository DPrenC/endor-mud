/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
    ::create();
    switch (random(2)){
	case 0:
	    SetStandard("un pueblerino","humano",9+random(3),GENERO_MASCULINO);
		SetShort("un pueblerino de Enalel");
		SetLong("Es un pueblerino de Enalel. Sus ropas son de tonos "
		"amarillentos y verdosos y su tez es aceitunada.\n");
		SetIds(({"humano","pueblerino","hombre"}));
		break;

	default:
	    SetStandard("una pueblerina","humano",8+random(3),GENERO_FEMENINO);
		SetShort("una pueblerina de Enalel");
		SetLong("Es una bella pueblerina de Enalel. Sus ropas son de "
		"tonos amarillentos y verdosos y su tez es aceitunada.\n");
		SetIds(({"humano","humana","pueblerina","mujer"}));
		break;
  }
    SetAlign(100);
    AddWalkZones(ENALHAB);
    /*
    AddWalkZones(ENALHAB"poblado/calles");
    AddWalkZones(ENALHAB"poblado/manzanal");
    AddWalkZones(ENALHAB"poblado/posada");
  AddWalkZones(ENALHAB"poblado/varios");
  */
  SetGoChance(40);
    AddItem(ENALPRT"pantalon",REFRESH_REMOVE,SF(wearme));
    AddItem(ENALPRT"camisa",REFRESH_REMOVE,SF(wearme));

}
