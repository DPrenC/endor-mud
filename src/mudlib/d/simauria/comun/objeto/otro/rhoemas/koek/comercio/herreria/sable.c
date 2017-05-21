/***************************************************************************************
 ARCHIVO:	sable.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Sable del herrero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
#define MIN_LEVEL 30


inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_ESPADA,13,P_SIZE_MEDIUM,M_ACERO);
  SetNumberHands(2);
//  Set(P_WP_PER_QP,25);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"sable"}));
  SetShort("un sable");
  SetLong(W("Es algo parecido a una espada, pero algo curva y menos pesada, "
  	"lo que le proporciona mejor control en el golpe a su portador. "
  	"La hoja está tan bien pulida que brilla al más mínimo atisbo de luz. "
  	"Como es normal en las piezas que hace Kolen, lleva grabado su distintivo.\n"));
  AddSubDetail(({"hoja"}),W("Tiene una magnífica hoja pulida. El forjador debe ser un "
  	"verdadero genio.\n"));
  AddSubDetail(({"distintivo","marca"}),"Es la marca de su creador: Kolen el herrero.\n");
}


public varargs mixed ChkEquip(object liv, object weapon, int flags)
{
 	if (weapon!=TO) return EQ_OK;
   if (!liv || !query_once_interactive(liv) || liv->QueryGuildLevel() >= MIN_LEVEL)
    // se da el control a la función del propio weapon
    {
        return ::ChkEquip(liv, weapon, flags);
    }
    // no se puede empuñar
    return "Este sable es demasiado peligroso para que puedas empuñarlo. Deberás "
           "ser al menos de nivel " + to_string(MIN_LEVEL) + " para poder usarlo.\n";
}