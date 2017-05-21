/***************************************************************************************
 ARCHIVO:	arbol_01.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	El Gran Árbol
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
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

  SetIntShort("el árbol");
  SetIntLong("Estás en una plataforma de madera, en lo alto del Gran Árbol. "
  	"Desde aquí puedes divisar todo el poblado, e incluso parte de los "
  	"alrededores. Es un lugar ideal para la vigilia y también para estar "
  	"alejado de todo. Se respira mucha paz aquí arriba.\n");

  AddDetail(({"rama"}),"Miras una rama encima de tu cabeza. No es muy fuerte, "
  	"pero quizás aguantaría el peso de un niño.\n");
  AddDetail(({"hojas"}),"Ves como el viento agita las hojas de la copa del árbol.\n");
  AddDetail(({"plataforma","suelo"}),"Es una plataforma de madera. Es muy sólida.\n");
  AddDetail(({"horizonte","alrededores"}),"Miras al horizonte, desde aquí puedes "
  	"divisar todos los parajes vecino...\n");
  AddDetail(({"poblado"}),"Desde aquí puedes divisar todo el poblado. Se ve todo "
  	"distinto desde aquí.\n");

  AddRoomCmd("trepar","fsubir");
  AddRoomCmd("subir","fsubir");

  AddExit("abajo",FLENHAB+"varios/arbol_00");
}

int fsubir(string str)
{
	if (str=="rama" || str=="a la rama" || str==" a rama")
	{
		if((TP->QueryWeigth()) < 50000 )
		{
			write("Continúas trepando hacia la copa del árbol...\n");
			say(CATP+" empieza a trepar por las ramas del árbol...\n",TP);
			call_out("farbol2",3);
			return 1;
		}
		else
		{
			write("¡Notas como la rama cede, pierdes el equilibrio y "
				"comienzas a caer! Quizás pesabas demasiado para aquella "
				"rama.\n");
			say(CATP+" intenta seguir trepando, pero una rama cede, pierde "
				"el equilíbrio y se precipita hacia el suelo.\n",TP);
			call_out("farbol3",2);
			return 1;
		}
	}
	else
	{
		return notify_fail("¿Subir o Trepar <dónde>?\n");
	}
}

int farbol2()
{
	write("Llegas a un nuevo lugar, estás a mucha altura del suelo.\n");
	say(CATP+" llega trepando desde abajo.\n",TP);
	TP->move(FLENHAB+"varios/arbol_02",M_SILENT);
	TP->LookAfterMove();
	return 1;
}

int farbol3()
{
	TP->move(FLENHAB+"varios/arbol_00",M_SILENT);
	TP->LookAfterMove();
	TP->SetHP((TP->QueryHP())-(random(10)+random(10)));
	write("Al fin llegas al suelo. ¡No es una caída suave... menudo "
		"porrazo! ¡¡Ouchhh!!. Te sientes bastante dolorido por la caída.\n");
	say(CATP+" cae de repente desde el árbol como una fruta madura. ¡Menudo porrazo!\n",TP);
	return 1;
}
