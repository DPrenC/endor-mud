/********************
Fichero: /obj/balsamo.c
Autor: Yalin
Fecha: 05/01/2008 23:54:41
Descripcion: Objeto fantasma para aplicar el bálsamo.
********************/

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <messages.h>

inherit THING;
nosave int tiempo, efecto;

int SetTiempo(int tmp) { return tiempo = tmp; }
int QueryTiempo() {	return tiempo; }
int SetEfecto(int efc) { return efecto = efc; }
int QueryEfecto() { return efecto; }

//Función de curación y control de tiempo
private void CheckHeal()
{
    object env;
    while(remove_call_out(SF(CheckHeal))!=-1);
    if (!(env = environment())||!living(env))
    {
        SetNoDrop(0);
        remove();
        return;
    }
    if (env->QueryHealth() == 100 || tiempo<1)
    {
        tell_object(env,"Pasan los efectos del bálsamo.\n");
        SetNoDrop(0);
        remove();
        return;
    }
    tell_object(env,"Sientes aliviarse tus dolores, mientras tus heridas cicatrizan.\n");
    env->HealHP(1+efecto/6);
    tiempo--;
    call_out(SF(CheckHeal),4+d6());
}

//Inicializa el proceso de curación
public void start_heal(int efecto)
{
    call_out(SF(CheckHeal),4+d6());
}

int _check()
{
	   return find_call_out("CheckHeal");
}

create()
{
    ::create();
    SetShort("");
    SetLong("");
    SetInvis(1);
    SetWeight(0);
    SetNoDrop(1);
}
