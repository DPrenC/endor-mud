/*

    Nombre      : temploNhaigel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Templo del dios de la agricultura y la naturaleza controlada.
                  Si se reza, se recuperan puntos de vida si se es bueno de alineamiento.

*/

#include "./path.h"

inherit SIM_ROOM;

int Rezar(string str);

create() {
    ::create();

    SetIntBright(50);
    SetLocate("Poblado de Enalel");
    SetIntShort("el templo de Nhaigel");
    SetIntLong("Estás bajo el techo de un pequeño templo dedicado al dios Nhaigel, "
    "deidad de la agricultura. Aquí, los fieles se postran para orar frente a su altar "
    "al dios de la agricultura y la ganadería. El pequeño altar está presidido por una "
    "estatua de la deidad. La salida al camino de la meditación está al sur.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail("altar","Es un bello altar tallado en madera y piedra cuyos motivos "
    "son la agricultura y la ganadería.\n");
    AddDetail(({"estatua","escultura","estatua de nhaigel","nhaigel","Nhaigel","dios",
        "deidad"}), "Es una hermosa estatua de unos 3 metros de alto donde, en cálida "
        "piedra dorada, está tallada la forma del dios Nhaigel. Parece un humano con "
        "rasgos élficos cuyos ojos, serenos y sábios, parecen mirarte atentamente. "
        "Sus manos descansan sobre sus rodillas tomando una postura de meditación y "
        "contemplación.\n");
    AddExit("sur",ENALHAB"poblado/calles/calle24");
    AddDoor("sur", "la puerta de salida",
    "Es la puerta del templo para salir a la calle de la meditación.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del sur"}));
    AddRoomCmd(({"rezar","orar"}),"Rezar");
}

int Rezar(string str){
  say(CATP+" se postra orando ante el altar.\n",TP);
  if (TP->QueryAlign()>0){
  	write("El dios escucha tus plegarias y te recompensa por tu alma bondadosa.\nSientes que tu fatiga desaparece.\n");
	TP->SetTP( TP->QueryMaxTP() );
  }
  else {
	write("El dios se encoleriza con la impureza de tu espíritu y te castiga.\n");
	TP->Defend(random(30));
  }
  return 1;
}
