/****************************************************************************
Fichero: dhorin.c
Autor: [T] Tagoras
Creaci�n: 28/03/2009
Descripci�n: El reclutador en el centro de alistamiento
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
	SetLong("Es un viejo soldado enano ya retirado del servicio que trabaja en el centro de alistamiento de Annufam.\nM�s en detalle ves las m�ltiples heridas que le han causado los largos a�os de guerra en los que se han visto inmersos los enanos. Le falta un ojo y se tapa con un parche. Tambi�n debi� sufrir graves heridas en la pierna derecha porque la arrastra al caminar.\n");
	Set(P_CANT_LURE, 1);
	AddQuestion(({"alistarse"}), "Dhorin te dice: 'Si te alistas, servir�s como recluta durante un a�o en el ej�rcito o la legi�n. Podr�s adiestrarte como guerrero con los maestros en el Centro de Adiestramiento de Guerreros de Annufam.'\n");
	AddQuestion(({"legi�n", "legion"}), "Dhorin te dice: 'La legi�n es el cuerpo militar que reservamos a las otras razas pero que quieren luchar brazo con brazo con nosotros, los enanos.'\n");
	AddQuestion(({"ej�rcito", "ejercito"}), "Dhorin te dice: 'Ahhhh!!!! El ej�rcito enano, yo serv� en �l durante muchos a�os y luch� en incontables batallas. Es el cuerpo militar al que pueden alistarse los enanos guerreros.'\n");
	InitChats(5, ({
		"Dhorin te dice: 'Si quieres alistarte al ej�rcito o a la legi�n, s�lo tienes que pedirlo.'\n",
		"Dhorin se lamenta: 'Ay, qu� tiempos aquellos en que combatiamos con los ogros, los jovenes de ahora parec�is de mantequilla.'\n",
		"Dhorin canturrea una vieja canci�n de batalla: 'Nosotros somos los enanos guerreros, ...'\n",
		"Dhorin te dice: 'Si te alistas podr�s entrenarte con los mejores maestros guerreros y mejorar tus habilidades de combate.\n"
	}));
}
