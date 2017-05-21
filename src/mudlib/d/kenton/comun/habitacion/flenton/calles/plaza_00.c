/***************************************************************************************
 ARCHIVO:	plaza_00.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Plaza central de Flenton, donde paran las caravanas
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <sounds.h>
inherit CARAVAN_STOP;

object ninyo,rana;

create(){
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas voces y risas.\n");
  SetIntSmell("Te llega el aroma de comida. Alguien debe estar preparando algo.\n");

  SetIntShort("la plaza principal de Flenton");
  SetIntLong("Te encuentras en la plaza principal de Flenton. Es el "
  	"centro del poblado y por lo tanto el mas transitado. Está rodeado "
  	"de casas, al oeste la casa del jefe, al norte está la única tienda "
  	"de Flenton y al sur hay un bar. Al este se encuentra la calle del "
  	"Jefe, y al suroeste se extiende la calle Kendarg. En el centro de "
  	"la plaza hay una fuente, y al nordeste un gran árbol.\n");

  AddDetail(({"arbol","árbol"}),"Es un árbol grande y robusto, aunque parece "
  	"muy viejo.\n");
  AddDetail(({"estatua"}),"Es la estatua de un kender que empuña una espada. "
  	"Tiene una inscripción.\n");
  AddDetail(({"bar","taberna"}),"Es un casa algo mayor que las demas, y tiene "
  	"una gran puerta de dos hojas.\n");
  AddDetail(({"tienda"}),"Es una casa corriente con un cartel a la entrada.\n");
  AddDetail(({"casa del jefe"}),"Es una casa bastante mayor que las demas, y "
  	"con más habitaciones.\n");
  AddReadMsg(({"inscripcion","inscripción"}),"Lees la inscripción de la estatua:"
  	"\nEn honor a Kendarg, nuestro héroe local, por salvar a Flenton de su fin.\n");

    AddItem(OTRO("flenton/fuente"));
    AddExit("norte",FLENHAB+"tiendas/tienda");
    AddExit("sur",FLENHAB+"tiendas/pub");
    AddExit("oeste",FLENHAB+"casas/jefe");
    AddExit("este",FLENHAB+"calles/jefe_02");
    AddExit("nordeste",FLENHAB+"varios/arbol_00");
    AddExit("suroeste",FLENHAB+"calles/kendarg_00");
    AddCaravana(C_KENTON("kenton"));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}

init(){
  ::init();

  call_out("ffuente",220);
}

int ffuente(int p)
{
	p=random(10);
	switch (p)
	{
		case 0:	tell_room(TO,"En la fuente el agua comienza "
			"a brotar con mas fuerza... tras unos segundos vuelve a la "
			"normalidad.\n");
     			call_out("fuente",220);
     			break;

		case 1:	if (!rana)
			{
				rana=clone_object(FLENPNJ+"poblado/rana");
				rana->move(TO);
				tell_room(TO,"De la fuente salta una "
				"rana a la calle.\n");
			}
			call_out("fuente",220);
			break;

		case 2: if (!ninyo)
			{
				ninyo=clone_object(FLENPNJ+"poblado/ninyo");
				ninyo->move(TO);
				tell_room(TO,"Un niño se pone a chapotear en la fuente y a "
    				"reír.\n");
			}
			call_out("fuente",220);
			break;

		case 3:	tell_room(TO,"De repente el agua de la "
			"fuente deja de fluir... para volver segundos después\n");
			call_out("fuente",220);
			break;
	return 1;
	}
	return 1;
}
