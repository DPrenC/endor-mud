/* SIMAURIA '/obj/carcaj.c'
   ========================
   [w] Woo@simauria.upv.es

   28-10-99 [w] Un carcaj lleno de flechas.
   09-11-99 [w] Solucionado el problema de que cuando
                hacias quit te aparecian 10 flechas, aunque
                el carcaj estuviera vacio.
   02-12-99 [w] Introducido el QuerySpecialWeapon() para que se
                pueda vender y comprar en tiendas de armas.
                Ademas arreglado un bug por el cual no se podian
                comprar los carcaj.
   09-04-00 [w] Ahora con el nuevo sistema de carga de 'containers'
                he tenido que modificar el carcaj para que te diera
                las flechas más tarde porque si no podian juntarse
                20 a la vez.
   13-04-00 [w] Si si, se que es una chapuza pero me he quitao los
                cuernos intentando averiguar porque en una tienda no
                puedes vender nada que le metan algo después.
*/

#define FLECHA "/obj/flecha"

#include <moving.h>
#include <properties.h>

inherit "/std/container";


void llenar_carcaj()
{
    object ob;
    int i;

    for(i=0;i<10;i++)
    {
        ob=clone_object(FLECHA);
        if(ob) ob->move(TO);
    }
}



create () {
 int i;
  ::create();
 seteuid(getuid());
  SetLong ("Es un carcaj de cuero donde guardar las flechas.\n");
  SetIntLong ("Miras dentro del carcaj.\n");
  SetValue (500);
  SetWeight (200);
  AddId ("carcaj");
  AddId ("saco");
  SetMaxIntWeight (5000);
  call_out("llenar_carcaj",2);
}


// parche cutre, pero que funciona.
// la filosofía es que, un player al entrar con este objeto en su mapping de inventario,
// hará un SetProperties para ajustar las propiedades... Si lo hace en el
// tiempo 0 que resulta de restar el CreationTime y el tiempo actual, verificamos
// que es exáctamente esto lo que está ocurriendo.
public mapping SetProperties(mapping props)
{
    if (!(time() - QueryCreationTime()))
    // este objeto está siendo clonado por un player y se están ajustando sus
    // propiedades al estado anterior, por lo que borramos el call_out para rellenar
    // el carcaj de flechas como si fuese la primera vez:
    {
        while (remove_call_out("llenar_carcaj") != -1);
    }
    return ::SetProperties(props);
}


public string QueryShort() {
  object test;
  test=first_inventory(TO);
  if (!test) return "un carcaj vacío";
  return "un carcaj con flechas";
}

int QuerySpecialWeapon() { return 1; }

int QueryWeight() {
  return (::QueryWeight()<200)?200:(::QueryWeight());
}

int allow_enter(int method,mixed extra) {
        if (!PO->id("flecha")) return ME_NO_ENTER;
        return ::allow_enter(method,extra);
}

