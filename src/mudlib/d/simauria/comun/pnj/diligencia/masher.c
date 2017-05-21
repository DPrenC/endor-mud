/****************************************************************************
Fichero: /d/simauria/comun/pnj/diligencia/masher.c
Autor: Lug y Yalin
Fecha: 02/08/2006
Descripción: Conductor de la diligencia Masher
****************************************************************************/

inherit NPC;

create()
{
    ::create();
    SetShort("El conductor");
    SetLong("Es el conductor de la diligencia.\nEs un aldeano de la lejana aldea "
        "de Sloch, demasiado débil (o demasiado listo) para trabajar en los campos.\n");
    SetName("Rayshen");
    AddId(({"rayshen","Rayshen"}));
    SetRace("humano");
    SetLevel(20);
    SetAlign(10);
    SetGender(1);
}


