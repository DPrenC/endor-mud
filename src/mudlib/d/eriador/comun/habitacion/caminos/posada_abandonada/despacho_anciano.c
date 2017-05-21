/*****************************************************************************
 AUTOR:		orome
 DETALLES:	posada abandonada
 *****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <door.h>
inherit ROOM;

public string MirarMapa();
public int MoverMapa (string str);

int LlaveEnMapa;

create() {
    ::create();

    SetIntBright(20);
    SetLocate("una posada abandonada");
    SetIntShort("el despacho del anciano");
    SetIntLong("Est�s en un enorme despacho cuyas paredes est�n cubiertas de "
    "nobles y gruesas maderas. Bellos tapices adornan las paredes. Aqu�, la familia "
    "Fhainfos trata los temas de importancia para la familia y para la poblaci�n. "
    "Hacia el oeste se encuentra el sal�n principal y al este hay una peque�a puerta.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"pared","paredes","madera","pared de madera","maderas","paredes de madera"}),
    "Son gruesas paredes de madera para evitar que nadie pueda escuchar desde el exterior.\n");
    AddDetail("tapices","Son unos bellos tapices colgados de las paredes con motivos "
    "naturistas conmemorando haza�as de la familia.\nUno de los tapices es un enorme mapa "
    "de la regi�n.\n");
    AddDetail(({"cuadro","tapiz","mapa"}),SF(MirarMapa));
    AddExit("oeste","./salon1");
    AddExit("este", "./dormitorio_anciano");
    AddDoor("oeste", "la puerta del sal�n",
    "la puerta que comunica con el gran sal�n.\n",
    ({"puerta", "puerta del oeste", "puerta del sal�n", "puerta del salon"}));
    AddDoor("este", "una puerta de madera oscura",
    "Es una puerta de madera oscura.\n",
    ({"puerta", "puerta de madera", "puerta del este"}),
    "llave peque�a",
    ([P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
    AddRoomCmd("mover","MoverMapa");
    LlaveEnMapa = 1;
}

public string MirarMapa(){
  string cadena = "Es un cuadro con el mapa de la zona de Enalel. Se detalla el poblado, "
  "el bosque del manzanar y el antiguo templo situado en el centro del manzanar.";
  if (LlaveEnMapa==1) cadena += "\nParece que hay algo en una de las esquinas del marco. "
  "Si movieses un poco el cuadro quiz�s puedas sacarlo.\n";
  return cadena;
}

public int MoverMapa(string str){
 object llave;
 if (!str) return notify_fail("�qu� quieres mover?\n"),0;
 str = lower_case(str);

 if (str=="cuadro"||str=="tapiz"||str=="mapa"){
	if (LlaveEnMapa){
		LlaveEnMapa = 0;
		write("Mueves el cuadro y encuentras una peque�a llave.\n");
		say(CATP+" mueve el tapiz del mapa y encuentra algo brillante.\n");
		llave = clone_object("/d/simauria/comun/objeto/otro/marhalt/enalel/llave_dormitorio");
		llave->move(TP,M_NOCHECK);
		return 1;
	}
	write("Mueves el cuadro pero no hay nada dentro.\n");
	say(CATP+ " mueve el tapiz buscando algo.",TP);
	return 1;
  }
  return 0;
}
