/*

    Nombre      : encimaGranManzanoEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Encima del gran manzano
    
*/

#include "path.h"

inherit SIM_ROOM;

public int CogerManzana(string str){
  if (str=="manzana" || str=="manzanas"){
  	write(W("Ves que las manzanas aún no están maduras. Quizás cuando pase "
  	"algún tiempo podrás cogerlas.\n"));
        return 1;
  }
}

create() {
  ::create();
  
  SetIndoors(0);
  SetLocate("Poblado de Enalel");
  SetIntShort("la copa del gran árbol");
  SetIntLong(W("Estás en la copa del gran manzano. Las ramas son tan tupidas "
  "que te impiden ver el suelo. Puedes bajar con cuidado al suelo del bosque.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"manzano","gran manzano","majestuoso manzano","árbol","arbol"}),
  "Es un majestuoso manzano de altas ramas.\n");
  AddDetail(({"ramas","rama"}),"Son ramas muy fuertes y de oscura madera");
  AddDetail(({"manzana","manzanas","fruto","frutos","fruta","frutas"}),
  "Parecen brillar con cierta tonalidad mágica");
  AddExit("abajo",ENALHAB"poblado/manzanal/manzano00");
  AddRoomCmd("coger","CogerManzana");
}