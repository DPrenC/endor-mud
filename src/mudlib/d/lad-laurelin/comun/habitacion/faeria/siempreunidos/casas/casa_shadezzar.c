/***
Fichero: casa_shadezzar.c
Autor: kastwey@simauria
Descripción: La casa de Shadezzar, el guardian de Faeria.
Creación: 07/12/2004
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("hab_siempreunidos");

int ir_bosquecillo();
string mirar_estanteria();

create()
{
    ::create();
    SetIntShort("la casa de Shadezzar");
    SetIntLong(W("Te encuentras en la casa de Shadezzar, el guardián del pueblo de Siempreunidos.\n"
    "Estás por así decirlo en la sala principal, que consta de una mesa con algunas sillas y un mueble con infinidad de libros apilados en numerosas filas.\n"
    "Al oeste está el dormitorio, al este la cocina, y al norte una puerta cerrada.\n"));
    SetOficina(HAB_PUESTO("calles/calle_04"));
    SetIndoors(1);
    SetIntBright(30);
    AddItem(PNJ_PUESTO("shadezzar"), REFRESH_HOME, 1);
    AddDetail(({"mueble", "libreria", "librería", "libros"}), SF(mirar_estanteria));
    AddDetail("mesa", "Es una mesa cubierta por un fino mantel. A su alrededor ves algunas sillas.\n");
    AddDetail(({"sillas", "silla"}), "Son algunas sillas colocadas alrededor de la mesa.\n");
    AddDetail("puerta","Es una puerta de metal. Está situada en la pared norte de la habitación.\n");
    AddExit("este", HAB_PUESTO("casas/cocina_shadezzar"));
    AddExit("oeste", HAB_PUESTO("casas/dormitorio_shadezzar"));
    AddExit("norte", SF(ir_bosquecillo));
    AddExit("sur", HAB_PUESTO("calles/calle_04"));
}
string mirar_estanteria()
{
    if (present("shadezzar", TO) && living(present("shadezzar", TO)))
    {
        if (member(present("shadezzar", TO)->QueryEnemies(), TP) != -1)
        {
            if (TP->SetCombatDelay(5+random(6)))
            {
              say(W("Cuando Shadezzar advierte que " + capitalize(TP->QueryName()) + " está distraid" + AO + ", le lanza un hechizo que l" + AO + " deja totalmente paralizad" + AO + ".\n"), TP);
              return     W("Es un mueble en el que puedes ver apilados infinidad de libros. Casi llega desde el suelo al techo.\n"
                "Cuando Shadezzar advierte que estás distraid" + AO + ", te lanza un hechizo, y notas como quedas totalmente paralizad" + AO + ".\n");
            }
            else
            {
              say(W("Cuando Shadezzar se da cuenta de que " + capitalize(TP->QueryName()) + " está distraid" + AO + ", le lanza un hechizo, aunque parece no afectarle en lo más mínimo.\n"), TP);
              return     W("Es un mueble en el que puedes ver apilados infinidad de libros. Casi llega desde el suelo al techo.\n"
                "Cuando Shadezzar advierte que estás distraid" + AO + ", te lanza un hechizo que parece no haberte afectado en lo más mínimo.\n");
            }
        }
        else if (member(RAZASENEMIGAS, TP->QueryRace()) != -1)
        {
            return W("Es un mueble en el que puedes ver apilados infinidad de libros. Casi llega desde el suelo al techo.\n"
            "Shadezzar te mira con mala cara y te dice hoscamente: Anda... Ahora va a resultar que los " + TP->QueryRace() + "s también se interesan por la literatura?\n");
        }
        else
        {
            return     W("Es un mueble en el que puedes ver apilados infinidad de libros. Casi llega desde el suelo al techo.\n"
            "Shadezzar te dice: ¿A que son preciosos? Todos esos libros son libros de magia y sobre todo de plantas. Adoro la naturaleza.\n"
            "Aah! - Dice mientras te señala uno de los libros: - Este es el libro del cuidado de los dragones... No me mires con esa cara..."
            "-Que no. - Te dice mientras sonríe - Solo tengo un pequeño pseudodragón. Ya no se encuentran dragones por aquí... Eso supongo que lo sabes.\n");
        }
    }
    else
    {
        return "Es un mueble en el que puedes ver apilados infinidad de libros. Casi llega desde el suelo al techo.\n";
    }
}


int ir_bosquecillo()
{
    if (TP->Fighting()) return write("Estás en mitad de una lucha. Si quieres dejar este lugar, lo mejor que puedes hacer es huir.\n"),1;
    if (present("guardian_siempreunidos",TO) && living(present("guardian_siempreunidos",TO)))
    {
        if (member(RAZASENEMIGAS,TP->QueryRace()) > -1)
        // es una raza enemiga
        {
            write(W("Shadezzar te mira con desprecio y te dice: ¿De verdad crees que voy a dejar pasar a un " + TP->QueryRace() + " a nuestro bosque?\n"));
            say(W("Shadezzar mira a " + capitalize(TP->QueryName()) + " con desprecio y le dice: ¿De verdad crees que voy a dejar pasar a un " + TP->QueryRace() + " a nuestro bosque?\n"),TP);
            return 1;
        }
        else if (TABLON_ENEMIGOS->QueryEnemies()[TP->QueryRealName()])
        {
        	  write("Shadezzar te lanza una mirada asesina y te grita: ¡crees que después de matar a alguno de los habitantes de nuestro pueblo te voy a dejar pasar a nuestro bosque?\n");
        	  say(W("Shadezzar le lanza a " + capitalize(TP->QueryName()) + " una mirada asesina y le grita: ¡Te crees que después de asesinar a alguno de nuestros habitantes te voy a dejar pasar a nuestro bosque?\n"),TP);
        	  return 1;
        }
        else if (TABLON_ENEMIGOS->QueryNonGratas()[TP->QueryRealName()])
        {
            write("Shadezzar te mira, te abre la puerta de mala gana y te dice: Anda. Piérdete de mi vista.\n");
            say(W("Shadezzar abre la puerta a " + capitalize(TP->QueryName()) + " de mala gana y le dice: Anda. Piérdete de mi vista.\n"),TP);
            return 1;
            }
        else
        {
            write(W("Shadezzar te abre la puerta y te dice:\n"
            "Ten cuidado en el bosque, no vayas a perderte.\n"));
            say(W("Shadezzar le abre la puerta a " + capitalize(TP->QueryName()) + " y le dice:\n"
            "Ten cuidado en el bosque, no vayas a perderte.\n"),TP);
        }
    }
    else
    {
        write("Abres la puerta, sales y vuelves a cerrar.\n");
        say(capitalize(TP->QueryName()) + " abre la puerta, sale y vuelve a cerrar.\n",TP);
    }
    if (TP->move(HAB_BOSQUE_PUESTO("bosque_01"),M_GO,"norte") != ME_OK) return write("Por alguna razón no puedes ir en esa dirección.\nConsulta con un wizard.\n"),1;
    return 1;
}
