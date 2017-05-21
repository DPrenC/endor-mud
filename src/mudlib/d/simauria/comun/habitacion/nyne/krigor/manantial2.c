/*
DESCRIPCION  : Manantial del norte de Krigor.
FICHERO      : KRIGOR("manantial2")
MODIFICACION : 27-11-01 [Chaos@Simauria] Creacion.

--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <messages.h>
#define SED 10 // puntos de sed que regenera por trago
#include <sounds.h>

inherit SIM_ROOM;


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
    SetIntShort("un manantial");
    SetIntLong("Te encuentras al lado de una pequeña fuentecilla natural de agua cristalina. "
    "Debajo hay un pequeño estanque donde cae el agua, del cual sale un fino "
    "chorro de agua que se filtra por entre las piedrecillas del suelo. A un lado "
    "ves unas altas montañas, al otro una pradera y hacia el noroeste ves la casa "
    "de algun ganadero de la zona.\n");
    AddDetail(({"fuente"}),"Es una fuente con un largo caño de piedra de la cual "
    "mana un fino chorro de agua fresca y cristalina que cae en el estanque.\n");
    AddDetail(({"estanque"}),"Es un estanque de piedra pulida. Es un poco tosca "
    "pero cumple su función perfectamente y tiene un pequeño agujero al final "
    "del cual sale el agua que se derrama. De aqui suelen beber las vacas.\n");
 AddDetail("agua",
        "El agua es fría y transparente, te dan ganas de bebértela. "
      "Seguro que te refresca y apaga tu sed.\n");
    AddDetail("chorro",
        "Es un fino hilillo de agua que cae en un estanque.\n");
    AddDetail(({"piedras","piedrecillas"}),
        "Son unas piedrecillas blancas que han sido alisadas por "
      "el paso del agua durante años.\n");
    AddDetail(({"montaña","montanya","montañas","montanyas"}),
        "Son unas escarpadas montañas que rodean todo el valle del "
      "pueblo de Krigor.\n");
    AddDetail(({"krigor","Krigor"}),
        "Es el típico pueblo de montaña, con diversas casas por los "
      "alrededores y una plaza donde se encuentran los edificios "
      "más significativos.\n");
    AddDetail("casa",
        "Es una casa de madera con el tejado de pizarra.\n");
 AddDetail(({"tejado","tejado de pizarra"}),
    "Sin duda está hecho así para que la nieve no se acumule "
      "sobre él en invierno y lo hunda.\n");
    AddDetail(({"flor","flores"}),
      "Son pequeñas y de diversos colores, dando alegría y color al prado.\n");
    AddDetail(({" pájaros"}),"Son los tipicos pajarillos de bonito canto, que alegran el lugar "
      "con su trinar.\n");
    SetSoundEnvironment(SND_AMBIENTES("manantial"));
    SetIntNoise("Se oye el trinar de los pájaros y el murmullo del agua del manantial.\n");
    SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
    SetLocate("Krigor");
    SetIndoors(0);


    AddExit("oeste",KRIGOR("prado10"));
    AddRoomCmd("beber","beber_cmd");
}
