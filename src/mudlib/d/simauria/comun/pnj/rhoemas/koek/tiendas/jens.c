/***************************************************************************************
 ARCHIVO:	jens.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Jens, el panadero.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Jens el panadero","humano",12,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Jens");
  SetIds(({"humano","jens","Jens","panadero"}));
  Set(P_CANT_LURE,1);
  SetShort("Jens el panadero");
  SetLong(W("Jens es el panadero del pueblo, un humano de aspecto bastante "
  	"rudo y fuerte de tanto cargar con los sacos y cubos de agua que "
  	"utiliza para hacer el pan. Lleva un delantal lleno de harina que "
  	"le cubre bastante, pero eso no ha impedido que se manche por todas "
  	"partes. Tiene la barba muy rasurada y el pelo muy corto, puede que "
  	"para aguantar mejor el calor que hace en el horno.\n"));

  AddQuestion(({"panaderia","panadería","horno"}),W("Jens te dice: Esta es mi panaderia, "
  	"la heredé de mi padre cuando la construyó hace años. Cuando era "
  	"pequeño solía ayudar a mi padre en el horno, y a mi madre en la "
  	"venta del pan. ahora mi hijo me ayuda a mi... estoy muy orgulloso "
  	"de él.\n"),1);
  AddQuestion(({"hijo","geagan","Geagan"}),W("Jens te dice: Geagan es mi hijo, es un "
  	"muchacho aún pero fuerte como un roble, estoy seguro de que "
  	"algún día se encargará de maravilla de este comercio, es el mejor "
  	"hijo que podia haber tenido.\n"),1);
  AddQuestion(({"mujer","esposa","jynad","Jynad"}),W(
	"Jens te dice: Jynad es mi mujer, una esposa ejemplar que me ayuda en la panadería "
	"y que ha criado a nuestro hijo Geagan hasta convertirlo en un muchacho "
	"excepcional. La verdad es que tuve mucha suerte en encontrarla y aún "
	"la sigo queriendo como el primer día.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Jens te dice: Koek es el pueblo donde te encuentras. Fue fundado hace muchos años "
	"cuando el templo de Seri-Solderteg empezó a congregar pequeños "
	"comercios a su alrededor para abastecerse. Ahora es un pueblo muy, "
	"muy grande que tiene de todo.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Jens te dice: El bosque de cylin está al norte del templo de Seri-Solderteg. Es "
	"un lugar muy peligroso y confuso donde varias personas se han perdido "
	"y no se ha vuelto a saber de ellas. Por las noches se oyen ruidos "
	"de lo más extraño de todas las criaturas que viven allí. Dicen que "
	"hay alguien viviendo en él, pero yo creo que es solo un rumor, nadie "
	"sobreviviría allí más de cinco minutos.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Jens te dice: El templo de Seri-Solderteg es un lugar un tanto misterioso a pesar de "
	"que se puede visitar parcialmente. Allí los monjes se entrenan en las "
	"artes de la lucha y el ingenio e inteligencia para poder estar "
	"preparados en cualquier momento que se les requiera. Solo sé de ese "
	"sitio que nos pagan bien por el pan.\n"),1);
  AddQuestion(({"pan","hogaza","hogaza de pan","panes","hogazas de pan"}),W(
	"Jens te dice: El pan de esta panadería es el mejor del valle, hasta los conjuradores "
	"capaces de realizar el conjuro hogaza de pan vienen a comprar aquí en "
	"lugar de usar la magia... digo yo que será por algo. Tenemos muy buena "
	"fama, y solo trabajamos con los mejores ingredientes de la zona.\n"),1);
  AddQuestion(({"horario","abierto","cerrado","abrir","cerrar"}),W("Jens te dice: La panadería "
  	"está abierta de 8 a 20, pero yo estoy haciendo pan casi todo el día.\n"),1);
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
}
