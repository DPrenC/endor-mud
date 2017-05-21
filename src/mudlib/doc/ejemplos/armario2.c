/****************************************************************************
Fichero: armario
Autor: Buh
Fecha: 09/07/2006
Descripción: un armario par aprobar las closures
simplemente para mirar código, para usarse habría que ponerle sonido, descripción de
múltiples objetos a las tablas, y quizá convertir el armario en contenedor.
****************************************************************************/

#include <properties.h>


inherit THING;

private int abierto;

public int cmd_abrir(string str)
{
if (str=="armario" || str=="armario verde")
    {
        if (abierto==0)
        {
            write ("Abres el armario.\n");
            say (CAP (TP->QueryRealName()) + " abre el armario.\n");
            abierto=1;
            return 1;
            }
else
{
return notify_fail("Ya está abierto.\n", NOTIFY_NOT_VALID);
}
}
{
return notify_fail("¿Qué quieres abrir?.\n", NOTIFY_NOT_VALID);
}
}

public int cmd_cerrar(string str)
{//a
if (str=="armario" || str=="armario verde")
{//b
if (abierto==1)
{//c
write ("Cierras el armario.\n");
say (CAP(TP->QueryRealName()) + " Cierra el armario.\n");
abierto=0;
return 1;
}//C
else
{//d
return notify_fail("El armario ya está cerrado.\n", NOTIFY_NOT_VALID);
}//D
}//b
{//e
return notify_fail ("¿Qué quieres cerrar.?\n", NOTIFY_NOT_VALID);
}//e
}//a

public int cmd_empujar(string str)
{
    if (str=="armario" || str=="armario verde")
    {
        object tablas;
        write ("Le das un fuerte empujón al armario y este se desploma al suelo "
        "destrozándose por completo y convirtiéndose en un montón de tablas.\n   "
        "Vaya mierda de muebles que fabrican hoy en día.\n");
        say (CAP(TP->QueryRealName()) + " empuja con fuerza el armario verde hasta "
        "que lo derriba cayendo al suelo y destrozándose y convirtiendose en un "
        "montón de tablas.\n");
int n_tabla=8+d4(); //cantidad de tablas en que se convertirá el armario
     for (int i = 0;i<n_tabla;i++) {
      tablas =clone_object(THING);
      tablas->SetShort("una tabla");
      tablas->SetLong("Un trozo de madera más o menos regular procedente de un armario.\n");
      tablas->SetIds(({"tabla","madera"}));
      tablas->SetWeight(1500);
      tablas->move(environment(TP));
      }

return remove();
}
else
    {
        return notify_fail("qué quieres empujar?.\n");
    }
}

public string desc_corta()
{
    if (abierto==1)
    {
        return "un armario verde abierto";
    }
    return "un armario verde cerrado";
}
public string desc_larga()
{
    if (abierto==1)
    {
        return "Un armario grande de madera de una sola puerta.\n  Ahora está abierto.\n";
    }
    return "Un Gran armario de una sola puerta.\n  ahora está cerrado.\n";
    }

create()
{
    ::create();
        seteuid(getuid()); //da permiso para clonar
    SetShort(SF(desc_corta));
    SetLong(SF(desc_larga));
    SetWeight(50000);
    SetNoise("No se oye nada.\n");
    SetSmell("Huele a madera.\n");
    SetIds(({"armario", "mueble"}));
    SetAds(({"verde", "grande"}));
    Set(P_NOGET, "pesará mucho para ti.\n");
    SetSize(P_SIZE_LARGE);
    }
    public void init()
{
    ::init();
add_action("cmd_abrir", "abrir");
add_action("cmd_cerrar", "cerrar");
add_action("cmd_empujar", "empujar");
    }