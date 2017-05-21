/*
   Habitacion base para control de hongos en Kha-annu
   Por Heimy
   Modificaciones:
     19 Ene, 1998: Descripcion
      5 Feb, 1998: La habitacion controla el numero de hongos y su duracion
     18 Feb, 1998: Modificaciones para poder heredar la habitacion
*/

#include "path.h"
#define THIS TO
inherit KHA_ROOM;
int hongos;
string longdesc, strhon;

create()
{
    ::create();
    longdesc = QueryLong();
}

init()
{
    ::init();
    AddDetail(({"hongo","hongos"}),"Los hongos brillan con una tenue luz azulada. Parece que "
        "los pudieras coger.\n");
    add_action("HazCoger", "coger");
}

public void Describe()
{
    strhon = "Ves en la pared ";
    switch (hongos)
    {
        case 5:
            strhon = strhon + "cinco hongos que puedes coger.\n";
        break;
        case 4:
            strhon = strhon + "cuatro hongos que puedes coger.\n";
        break;
        case 3:
            strhon = strhon + "tres hongos que puedes coger.\n";
        break;
        case 2:
            strhon = strhon + "dos hongos que puedes coger.\n";
        break;
        case 1:
            strhon = strhon + "un hongo que puedes coger.\n";
        break;
        case 0:
            strhon = "No ves hongos en las paredes.\n";
        break;
        default:
            strhon = strhon + "varios hongos que puedes coger.\n";
        break;
    }
    SetIntLong(longdesc + strhon);
}

public void HazApagado(object hon)
{
    int luz;
    luz = hon->QueryLight();
    hon->CambiaLuz(luz - 1);
    luz = luz - 1;
    if (luz > 0)
    {
        switch(luz)
        {
            case 40:
    	           tell_object(environment(hon), "Al hongo le queda poco.\n");
   	        break;
    	       case 10:
    	           tell_object(environment(hon), "El hongo está en las últimas!\n");
   	        break;
        }
        call_out("HazApagado", 2, hon);
    }
    else
    {
        tell_object(environment(hon), "Te has quedado sin hongo...\n");
        hongos++;
        Describe();
        tell_room(THIS, "Ha crecido un nuevo hongo en la pared.\n");
        hon->remove();
    }
}

public int HazCoger(string str)
{
    object hongo;
    if (!hongos)
    {
        write("No quedan mas hongos\n");
        tell_room(THIS, TP->QueryName() + " intenta coger un hongo... Pero no "
            "queda ninguno!\n", ({TP}) );
        return 1;
    }
    if (str == "hongo")
    {
        hongos--;
        Describe();
        hongo = clone_object(OTRO("hongo"));
        hongo->move(TP);
        write("Has cogido un hongo luminoso.\n");
        tell_room(THIS, TP->QueryName() + " coge un hongo de la pared.\n",({TP}) );
    	   call_out("HazApagado", 60, hongo);
        return 1;
    }
    if (str == "hongos")
    {
        write("El guardia dice:  No seas avaricioso! Solo uno por vez!\nHas cogido un hongo "
            "luminoso.\n");
        tell_room(THIS, "El guardia reprende a " + TP->QueryName() + " por avaro.\nNo se debe "
            "coger mas de un hongo a la vez!\n", ({TP}) );
        return 1;
    }
    return 0;
}
