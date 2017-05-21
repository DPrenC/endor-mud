#include "/secure/config.h"
#include "/secure/wizlevels.h"
#include "/secure/userinfo.h"
#include <properties.h>
#include <wizlevels.h>
#include <attributes.h>
#include <files.h>
#include <guild.h>

inherit PLAYER; //Asin a lo burro...

#define MUMMYDIR "/secure/momias/"

//--- Funciones necesarioas para q funcione lo q tengo q hacer

private mapping inventory;  /* El sistema de inventario actual:
                        ([objeto:QueryProperties();container]) */
private mapping pInventory; /* El nuevo sistema de inventario:
                        ([blueprint: save_object(); container ]) */

private mapping auto_load;  // autoload mapping

private mapping pAutoLoad; // New autoload mapping

private void actualize_containers(object ob, string name) {
    mixed *idx;
    int i;

    idx = m_indices(inventory||([]));
    for (i=sizeof(idx); i--; )
        if (inventory[idx[i],1]==name)
            inventory[idx[i],1]=object_name(ob);
}

protected void _restore_inventory() {
    mapping objects = ([]);
    mixed *idx;
    string str, *empunyar = ({}), *vestir = ({});
    int i;
    object cont, ob;

    if (mappingp(auto_load)) walk_mapping(auto_load, SF(restore_autoobject));


    idx = m_indices(inventory||([]));
    str = lower_case(blueprint());

  //clonarlo todo y dejarlo en el vacío sideral...
  // [Nyh] Ahora solo deja en el vacio aquello que estuviese en un contenedor
    for (i=sizeof(idx); i--; )
    {
        if (!catch(ob=clone_object(blueprint(idx[i]))))
        {
            mapping m;

            m = inventory[idx[i]];

            if (sizeof(inventory[idx[i]])) ob->SetProperties(m - ([P_WIELDED, P_WORN]));

            actualize_containers(ob, idx[i]); //Por que los contenedores han cambiado de #<numero>

            // El lower_case es porq antes era /Nyh y ahora es /nyh
            if (lower_case(inventory[idx[i], 1]) == str) //str es el player
            {// Si NO estaba en un contenedor, me mueve al player
                if ( ob->move(TO, M_NOCHECK) == ME_OK )
                {
                    if (m[P_WIELDED])
                    { //Empuña las armas
                        ob->Equip(TO, EWF_SILENT|EWF_WEAPON);
                        empunyar += ({ ob->QueryShort() });
                    }
                    if (m[P_WORN])
                    { //Se pone las ropas
                        ob->Equip(TO, EWF_SILENT|EWF_WEAPON);
                        vestir += ({ ob->QueryShort() });
                    }
                }
                else if (ob->move(environment(TO), M_SILENT) != ME_OK)
                {
                    ob->remove();
                    if (ob) destruct(ob);
                }
            } // En objects guardo lo q estaba dentro de containers, para luego moverlo
            else {
                objects += ([ idx[i]: ob ]);
            }
            //'Vacía' los contenedores...
            if ( member(inherit_list(ob), "/std/container.c") != -1 )
            {
                ob->AddIntWeight(-ob->QueryWeightContent());
                ob->SetWeightContent(0);
            }
        }
        else
        {
            log_file("INVENTARIO", ctime()+" No puedo clonar: "+idx[i]+
	             " para "+capitalize(TP->QueryRealName())+".\n");
    	}
    }

    if (sizeof(empunyar))
        TO->catch_msg("Empuñas "+implode(empunyar[0..<2], ", ") + (sizeof(empunyar)>1?" y ":"")+empunyar[<1]+".\n");
    if (sizeof(vestir))
        TO->catch_msg("Te pones "+implode(vestir[0..<2], ", ") + (sizeof(vestir)>1?" y ":"")+vestir[<1]+".\n");


    //meter los objetos que estaban en containers...
    for (i=sizeof(idx = m_indices(objects||([]))); i--; )
    {
        ob = objects[idx[i]];
        if (ob->Query(P_WIELDED) || ob->Query(P_WORN)) continue;
        if (cont = find_object(inventory[idx[i],1]))
        {
            if (    (ob->move(cont, M_NOCHECK) != ME_OK)
                 && (ob->move(environment(TO), M_SILENT) != ME_OK))
            {
                ob->remove();
                if (ob) destruct(ob);
            }
        }
        else
        {
            log_file("INVENTARIO", ctime()+" El objeto padre ("+
                     inventory[idx[i],1]+") de ("+idx[i]+
                     ") no ha sido clonado todavía para "+
                     capitalize(TP->QueryRealName())+".\n");
        }
    }
    auto_load = 0;
}

