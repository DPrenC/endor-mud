#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit SIM_ROOM;


int muick(string str)
{
    object ob;
    if (!str) return notify_fail("¿Ordeñar qué?\n",NOTIFY_NOT_VALID);
    if (str != "vaca")
    {
        return notify_fail(W("¿Seguro que lo que quieres ordeñar no es una "
                             "vaca?\n"),NOTIFY_NOT_VALID);
    }
    if(!present("vaca",TO))
    {
        return notify_fail(W("NO hay aquí ninguna vaca a la que puedas "
                             "ordeñar.\n"),NOTIFY_NOT_VALID);
    }
    if (!(ob=present("qbo",TP)) || ob->QueryOwner() != TNREAL)
    {
        if (present("cubo",TP) )
        {
            write("La vaca se resiste a que la ordeñes.\n"
                  "Parece que ese cubo no le ha hecho mucha gracia...\n");
            return 1;
        }
        return notify_fail(W("¿No crees que deberías buscar algún recipiente "
                             "donde verter la leche que ordeñes de la "
                             "vaca?\n"),NOTIFY_NOT_VALID);
    }
    write("Ordeñas la vaca... Es más difícil de lo que creías...\n"
          ".....................................\n"
          ".... La vaca muge lastimosamente.....\n"
          ".....................................\n"
          "....... Sigues ordeñando a la vaca.........\n"
          "Por fin, consigues llenar el cubo de leche fresca...\n");

    ob->remove();
    if (ob) destruct(ob);
    ob = clone_object(QUEST "granjero/cubo");
    ob->SetOwner(TNREAL);
    if (ob->move(TP,M_SILENT) != ME_OK)
    {
        write("Sin poder evitarlo, el cubo se te cae al suelo.\n");
        say(W("Sin poder evitarlo, a " + capitalize(TNAME) + " se le cae "
              "el cubo de leche al suelo.\n"));
        ob->move(environment(TP));
    }
    return 1;
}



create () {
  ::create();
Set(P_INT_SHORT,"una cuadra");
SetIntLong(
"Una enorme cuadra es el lugar en el que te encuentras. Los animales "
"te miran nerviosos al no reconocerte. Entre ellos encuentras un par "
"de caballos y un burro. Ademas puedes distinguir distintos utensilios "
"para manejar los animales.\n");

SetIndoors(1);
SetIntBright(30);

SetIntNoise("Lo unico que escuchas es el ruido de los animales.\n");
SetIntSmell("Un fuerte olor a animales de granja llega a tu nariz.\n");
SetLocate("Villa de Nandor");

AddRoomCmd("ordenyar",SF(muick));
AddRoomCmd("ordeñar",SF(muick)); //[Nyh] que con la ny se vuelven locos los PJ...
AddDetail(({"caballo","caballos"}),
"Son dos magnificos ejemplares que supones se destinan a reproduccion.\n");
AddDetail(({"burro"}),
"Es un terco animal que te dirige una mirada de indiferencia.\n");
AddDetail(({"utensilios","utensilio"}),
"Bocados, bridas, alguna silla de montar y un par de mantas es lo unico "
"que ves.\n");
AddExit("norte","../sendero2");
AddExit("este","../sendero1");
AddExit("oeste","../sendero3");
AddItem(QUEST "granjero/vaca",REFRESH_DESTRUCT,3);
}