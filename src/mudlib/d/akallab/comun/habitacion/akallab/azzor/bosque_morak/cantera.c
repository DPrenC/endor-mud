/*
DESCRIPCION  : base de la cantera al norte del bosque de Morak
FICHERO      : cantera.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create()
{
    ::create();
   SetIntShort("la cantera del bosque de Morak");
    SetIntLong("En la cantera del bosque de Morak.\n");
    AddDetail(({"cabanya","cabanyas","caba�a","caba�as"}),"En el l�mite "
        "oeste de la cantera se hallan construidas dos toscas caba�as de "
        "madera donde probablemente vivan los canteros que trabajan aqu�. "
        "Las caba�as son unas simples construcciones rectangulares hechas "
        "con troncos de madera y un sencillo tejado de barda.\n");
    AddDetail(({"barda","tejado de barda","tejado"}),"El tejado de las "
        "caba�as esta hecho de barda, un seto espinoso abundante en esta "
        "zona. Es un tejado sencillo y no muy bueno, pero es r�pido y barato "
        "de realizar.\n");
    AddDetail(({"cantera"}),"Te encuentras en la cantera del bosque de Morak. "
        "De esta cantera los orcos extraen los bloques de piedra que emplean "
        "en sus construcciones de piedra, principalmente fortalezas y "
        "murallas. La cantera en s� es una explanada de mediano tama�o junto "
        "a una gran pared rocosa al pie mismo de las monta�as de la "
        "cordillera de Kova.\n");
    AddDetail(({"bosque","bosque de Morak"}),"El bosque rodea la cantera.\n");
    AddDetail(({"marcas","huellas","suelo"}),"En el suelo arenoso de la "
        "cantera se pueden ver algunas de las huellas que a su paso por aqu� "
        "dejan las carretas cargadas con las pesadas piedras que se extraen "
        "de la cantera.\n");
    AddDetail(({"montanyas","monta�as","cordillera","cordillera de Kova","cumbres"}),
        "La cordillera de Kova es una alta cadena monta�osa que se halla al "
        "norte de este valle, formando as� su l�mite natural. Sus altas "
        "monta�as est�n cubiertas de nieve durante pr�cticamente todo el a�o "
        "y apenas si existen pasos en condiciones para atravesarlas.\nEl "
        "bosque de Morak se halla al pie de estas impresionantes cumbres.\n");
    SetIntNoise("Sopla una suave brisa desde el sur.\n");
    SetIntSmell("Huele a polvo de la piedra en el ambiente.\n");
    SetLocate("valle de Azzor");
    SetIndoors(0);
}
