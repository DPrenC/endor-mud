/***************************************************************************************
 ARCHIVO:	templo_00.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Calle que lleva al templo
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Cendaf");
    carcel=(RHOEHAB("koek/calles/templo_01"));
    AddDetail(({"puerta","puertas","puertas del templo","puertas del Templo","templo",
      "Templo","templo de seri-solderteg","Templo de Seri-Solderteg","seri-solderteg",
      "Seri-Solderteg"}),
  	"Desde aquí ves el templo en toda su inmensidad. No parecía tan grande desde "
  	"el pueblo.\n");
    AddDetail(({"pueblo","koek","Koek"}),"Muy bonito... dan ganas de quedarse para siempre.\n");
    AddExit("templo",RHOEHAB("seri/piso00/centro/entrada"));
    AddExit("sur",RHOEHAB("koek/calles/templo_01"));
    AddItem(RHOEPNJ("koek/varios/peregrino"),REFRESH_DESTRUCT,2+random(3));


    map[neu,des]= "Estás a las puertas del Templo de Seri-Solderteg, al norte de "
  	"aquí. Al sur te adentras otra vez en el pueblo. Desde aquí el templo "
  	"parece mucho más grande de lo que te parecía en la lejanía. ";
}