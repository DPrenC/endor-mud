/***************************************************************************************
 ARCHIVO:	mireba.c
 AUTOR:		[z] Zomax
 FECHA:		24-10-2001
 COMENTARIOS:	Mireba, la mujer del carnicero.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Mireba la carnicera","humano",10,GENERO_FEMENINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Mireba");
  SetIds(({"humana","mireba","Mireba","carnicera"}));
  Set(P_CANT_LURE,1);
  SetShort("Mireba la carnicera");
  SetLong(W("La mujer de Galonor, Mireba, es una humana de mediana edad "
  	"con el pelo rubio que ayuda a su marido en la carnicería. Tiene "
  	"el pelo recogido por una cinta naranja para que no le moleste al "
  	"trabajar, y unos guantes de acero para evitar posibles accidentes. "
  	"Además parece una experta en el manejo de los cuchillos.\n"));
  AddSubDetail(({"pelo"}),"Es rubio y muy tupido.\n");
  AddSubDetail(({"cinta","cinta naranja"}),W("Una bonita cinta naranja "
  	"que le ayuda a mantener el pelo fuera de la cara.\n"));
  AddQuestion(({"carniceria","carnicería"}),W("Mireba te dice: Esta carnicería la fundamos "
  	"mi marido y yo cuando nos mudamos a Koek. Desde entonces las cosas "
  	"nos han ido muy bien. Espero que siga así por muchos años.\n"),1);
  AddQuestion(({"hijo","broe","Broe"}),W("Mireba te dice: Broe es el niño mimado de la casa. "
  	"Hace unos meses que nació y ya ha conquistado el corazón de toda la casa. "
  	"Además es un niño muy tranquilo, no da nada de trabajo y no llora casi "
  	"nada. Eso es buena señal, tiene el carácter fuerte de su padre.\n"),1);
  AddQuestion(({"hija","adwel","Adwel"}),W("Mireba te dice: Adwel es nuestra hija mayor. "
  	"Siempre ha estado jugando y paseando con Geagan, el hijo de los "
  	"panaderos, pero ultimamente ven a escondidas. El otro día hablé con "
  	"la madre de Geagan y las dos nos contamos nuestras sospechas. Parece "
  	"que están enamorados y les preocupa lo que digamos, pero a nosotros "
  	"nos parece bien. No les hemos dicho nada porque así es más romántico, "
  	"además, si son listos ya sabrán que lo sabemos.\n"),1);
  AddQuestion(({"geagan","Geagan"}),W("Mireba te dice: Se le ve un chico mu templao, si no "
  	"fuera casada y tuviera su edad... um... me recuerda a mi marido "
  	"cuando era joven. Pero prefiero el que tengo en casa, el 'original'.\n"
  	"Mireba te guiña un ojo.\n"),1);
  AddQuestion(({"marido","esposo","galonor","Galonor"}),W("Mireba te dice: Galonor es mi "
  	"marido... es un buen hombre, y muy buen padre y marido. Además trabaja "
  	"como el que más. Somos muy felices juntos. Por cierto... ¿no me digas "
  	"que no parece un enano alto?.\nA Mireba se le saltan unas lágrimas de "
  	"tanto reirse.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Mireba te dice: Es un sitio precioso, tiene de todo: tiendas, lugares de culto, bosque, "
	"río, lago, campos...\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Mireba te dice: Es un sitio tenebroso... no te acerques a él. No quiero hablar de "
	"sitios así. Pregúntale a Froeker, el pescador.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Mireba te dice: El templo es el corazón de Koek, sin él no existiría nada aquí.\n"),1);
  AddQuestion(({"horario","abierto","cerrado","abrir","cerrar"}),W(
	"Mireba te dice: Abrimos la carnicería de 10 a 22.\n"),1);
  AddItem(RHOEWEA("koek/varios/cuchillo"),REFRESH_REMOVE,SF(wieldme));
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
  AddItem(RHOEARM("koek/varios/guantes"),REFRESH_REMOVE,SF(wearme));
}
