/* SIMAURIA '/obj/monster/familiar.c'
   ==================================
   [w] Woo@simauria
   [h] Nyh@simauria

   14-02-00 [w] Creación. Este es el bichejo base para los familiares,
                o sea, los animalitos que te siguen y que hacen alguna
                que otra cosilla.
   15-02-00 [w] Ahora incrementa una cuarta parte de SP pero puede
                durar hasta 2 horas. Además te defiende si tu estás
                atacando.
   16-02-00 [w] Espectacular, ahora atacan o no.. a conveniencia.
   21-02-00 [w] Además le da los xp a su propietario :)
*/

inherit "/std/npc";
#include <living.h>
#include <properties.h>

#define OWNER QueryOwner()


#define INC_SP 1 // Cantidad de puntos de magia que incrementa

private static object amo;
private static string nombre;
private static int contador,creacion,duracion,ataque;

public int QueryFamiliar()		{ return 1; }
public int QueryIsFamiliar()		{ return QueryFamiliar(); }
public object QueryOwner()		{ return amo||0; }
public object SetOwner(object own)	{ return amo=own||0; }

//los familiares no ganan experiencia...
public int AddXP(int xp) { return QueryXP();}

public void Die(mixed silent) {
  if (OWNER) {
    OWNER->RemoveFollower(TO);
    tell_object(OWNER,"Ha muerto tu animal de compañia.\n");
  }
  return ::Die(silent);
}

public int SetFamiliar(object fam) {
  if (OWNER) return 0;
  SetOwner(fam);
  SetFriendFunction("IsFriend", fam);
  fam->AddFollower(TO);
  creacion=time();
  return 1;
}

void IncreSP() {
  int necesario;
  necesario = 0;
  contador = 0;
  if (OWNER) {
      if (amo->QuerySP() < amo->QueryMaxSP()+INC_SP) {
          amo->SetSP(amo->QuerySP() + INC_SP );
          necesario = 1;
      }
  }
  if (!necesario) {
     remove_call_out("IncreSP");
     call_out("IncreSP", 120); /* Chequeará a los 2 minutos */
     DropHeart(HEART_USER);
  }
  else {
     GetHeart(HEART_USER);
  }
}

void Huye() {
  DropHeart(HEART_USER);
  DropHeart(HEART_HEAL);
  remove();
}

void ComprobarEnemigos() {
  mixed enemigos;
  int i,xp;

  if (!OWNER) return;
  if (environment(TO)!=environment(OWNER)) return;

  enemigos=OWNER->QueryEnemies();
  if (!enemigos) return;
  else for (i=0;i<sizeof(enemigos);i++) Kill(enemigos[i]);
  return;
}

heart_beat() {
  int i;
  if (OWNER && time()>(creacion+duracion)) {
    OWNER->RemoveFollower(TO);
    tell_object(OWNER,"Tu familiar decide no seguirte más.\n");
    tell_room(environment(TO),capitalize(QueryName())+" huye y desaparece.\n");
    call_out("Huye",2);
  }
  if (ataque) ComprobarEnemigos();
  contador += 1;
  if (contador >= 15) IncreSP();
  return ::heart_beat();
}

cmd_salir() {
  if (TP!=OWNER) return;
  write("Tu familiar huye y desaparece.\n");
  OWNER->RemoveFollower(TO);
  remove();

  return 0;
}

cmd_nombre(string str) {
 if (TP!=OWNER || !OWNER) return 0;
 if (!str) return 0;
 if (strlen(str)>12) return notify_fail("¿No crees que es un nombre un poco largo?.\n"),0;
 else {
  write("Ahora tu familiar se llama "+capitalize(str)+".\n");
  if (nombre) RemoveId(nombre);
  AddId(str);
  nombre=str;
  return 1;
 }
}

cmd_ataque(string str) {
 if (TP!=OWNER || !OWNER) return 0;
 if (!str) return notify_fail("Escribe 'ataque si/no'.\n"),0;

 if (str=="no") { ataque=0; return write("Tu familiar ahora NO te defenderá.\n"),1; }
 else if (str=="si") { ataque=1; return write("Tu familiar ahora SI te defenderá.\n"),1; }
 else return notify_fail("Escribe 'ataque si/no'.\n"),0;
 return 1;
}

public create() {
  ::create();
 AddId("familiar");
  REGISTER->Register(TO,"FAMILIAR");
  SetNoGet(0);
  Set(P_NOBUY,1);
  Set(P_IS_PET, 1);
  contador=0;
  creacion=0;
  ataque=0;
  duracion=7200; // Como maximo estará 2 horas
  return 0;
}

void PlayerNetdead(int arg) {
  if (!OWNER || PO != OWNER) return;
  if (arg) {
    DropHeart(HEART_HEAL);
    DropHeart(HEART_USER);
    remove_call_out("IncreSP");
  }
  else {
    GetHeart(HEART_HEAL);
    IncreSP();
  }
}

init() {
 ::init();
 GetHeart(HEART_USER);
 add_action("cmd_salir","quit");
 add_action("cmd_nombre","nombre");
 add_action("cmd_ataque","ataque");
 add_action("cmd_salir","exit");
 add_action("cmd_salir","abandonar");
 add_action("cmd_salir","reiniciar");
}

void Huye2() {
  say(capitalize(QueryName())+" se siente no querido y decide irse.\n");
  if (OWNER) OWNER->RemoveFollower(TO);
  DropHeart(HEART_USER);
  DropHeart(HEART_HEAL);
  remove();
}

 // Si le ataca su 'amo' huye.
public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
  if (OWNER && ((TP||PO)==OWNER)) call_out("Huye2",1);
  return ::DoDamage( damage,  type,  gentle,  xtras);
}

QueryShort() {
 if (!OWNER) return ::QueryShort();
 else if (!nombre) return (QueryGender()==2?"La ":"El ")+(QueryRace()||"animal")+" de "+capitalize(amo->QueryRealName());
 else return capitalize(nombre)+(QueryGender()==2?", la ":", el ")+(QueryRace()||"animal")+" de "+capitalize(amo->QueryRealName());
}

QueryLong() {
 if (!OWNER) return ::QueryLong()+"Es un animal bastante influenciable, seria un buen familiar.\n";
 else if (TP!=OWNER) return ::QueryLong()+"Este animal pertenece a "+capitalize(OWNER->QueryRealName())+".\n";
 else return ::QueryLong()+"Con 'nombre <nuevo>' puedes cambiarselo y con 'ataque <si/no>' consigues\n\que tu familiar te defienda o no en los combates.\n";
}
