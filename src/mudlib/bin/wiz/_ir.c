#include <moving.h>
#include <sounds.h>


public int main(string arg)
/* Sintaxis:
 *   ir                <objetivo>
 *   ir mon[struo]     <nombre>
 *   ir jug[ador]      <nombre>
 *   ir obj[eto]       <object spec>|<fichero del objeto>
 *   ir hab[itacion]   <objeto spec>|<fichero del objeto>
 *   ir objetivo       <nombre>
 */
{
    object * target, env;
    int flag;

    if (!arg) return notify_fail("¿Ir donde?\n", NOTIFY_NOT_VALID);

    target = TP->find_target(arg, 0, 0);
    if (!target) return 0;
    env = target[1];

    if (!env) write("Oh oh, "+arg+" está en el mas alla.\n");
    else if (env == environment(TP)) write("Te encuentras ya en ese lugar.\n");
    else {
        object oldenv = environment(TP);
        flag = TP->move(env, M_TELEPORT);
        if (ME_OK != flag) write("El movimiento ha fallado: "+flag+".\n");
        else
        {
            if (!TP->QueryInwiz())
            {
                play_sound(({oldenv, env}), SOUND_AINU("ir"));
            }
            else
            {
                play_sound(filter(all_inventory(oldenv) + all_inventory(env),
                                  (:query_once_interactive($1) && query_wiz_level($1):)),
                           SOUND_AINU("ir"));
  }
        }
    }
    return 1;
}
