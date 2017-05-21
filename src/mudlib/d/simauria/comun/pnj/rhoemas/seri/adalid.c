/***************************************************************************************
 ARCHIVO:	adalid.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	Kaleband, el adalid del templo
 MODIFICACION:	10-04-2003 Cambio nivel 60 a 50 para que no haga cosillas raras.
		20-04-2003 Cambio radical para adaptarlo al nuevo combat. Ahora como
		lanza hechizos es un spellmonster y los lanza de verdad.
		05-05-2003 Quito Defences para que no mate a to er mundo.
		11-05-2003 Bajo a nivel 30 a petición popular debido a los cambios
		12-06-2003 Bajo HP al Standard
 		12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <gremios.h>

inherit RHOEPNJ("seri/superior_base");

create(){
  ::create();
 seteuid(getuid());

  SetStandard("Kaleband","humano",([GC_EXPERTO: 35]),GENERO_MASCULINO);
  SetStr(QueryStr()-5);
  SetDex(QueryDex()-5);
  SetInt(QueryInt()+10);
  SetAlign(0);
  SetWhimpy(0);
  SetShort("Kaleband el adalid");
  SetGoChance(0);
  SetAggressive(random(2));
  SetAds(({"un","el"}));
  SetIds(({"adalid","humano","kaleband","Kaleband"}));
  SetLong(W("Miras al adalid del templo. Es un humano muy viejo pero seguro "
    "que muy sabio si es el superior del templo. Sus músculos son muy "
    "extraños, parece que en su dia fue un gran guerrero, pero en algún "
    "momento, sabiendo que las aptitudes físicas se pierden con la edad, "
    "se dedicó a entrenar su lado espiritual. Parece que esa doctrina "
    "se ha aplicado en el templo desde su creación.\n"));

  GiveSuperiorSpells();

  AddItem(RHOEVAR("seri/llave_cylin"),REFRESH_REMOVE);
  AddItem(RHOEWEA("seri/adalid/baculo"),REFRESH_REMOVE,	SF(wieldme));
  AddItem(RHOEARM("seri/adalid/sandalias"),REFRESH_REMOVE,	SF(wearme));
  AddItem(RHOEARM("seri/adalid/tunica"),REFRESH_REMOVE,	SF(wearme));
}
