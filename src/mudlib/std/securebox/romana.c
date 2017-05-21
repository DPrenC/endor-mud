/***
fichero: romana.c
Autor: kastwey@simauria.
Descripción: Es una romana para pesar los objetos. Pesa un máximo de 15 kilos.
Fecha inicio: 21/08/2004
27/09/2004 Añadida la acción pesar y modificada la obtención del peso en kilos / gramos.
27/01/2005: resangro el código y arreglo algunas cosas
07/04/2005: Ahora sí, lo vuelvo a sangrar :P
***/

#include <securebox.h>
#define GENDER_OB_PESAR ob->QueryThingArticle()

inherit "/std/container";
int pesar(object ob, object player);
string convertir(int valor);
int cmd_pesar(string objeto);
public string QueryDesc(object ob);

public void init()
{
    add_action("cmd_pesar","pesar");
}

public void create()
{
    ::create();
    SetShort("una romana de metal");
    SetLong(W("Se trata de una romana para pesar los objetos.\n"
              "Para usarla, escribe pesar <objeto>, o coloca en ella el objeto "
              "que quieras pesar.\n"));
    SetClassIds(({"thing"}));
    SetNoGet("La romana parece atornillada a la mesa.\n");
    SetNoTake(1);
    SetNoDrop(1);
    SetNoGive(1);
    SetWeight(0);
    SetMaxIntWeight(15000);
    AddId(({"romana","romana de metal","peso"}));
}

int allow_enter(int method, mixed extra)
// se puede pesar?
{
    int val;
    if (sizeof(all_inventory(TO)))
    {
        write (W("Ya hay un objeto en la romana. Espera a pesarlo y luego "
                 "pones otro.\n"));
        return ME_NO_ENTER;
    }
    if (PO->QueryWeight() > TO->QueryMaxWeight())
  // es demasiado grande.
  {
        write (W(QueryDesc(PO) + " es demasiado grande para esta romana.\n"));
        return ME_NO_ENTER;
    }
    if ((val = ::allow_enter(method, extra)) == ME_OK) call_out("pesar",1,PO,TP);
    return val;
}

int pesar(object ob, object player)
    {
    if (!player || !present(player,environment())) return 0;
    write (W("Mueves la pesa por la barra hasta que esta queda en "
             "equilibrio.\n"
             "A continuación, miras la marca y observas que " +
             QueryDesc(ob) + " pesa " + convertir(ob->QueryWeight()) + ".\n"));
    say(W(capitalize(TNAME) + " mueve la pesa hasta que la barra está en "
          "equilibrio y lee la marca correspondiente.\n"
          "Miras la marca, y ves que " + QueryDesc(ob) + " pesa " +
          convertir(ob->QueryWeight()) + ".\n"),player);
    ob->move(player,M_GET);
    write(W("Recoges " + QueryDesc(ob) + " de la romana.\n"));
    return 1;
}

string convertir(int valor)
{
    int kilos, gramos;
    string msg = "";
    kilos = valor/1000;
    gramos = valor % 1000;
    if (kilos)
    {
        msg = kilos + "kilo" + (kilos > 1?"s":"") + " y ";
    }
    switch(gramos)
    {
        case 0 .. 100: msg += "50 gramos aproximádamente.\n";
                       break;
        case 101 .. 200: msg += "150 gramos aproximádamente.\n";
                         break;
        case 201 .. 300: msg += "250 gramos aproximádamente.\n";
                         break;
        case 301 .. 400: msg += "350 gramos aproximádamente.\n";
                         break;
        case 401 .. 500: msg += "450 gramos aproximádamente.\n";
                         break;
        case 501 .. 600: msg += "550 gramos aproximádamente.\n";
                         break;
        case 601 .. 700: msg += "650 gramos aproximádamente.\n";
                         break;
        case 701 .. 800: msg += "750 gramos aproximádamente.\n";
                         break;
        case 801 .. 900: msg += "850 gramos aproximádamente.\n";
                         break;
        case 901 .. 999: msg += "950 gramos aproximádamente.\n";
                         break;
    }
    return msg;
}

int cmd_pesar(string obj)
{
    if (!obj)
    {
        return notify_fail("Pesar qué?\n",NOTIFY_NOT_VALID);
    }
    if (!present(obj,TP))
    {
        return notify_fail("No tienes " + obj + " en tu inventario.\n",
                           NOTIFY_NOT_VALID);
    }
    object ob;
    int movimiento;
    ob=present(obj,TP);
    if (ob->QueryGuildObject())
    // objeto de gremio
    {
        return notify_fail("Este objeto es un distintivo de tu gremio. No "
                           "puedes pesar eso.\n",NOTIFY_NOT_VALID);
    }
    if (ob->QueryNoDrop())
    {
        return notify_fail("No puedes dejar " + QueryDesc(ob) + " en la "
                           "romana.\n",NOTIFY_NOT_VALID);
    }
    if (ob->QueryEquipped() == TP)
    // lo tienes puesto
    {
        return notify_fail("No puedes pesar las cosas que llevas puestas.\n",
                           NOTIFY_NOT_VALID);
    }
    if (ob->QueryEquipped() == TP)
    // tiene el objeto empuñado
    {
        return notify_fail("No puedes pesar objetos que tengas empuñados.\n",
                           NOTIFY_NOT_VALID);
    }
    movimiento = ob->move(TO);
    if (movimiento != ME_OK)
    {
        return notify_fail("No te es posible colocar " + QueryDesc(ob) + " en "
                           "la romana.\n",NOTIFY_NOT_VALID);
    }
    write (W("Colocas " + QueryDesc(ob) + " en la romana.\n"));
    return 1;
}

public string QueryDesc(object ob)
{
    return (ob->QueryShort() || ob->QueryName() || "algo");
}
