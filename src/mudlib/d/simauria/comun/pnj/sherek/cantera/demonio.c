/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/cantera/demonio.c
Autor: Lug y Yalin
Fecha: 08/01/2007
Descripci�n: Demonio aleatorio para el �ltimo nivel del laberinto
****************************************************************************/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <moving.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    switch (d4())
    {
        case 1:
            SetStandard("un ni�o demonio","demonio",([ GC_LUCHADOR:24+d6() ]),GENERO_MASCULINO);
            SetShort("un ni�o demonio");
            SetLong("Es un peque�o demonio. Su cuerpo brilla con un color "
                "rojo oscuro incandescente. La cola larga con garras que "
                "nace de su espalda se agita en el aire amenazadoramente.\n"
                "Aunque es a�n un ni�o, no te f�es de su tama�o. Los "
                "demonios son muy agresivos.\n");
            AddId(({"ni�o","ninyo","ninyo demonio","ni�o demonio","demonio"}));
            SetAlign(-300);
            SetWhimpy(30); // es un ni�o, se resiste a morir
            AddItem(ARMA("sherek/cantera/barra"),REFRESH_REMOVE,1,SF(wieldme));
            InitAChats(10,({"El ni�o demonio te clava los dientes.\n",
                "El ni�o demonio ruge: �Quiero tu h�gado! Hace mucho que no "
                    "como buena carne.\n"}));
        break;
        case 2:
            SetStandard("una ni�a demonia","demonio",([ GC_LUCHADOR:24+d6() ]),GENERO_FEMENINO);
            SetShort("una ni�a demonia");
            SetLong("Es una peque�a demonia. Su cuerpo brilla con un color "
                "rojo oscuro incandescente. La cola larga con garras que "
                "nace de su espalda se agita en el aire amenazadoramente.\n"
                "Aunque es a�n una ni�a, no te f�es de su tama�o. Los "
                "demonios son muy agresivos.\n");
            AddId(({"demonia","ni�a","ni�a demonia","ninya","ninya demonia"}));
            SetAlign(-200);
            SetWhimpy(30); // es una ni�a, se resiste a morir
            AddItem(ARMA("sherek/cantera/cadena"),REFRESH_REMOVE,1,SF(wieldme));
            InitAChats(10,({"La ni�a demonia te clava los dientes.\n",
                "La ni�a demonia ruge: �Quiero tu coraz�n! Hace mucho que no "
                    "como buena carne.\n"}));
        break;
        case 3:
            SetStandard("un demonio","demonio",([ GC_LUCHADOR:44+d6() ]),GENERO_MASCULINO);
            SetShort("un demonio");
            SetLong("Naturalmente, es un demonio. Su cuerpo brilla con un "
                "color rojo oscuro incandescente. La cola larga con garras "
                "que nace de su espalda se agita en el aire amenazadoramente.\n\n");
            SetAlign(-500);
            AddItem(ARMA("sherek/cantera/cuchilla"),REFRESH_REMOVE,1,SF(wieldme));
            InitAChats(10,({"El demonio ruge: �Vas a morir! �Nunca saldr�s de aqu�!",
                "El demonio grita: �C�mo te atreves a entrar en nuestras cuevas?\n"}));
        break;
        case 4:
            SetStandard("una demonia","demonio",([ GC_LUCHADOR:44+d6() ]),GENERO_FEMENINO);
            SetShort("una demonia");
            SetLong("Es una demonia sucia y furiosa. Su cuerpo brilla con un "
                "color rojo oscuro incandescente. La cola larga con garras "
                "que nace de su espalda se agita en el aire amenazadoramente.\n\n");
            SetAlign(-400);
            AddId("demonia");
            AddItem(ARMA("sherek/cantera/hacha"),REFRESH_REMOVE,1,SF(wieldme));
            InitAChats(10,({"La demonia ruge: �Vamos a destriparte para cenar! �Nunca saldr�s de aqu�!",
                "La demonia grita: ��sta es mi casa! �L�rgate o muere!\n"}));
        break;
    }
    SetHP(QueryMaxHP());
    SetAggressive(1);
    SetGoChance(90);
    AddWalkZones(SHERCAN("fondo"));
}
