/***************************************************************************************
 ARCHIVO:	galonor.c
 AUTOR:		[z] Zomax
 FECHA:		22-10-2001
 COMENTARIOS:	Galonor, el carnicero.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Galonor el carnicero","humano",13,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Galonor");
  SetIds(({"humano","galonor","Galonor","carnicero"}));
  Set(P_CANT_LURE,1);
  SetShort("Galonor el carnicero");
  SetLong(W("Galonor es el carnicero, un humano pelirrojo que tiene el "
  	"cuerpo cubierto de pecas y un pelo m�s rojo que el mismo infierno. "
  	"Adem�s tiene una generosa barba del mismo color que, de no ser por "
  	"su enorme estatura le har�a parecer el m�s t�pico de los enanos de "
  	"Kha-annu.\n"));

  AddSubDetail(({"barba","pelo"}),W("Tiene la barba m�s roja que has visto en tu vida, y el "
  	"resto del pelo no se queda atr�s.\n"));
  AddSubDetail(({"peca","pecas"}),"Te preguntas c�mo es posible que tenga tantas pecas...\n");
  AddQuestion(({"carniceria","carnicer�a"}),W("Galonor te dice: Fund� esta carnicer�a con mi mujer cuando "
  	"nos casamos hace ya muchos a�os. Aqu� he criado a mis hija Adwel, "
  	"y espero hacer lo mismo con mi nuevo hijo Broe. La verdad es que por "
  	"ahora las cosas nos han ido muy bien. Espero que sigan igual.\n"),1);
  AddQuestion(({"hija","adwel","Adwel"}),W("Galonor te dice: Adwel es mi hija mayor. Es una "
  	"chica muy aplicada, aunque parece que no le gusta eso de ser "
  	"carnicera. Ya me ha sugerido varias veces que le deje el negocio "
  	"a Broe, ahora que tengo otro hijo. La verdad es que no se si ha "
  	"sido ella o nosotros los que nos hemos puesto m�s contentos con "
  	"el nacimiento.\n"),1);
  AddQuestion(({"mujer","esposa","mireba","Mireba"}),W("Galonor te dice: Mireba es mi mujer. "
  	"La conoc�a hace muchos a�os cerca de Kha-annu, me estaba mirando con "
  	"curiosidad, porque pensaba que era un enano, por mi aspecto pelirrojo "
  	"y robusto, y me lleg� a preguntar c�mo era posible que un enano fuera "
  	"tan alto. Casi me ahogu� de la risa y la verg�enza que pas�, hasta que "
  	"le consegu� explicar que tambi�n hay humanos pelirrojos y robustos en "
  	"Kha-annu, adem�s de enanos, entonces fue ella la que se puso m�s roja "
  	"que mi barba, y desde entonces cada vez que nos ve�amos nos poniamos "
  	"los dos de ese color, hasta que tuve el valor de pedirle en matrimonio.\n"),1);
  AddQuestion(({"hijo","broe","Broe"}),W("Galonor te dice: Broe es mi nuevo hijo, tiene s�lo unos "
  	"meses, pero se le ve muy despierto, espero que muestre algo de inter�s "
  	"por el negocio y decida encargarse de �l cuando sea mayor. Por ahora "
  	"no hace gran cosa, salvo mirar a todas partes, pero ya aprender�.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Galonor te dice: Koek es un lugar perfecto para instalarse cuando quieres progresar en "
	"un negocio nuevo. Hay muchos clientes y todos nos conocemos y respetamos, "
	"aunque ultimamente est� habiendo algunos robos.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Galonor te dice: Cylin es el bosque que hay al norte del templo. Yo de ti no entrar�a, "
	"dicen que los que se han adentrado no han vuelto, creo que los padres "
	"de Zaesh, el nieto del Froeker, el pescador, fueron al bosque. Desde "
	"entonces no han vuelto, y Froeker y su mujer, Kaewin, se han tenido "
	"que ocupar de �l.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Galonor te dice: El templo es en cierto "
  	"modo el que nos mantiene a todos. No se lo que hacen dentro, ni me "
  	"importa. Lo que importa es que sin el templo de Seri-Solderteg Koek no "
  	"existir�a.\n"),1);
  AddQuestion(({"horario","abierto","cerrado","abrir","cerrar"}),W("Galonor te dice: Abrimos "
  	"la carnicer�a de 10 a 22.\n"),1);
  AddItem(RHOEWEA("koek/varios/cuchillo"),REFRESH_REMOVE,SF(wieldme));
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/varios/guantes"),REFRESH_REMOVE,SF(wearme));
}
