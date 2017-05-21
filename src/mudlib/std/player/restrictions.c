/**
 * SIMAURIA '/std/player/restrictions.c'
 */

inherit "/std/living/restrictions";

public int QueryIVision();              // std/living/description
public int QueryUVision();              // std/living/description
public varargs int CantSee(object env); // std/living/description
public void CallOut( mixed fun, int delay, varargs mixed * args);
                                        // std/living/heart
public int FindCallout ( mixed fun );   // std/living/heart
public int RemoveCallout ( mixed fun ); // std/living/heart

//---------------------------------------------------------------------------

nosave int last_light = 0; // Último nivel de luz recibido

//---------------------------------------------------------------------------

static void announce_light_changed_to(int l)
{
  int csee, vdiff, i, diff;
  string rc;

  while(RemoveCallout("announce_light_change") >= 0) ;

  if (l == last_light) return;

  diff = l - last_light;
  last_light = l;

  csee = CantSee();
  vdiff = QueryUVision() - QueryIVision();
  i = (diff * 4) / (vdiff || 1);
  rc = "";
  if (i <= -4) rc = "Súbitamente desaparece la mayor parte de la luz";
  else if (i > 4) rc = "Una luz brillante aparece";
  else
    switch (i) {
      case -3: rc = "Ahora está mucho más oscuro"; break;
      case -2: rc = "La luz decae rápidamente"; break;
      case -1: rc = "La luz se desvanece"; break;
      case  1: rc = "La luz se hace más brillante"; break;
      case  2: rc = "La luz se hace mucho más brillante"; break;
      case  3: rc = "Hay mucha más luz"; break;
    }

  if (i && diff < 0 && csee < 0 && csee >= diff) rc += " y tu visión se va";
  if (i && diff > 0 && csee > 0 && csee <= diff) rc += " y te ciega";
  if (rc != "") TO->catch_msg(rc+".\n");
}

public void light_outside(int l)
{
  if (-1 == FindCallout("announce_light_changed_to"))
    CallOut("announce_light_changed_to", 0, l);
}

/***************************************************************************/
