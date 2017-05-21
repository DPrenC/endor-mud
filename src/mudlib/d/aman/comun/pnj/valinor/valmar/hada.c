/*****************************************************************************************
 ARCHIVO:       hada.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCI�N:   Una hada traviesa.
 COMENTARIOS:   tendr� que hacer travesuras...
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un hada traviesa", "duende", ([GC_CONJURADOR: 25]), GENERO_MASCULINO);
    AddId(({"hada", "hada traviesa"}));
    SetShort("un hada traviesa");
    switch(d2())
    {
        case 1:
             SetLong("Por orden de su reina, esta hada se burla de todos aquellos que "
                 "se infiltran en el bosque, para espantarlos de aqu� lo m�s r�pido "
                 "posible...\n");
             break;
        case 2:
             SetLong("Se te hace dif�cil poder observar a esta peque�a criatura, ya "
                 "que cuando la miras, se va volando tan rapidamente que s�lo puedes ver "
                 "su estela de brillante polvo de hadas.\n");
             break;
    }

    InitChats(4,
          ({"Un hada diminuta te est� mirando desde que te vi�. Parece que cuando te "
            "mira, se rie... �Divertido, no?\n",
            "Un hada revolotea gracilmente, flota un poco y revolotea otra vez para "
            "perderse de nuevo de vista...\n"}));
}
