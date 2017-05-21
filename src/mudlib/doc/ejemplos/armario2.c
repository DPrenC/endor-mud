/****************************************************************************
Fichero: armario
Autor: Buh
Fecha: 09/07/2006
Descripci�n: un armario par aprobar las closures
simplemente para mirar c�digo, para usarse habr�a que ponerle sonido, descripci�n de
m�ltiples objetos a las tablas, y quiz� convertir el armario en contenedor.
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
return notify_fail("Ya est� abierto.\n", NOTIFY_NOT_VALID);
}
}
{
return notify_fail("�Qu� quieres abrir?.\n", NOTIFY_NOT_VALID);
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
return notify_fail("El armario ya est� cerrado.\n", NOTIFY_NOT_VALID);
}//D
}//b
{//e
return notify_fail ("�Qu� quieres cerrar.?\n", NOTIFY_NOT_VALID);
}//e
}//a

public int cmd_empujar(string str)
{
    if (str=="armario" || str=="armario verde")
    {
        object tablas;
        write ("Le das un fuerte empuj�n al armario y este se desploma al suelo "
        "destroz�ndose por completo y convirti�ndose en un mont�n de tablas.\n   "
        "Vaya mierda de muebles que fabrican hoy en d�a.\n");
        say (CAP(TP->QueryRealName()) + " empuja con fuerza el armario verde hasta "
        "que lo derriba cayendo al suelo y destroz�ndose y convirtiendose en un "
        "mont�n de tablas.\n");
int n_tabla=8+d4(); //cantidad de tablas en que se convertir� el armario
     for (int i = 0;i<n_tabla;i++) {
      tablas =clone_object(THING);
      tablas->SetShort("una tabla");
      tablas->SetLong("Un trozo de madera m�s o menos regular procedente de un armario.\n");
      tablas->SetIds(({"tabla","madera"}));
      tablas->SetWeight(1500);
      tablas->move(environment(TP));
      }

return remove();
}
else
    {
        return notify_fail("qu� quieres empujar?.\n");
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
        return "Un armario grande de madera de una sola puerta.\n  Ahora est� abierto.\n";
    }
    return "Un Gran armario de una sola puerta.\n  ahora est� cerrado.\n";
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
    Set(P_NOGET, "pesar� mucho para ti.\n");
    SetSize(P_SIZE_LARGE);
    }
    public void init()
{
    ::init();
add_action("cmd_abrir", "abrir");
add_action("cmd_cerrar", "cerrar");
add_action("cmd_empujar", "empujar");
    }