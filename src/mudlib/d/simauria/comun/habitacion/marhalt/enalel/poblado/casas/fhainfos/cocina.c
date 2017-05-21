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
    SetIntLong("Estás en la cocina de la casa. Una enorme mesa de piedra está "
    "situada en el centro de la habitación, y al fondo, un gran armario de madera "
    "guarda los secretos de esta cocina. En el otro extremo de la cocina, cuelgan "
    "utensilios de cocina de un extraño perchero. Hay enormes cacharros y cacerolas "
    "por todas partes.\n Hacia el sur está la puerta de la despensa y hacia el este se sale "
    "al salón principal.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"mesa","mesa de piedra","piedra"}),"Es una enorme piedra plana y "
    "alargada de tonos oscuros, que se utiliza como mesa para cocinar.\n");
    AddDetail(({"utensilio","utensilios","cacerola","cacerolas","cacharro","cacharros"}),
    "Son los diferentes útiles de cocinar que hay en la cocina. No ves ninguno interesante.\n");
    AddDetail(({"perchero","extraño perchero","extranyo perchero"}),"Es una barra "
    "de metal adosada a la pared y de ella sobresalen multitud de ganchos donde se "
    "cuelgan los utensilios. En un extremo de la barra hay una palanca.\n");
    AddDetail(({"puerta","puerta de la despensa"}),SF(MirarPuerta));
    AddDetail(({"palanca","mecanismo"}),"Es una palanca de metal incrustada al "
    "extraño perchero. Parece que se puede mover.\n");
    AddExit("este",ENALHAB"poblado/casas/fhainfos/salon1");
    AddExit("sur",SF(IrAlmacen));
    AddDoor("este", "la puerta del salón",
    "La puerta que comunica con el salón de la casa.\n",
    ({"puerta", "puerta del salón", "puerta del salon", "puerta del este"}));
    AddRoomCmd(({"empujar","tirar","mover","pulsar"}),"PulsarPalanca");
    AddRoomCmd(({"abrir","cerrar"}),"AbrirCerrarPuerta");
    despensa=0;
}

public int IrAlmacen(){
  if (despensa) TP->move(ENALHAB"poblado/casas/fhainfos/almacen_cocina",M_GO,"sur");
  else {
	write("Comienzas a caminar hacia la puerta y te percatas de que está cerrada.\n");
	say(CATP+" comienza a caminar hacia el sur y se queda parado frente a la puerta.\n",TP);
  }
  return 1;
}

public string MirarPuerta(){
  string cadena = "Es la puerta de la despensa. Es de resistente metal y no parece tener "
  "ningún tipo de cerradura o picaporte. ";

  if (!despensa) 	cadena += "La puerta está cerrada.\n";
  else 			cadena += "La puerta está abierta.\n";
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
  	write("La puerta no tiene ningún picaporte o pomo para ser abierta o cerrada.\n");
	say(CATP+ " mira atentamente la puerta de la despensa.\n",TP);
	return 1;
  }
  return 0;
}
