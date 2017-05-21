/* SIMAURIA '/std/magia/m_armour.c'
   ================================
   [w] Woo@simauria

   Protecci�n m�gica a heredar en los conjuros de creaci�n.
   26-11-99 [w] Creaci�n.
*/

#include <combat.h>
#include <guild.h>
#include <moving.h>
#include <properties.h>
#include <messages.h>

inherit ARMOUR;

#define TIME_OFFSETT 30
#define TIME_PERIOD 60

private static int power;
private static string *power_desc;


/* 'power' es el tiempo en que la armadura permanecer� antes de ser destruida. */

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


/* Seg�n el tiempo que le quede al arma podr� tener distintas
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
  int timer;
  timer = QueryPower();
  if (timer == -1) call_out("weg",1);
  timer = (timer + TIME_OFFSETT) / TIME_PERIOD;
  return timer;
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
  SetStandard(AT_CASCO,1,P_SIZE_GENERIC);
  SetShort("un casco m�gico");
  SetLong("Un estupendo casco m�gico.\n");
  Set(P_NOGIVE, 1);
  Set(P_NOGET, 1);
  Set(P_NOSELL, 1);
  SetMagic("Esta protecci�n ha sido creada por alg�n mago.\n");
  SetAPperQP(0);
  SetPowerDesc(
    ({"Parece que vaya a desaparecer en cualquier momento.\n",
      "Apenas le queda poder.\n",
      "Est� en buenas condiciones aunque su poder se debilita.\n",
      "A�n conserva la mayor parte de su poder.\n",
      "Est� en perfectas condiciones y parece que vaya a durar una eternidad\n"}) );
}

/*
  Si el poder se agota la arma desaparece y dice un mensaje.
*/

public void weg()
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
  if (method == M_DROP)
    call_out("weg",5);
  else
    if ( (env = environment()) &&
         (!living(env) || (member(GC_MAGIA,env->QueryGuild())==-1)) )
      call_out("weg",5);
  return ME_OK;
}

