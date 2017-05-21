/*
Fichero: ratones.c
Autor: Aule.
Fecha: 13/06/2014
Descripción: Archivo base de ratoncillos de nivel mínimo
*/
#include <gremios.h>
#include <properties.h>
#include <combat.h>
//#include <sounds.h>

inherit NPC_NOBEL;

string * raton_colores = ({ "gris", "blanco", "pardo", "negro", "marrón" });
string raton_color = "";
create ()
{
	::create();

	seteuid(getuid());
	raton_color = raton_colores[random(sizeof(raton_colores))];
	SetStandard("un ratoncillo " +raton_color, "raton",([GC_CM_MM:1]), GENERO_MASCULINO);
	  SetMaxHP(QueryMaxHP()/4);
  SetHP(QueryMaxHP());

	SetShort("un ratoncillo "+raton_color);
	SetLong("Es un pequeño ratón  "+raton_color+". de inquieta y diminuta cola.\n"
	"Tiene ojillos negros y vivos como cuentas de azabache. Su movimiento es tan veloz "
	"que apenas puede seguírselo con la vista cuando se camufla en la sombra proyectada "
	"por los objetos mientras busca alimento.\n");
	AddId(({"ratón", "ratoncillo"}));
	SetAds(({raton_color}));


	InitChats(4, ({"Un ratoncillo "+raton_color+" pasa correteando como una diminuta sombra junto a uno de tus pies.\n",
			"Un ratoncillo "+raton_color+" te mira furtivamente con sus astutos ojillos.\n",
			"Un ratoncillo "+raton_color+" roe algo que encuentra por el suelo mientras mueve "
		"sus diminutos bigotes.\n"}));
	InitAChats(6, ({"El ratoncillo "+raton_color+" corretea haciendo veloces quiebros, "
	"tratando de escapar.\n",
			"El ratoncillo "+raton_color+" corretea  aterrorizado.\n",
			"El ratoncillo "+raton_color+" brinca mientras chilla, tratando de huir.\n",
			"El ratoncillo "+raton_color+" lanza una diminuta dentellada.\n"
			}));
	SetSmell("Un ratoncillo "+raton_color+" se escabulle  ágilmente de tus dedos cuando "
	"intentas capturarlo para olerlo.\n");
	SetNoise("El ratoncillo "+raton_color+" no hace ningún ruido a escepción de algún chillidito casi inaudible de vez en cuando.\n");
	SetShrugMsg("Un ratoncillo "+raton_color+" pega un brinco, alarmado ante el sonido de "
	"tu voz.\n");

	SetWhimpy(2);
	SetMsgIn("llega correteando furtivamente");
	SetMsgOut("se escabulle ");

	SetGoChance(30);
}
