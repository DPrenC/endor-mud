/*
  ***************************************************************
   Fichero para la generacion de pajaros tipicos de un bosque
  ***************************************************************
   22-10-98 [Chaos]		Creacion

   04-11-98 [Chaos] Modificacion: cambio del path por que ahora
    		  no hace falta la funcion Actualizar y han
   		  sido eliminados los ficheros ave.c mamifero.c
  		  reptil.c
  **************************************************************
*/
#define ART (QueryArtIndString()+" ")

#include <properties.h>
#include <living.h>
#include <miembro.h>

inherit "/d/akallab/comun/pnj/animal/animal";

create(){
     ::create();
     SetSize(4);
SetRace("mamífero");
SetShort("un bicho");
SetLong("Es un bicho enorme\n");

}