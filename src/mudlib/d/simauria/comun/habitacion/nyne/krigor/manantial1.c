/*
DESCRIPCION  : Manantial del sur de Krigor.
FICHERO      : KRIGOR("manantial1")
MODIFICACION : 27-11-01 [Chaos@Simauria] Creacion.

--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <messages.h>
#include <moving.h>
#include <sounds.h>
#define SED 10 // los puntos de sed que da este manantial por cada grago

inherit SIM_ROOM;

int llenar_cmd(string str){
  string que,donde;
  object frasco_lleno,frasco_medicamento;
  if (!TP) return 0;
  if ((!str) || (sscanf(str,"%s del %s",que,donde)<2) ||
      (que!="frasco") || (donde!="manantial") )
	write("Tal vez deberías llenar frasco del manantial.\n");
  else {
	  while(frasco_medicamento = present("frasco_medicamento",TP)) {
	    write("Sumerges el frasco de cristal en el manantial y lo llenas de agua.\n");
	    tell_room(TO, ({ MSG_SEE, capitalize(TP->QueryName())+" llena un frasquito con un poco de agua del manantial.\n"}), ({ TP }));
	    frasco_medicamento->remove();
	    frasco_lleno=clone_object("/players/chaos/kuest/frascolleno");
	    frasco_lleno->move(TP, M_SILENT);
	    return 1;
	  }
	  write("Necesitas un frasco para llenarlo de agua.\n");
	  return 1;
  }
}
int beber_cmd(string str)
{
  string que,donde;
  int cantidad;
  object pl;

  if (!pl = TP) return 0;
  // Todos estos ifs se pueden meter en un if ("Un if para gobernarlos a todos...")
  if ((!str) || (sscanf(str,"%s del %s",que,donde)<2) ||
      (que!="agua") || (donde!="manantial"))
      write("Tal vez deberías beber agua del manantial.\n");
  else {
	if (!(cantidad = pl->AddDrink(SED)))
	{
        return notify_fail("No puedes beber más.\n", NOTIFY_NOT_VALID);
    }
    if (cantidad < SED)
    {
        write("Bebes hasta quedar saciad" + pl->QueryGenderEndString() + ".\n");
        say(CAP(NNAME(pl)) + " bebe agua del manantial.\n");
        return 1;
    }

    write("El agua te refresca apagando parte de tu sed.\n");
	tell_room(TO, ({ MSG_SEE, CAP(NNAME(pl)) +" bebe un poco de agua del manantial "
	                          "parece que se siente refrescad"+
	                          pl->QueryGenderEndString() +".\n"}), ({ pl }));
  }
return 1;
}


create() {
  ::create();
	SetIntShort("el manantial de agua del pueblo de Krigor");
	SetIntLong("Te encuentras dentro de una pequeña gruta en medio de las montañas.\n Debajo"
		  " de una piedra aparece un hilillo de agua, el cual se acumula"
		  " formando una pequeña charquita de agua fresca y clara.\n");

	SetIntNoise("Se oye el trinar de los pájaros y el murmullo del agua del manantial.\n");
	SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
	SetLocate("Krigor");

	AddDetail(({"montaña","montanya","montañas","montanyas","montana","montanas"}),
  		  "Estás dentro de ellas\n");
	AddDetail(({"gruta","pequeña gruta","pequenya gruta"}),
	          "Es una pequeña gruta natural, que se ha creado entre"
  		    " las montañas, debido a la erosión del agua.\n");
	AddDetail("agua",
	          "El agua es pura y cristalina, y surge de entre las rocas.\n");
	AddDetail(({"hilillo","hilillo de agua"}),
	          "Es una fina línea de agua que surge de entre "
		    "las rocas, la cual  va a parar a una charca.\n");
	AddDetail(({"rocas","roca"}),
	          "Son unas piedras de diversos tamaños y formas,"
	      	    " y de entre ellas surge un hilillo de agua.\n");
	AddDetail(({"charca","charquita", "charco"}),
	          "Es una charca de agua clara y fresca, donde se acumula "
  		    "el hilillo de agua que sale de entre las rocas.\n");
	AddDetail(({"pradera", "prado"}),
	          "Es un prado de hierba verde donde pastan las vacas.\n");
    SetSoundEnvironment(SND_AMBIENTES("manantial"));
	AddExit("sudeste",KRIGOR("prado03"));
	AddRoomCmd("beber","beber_cmd");
	AddRoomCmd("llenar","llenar_cmd");
}