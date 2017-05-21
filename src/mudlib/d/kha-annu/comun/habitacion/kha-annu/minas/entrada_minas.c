/**************************************************************************
fichero: entrada_minas.c
Autor: Riberales
Creación: 05/01/06
Descripción: Entrada de las minas.
**************************************************************************/


#include <moving.h>
#include "path.h"

inherit BASE_MINAS;



create()
{
    ::create();

    SetIntShort("la entrada a las minas");
    SetIntLong("Te hallas en la entrada a las minas enanas de Kha-annu. En la "
               "roca de la pared sur observas un cartel colgado, debajo de "
               "unas antorchas que alumbran el lugar. Al norte te parece "
               "divisar lo que aparenta ser un almacén, mientras que las "
               "minas propiamente dichas comienzan al oeste.\n");



    AddDetail("techo","El techo está lleno de salientes y algunas estalactitas, "
              "con lo que es relativamente sencillo que te des algún "
              "golpe.\n");

    AddDetail(({"roca","rocas"}),"Observas roca por doquier, es la base de las "
                "minas.\n");

    AddDetail(({"almacen","almacén","norte"}),
                "Supones que ahí almacenarán el mineral para luego "
                "transportarlo a la gran cámara del tesoro de Kha-annu.\n");


    AddDetail(({"pared","paredes"}),
                "Las paredes son de roca y en esta parte de las minas "
                "no parece que se haya explotado nada, supones que por ser la "
                "entrada.\n");


    AddDetail("suelo","El suelo está muy gastado, pues esta será la zona más "
              "transitada de las minas.\n");

    AddDetail("cartel","Es un viejo y carcomido cartel de madera, quizá "
              "deberías leerlo.\n");

    AddReadMsg("cartel",
               "|||||||||||||||||||||||||Las Grandes Minas de Kha-annu|||||"
               "||||||||||||||||||||\n\n"
               "Estas minas pertenecen al reino de Kha-annu y a su señor, el "
               "rey Belthain. Queda totalmente prohibida la explotación de "
               "las mismas a todo individuo que no tenga el beneplácito "
               "de nuestro señor. Si algún individuo es descubierto "
               "intentando picar o tratando de salir de las minas "
               "con mineral, será inmediatamente ajusticiado por nuestra "
               "guardia.\n\nEl pueblo enano de Kha-annu.\n");

    SetIntNoise("Escuchas de fondo algún pico estampándose contra la roca de "
                "estas minas.\n");

    SetIntSmell("Hueles el combustible quemado proveniente de las antorchas.\n");
    DetalleAntorchas();


    AddItem(PNJ_MINAS("romli"),REFRESH_DESTRUCT);
    AddItem(PNJ_MINAS("jefe_hierro"),REFRESH_DESTRUCT);
    AddItem(PNJ_MINAS("jefe_plata"),REFRESH_DESTRUCT);
    AddItem(PNJ_MINAS("jefe_mithril"),REFRESH_DESTRUCT);

    AddExit("este",CAM_KHA_KEN("entra_mina"));
    AddExit("oeste",HAB_PRIMERA_MINAS("minas01"));
    AddExit("norte",(: write("La entrada al almacén sólo está permitida a los "
                              "trabajadores de la mina.\n"); return 1;:));
}




public void notify_enter(mixed from, int method, mixed extra)
{
    ::notify_enter(from,method,extra);
    if (!PO || method != M_GO || extra != "oeste") return ;

    tell_object(PO,"Comienzas a descender hacia las minas.\n");
    return ;
}

public int prevent_leave(mixed to, int method, mixed extra)
{

    object prev = PO || TP;

    if (prev && method == M_GO && extra == "este" && !query_wiz_level(prev))
    {
        object *mineral;
        object *guardia = filter(all_inventory(),
                         (:$1->id("guardian_minas") && living($1):));
        object *inv = deep_inventory(prev);

        if (sizeof(guardia) &&
            sizeof(mineral = filter(inv,(:$1->id("mineral"):))))
        {
            if (prev->QueryRace() == "enano")
            {
                tell_object(prev,"Un guardia te corta el paso y empieza a "
                      "cachearte. Cuando encuentra el mineral que llevabas "
                      "encima, te dice: ¿Has olvidado pasar por el "
                      "almacén?\n");
                tell_room(TO,"Un guardia le coge el mineral a "+CAP(prev->
                             QueryName())+" y lo mete en el almacén.\n",({prev}));
                mineral->Remove();
                return ME_NO_LEAVE;

            }

            tell_object(prev,"El guardia te coge, y antes de que te puedas "
                  "dar cuenta, te cachea y te quita todo el mineral que "
                  "habías conseguido. Te mira y grita: ¡Nadie osa intentar "
                  "robar en nuestras minas sin haber probado las hachas de nuestra "
                  "guardia!\n");
            tell_room(TO,"el guardia cachea a "+ CAP(prev->QueryName())+
                         " antes de dejarle salir, y al descubrir el mineral, "
                         "comienza a atacarle.\n",({prev}));
            mineral->remove();
            guardia->Kill(prev);
            return ME_NO_LEAVE;

        }
    }
    return ::prevent_leave(to,method,extra);
}


public void notify_leave(mixed to,int method,mixed extra)
{

    object prev;
    if ((prev = PO) && living(prev) && method == M_GO && extra == "este" && !query_wiz_level(prev))
    {
        object *guardia = filter(all_inventory(),
                                 (:$1->id("guardian_minas") && living($1):));
        if (sizeof(guardia))
        {
            tell_object(prev,"Un guardia te cachea antes de dejarte salir.\n");
            tell_room(TO,"Un guardia cachea a "+CAP(NNAME(prev))+
                         " antes de dejarle salir.\n",({prev}));
        }

        tell_object(prev,"Comienzas a ascender hacia el exterior de las "
                        "minas.\n");
        return ::notify_leave(to,method,extra);;
    }

    if (prev && method == M_GO && extra == "oeste")
    {
        tell_object(prev,"Te diriges hacia el oeste y comienzas a descender una "
                       "pronunciada pendiente que se precipita hacia el "
                       "primer nivel de las minas.\n");

    }
    return ::notify_leave(to,method,extra);;
}
