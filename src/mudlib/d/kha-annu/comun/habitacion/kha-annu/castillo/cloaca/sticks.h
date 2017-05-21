// Coded by Kayra.
// Modificado por Izet@Simauria para implementar a Kha-annu

int x,y;

#include "./path.h"

void init()
{
    call_out("estacazo",1);
    ::init();
}

estacazo()
{
    x=TP->QueryDex();
    y=random(10);
    if ((x-y)>1)
	   {
        write("El suelo se rompe bajo tus pies, pero ágilmente logras evitar caer.\n");
        say("El suelo se rompe bajo los pies de "+TP->QueryName()+", pero ágilmente logra "
            "evitar la caída.\n",TP);
	   }
    if ((x-y)<2)
    {
        write("De repente el suelo se rompe bajo tus pies, y caes en un foso de estacas.\n");
        say("¡Repentinamente el suelo se rompe y "+TP->QueryName()+" cae en un foso de estacas!\n",TP);
        TP->SetHP(TP->QueryHP() - (x+y) );
    }
}
