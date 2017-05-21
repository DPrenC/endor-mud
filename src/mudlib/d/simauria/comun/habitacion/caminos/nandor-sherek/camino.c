/*****
archivo:        /d/simauria/comun/habitacion/caminos/nandor-sherek/camino.c
Descripción: Habitación base para el camino de Nandor a Sherek.
Autores:        Yalin y Lug.
Fecha:      01/05/2006
*/

#include "path.h"
inherit SIM_ROOM;

private void DescCorta()
{
    SetIntShort("el camino de Nandor a la abadía de Sherek");
}

private void DescLarga()
{
    switch (d6())
    {
        case 1:
            SetIntLong("Estás caminando por una polvorienta senda que "
                "conecta la lejana abadía de Sherek con la aldea de Nandor. "
                "Sobre tu cabeza se entrecruzan a lo alto las ramas de "
                "algunos grandes árboles.\n");
        break;
        case 2:
            SetIntLong("Avanzas por un largo camino que une la aldea de "
            "Nandor a través de su bosque, con la abadía de Sherek. A los "
            "lados puedes ver grandes árboles que crecen delimitándolo "
            "impidiendo el paso en cualquier otra dirección que no sea el "
            "propio camino.\n");
        break;
        case 3:
            SetIntLong("Andas por el viejo camino que une Nandor con las "
                "montañas de Sherek y su gran Abadía. Los árboles te impiden "
                "salir campo a través, pero, en los días de calor ofrecen una "
                "agradable sombra al viandante, y cuando hace viento, lo "
                "resguardan de él.\n");
        break;
        case 4:
            SetIntLong("Recorres un largo camino que cruza los bosques desde "
                "Nandor hasta la abadía de Sherek. Grandes árboles crecen en "
                "sus márgenes impidiéndote salir de él.\n");
	       break;
        case 5:
            SetIntLong("El camino por el que te desplazas se extiende a lo "
                "largo de los bosques de Simauria uniendo la pequeña aldea de "
                "Nandor con la abadía de Sherek que se encuentra muy al "
                "norte en las montañas. Sobre ti puedes ver las copas de "
                "grandes árboles entrecruzándose.\n");
        break;
        case 6:
            SetIntLong("Caminas entre grandes árboles por una larga senda "
                "que une la abadía de Sherek, en las montañas, con la "
                "pequeña aldea de Nandor. No puedes caminar en otra "
                "dirección que no sea el propio camino.\n");
        break;
    }
}

private void Olores()
{
    switch (d6())
    {
        case 1:
            SetIntSmell("Huele a foresta.\n");
        break;
        case 2:
            SetIntSmell("Huele bastante bien. ¡Te gusta!.\n");
        break;
        case 3:
            SetIntSmell("Huele a campo.\n");
        break;
        case 4:
            SetIntSmell("Un agradable olor a vegetación lo llena todo.\n");
        break;
        case 5:
            SetIntSmell("Hmmmm..., sientes la fragancia de los bosques.\n");
        break;
        case 6:
            SetIntSmell("El olor de las plantas que te rodean está por todas "
                "partes.\n");
        break;
    }
}

private void Sonidos()
{
    switch (d6())
    {
        case 1:
            SetIntNoise("Oyes el gorjeo de las aves en la espesura.\n");
        break;
        case 2:
            SetIntNoise("Puedes oír el canto de los pájaros en las ramas y el zumbar de los insectos.\n");
        break;
        case 3:
            SetIntNoise("Escuchas los sonidos de la naturaleza a tu alrededor.\n");
        break;
        case 4:
            SetIntNoise("Puedes escuchar los sonidos de los animales entre "
                "la maleza.\n");
        break;
        case 5:
            SetIntNoise("Oyes el piar de los pájaros en lo alto de los árboles.\n");
        break;
        case 6:
            SetIntNoise("Escuchas el sonido de la vida que discurre a tu alrededor.\n");
        break;
    }
}

