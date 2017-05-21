/*          templo4.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 1-11-97
            Ultima modificacion : 13-11-01
	    [Nemesis]
	    [Jessy]    Castellanización del fichero, y cambio de las
	               descripciones del templo que antes era ermita.
            [Nemesis] Retocado el texto porque lo de la Biblia...
*/
#include <properties.h>
#include "./path.h"
inherit SIM_ROOM;

int altar;
string LookAltar();
string LookBible();

create() {
::create();
altar=0;
SetLocate("Cementerio de Nandor");
SetPreIntShort("frente a");
SetIntShort("el altar");
SetIntLong(
           "Estás frente al altar, detrás de él puedes ver unas escaleras que suben "
           "a la cámara superior.\n");
SetIndoors(1);
SetIntBright(20);

AddDetail("altar",SF(LookAltar));
AddDetail(({"libro","extraño libro","extranyo libro"}),SF(LookBible));
AddExit("sur","templo3");
AddExit("arriba","templo4u");
}

void init()
{
   ::init();
   add_action("MoveBible","mover");
}

int MoveBible(string str)
{
   if( (str == "libro") ||
       (str == "libro de Sharanna") ||
       (str == "libro falso")
     ) {
      write("Mueves el libro, y de repente el altar empieza a desplazarse...\n");
      tell_room(TO,TP->QueryName()+" hace algo en el "
                "altar y éste empieza a moverse...\n", ({TP}) );
      tell_room(TO,"¡¡¡RUMMMMMMMBLEEEEEEE!!!\n");
      TO->AddExit("abajo","/guilds/asesinos/gremio");
      altar=1;
      call_out("CloseEntrance",10);
      return 1;
   }
   else return 0;
}

void CloseEntrance()
{
   tell_room(TO,
   "El altar se mueve, y vuelve a su sitio. ¡¡¡RUMMMMMMMBLEEEEEEE!!!!\n");
   TO->RemoveExit("abajo");
   altar=0;
}

string LookAltar()
{
string mess;
   mess="Es un altar de mármol. Sobre él puedes ver un extraño libro.\n";
   if(altar==1)
      mess+="El altar parece estar fuera de su sitio.\n";
   return mess;
}

string LookBible()
{
string mess;
   mess="Parece un libro usado en el culto a Sharanna.\n";
   if(TP->QueryInt() > 29)
      mess+="¡Ey! ¡Ese libro es falso!\n";
   return mess;
}
