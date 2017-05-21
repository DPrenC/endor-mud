/*
DESCRIPCION  : Cota de malla
FICHERO      : cota_malla.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               04-12-98 [Nemesis@Simauria] Anyadido el P_GENDER a 1 (femenino)
	                                   Quitado el SetWeaponHands()
			   02-03-00 [Angor@Simauria] remodelada
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_MAIL, 1, P_SIZE_MEDIUM, M_HIERRO);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 AddId("cota");
 AddId("cota de malla");
 AddAdjective("de malla");
 SetShort("una sencilla cota de malla");
 SetLong("Es una sencilla cota de malla, tosca, pero cumple su cometido.\n");
}


