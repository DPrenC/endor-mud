/*

    Nombre      : calle10
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de la empalizada

*/
#include "./path.h"
#include <moving.h>


inherit SIM_ROOM;

public int PuertaManzanar;
public string MirarPuerta();
public int IrManzanar();

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle de la empalizada");
    SetIntLong("Estás en la calle de la empalizada. Aquí la calle se ensancha "
    "un poco para alojar a la enorme puerta que comunica con el manzanar. Al sur "
    "se encuentra la puerta trasera del cuartel general de la guardia de Enalel y al norte "
    "la salida hacia el manzanar. La calle continua al oeste y al este.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddDetail("empalizada","Es una empalizada de madera que rodea todo el poblado.\n");
    AddDetail(({"puerta del manzanal", "puerta"}),SF(MirarPuerta));
    AddExit("este",ENALHAB"poblado/calles/calle09");
    AddExit("oeste",ENALHAB"poblado/calles/calle11");
    AddExit("sur",ENALHAB"poblado/varios/cuartel");
    AddExit("norte",SF(IrManzanar));
    AddDoor("sur", "la puerta trasera del cuartel",
    "Por esa puerta se entra al cuartel de la guardia de Enalel.\n",
    ({"puerta", "puerta trasera del cuartel", "puerta del sur"}));
    AddRoomCmd("abrir","AbrirPuerta");
    PuertaManzanar = 0; // La puerta del manzanar está cerrada
  AddItem(ENALPNJ"guardias/enalel",REFRESH_DESTRUCT,1);
}

public string MirarPuerta(){
  string cadena = "Es una enorme puerta de madera y metal que protege la entrada desde el manzanar.\n";

  if (PuertaManzanar)	cadena += "La puerta está abierta.\n";
  else 			cadena += "La puerta está cerrada.\n";
  return cadena;
}

public int IrManzanar(){
  if (PuertaManzanar) 	TP->move(ENALHAB"manzanar/sendero01",M_GO);
  else {
  	write("Comienzas a caminar hacia la puerta y te das cuenta de que está cerrada.\n");
	say(CATP+" mira la puerta del manzanar.\n");
  }
  return 1;
}

public int AbrirPuerta(string str){
  if (!str) return notify_fail("¿Qué quieres abrir?\n"),0;
  str = lower_case(str);

  if (str=="puerta" || str=="puerta del manzanar"){
        write("La puerta está cerrada con llave.\n");
        return 1;
  }
}
