/****************************************************************************
Fichero: cuadras.c
Autor: Riberales
		[T] Tagoras
Creaci�n: 28/09/2005
Descripci�n: Las cuadras de Annufam.
[T] 20/023/2009: A�ado sondio ambiente para el chorrito del abrevadero
****************************************************************************/

#include "./path.h"
#include <sounds.h>

inherit ROOM;

int ir_oeste();
int cmd_beber();
int cmd_coger();
string cmd_escuchar();
int caballo_vivo();

public void create()
{
	::create();

	SetIntShort("las cuadras de Annufam");
	SetIntLong(W("Has entrado en las cuadras de Annufam, donde los enanos "
				 "dejan sus caballos cuando vienen a la ciudad. Ves un "
				 "abrevadero para que beban los caballos y una fuente para "
				 "los jinetes. Tambi�n un poco de heno para que los animales "
				 "coman mientras descansan. Adem�s, en la pared oeste hay una "
				 "puerta que da a la herrer�a.\n"));


	AddDetail("heno",
			W("Es la pastura sometida a un proceso de deshidrataci�n. El "
			  "objetivo es reducir el contenido de agua en los forrajes "
			  "verdes para poder almacenarlos el tiempo que sea necesario sin "
			  "que se fermenten o se enmohezcan.\n"));


	AddDetail(({"fuente","chorro"}),
			  W("Es un chorro que sale de la pared de la herrer�a y que cae a "
				"una especie de abrevadero, para aprovechar el agua tanto "
			  "para las personas como para los animales.\n"));


	AddDetail("abrevadero",
			W("Es un peque�o estanque donde cae el chorro de agua y se "
			  "aprovecha para que los caballos beban.\n"));


	AddDetail("puerta",
			  "Es una rudimentaria puerta que comunica la cuadra con la herrer�a.\n");


	AddDetail("suelo",
			W("El suelo est� repleto de restos de paja y heno, y alg�n "
			  "excremento equino.\n"));


	AddDetail(({"excremento","excremento equino","mierda"}),
			  W("Son restos g�stricos unidos a �cidos procedentes de los "
				"intestinos de los caballos.\n"));


	AddDetail(({"arriba","techo"}),
			  W("El techo est� hecho con paja y vigas de madera. Parece "
				"bastante resistente, pero tambi�n muy inflamable.\n"));


	SetIndoors(1);
	SetIntLight(75);
	SetIntSmell("Hum... huele a... a... a cuadra. Puaj.\n");
	SetIntNoise(SF(cmd_escuchar));
	AddItem(PNJ_CIUDAD_ANNUFAM("caballo"),REFRESH_DESTRUCT,random(4));
	AddRoomCmd("coger","cmd_coger");
	AddRoomCmd("beber","cmd_beber");
	AddExit("oeste",SF(ir_oeste));
	AddExit("sur",HAB_UNGRIM_ANNUFAM("ungrim_06"));

	SetSoundEnvironment(SND_AMBIENTES("Manantial"), 50);
}


int ir_oeste()
{
	return notify_fail(W("La puerta s�lo se puede abrir desde la "
					   "herrer�a, por aqu� no podr�s entrar.\n"),
					   NOTIFY_NOT_VALID);
}


int caballo_vivo(object caballo)
{
	return caballo->id("caballo") && living(caballo);
}

string cmd_escuchar(string str)
{
	if(!str)
	{
		if (sizeof(filter(all_inventory(),SF(caballo_vivo))))
		{
		   return W("Escuchas el caer del chorro al abrevadero y de cuando en "
					"cuando el relinchar de los caballos.\n");
		}
		return "Escuchas como cae el chorro de agua al abrevadero.\n";
	}
}


int cmd_coger(string str)
{
	if (!str) return 0;
	if (str == "heno") return notify_fail("Deja el alimento de los caballos.\n"
							 ,NOTIFY_NOT_VALID);
}


int cmd_beber(string str)
{
	if(!str) return notify_fail("�Beber qu�?\n",NOTIFY_NOT_VALID);;
	if (str == "abrevadero") return notify_fail("�Acaso eres un caballo?\n",
									NOTIFY_NOT_VALID);
	if (member(({"agua","agua de chorro","agua de fuente"}),str)<= -1)return 0;
	if (TP->QueryMaxDrink() == TP->QueryDrink())
	{
		return notify_fail("No puedes beber m�s y te mojas la cara.\n",
			   NOTIFY_NOT_VALID);
	}

	write(W("Pegas un largo trago del chorro de agua, mientras por la comisura"
		  " de los labios va cayendo el l�quido elemento hacia el "
		  "abrevadero.\n"));
	say(CAP(TNAME)+ " bebe del chorro de agua.\n");
	TP->AddDrink(4);
	return 1;
}

int QueryCuadraAnnufam()
{
	return 1;
}
