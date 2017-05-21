/**************************************************************************
fichero: posadera.c
Autor: Riberales
Creación: 03/10/2005
Descripción: La mujer del posadero, en la plaza.
**************************************************************************/

#include "path.h"
#include <properties.h>
int es_amiga();
string chats();


inherit NPC;

public void create()
{
    ::create();
    seteuid(getuid());
    SetStandard("posadera","enano",18,GENDER_FEMALE);
    SetShort("la posadera");
    SetLong(W("Es la mujer del posadero de la ciudad, una enana rechoncha y "
              "bonachona que la mayor parte del tiempo está cuchicheando con "
              "sus dos amigas. Lleva un delantal para cuando tiene que "
              "atender las necesidades del negocio, aunque siempre está en la "
              "plaza.\n"));
    SetIds(({"posadera","la posadera","posadera_annufam"}));

    InitChats(3,SF(chats));
    AddItem(PROT_ANNUFAM("ciudad/delantal"),REFRESH_REMOVE,SF(wearme));
}

int es_amiga(object amiga)
{
    return amiga->id("amiga_posadera") && living(amiga);
}

string chats()
{
    int i = sizeof(filter(all_inventory(environment(TO)),SF(es_amiga)));
    if(!i)
    {
        return W("La posadera dice: Buenas forastero, si quieres alojamiento, "
                 "al este se encuentra mi posada.\n");
    }
    switch(random(4))
    {
        case 0:
            object moili;
            string generico = "La posadera dice: ¿Sabéis? Se ha alojado una "
                              "inquilina en la posada y todas las noches "
                              "llega un soldado, es muy sospechoso.\n";
            if((moili = present("moili_annufam")) && living(moili))
            {
                return W(generico + "\nMoili susurra: Pues cuando sepas algo más "
                         "nos lo cuentas.\n");
            }
            else return W(generico);
            break;
        case 1:
            return W("La posadera suspira: Buf, menos mal que de vez en "
                          "cuando puedo hacer una escapadita y hablar un rato "
                          + (i==1 ? "contigo" : "con vosotras")+ ".\n");
            break;
        case 2:
            object bleni;
            if ((bleni = present("bleni_annufam")) && living(bleni))
            {
                return W("La posadera dice: Con todos los enanos que hay ahí "
                         "dentro, a ver si espabilas, Bleni.\n\nBleni se "
                         "sonroja.\n");
            }
            else return W("La posadera suspira: Esta Bleni, a ver cuando se "
                          "nos espabila.\n");
            break;

        case 3:
            return W("La posadera dice: Buenas forastero, si quieres "
                     "alojamiento, al este se encuentra mi posada.\n");
            break;
    }

    return "La posadera dice: Buenas forastero, si quieres alojamiento, al este se encuentra mi posada.\n";
}
