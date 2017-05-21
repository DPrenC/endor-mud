/*

    Nombre      : encimaGranManzanoEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Encima del gran manzano
    
*/

#include "path.h"

inherit SIM_ROOM;

public int CogerManzana(string str){
  if (str=="manzana" || str=="manzanas"){
  	write(W("Ves que las manzanas a�n no est�n maduras. Quiz�s cuando pase "
  	"alg�n tiempo podr�s cogerlas.\n"));
        return 1;
  }
}

create() {
  ::create();
  
  SetIndoors(0);
  SetLocate("Poblado de Enalel");
  SetIntShort("la copa del gran �rbol");
  SetIntLong(W("Est�s en la copa del gran manzano. Las ramas son tan tupidas "
  "que te impiden ver el suelo. Puedes bajar con cuidado al suelo del bosque.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"manzano","gran manzano","majestuoso manzano","�rbol","arbol"}),
  "Es un majestuoso manzano de altas ramas.\n");
  AddDetail(({"ramas","rama"}),"Son ramas muy fuertes y de oscura madera");
  AddDetail(({"manzana","manzanas","fruto","frutos","fruta","frutas"}),
  "Parecen brillar con cierta tonalidad m�gica");
  AddExit("abajo",ENALHAB"poblado/manzanal/manzano00");
  AddRoomCmd("coger","CogerManzana");
}