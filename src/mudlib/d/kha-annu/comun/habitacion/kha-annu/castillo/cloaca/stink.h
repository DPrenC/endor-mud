// Coded by Kayra.
// Modificado por Izet@Simauria para implementar a Kha-annu.

#include <colours.h>

int x;

void init()
{
    call_out("pestazo",1);
    ::init();
}

pestazo()
{
    x=random(20);
    if (x>10)
	   {
        tell_object(TP, TC_BOLD"Te sientes mal.\n"TC_NORMAL);
        tell_room(environment(TP),TC_BOLD"El olor de este lugar es insoportable.\n"TC_NORMAL);
	   }
    if (x<10)
	   {
        tell_object(TP,TC_BOLD"Algo liquido cae sobre ti.\n"TC_NORMAL);
        say(TC_BOLD"Algo liquido cae sobre "+TP->QueryName()+".\n"TC_NORMAL,TP);
	   }
}
