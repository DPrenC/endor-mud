/***************************************************************************************
 ARCHIVO:	mapa.c
 AUTOR:		[k] Korsario
 FECHA:		08-02-1998
 COMENTARIOS:	Mapa de Flenton
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetShort("un mapa");
  SetLong("Es un mapa dibujado en papel, lo puedes leer.\n");
  SetIds(({"mapa","mapa de flenton"}));
  SetValue(5);
  SetWeight(10);
  Set(P_AUTOOBJECT,1);
  Set(P_SEE_INVIS,1);
}

init(){
  ::init();
  add_action("fleer","leer");
}

int fleer(string str)
{
	if (str=="mapa"|str=="mapa de flenton")
	{
		write(
		"\n"
		"+--------------------------- Mapa de Flenton ----------------------------+\n"
		"|                CH                                                      |\n"
		"|                |                                                N      |\n"
		"|                S3                                             O-+-E    |\n"
		"|               /                                                 S      |\n"
		"|              S2                      T  A     C2   C1                  |\n"
		"|               \\                      | /      |    |                   |\n"
		"|               S1        CU      J - PP - J3 - J2 - J1 - E              |\n"
		"|               |         |          / |        |    |                   |\n"
		"|           C8  K5 - K4 - K3 - K2- K1  B        C4   C3                  |\n"
		"|           | /      |    |        |                                     |\n"
		"|       K - P2 -C7   C6   C5       S                                     |\n"
		"|           |                                                            |\n"
		"|           C9                                                       [K] |\n"
		"+------------------------------------------------------------------------+\n"
		"  - E........ entrada               - C#............. casas (#=1..9)\n"
		"  - J1,J2,J3. calle del jefe        - B ............. bareto\n"
		"  - PP ...... plaza principal       - K1,K2,K3,K4,K5. calle Kendarg\n"
		"  - T ....... tienda-almacén        - S ............. Smithy, herreria\n"
		"  - A ....... gran árbol            - CU ............ tienda de cuero\n"
		"  - J ....... casa del Jefe         - S1,S2,S3 ...... sendero\n"
		"  - P2 ...... plaza pequeña         - CH ............ casa del shaman\n"
		"  - K ....... casa de Kendarg\n");
  		return 1;
  	}
	return 0;
}
