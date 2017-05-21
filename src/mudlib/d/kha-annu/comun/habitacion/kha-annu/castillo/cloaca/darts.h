// Coded by Kayra.
// Modificado por Izet@Simauria para implementar a Kha-annu.

#include <colours.h>

int x,y,z;
string *cuerpo;

void init()
{
    call_out("dardazo",1);
    ::init();
}

dardazo()
{
    cuerpo=({"cuello","cabeza","torso","flanco derecho","flanco izquierdo",
    	   "espalda"});
    x=TP->QueryDex();
    y=random(8)+2;
    z=random(5);
    tell_room(environment(TP),"De repente oyes un sonido cortando el viento y "+y+" dardos "
        "salen disparados de las paredes");
    if ((x-y) > 2)
    {
        tell_object(TP,"..., pero ágilmente logras esquivarlos.\n"TC_NORMAL);
        say("..., pero "+TP->QueryName()+" logra esquivarlos con agilidad.\n",TP);
    }
    if ((x-y) <= 2)
    {
        z=random(5);
        tell_object(TP,"..., y se clavan en tu "+cuerpo[z]+".\n");
        say("..., pero "+TP->QueryName()+" no logra evitarlos del todo, y se clavan en su "+
            cuerpo[z]+".\n"TC_NORMAL,TP);
        if (x==2)
        {
            tell_object(TP, TC_BOLD"Te falla la vista... y te sientes mucho mas débil.\n"TC_NORMAL);
       	    TP->SetHP(TP->QueryHP()-50);
        }
        else TP->SetHP(TP->QueryHP()-10);
    }
}
