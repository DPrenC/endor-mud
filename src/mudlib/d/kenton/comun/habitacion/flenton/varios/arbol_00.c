/***************************************************************************************
 ARCHIVO:	arbol_00.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	El Gran �rbol
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit ROOM;

int cogida;

create(){
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas la dulce y encantadora melod�a que podrucen las hojas "
  	"cuando las agita el viento. Te parece como si una dulce mujer cantase a "
  	"trav�s de ellas.\n");
  SetIntSmell("Huele a frescor primaveral.\n");

  SetPreIntShort("a");
  SetIntShort("el pie del �rbol");
  SetIntLong("Est�s frente al Gran �rbol. Un �rbol milenario, lleno de nudos y "
  	"hendiduras, orgullo de los habitantes de Flenton. Cuentan los mas viejos "
  	"del poblado que esta aqu� desde la fundaci�n de Flenton. Cuentan tambi�n "
  	"las leyendas que lo plant� un elfo amigo de los kenders, aunque no saben "
  	"que especie de �rbol es. Es un �rbol muy hermoso y sus hojas doradas parecen "
  	"entonar una melodia cuando las agita el viento. Hay un columpio colgado de "
  	"una de las ramas inferiores.\n");

  AddDetail(({"arbol","�rbol"}),"Es un gran arbol. Tiene varias ramas cercanas al suelo.\n");
  AddDetail(({"rama"}),"Es una rama fuerte, aguantaria el peso de mas de un kender.\n");
  AddDetail(({"ramas"}),"Grandes ramas salen del tronco. Una de ellas esta cerca del suelo.\n");
  AddDetail(({"hojas"}),"Ves como el viento agita las hojas de la copa del arbol.\n");
  AddDetail(({"remo","columpio"}),"Un columpio hecho de madera, colocado seguramente "
  	"por los ni�os del poblado.\n");
  AddDetail(({"tronco"}),"Es un tronco bastante ancho, de unos dos metros de diametro. "
  	"Ves una peque�a hendidura en �l.\n");
  AddDetail(({"hendidura"}),"Ves una peque�a hendidura, hay una piedra escondida en �l.\n");
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
	if (str=="al arbol" || str=="a la rama" || str=="arbol" || str=="al �rbol" || str=="�rbol")
	{
		write("Comienzas a subir al �rbol trepando por sus ramas...\n");
		if (TP->QueryInvis() != 1)
		{
			say(CATP+" empieza a trepar por las ramas del �rbol...\n",TP);
		}
		call_out("farbol2",2);
		return 1;
	}
	else
	{
		return notify_fail("�Subir o Trepar <d�nde>?\n");
	}
}

int farbol2()
{
	if (TP->QueryInvis() != 1)
	{
		write("Llegas a un nuevo lugar, est�s a bastante altura del suelo.\n");
		TP->move(FLENHAB+"varios/arbol_01",M_SILENT);
		say(CATP+" llega trepando desde abajo.\n",TP);
		TP->LookAfterMove();
	}
	else
	{
		write("Llegas a un nuevo lugar, est�s a bastante altura del suelo.\n");
		TP->move(FLENHAB+"varios/arbol_01",M_SILENT);
		TP->LookAfterMove();
	}
	return 1;
}

int fcolumpiarse(string str)
{
	write("Comienzas a columpiarte y a recordar tu dulce infancia. Cuando te "
		"das cuenta ya te est�s chupando el dedo!\n");
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
			AddDetail(({"hendidura"}),"Ves una peque�a hendidura, est� vac�a.\n");
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
