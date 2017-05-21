/***************************************************************************************
 ARCHIVO:	arbol_02.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	El Gran �rbol
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

int cogida;



create(){
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas la dulce y encantadora melod�a que podrucen las hojas "
  	"cuando las agita el viento... parece como si una mujer cantase a trav�s "
  	"de ellas.\n");
  SetIntSmell("Huele a frescor primaveral.\n");

  SetIntShort("la copa del �rbol");
  SetIntLong("Est�s en la copa del �rbol, desde aqu� puedes ver a�n m�s lejos. "
  	"El viento acaricia tu cara, y te sientes en la cima del mundo. Est�s tan "
  	"contento que te entran ganas de bailar... aunque no ser�a una sensata idea.\n");

  AddDetail(({"rama"}),"Las ramas donde est�s apoyado no son muy fuertes...\n");
  AddDetail(({"hojas"}),"Ves como el viento agita las hojas de la copa del �rbol.\n");
  AddDetail(({"suelo"}),"�Miras abajo y ves el suelo bastante lejos! debes estar al "
  	"menos a 50 metros de altura\n");
  AddDetail(({"horizonte","alrededores"}),"Miras al horizonte, desde aqu� puedes "
  	"divisar todos los parajes vecinos...\n");

  AddRoomCmd("bailar","fbailar");

  AddExit("abajo",FLENHAB+"varios/arbol_01");
  AddItem(FLENVAR+"musgo_quest",REFRESH_REMOVE);
}

int fbailar()
{
	write("Comienzas a bailar y a moverte peligrosamente.\n");
	say(W(CATP+" comienza a bailar y a hacer tonterias.\n"),TP);
	call_out("farbol2",2);
	return 1;
}

int farbol2()
{
	write(W("�Notas como una de las ramas cede, pierdes el equilibrio y "
		"comienzas a caer! Deb�as haber hecho caso a tu sentido comun "
		"y no hacer tonter�as.\n"));
	say(W(CATP+" pierde el equilibrio y se precipita hacia el suelo.\n"),TP);
	write("Te vas ara�ando con las ramas al caer...\n");
	call_out("fcaida1",1);
	return 1;
}

int fcaida1()
{
	tell_room(FLENHAB+"varios/arbol_01",W("Oyes crujidos de ramas que se "
		"rompen y quejidos que provienen de la copa del �rbol. Al instante, "
		"ves como alguien cae desde arriba, hacia el suelo a gran velocidad.\n"),({TP}));
	call_out("fcaida2",2);
	return 1;
}

int fcaida2()
{
	TP->move(FLENHAB+"varios/arbol_00");
	TP->SetHP((TP->QueryHP())-(random(15)+random(15)));
	write(W("Al fin llegas al suelo. No es una ca�da suave... �menudo porrazo! "
		"��Ouchhh!!. Te sientes bastante dolorido y aturdido por la ca�da.\n"));
	say(W(CATP+" cae de repente desde el �rbol como una fruta madura. �Menudo porrazo!\n"),TP);
	return 1;
}