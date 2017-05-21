/*****************************************************************************************
 ARCHIVO:       ruergh.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCI�N:   Ruergh, el protector de la reina.
 COMENTARIOS:   A�adir hechizos...
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>
#include <colours.h>

inherit NPC;

public string fun_msgs();

create()
{
    if(::create()) return 1;

    SetStandard("ruergh", "duende", ([GC_CONJURADOR: 40]), GENERO_MASCULINO);
    AddId(({"protector", "protector de la reina"}));
    SetShort("ruergh, el protector de la reina");
    SetLong("Ruergh, es un peque�o ser, invocado con extra�as artes, con ramas y "
        "flores por todas partes, que sirve a la reina Twyligh como protector...\n");
    InitChats(4,
            ({SF(fun_msgs),
              "Ruergh se hurga la nariz, cuando piensa que no le ves.\n",
              "Ruergh se rasca la espalda.\n"
              "El Protector de la Reina no te quita la mirada de encima ni por un "
              "instante.\n"}));
}

public string fun_msgs()
{
    object reina;

    //Si la reina est� en la habitaci�n...
    if ((reina = present("reina_faeria")) && living(reina))
        return TC_TEL_WHO + "Ruergh dice:" + TC_TEL_MSG + " No molest�is a Su Alteza con "
               "tonter�as.\n" + TC_NORMAL;
    return TC_TEL_WHO + "Ruergh dice:" + TC_TEL_MSG + " Tengo que vengar el honor de "
           "todas las hadas.\n" + TC_NORMAL;
}

//Para que defienda a la reina:

public int QueryIsProtected() { return 1; }
