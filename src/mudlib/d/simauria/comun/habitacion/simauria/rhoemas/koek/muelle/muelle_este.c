/***************************************************************************************

 ARCHIVO:	muelle_este.c

 AUTOR:		[z] Zomax

 FECHA:		18-11-2001

 COMENTARIOS:	Extremo Este del muelle

 ***************************************************************************************/



#include "path.h"



inherit RHOESTD("muelle");



create () {

  ::create();



  SetLocate("Koek");

  SetIntShort("el extremo este del muelle");

  AddRoomCmd("pescar","fpescar");

  carcel=(RHOEHAB("koek/muelle/muelle_centro"));

  

  AddExit("oeste",RHOEHAB("koek/muelle/muelle_centro"));

  AddItem(RHOEPNJ("koek/varios/gato"),1,3+random(3));

  map[neu,des]= "Estás en el extremo este del muelle. Aquí los pescadores se "

  		"dedican a remendar sus redes. Hay un gran pilar de madera "

  		"donde están amarradas un par de barcazas de madera muy bien "

  		"conservadas. Bajo el muelle y donde alcanza tu vista puedes "

  		"ver el lago. ";

  

  AddDetail(({"pilar","pilar de madera"}),W("En una de las esquinas de esta parte "

  	"del muelle puedes ver un gran pilar de madera, lleno de marcas y con unas "

  	"gruesas cuerdas a su alrededor que hacen de amarras de las barcazas.\n"));

  AddDetail(({"amarras","cuerda","cuerdas"}),W("Son unas grandes cuerdas demasiado "

  	"pesadas para que nadie las quiera coger.\n"));

  AddDetail(({"marca","marcas"}),W("Las amarras, en contacto con la madera, han hecho "

  	"unas grandes marcas a lo largo del pilar.\n"));

  AddDetail(({"barcaza","barcazas"}),W("Hay un par de barcazas de pesca amarradas al muelle. "

  	"Son algo pequeñas, pero muy funcionales y parecen hechas con mucho esmero, puesto "

  	"que a pesar de estar ya algún tiempo en el agua están en perfecto estado.\n"));

}



int fpescar(string str)

{

	notify_fail("Este no parece un buen sitio para pescar.\n");

	return 0;

}
