/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"
#include <moving.h>

inherit SIM_ROOM;

public int IrAlmacen();
public string MirarPuerta();
public int despensa;
public int PulsarPalanca(string str);
public int AbrirCerrarPuerta(string str);
public int QueryDespensa() { return despensa; }
create() {
  ::create();

    SetIntBright(30);
    SetLocate("Casa Fhainfos");
    SetIntShort("la cocina");
    SetIntLong("Est�s en la cocina de la casa. Una enorme mesa de piedra est� "
    "situada en el centro de la habitaci�n, y al fondo, un gran armario de madera "
    "guarda los secretos de esta cocina. En el otro extremo de la cocina, cuelgan "
    "utensilios de cocina de un extra�o perchero. Hay enormes cacharros y cacerolas "
    "por todas partes.\n Hacia el sur est� la puerta de la despensa y hacia el este se sale "
    "al sal�n principal.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"mesa","mesa de piedra","piedra"}),"Es una enorme piedra plana y "
    "alargada de tonos oscuros, que se utiliza como mesa para cocinar.\n");
    AddDetail(({"utensilio","utensilios","cacerola","cacerolas","cacharro","cacharros"}),
    "Son los diferentes �tiles de cocinar que hay en la cocina. No ves ninguno interesante.\n");
    AddDetail(({"perchero","extra�o perchero","extranyo perchero"}),"Es una barra "
    "de metal adosada a la pared y de ella sobresalen multitud de ganchos donde se "
    "cuelgan los utensilios. En un extremo de la barra hay una palanca.\n");
    AddDetail(({"puerta","puerta de la despensa"}),SF(MirarPuerta));
    AddDetail(({"palanca","mecanismo"}),"Es una palanca de metal incrustada al "
    "extra�o perchero. Parece que se puede mover.\n");
    AddExit("este",ENALHAB"poblado/casas/fhainfos/salon1");
    AddExit("sur",SF(IrAlmacen));
    AddDoor("este", "la puerta del sal�n",
    "La puerta que comunica con el sal�n de la casa.\n",
    ({"puerta", "puerta del sal�n", "puerta del salon", "puerta del este"}));
    AddRoomCmd(({"empujar","tirar","mover","pulsar"}),"PulsarPalanca");
    AddRoomCmd(({"abrir","cerrar"}),"AbrirCerrarPuerta");
    despensa=0;
}

public int IrAlmacen(){
  if (despensa) TP->move(ENALHAB"poblado/casas/fhainfos/almacen_cocina",M_GO,"sur");
  else {
	write("Comienzas a caminar hacia la puerta y te percatas de que est� cerrada.\n");
	say(CATP+" comienza a caminar hacia el sur y se queda parado frente a la puerta.\n",TP);
  }
  return 1;
}

public string MirarPuerta(){
  string cadena = "Es la puerta de la despensa. Es de resistente metal y no parece tener "
  "ning�n tipo de cerradura o picaporte. ";

  if (!despensa) 	cadena += "La puerta est� cerrada.\n";
  else 			cadena += "La puerta est� abierta.\n";
  return cadena;
}

public int PulsarPalanca(string str){
  if (str=="palanca"){
	if (despensa){
		write("mueves la palanca y la puerta de la despensa se cierra.\n");
		say(CATP+" mueve una palanca y la puerta de la despensa se cierra.\n",TP);
		tell_room(ENALHAB"poblado/casas/fhainfos/almacen_cocina", "La puerta se cierra.\n");
		despensa= 0;
	}
	else{
		write("mueves la palanca y la puerta de la despensa se abre.\n");
		say(CATP+" mueve una palanca y la puerta de la despensa se abre.\n",TP);
		tell_room(ENALHAB"poblado/casas/fhainfos/almacen_cocina", "La puerta se abre.\n");
		despensa= 1;
	}
	return 1;
  }
  return 0;
}

public int AbrirCerrarPuerta(string str){
  if (str=="puerta"){
  	write("La puerta no tiene ning�n picaporte o pomo para ser abierta o cerrada.\n");
	say(CATP+ " mira atentamente la puerta de la despensa.\n",TP);
	return 1;
  }
  return 0;
}
