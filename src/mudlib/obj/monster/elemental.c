/* SIMAURIA '/obj/monster/elemental.c'
   ===================================
   [w] Woo@simauria

   16-02-00 [w] Creación. Este es el bichejo base para los familiares,
                o sea, los animalitos que te siguen y que hacen alguna
                que otra cosilla.
   19-02-00 [w] Ahora la experiencia que acumula el elemental va tb
                al jugador que lo posee. Por supuesto, para que los
                jugadores no consigan el doble de xp matando a su
                elemental si le ataca su amo éste huye.
*/

inherit NPC;
#include <living.h>
#include <properties.h>

#define OWNER QueryOwner()

private static object amo;
private static string nombre;
private static int creacion,duracion,xp_init;

public object QueryOwner()
{ return amo||0; }

public object SetOwner(object own)
{ return amo=own||0; }

public varargs void Die(mixed silent) {
   if (OWNER) {
      OWNER->RemoveFollower(TO);
      tell_object(OWNER,"Ha muerto tu elemental.\n");
   }
   return ::Die(silent);
}

public int QueryElemental() { return 1; }

public int SetElemental(object fam)
{
 if (OWNER) return 0;
 SetOwner(fam);
 SetFriendFunction("IsFriend", fam);
 fam->AddFollower(TO);
 creacion=time();
 heart_beat();
 return 1;
}

void Huye()
{
  DropHeart(HEART_USER);
  DropHeart(HEART_HEAL);
  remove();
}

void ComprobarEnemigos()
{
 mixed enemigos;
 int xp;

 if (!OWNER) return;
 if (environment(TO)!=environment(OWNER)) return;

 enemigos = OWNER->QueryEnemies();
 if (!enemigos) return;
 else map(enemigos, (: Kill($1) :));
 return;
}

heart_beat()
{
 int i;
 if (OWNER && time()>(creacion+duracion)) {
    if (OWNER) {
      OWNER->RemoveFollower(TO);
      tell_object(OWNER,"Tu elemental decide no seguirte más.\n");
    }
  tell_room(environment(TO),
    capitalize(QueryName())+" huye y desaparece.\n");
  call_out("Huye",2);
 }

 ComprobarEnemigos();
 return ::heart_beat();
}

cmd_salir() {
  if (TP!=OWNER) return;
  write("Tu elemental huye y desaparece.\n");
  OWNER->RemoveFollower(TO);
  remove();

  return 0;
}


public void create()
{
  ::create();
 SetStandard("un elemental de fuego","frirel",25,GENDER_NEUTER);
  AddId("elemental");
  AddId("elemental de fuego");
  REGISTER->Register(TO,"ELEMENTAL");
  SetNoGet(0);
  Set(P_NOBUY,1);
  Set(P_IS_PET, 1);
  creacion=0;
  duracion=180; // Como maximo estará 3 minutos
  xp_init=QueryXP();
  return 0;
}

void PlayerNetdead(int arg)
{
  if (!OWNER || PO != OWNER)
    return;
  if (arg)
  {
    DropHeart(HEART_HEAL);
    DropHeart(HEART_USER);
  }
  else
  {
    GetHeart(HEART_HEAL);
  }
}

void Huye2()
{
  say("El elemental, al verse atacado por su amo, decide irse.\n");
  DropHeart(HEART_USER);
  DropHeart(HEART_HEAL);
  remove();
}

DoDamage(int dmg) // Si le ataca su 'amo' huye.
{
  if (OWNER && ((TP||PO)==OWNER))
   call_out("Huye2",1);

 return ::DoDamage(dmg);
}

init() {
 ::init();
 GetHeart(HEART_USER);
 add_action("cmd_salir","quit");
 add_action("cmd_salir","exit");
 add_action("cmd_salir","abandonar");
 add_action("cmd_salir","reiniciar");
}
