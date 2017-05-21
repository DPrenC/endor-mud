#include <properties.h>
inherit THING;

string contiene;
#define MAX_CARACTERES 4000
int escrito;

string describe()
{
    string estado;
    if (!escrito) estado = "Está en blanco.\n";
    else estado ="Hay algo escrito en él.";
    return "Es un rectángulo de pergamino de unos 20 por 30 centímetros, que suele usarse para escribir sobre él.\n"+estado;
}
    
create()
{
    ::create();
    AddId(({"papel","pergamino", "hoja", "hoja de pergamino", "to_write"}));
    SetShort("una hoja de pergamino");
    SetLong(SF(describe));
    SetValue(500);
    SetWeight(100);
    Set(P_SIZE,P_SIZE_SMALL);
}

init()
{
    ::init();
    add_action("cmd_leer", "leer");
    add_action("cmd_escribir", "escribir");
    add_action("cmd_romper", "romper");
}

int cmd_escribir(string str){
    if (escrito<1) contiene="";
    if (!str)
        return notify_fail("¿Qué quieres escribir?.\n");
    if (present("lapiz", TP)){
        if (escrito>(MAX_CARACTERES-2))
            return notify_fail("El pergamino está lleno por completo, no se puede escribir nada más en él.\n",
            NOTIFY_NOT_VALID);
        if ((escrito+strlen(str)) < MAX_CARACTERES){
            write("Escribes sobre el pergamino:\n"+str);
            say(CAP(TNAME)+ " escribe algo en una hoja de pergamino.\n",TP);
            if (escrito<1) contiene="";
            contiene += str + "\n";
            escrito += strlen(str);
            return 1;
        }
        return notify_fail ("No queda espacio en el pergamino para escribir tanto."
            " Sólo puedes escribir unos "+(MAX_CARACTERES-escrito)+" caracteres más "
            "o menos.\n", NOTIFY_NOT_VALID);
    }
    return notify_fail("Necesitas algo que escriba.\n",NOTIFY_NOT_VALID);
}

int cmd_leer(string str)
{
    if (!str) return notify_fail("Qué quieres leer?.\n");
    if (TO->id(str))
    {
        if (!escrito)
        {
            write("No hay nada escrito en el pergamino, está en blanco.\n");
            say(CAP(TNAME)+ " mira una hoja de pergamino en blanco.\n",TP);
            return 1;
        }
        else
            {
            write("En el pergamino puedes leer: \n"+contiene);
            say(CAP(TNAME)+ " lee atentamente una hoja de pergamino.\n",TP);
            return 1;
        }
    }
}

int cmd_romper(string str)
{
    if (!str) return notify_fail("¿Qué quieres romper?.\n");
    if (TO->id(str))
    {
        if (!present(TO, TP)) return notify_fail("No lo tienes en las manos.\n",
            NOTIFY_NOT_VALID);
        write("Rompes en pedazos la hoja de pergamino.\n");
        say(CAP(TNAME)+ " rompe en pedazos una hoja de pergamino.\n",TP);
        return remove();
    }
    else
    {
        return notify_fail("Mejor no rompas nada que no debas.\n");
    }
}
