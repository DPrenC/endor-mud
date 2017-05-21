/*
DESCRIPCION  : Adaptacion del Daggerfall a la escala de tiempos de Simauria
FICHERO      : /obj/calendario/calendario_dagerfall.c
MODIFICACION : 14-02-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit "/obj/calendario/calendario";

public void create()
{
  ::create();
  SetTipoCalendario("daggerfall");
  SetNumMesesPorAnyo(12);
  SetNomMeses(([1:"morning star",2:"sun's down",3:"first seed",4:"rain's hand",5:"second seed",6:"mid year",7:"sun's height",8:"last seed",9:"heartfire",10:"frostfall",11:"sun's dusk",12:"evening star"]));
  SetNumDiasPorSemana(7);
  SetNomDias(([1:"morndas",2:"tirdas",3:"middas",4:"turdas",5:"fredas",6:"loredas",7:"sundas"]));
  SetAnyoBase(4000);
}


