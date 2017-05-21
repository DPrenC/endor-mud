/***************************************************************************************
 ARCHIVO:	arbol_01.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	El Gran �rbol
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
  SetIntNoise("Escuchas la dulce y encantadora melod�a que podrucen las hojas "
  	"cuando las agita el viento. Te parece como si una dulce mujer cantase a "
  	"trav�s de ellas.\n");
  SetIntSmell("Huele a frescor primaveral.\n");

  SetIntShort("el �rbol");
  SetIntLong("Est�s en una plataforma de madera, en lo alto del Gran �rbol. "
  	"Desde aqu� puedes divisar todo el poblado, e incluso parte de los "
  	"alrededores. Es un lugar ideal para la vigilia y tambi�n para estar "
  	"alejado de todo. Se respira mucha paz aqu� arriba.\n");

  AddDetail(({"rama"}),"Miras una rama encima de tu cabeza. No es muy fuerte, "
  	"pero quiz�s aguantar�a el peso de un ni�o.\n");
  AddDetail(({"hojas"}),"Ves como el viento agita las hojas de la copa del �rbol.\n");
  AddDetail(({"plataforma","suelo"}),"Es una plataforma de madera. Es muy s�lida.\n");
  AddDetail(({"horizonte","alrededores"}),"Miras al horizonte, desde aqu� puedes "
  	"divisar todos los parajes vecino...\n");
  AddDetail(({"poblado"}),"Desde aqu� puedes divisar todo el poblado. Se ve todo "
  	"distinto desde aqu�.\n");

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
			write("Contin�as trepando hacia la copa del �rbol...\n");
			say(CATP+" empieza a trepar por las ramas del �rbol...\n",TP);
			call_out("farbol2",3);
			return 1;
		}
		else
		{
			write("�Notas como la rama cede, pierdes el equilibrio y "
				"comienzas a caer! Quiz�s pesabas demasiado para aquella "
				"rama.\n");
			say(CATP+" intenta seguir trepando, pero una rama cede, pierde "
				"el equil�brio y se precipita hacia el suelo.\n",TP);
			call_out("farbol3",2);
			return 1;
		}
	}
	else
	{
		return notify_fail("�Subir o Trepar <d�nde>?\n");
	}
}

int farbol2()
{
	write("Llegas a un nuevo lugar, est�s a mucha altura del suelo.\n");
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
	write("Al fin llegas al suelo. �No es una ca�da suave... menudo "
		"porrazo! ��Ouchhh!!. Te sientes bastante dolorido por la ca�da.\n");
	say(CATP+" cae de repente desde el �rbol como una fruta madura. �Menudo porrazo!\n",TP);
	return 1;
}