private void Detalles()
{
    switch (d6())
    {
        case 1:
            AddDetail(({"suelo", "camino"}), "Al mirarlo ves diferentes "
                "huellas por todas partes.\n");
            AddDetail(({"huella", "huellas"}), "Son marcas de cascos de "
                "cabalgaduras y de ruedas de algún tipo de carruaje que te "
                "indican que este ccamino es transitado.\n");
            AddDetail(({"arboles", "árboles"}), "Son imponentes árboles que "
                "nacen a ambos lados del camino.\n");
        break;
        case 2:
            AddDetail(({"suelo", "camino"}), "Multitud de huellas se "
                "extienden por todas direcciones.\n");
            AddDetail(({"huella", "huellas"}), "Son marcas dejadas por "
                "monturas y carretas que a menudo pasan por aquí.\n");
            AddDetail(({"arboles", "árboles"}), "Hay grandes árboles que se "
                "entrecruzan a lo alto sobre tu cabeza.\n");
        break;
        case 3:
            AddDetail(({"suelo", "camino"}), "Ves huellas en toda su "
                "superficie.\n");
            AddDetail(({"huella", "huellas"}), "Puedes ver marcadas las "
                "huellas de rodaduras y cascos de caballos.\n");
            AddDetail(({"arboles", "árboles"}), "Inmensos árboles que te "
                "impiden ir en cualquier otra dirección que no sea el camino.\n\n");
        break;
        case 4:
            AddDetail(({"suelo", "camino"}), "Aquí y allá puedes encontrar "
                "infinidad de huellas marcadas en el camino.\n");
            AddDetail(({"huella", "huellas"}), "Fueron hechas, seguramente,  "
                "por cabalgaduras y por ruedas de carros.\n");
            AddDetail(({"arboles", "árboles"}), "Son muchos árboles que "
                "forman la espesura más allá del camino en el que estás.\n");
        break;
        case 5:
            AddDetail(({"suelo", "camino"}), "Al mirar adviertes que hay "
                "muchas huellas marcadas sobre el camino.\n");
            AddDetail(({"huella", "huellas"}), "Bastantes de las que ves "
                "están casi borradas por el viento y la lluvia, pero "
                "adviertes que han sido hechas por caballos y carretas.\n");
            AddDetail(({"arboles", "árboles"}), "Hay gruesos árboles que "
                "alzan sus ramas hacia el cielo en las lindes del camino.\n");
        break;
        case 6:
            AddDetail(({"suelo", "camino"}), "Ves las huellas de "
                "cabalgaduras y viandantes que usan este camino.\n");
            AddDetail(({"huella", "huellas"}), "Ves simples marcas del paso "
                "de la gente y de sus animales por este camino.\n");
            AddDetail(({"arboles", "árboles"}), "Simples árboles de muchos "
                "tipos, como en tantos otros lugares.\n");
        break;
    }
}
public void Bichejo()
{
    if (!random(3))
    {
        switch (d6())
        {
            case 1:
                AddItem(PNJ("sherek/ardilla"), REFRESH_DESTRUCT,1);
                break;
            case  2:
                 AddItem(PNJ("sherek/conejo"), REFRESH_DESTRUCT,1);
                break;
            case 3:
                AddItem(PNJ("sherek/ciervo"), REFRESH_DESTRUCT,1);
                break;
            case 4:
                AddItem(PNJ("sherek/lobo"), REFRESH_DESTRUCT,1);
                break;
            case 5:
                AddItem(PNJ("sherek/serpiente"), REFRESH_DESTRUCT,1);
                break;
            case 6: break;
        }
    }
}


create()
{
    ::create();
    if (!random(4))
    {
        AddItem("/d/simauria/comun/pnj/camino/aveboske",REFRESH_REMOVE,0+d2());
    }

    SetIndoors(0);
    SetLocate("Camino de Nandor a la abadía de Sherek");
    DescLarga();
    DescCorta();
    Olores();
    Sonidos();
    Detalles();
}
