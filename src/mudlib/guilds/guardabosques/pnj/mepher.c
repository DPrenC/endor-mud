/****************************************************************************
Fichero: mepher.c
Autor: Ratwor
Fecha: 10/08/2006
Descripci�n: GuildMaster del gremio de guardabosques
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Mepher", "elfo", ([GC_GUARDABOSQUES:100]), GENDER_MALE);
    AddId(({"silvano", "guarda", "guardabosques", "elfo", "mepher"}));
    SetShort("Mepher el guarda");
    SetLong(
    " Mepher Es la m�xima autoridad entre los guardabosques, pero no sin esfuerzo se ha "
    "ganado su puesto.\n A pesar que es un elfo silvano, su apariencia f�sica demuestra "
    "poder y fuerza, sum�ndose a un importante dominio del entorno natural.\n  Quiz� "
    "haya perdido la belleza que les caracteriza a los de su raza debido a la dureza del "
    "bosque, pero la experiencia ganada merece el esfuerzo.\n  Ahora  �l es quien decide "
    "los ingresos de los nuevos miembros del gremio, y la evoluci�n de los mismos.\n"
    "Siempre lo puedes ver con su preciado arco a cuestas, y su poblada cabellera que le "
    "da apariencia m�s r�stica.\n");
    SetSmell("Huele a hierbas y otras sustancias del bosque.\n");
    AddSubDetail("arco", "Siempre lo podr�s ver con su m�s preciado objeto que es su "
    "gran arco de madera de �bano con s�mbolos tallados en sus bordes.\n   Su tama�o le "
    "proporciona tiros m�s largos con mejor precisi�n.\n");
    AddSubDetail(({"flechas", "flecha", "carcaj"}), "Su carcaj de piel de ciervo contiene "
    "siempre un buen pu�ado de buenas flechas.\n");
    AddSubDetail(({"ropa", "ropas", "uniforme"}), "Viste ropas de color verde oliva para "
    "pasar desapercibido en las profundidades del bosque.\n");

    InitChats(1, ({"Mepher tensa su arco concentrado.\n",
    "Mepher te mira inquietantemente.\n", "Mepher respira profundamente.\n",
    "Mepher te dice: si quieres saber sobre nuestro gremio, puedes leer libros "
    "interesantes en nuestra biblioteca.\n",
    "Mepher parece concentrado.\n"}));
    AddQuestion("gremio", "Mepher el guarda dice: este es el gremio que domina los "
    "elementos naturales y con el que podr�s moverte con m�s seguridad  por los bosques.\n");
    AddQuestion(({"bosque", "bosques"}), "Mepher dice:� ay!, los bosques, cuanta riqueza "
    "aguarda la naturaleza en ellos.\n  Nosotros nos sentimos seguros en sus profundidades "
    "porque formamos parte de sus elementos.\n");
    AddQuestion(({"elfo", "elfos"}), "Mepher dice: la raza elfa es la m�s bella de las "
        "razas, y de las m�s versatiles.\n  Nuestras mujeres son muy hermosas y "
        "nuestros hombres muy apuestos, sin contar nuestra inteligencia superior.\n");
        AddQuestion("lad-laurelin", "Mepher dice: Lad-laurelin es el dominio de los "
            "elfos.\n  Nuestras tierras y nuestros bosques est�n impecables porque ya "
            "nos encargamos nosotros que as� sea.\n  Limita al oeste con Kha-annu y "
            "al sudeste tenemos mar con su correspondiente puerto y los necesarios "
            "enlaces mar�timos con otras tierras.\n");
    SetShrugMsg("No se le ve con muchos �nimos de contestar a esa pregunta.\n");
    Set(P_CANT_FIGHT, 1);
    Set(P_CANT_STEAL, 1);
    Set(P_CANT_LURE,1);
}

