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
    SetStandard("un sargento","humano",([GC_LUCHADOR: 26+d4()]),GENERO_MASCULINO);
  SetShort("un sargento de Enalel");
    SetLong("Es un hombre muy fornido con porte militar. En su pecho se ve "
    "una insignia que le identifica como un sargento de la guardia de Enalel.\n");
    SetIds(({"humano","sargento","sargento de enalel","guardia"}));
    SetIVision(0);
    SetGoChance(70);
    AddWalkZones(ENALHAB);
    SetStr(QueryStr()+3);
    SetDex(QueryDex()+3);
    AddItem(ARMAS("espada_larga"),REFRESH_REMOVE, SF(wieldme));
    AddItem("/std/armour", REFRESH_REMOVE,([
  	P_SHORT: "una armadura de hierro",
    	P_LONG: W("Es una armadura de hierro. En su centro está el emblema "
    	"de Enalel, una manzana rodeada de rayos del sol.\n"),
    	P_GENDER: GENERO_FEMENINO,
    	P_AC: 7,
    	P_ARMOUR_TYPE: AT_CORAZA,
    	P_MATERIAL: M_HIERRO,
    	P_SIZE: P_SIZE_MEDIUM,
    	P_VALUE: 450
   ]),SF(wearme));

    InitChats(3,({
	"El sargento limpia su insignia.\n",
	"El sargento mira a su alrededor.\n",
	"El sargento limpia su espada.\n"}));
}