_save_inventory() {


}

// Fin de funciones necesarias para q funcione lo q tengo q hacer.

create() {
//    seteuid(getuid());
//    printf("Cargando el FAKER con euid: %O.\n",geteuid());
}

public int save() {
// No salvo, por si acaso algo raro pasa...
}

heart_beat() {
// Tampoco me pongo heart_beat, por si acaso.
}

private static string dtime(int time)
{
  string ret;

  ret = "";
  if( time >= 86400) {
    ret += time/86400+"d ";
    time %= 86400;
  }
  if (time < 36000) ret += "0";
  ret += time/3600+":";
  time %= 3600;
  if (time < 600) ret += "0";
  ret += time/60+":";
  time %= 60;
  if (time < 10) ret += "0";
  ret += time+"";
  return ret;
}

public mixed fake(string path) {
  mixed rc;
/*
  if (rc=catch(!restore_object("/secure"+path)))
  {
    log_file("/FAKER", sprintf("\tError: %O (%O) no pudo ser restablecido.\n",QueryRealName(),"/secure"+path));
  }
  else
  */
  if (rc=catch(!restore_object(path)))
  {
      log_file("/FAKER", sprintf("\tError: %O (%O) no pudo ser restablecido.\n",QueryRealName(),path));
  }
  return rc;
}

//Aqui dentro es donde codeo las lineas que quier oque se ejecuten.
// Devuelve cero si todo ha salido bien
public mixed update() {
  mixed rc = 0;
  object fconv;

  seteuid(getuid());

  RestoreAttrs();

  // Introducir aqui el codigo a ejecutar en cada player

  _restore_inventory(); // Recupero el inventario viejo

  _save_inventory(); // guardo el inventario nuevo

  // Fin de introducir aqui el codigo a ejecutar en cada player

  return rc;

}

//#define YEAR (60*60*24*365)
#define YEAR    31536000
#define DAYS_FOR_ALLOW_ONE_YEAR 1
//#define DAY (60*60*24)
#define DAY 86400
#define YEARS_ALLOWED_FROM_AGE(x) ((x/DAY/DAYS_FOR_ALLOW_ONE_YEAR)||1)

public int CheckTooOld() {
    int edad, timeout;

    edad = 2*QueryAge(); //Edad en 2*heart_beats = segundos
    timeout = time() - QueryLastSave(); //el time de la ultima vez q se salvo.

//    log_file("FAKER",sprintf("Player %O [edad = %O][ausente = %O].\n",ctime(),QueryRealName(),dtime(QueryAge()),dtime(timeout) ));

    if ((timeout/YEAR) > YEARS_ALLOWED_FROM_AGE(edad))
    { //Demasiado tiempo fuera, lo borro...
//        return _remove_this_player();
        log_file("/FAKER",sprintf("Borro a %O (%O años)\n",QueryRealName(),(timeout/YEAR)));
        return call_other("/secure/remover","remove_player",QueryRealName(),1);
    }
    return 0;
}

// Si flag vale 0 name es el path completo, si no, es el nombre...
// Devuelve 0 si todo va bien.
public varargs mixed fake_and_update(string path, int flag) {
  mixed rc;

  if (flag)
  { // path es el nombre
    ::SetName(capitalize(path), 1);
    path = "/" SAVEPATH + QueryRealName()[0..0]+"/" + QueryRealName();
  }
  else
  { //path es el path
    if (path[<2..]==".o") path = path[..<3];
    ::SetName(capitalize(explode(path,"/")[<1]), 1);
  }

  //log_file("/FAKER",sprintf("[%O] Llamada al Faker para %O.\n",ctime(time()), capitalize(QueryRealName()) ));

  if (rc = fake(path)) return rc;

  if (rc = update()) return rc;

  if (rc = CheckTooOld()) return rc;

  if (!rc) save_object(path); //esto graba el archivo.

//  if (rc) log_file("/FAKER", sprintf("\tError: %O (%O) ha tenido algun error.\n",QueryRealName(),path));

  return rc;
}