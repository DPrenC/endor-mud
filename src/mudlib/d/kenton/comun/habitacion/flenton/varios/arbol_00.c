/***************************************************************************************
 ARCHIVO:	arbol_00.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	El Gran Árbol
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit ROOM;

int cogida;

create(){
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas la dulce y encantadora melodía que podrucen las hojas "
  	"cuando las agita el viento. Te parece como si una dulce mujer cantase a "
  	"través de ellas.\n");
  SetIntSmell("Huele a frescor primaveral.\n");

  SetPreIntShort("a");
  SetIntShort("el pie del árbol");
  SetIntLong("Estás frente al Gran Árbol. Un árbol milenario, lleno de nudos y "
  	"hendiduras, orgullo de los habitantes de Flenton. Cuentan los mas viejos "
  	"del poblado que esta aquí desde la fundación de Flenton. Cuentan también "
  	"las leyendas que lo plantó un elfo amigo de los kenders, aunque no saben "
  	"que especie de árbol es. Es un árbol muy hermoso y sus hojas doradas parecen "
  	"entonar una melodia cuando las agita el viento. Hay un columpio colgado de "
  	"una de las ramas inferiores.\n");

  AddDetail(({"arbol","árbol"}),"Es un gran arbol. Tiene varias ramas cercanas al suelo.\n");
  AddDetail(({"rama"}),"Es una rama fuerte, aguantaria el peso de mas de un kender.\n");
  AddDetail(({"ramas"}),"Grandes ramas salen del tronco. Una de ellas esta cerca del suelo.\n");
  AddDetail(({"hojas"}),"Ves como el viento agita las hojas de la copa del arbol.\n");
  AddDetail(({"remo","columpio"}),"Un columpio hecho de madera, colocado seguramente "
  	"por los niños del poblado.\n");
  AddDetail(({"tronco"}),"Es un tronco bastante ancho, de unos dos metros de diametro. "
  	"Ves una pequeña hendidura en él.\n");
  AddDetail(({"hendidura"}),"Ves una pequeña hendidura, hay una piedra escondida en él.\n");
  AddDetail(({"hendiduras","nudo","nudos"}),"Hay nudos y hendiduras por todas partes del "
  	"tronto.\n");

  AddRoomCmd("subir","fsubir");
  AddRoomCmd("trepar","fsubir");
  AddRoomCmd("columpiar","fcolumpiarse");
  AddRoomCmd("columpiarse","fcolumpiarse");
  AddRoomCmd("coger","fcoger");

  AddExit("suroeste",FLENHAB+"calles/plaza_00");
  AddItem(FLENPNJ+"poblado/ninyo",REFRESH_DESTRUCT,1);
}

int fsubir(string str)
{
	if (str=="al arbol" || str=="a la rama" || str=="arbol" || str=="al árbol" || str=="árbol")
	{
		write("Comienzas a subir al árbol trepando por sus ramas...\n");
		if (TP->QueryInvis() != 1)
		{
			say(CATP+" empieza a trepar por las ramas del árbol...\n",TP);
		}
		call_out("farbol2",2);
		return 1;
	}
	else
	{
		return notify_fail("¿Subir o Trepar <dónde>?\n");
	}
}

int farbol2()
{
	if (TP->QueryInvis() != 1)
	{
		write("Llegas a un nuevo lugar, estás a bastante altura del suelo.\n");
		TP->move(FLENHAB+"varios/arbol_01",M_SILENT);
		say(CATP+" llega trepando desde abajo.\n",TP);
		TP->LookAfterMove();
	}
	else
	{
		write("Llegas a un nuevo lugar, estás a bastante altura del suelo.\n");
		TP->move(FLENHAB+"varios/arbol_01",M_SILENT);
		TP->LookAfterMove();
	}
	return 1;
}

int fcolumpiarse(string str)
{
	write("Comienzas a columpiarte y a recordar tu dulce infancia. Cuando te "
		"das cuenta ya te estás chupando el dedo!\n");
	say(CATP+" empieza a columpiarse, pone cara de tont"+AO+" y se mete el dedo "
		"en la boca.\n",TP);
	return 1;
}

int fcoger(string str)
{
	if (str=="piedra de la hendidura" || str=="piedra de hendidura" || str=="piedra" || str=="piedra verde")
	{
		if(!cogida)
		{
			object piedra;
			write("Coges la piedra que estaba escondida en la hendidura.\n");
			piedra=clone_object(FLENVAR+"piedra_verde");
			piedra->move(TP,M_SILENT);
			AddDetail(({"hendidura"}),"Ves una pequeña hendidura, está vacía.\n");
      			cogida=1;
			return 1;
		}
		else
		{
			write("No ves ninguna piedra que coger.\n");
			return 1;
		}
	}
return 0;
}
