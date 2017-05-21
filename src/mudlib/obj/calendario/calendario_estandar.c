/*
DESCRIPCION  : Adaptacion del calendario real a la escala de tiempos de Simauria
FICHERO      : /obj/calendario/calendario_estandar.c
MODIFICACION : 14-02-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit "/obj/calendario/calendario";

public void create()
{
  ::create();
  SetTipoCalendario("estandar");
  SetNumMesesPorAnyo(12);
  SetNomMeses(([1:"enero",2:"febrero",3:"marzo",4:"abril",5:"mayo",6:"junio",7:"julio",8:"agosto",9:"septiembre",10:"octubre",11:"noviembre",12:"diciembre"]));
  SetNumDiasPorSemana(7);
  SetNomDias(([1:"lunes",2:"martes",3:"miercoles",4:"jueves",5:"viernes",6:"sabado",7:"domingo"]));
  SetAnyoBase(2012);
}


