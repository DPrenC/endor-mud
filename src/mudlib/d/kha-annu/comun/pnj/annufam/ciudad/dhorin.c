/****************************************************************************
Fichero: dhorin.c
Autor: [T] Tagoras
Creación: 28/03/2009
Descripción: El reclutador en el centro de alistamiento
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <guild.h>

inherit DEFENSOR_BASE_ANNUFAM;

public void create()
{
	if (::create()) return;

	SetStandard("dhorin", "enano", ([GC_LUCHADOR:60]), GENDER_MALE);
	AddId(({"dhorin", "soldado", "reclutador_cage"}));
	SetLong("Es un viejo soldado enano ya retirado del servicio que trabaja en el centro de alistamiento de Annufam.\nMás en detalle ves las múltiples heridas que le han causado los largos años de guerra en los que se han visto inmersos los enanos. Le falta un ojo y se tapa con un parche. También debió sufrir graves heridas en la pierna derecha porque la arrastra al caminar.\n");
	Set(P_CANT_LURE, 1);
	AddQuestion(({"alistarse"}), "Dhorin te dice: 'Si te alistas, servirás como recluta durante un año en el ejército o la legión. Podrás adiestrarte como guerrero con los maestros en el Centro de Adiestramiento de Guerreros de Annufam.'\n");
	AddQuestion(({"legión", "legion"}), "Dhorin te dice: 'La legión es el cuerpo militar que reservamos a las otras razas pero que quieren luchar brazo con brazo con nosotros, los enanos.'\n");
	AddQuestion(({"ejército", "ejercito"}), "Dhorin te dice: 'Ahhhh!!!! El ejército enano, yo serví en él durante muchos años y luché en incontables batallas. Es el cuerpo militar al que pueden alistarse los enanos guerreros.'\n");
	InitChats(5, ({
		"Dhorin te dice: 'Si quieres alistarte al ejército o a la legión, sólo tienes que pedirlo.'\n",
		"Dhorin se lamenta: 'Ay, qué tiempos aquellos en que combatiamos con los ogros, los jovenes de ahora parecéis de mantequilla.'\n",
		"Dhorin canturrea una vieja canción de batalla: 'Nosotros somos los enanos guerreros, ...'\n",
		"Dhorin te dice: 'Si te alistas podrás entrenarte con los mejores maestros guerreros y mejorar tus habilidades de combate.\n"
	}));
}
