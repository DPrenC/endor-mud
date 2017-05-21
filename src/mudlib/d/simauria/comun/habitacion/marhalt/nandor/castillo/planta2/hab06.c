/****************************************************************************
Fichero: hab06.c
Autor: Ratwor
Fecha: 29/03/2008
Descripción: La biblioteca del castillo.
****************************************************************************/

#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
public int escribible, escrito;
public int QueryEscribible() { return escribible; }
string contiene="";
#define MAX_CARACTERES 300
public string leer_pergamino();

public string mirar_pergamino(){
    if (!escrito)
        return "Es un trozo de pergamino en blanco que está clavado en la pared, "
        "posiblemente puesto ahí para escribir algo.\n";
        return "Es un trozo de pergamino clavado a la pared con cosas escritas.\n";
}

create() {
    ::create();
    escribible=1;
    SetIntShort("la biblioteca");
    SetIntLong(
    "Los libros cubren casi por completo las paredes de esta habitación, todas "
    "las estanterías están llenas de libros y manuscritos. Una pequeña mesa y "
    "una silla están dispuestos, para que los que utilicen los libros de esta sala, "
    "puedan sentarse y leer.\n En una de las paredes destaca un trozo de pergamino "
    "extendido y alisado.\n");
    SetIntBright(35);
    AddDetail(({"libros", "manuscritos"}),
    "Están llenos de polvo y un poco deteriorados.\n");
    AddDetail(({"pergamino", "trozo de pergamino", "papel"}), SF(mirar_pergamino));
    AddDetail(({"pared", "paredes"}), "Las paredes de esta estancia están empapeladas "
    "con un discreto papel gris claro. En una de las paredes llama la atención un "
    "trozo de pergamino clavado.\n");
    SetIntSmell("Huele profundamente a papel viejo.\n");
    SetIntNoise("Esta estancia está profundamente en silencio, como debe de ser "
    "en una biblioteca.\n");

    AddExit("oeste", "./pasillo5");
    AddDoor("oeste", "una puerta de madera",
    "Una puerta de madera para volver al pasillo.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del oeste"}));
    SetLocate("el castillo de Nandor");
    AddReadMsg(({"pergamino", "trozo de pergamino", "papel"}), SF(leer_pergamino));
    //AddRoomCmd("leer", "cmd_leer");
    AddRoomCmd("escribir", "cmd_escribir");
    AddRoomCmd("romper", "cmd_romper");
}

public int cmd_escribir(string str){
    if (escrito<1) contiene="";
    if (!str)
        return notify_fail("¿Qué quieres escribir?\n");
    if (present("carboncillo", TP)){
        if (escrito>(MAX_CARACTERES-2))
            return notify_fail("El pergamino está copmletamente escrito, no cabe nada "
            "más.\n", NOTIFY_NOT_VALID);
        if ((escrito+strlen(str)) < MAX_CARACTERES){
            write("Escribes en el trozo de pergamino de la pared:\n"+str);
            say(CAP(TNAME)+ " escribe algo en el trozo de pergamino de la pared.\n",TP);
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

public string leer_pergamino(){
    if (!escrito)
        return "No hay nada escrito en el pergamino de la pared , está en blanco.\n";
        return "En el trozo de pergamino de la pared puedes leer: \n"+contiene;
}

int cmd_romper(string str){
    if (!str)
        return notify_fail("¿Qué quieres romper?\n");
        return notify_fail("Mejor no rompas nada que no debas.\n");
}
