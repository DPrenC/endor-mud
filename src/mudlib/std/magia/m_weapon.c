/* SIMAURIA '/std/magia/m_weapon.c'
   ================================
   [w] Woo@simauria

   Arma mágica a heredar en los conjuros de creación.
   17-10-99 [w] Creación.
*/

#include <combat.h>
#include <guild.h>
#include <moving.h>
#include <properties.h>
#include <messages.h>

inherit WEAPON;

#define TIME_OFFSETT 30
#define TIME_PERIOD 60

private static int power;
private static string *power_desc;

/* 'power' es el tiempo en que el arma permanecerá antes de ser destruida. */

varargs int QueryPower(int arg)
{
  if (arg) return power;
  return find_call_out("weg");
}

int CalcPower(int time)
{
  if (power) return -1;
  power = time;
  if (power < 1) power = 1;
  if (clonep()) call_out("weg",power);
  return power;
}


/* Según el tiempo que le quede al arma podrá tener distintas
   descripciones largas. */

string AddPowerDesc(int i, string str)
{
  if (i<0) return 0;
  if (!power_desc) power_desc = (str?allocate(i+1):({}));
  if (!str && (sizeof(power_desc)<=i)) return 0;
  if (sizeof(power_desc)<=i) power_desc += allocate(i-sizeof(power_desc)+1);
  if (str) power_desc[i] = str;
  return power_desc[i];
}

string GetPowerDesc(int i)
{
  if (!power_desc) power_desc = ({});
  if ((i<0) || !sizeof(power_desc)) return "";
  if (i<sizeof(power_desc)) return power_desc[i] || "";
  return power_desc[<1];
}

nomask string *QueryPowerDesc() { return (power_desc||({})) + ({}); }

nomask string *SetPowerDesc(string *desc)
{
  int i;
  power_desc = ({});
  for (i=sizeof(desc||({})); i--; ) AddPowerDesc(i,desc[i]);
  return QueryPowerDesc();
}

private int CheckPower()
{
  int time = QueryPower();
  if (time == -1) call_out("weg",1);
  time = (time + TIME_OFFSETT) / TIME_PERIOD;
  return time;
}


public string QueryLong()
{
  CheckPower();
  return ::QueryLong();
}

public string QueryExaLong()
{
  CheckPower();
  return (::QueryExaLong() || ::QueryLong()) + GetPowerDesc(CheckPower());
}


/* Inicializamos */

create()
{
  ::create();
 seteuid(getuid());
  SetStandard(WT_CUCHILLO,1,P_SIZE_GENERIC);
  SetShort("un cuchillo mágico");
  SetLong("Un estupendo cuchillo mágico.\n");
  Set(P_NOGIVE, 1);
  Set(P_NOGET, 1);
  Set(P_NOSELL, 1);
  SetMagic("Esta arma ha sido creada por algún mago.\n");
  SetWPperQP(0);
  SetPowerDesc(
    ({"Parece que vaya a desaparecer en cualquier momento.\n",
      "Apenas le queda poder.\n",
      "Está en buenas condiciones aunque su poder se debilita.\n",
      "Aún conserva la mayor parte de su poder.\n",
      "Está en perfectas condiciones y parece que vaya a durar una eternidad\n"}) );
}

/*
  Si el poder se agota la arma desaparece y dice un mensaje.
*/

varargs void weg()
{
  if (!clonep()) return;
  while(remove_call_out("weg")!=-1);
  if (environment())
  {
    if (living(environment()))
      tell_object(environment(),capitalize(QueryShort())+" desaparece "
                                "produciendo una luz intensa.\n");
    else
      tell_room(environment(), ({ MSG_SEE, capitalize(QueryShort())+" desaparece "
                            "produciendo una luz intensa.\n" }));
  }
  TO->remove();
}

/* Si la arma se mueve a un 'environment' que no es un bicho viviente
   o no pertenece a un gremio que pueda hacer magia, automaticamente
   desaparece.
*/


int move (mixed dest, int method, mixed extra)
{
  int rc;
  object env;
  rc = ::move(dest, method, extra);
  if (rc != ME_OK)
    return rc;
/*
  if (method == M_DROP)
    call_out("weg",5);
  else
    if ( (env = environment()) &&
         (!living(env) || (member(GC_MAGIA,env->QueryGuild())==-1)) )
      call_out("weg",5);
*/
  return ME_OK;
}

