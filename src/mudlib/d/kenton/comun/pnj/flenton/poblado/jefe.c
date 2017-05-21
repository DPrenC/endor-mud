/***************************************************************************************
 ARCHIVO:	jefe.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	El Jefe de Flenton
 05/01/2005: [kastwey]. Simplifico con el SetStandard, y quito lo de los stats, que
 petaba que da gusto.
 ***************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit NPC;

int s,n,l,lv,xp,*sexo;
string *nombre,*corta, *larga, *id, *nivel;

create(){
    ::create();
    fjefe();
    n=random(5);
    SetStandard(nombre[n],"kender",nivel[n],sexo[n]);
    SetIds(id);
    SetShort(corta[n]);
    SetLong(larga[n]);
    InitChats(3,({nombre[n]+" da una cabezadita por un instante, y luego se despierta.\n",
	      nombre[n]+" dice: ¿Deseabas algo?\n",
	      nombre[n]+" sonríe.\n",
	      nombre[n]+" grita: ¡A ver! ¡Silencio en la sala!\n",
	      nombre[n]+" murmura: Hmmm ¿A qué hora era el consejo...? no me acuerdo.\n",
	      nombre[n]+" dice: ¿Has visto hoy a Kendarg? necesito hablar con él.\n"}));
    InitAChats(10,({nombre[n]+" grita: ¡Maldito seas! ¡Pagarás por esto!\n",
	       nombre[n]+" grita: ¡Te voy a matar!\n"}));
}

void fjefe()
{
	nombre=({"Whaikor","Zinah","Orkun","Kaztor","Keniak"});
	id=({"kender","jefe"});
 	corta=({"un kender inquieto","una kender bonita",
 		"un kender bajito y regordete","un kender sonriente",
		"una kender aventurera"  });
	larga=({"Ves a Whaikor, el jefe de Flenton. Es un kender muy "
		"inquieto, ni sentado se esta quieto. Incluso sus ojos "
		"parecen no dejar de moverse y seguro que nada escapa a "
		"su estudio.\n Mejor aseguraría todas tus cosas, nada "
		"está a salvo del examen de Whaikor.",
		"Ves a Zinah, la jefa de Flenton. Es una kender muy "
		"bonita, tiene una belleza singular entre los kenders. "
		"Sus ojos claros y sinceros cautivan todo lo que miran. "
		"Su sonrisa nada tiene que envidiar a sus ojos.\n",
		"Ves a Orkun, el jefe de Flenton. Es un kender bajito "
		"y regordete. Parece muy simpático y amigable. En sus ojos "
		"ves sabiduría, algo muy poco común entre su raza. Mas sus "
		"sonrisa picarona es una contradicción.\n",
		"Ves a Kaztor, el jefe de Flenton. Tiene una sonrisa "
		"eterna. Te preguntas por que sonreirá tanto. Sus dientes "
		"son blancos, relucientes, y de un tamaño considerable. "
		"Mas su sonrisa es muy bonita.\n",
		"Ves a Keniak, la jefa de Flenton. Cuentan de ella que "
		"es una gran aventurera y que ha viajado mucho conociendo "
		"los lugares mas sorprendentes y bonitos. Sus ojos dan fe de "
		"ello, y ves seguridad y firmeza en ellos.\n"});
	nivel=({22,25,18,24,22});
	sexo=({GENDER_MALE,GENDER_FEMALE,GENDER_MALE,GENDER_MALE,GENDER_FEMALE});
}

