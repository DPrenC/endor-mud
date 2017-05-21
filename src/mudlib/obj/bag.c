/*************************************************************************/
/* Nombre del Fichero: bag.c                                             */
/* Nombre antiguo: bag.c                                                 */
/* Comentarios: Es una bolsa estandard para clonear. Aumque te quieras   */
/*              hacer tu propia bolsa, debes de "inheritar" esta para    */
/*              mantener el factor de peso oficial                       */
/*************************************************************************/

#include <properties.h>
#include <moving.h>
#include <bags.h>


inherit CONTAINER;

private int pBagType; // tipo de mochila

public int SetBagType(int t)
{
    if (t > B_COUNT) t = B_COUNT;
    else if (t < B_BACK) t = B_BACK;
    return pBagType = t;
}
public int QueryBagType() { return pBagType; }



int QueryValue() {
	return 20 + 3*Query(P_SIZE)*100;
}

/*-------------------------------------------------------------------------
** Initialize us.
-------------------------------------------------------------------------*/

create () {
  ::create();
  SetShort("una bolsa");
  SetLong("Una simple bolsa. Puedes poner cosas dentro.\n");
  SetIntShort("dentro de una bolsa");
  SetIntLong("Estas en el interior de una bolsa.\n");
  SetPreContent("Contiene:\n");
  SetWeight(100); /* La bolsa pesa 100 gr */
  AddId("bolsa"); /* Anyadimos otra identidad, para no tener que escribir  */
                   /* "coger una bolsa" y que baste con "coger bolsa", p.e. */
  SetBagType(B_HAND); // bolsa de mano
  SetMaxIntWeight(5000); /* Podemos llevar hasta 5 kg */
  SetSize(P_SIZE_MEDIUM);
}

public int IsObjBag() { return 1; }

public varargs int move(mixed dest, int method, mixed extra)
{
    object donde, *bags;
    
    if (objectp(dest)) donde = dest;
    else if (stringp(dest)) donde = load_object(dest);
    else donde = 0;
    if ((method != M_GIVE && method != M_GET) || !donde ||!query_once_interactive(donde)) return ::move(dest, method, extra);
    if (sizeof(bags = filter(all_inventory(donde),
                             (:   member(inherit_list($1), "/obj/bag.c") >= 0
                               && $1->QueryBagType() == $2:), pBagType))
        > (pBagType == B_HAND ? 1 : 0))
    // si la mochila es de espalda o cintura, no puede tener ninguna. Si es bolsa de mano,
    // puede tener una
    {
        string msg;
        switch(pBagType)
        {
            case B_HAND:
                msg = "Ya llevas las manos ocupadas por " +
                      implode(map(bags, (:$1->QueryShort() || "una bolsa":)), " y ") +
                      ".\n";
                break;
            case B_WAIST:
                msg = "Ya llevas " + (bags[0]->QueryShort() || "una bolsa") + " en la cintura.\n";
                break;
            case B_BACK:
                msg = "Ya llevas " + (bags[0]->QueryShort()  || "una mochila") + " a tu espalda. ";
                break;
        }
        tell_object(donde, msg);
        switch(method)
        {
            case M_GIVE: return ME_NO_GIVE; break;
            case M_GET: return ME_NO_GET; break;
            default: return ME_NO_MOVE; break;
        }
    }
    return ::move(dest, method, extra);
}

public int allow_enter(int method, mixed extra) {
	if (member(inherit_list(PO), "/std/container.c") != -1) {
		return ME_NO_ENTER;
	}
	return ::allow_enter(method, extra);
}
