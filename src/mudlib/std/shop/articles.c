/*SIMAURIA '/std/shop/articles.c'
  ===============================
   19-02-97 Theuzifan, Traducido al cristiano
   08-02-99 [t] Castellanizado
*/

#define SHOP_DIRECTORY "/std/"
#define STORE_ID "This is my store."
#define LSF(x) symbol_function(x,TO)
#define ESF(x) symbol_function(x)

#include <rooms.h>
#include <moving.h>

public object GetStore()
{
  object *obs;
  if (!sizeof(obs = filter_objects(all_inventory(TO),"id_store")))
    return 0;
  return obs[0];
}

public int PutInStore(object ob)
{
  object st;
  if (!st = GetStore()) return ME_CAUGHT_ERR;
  if (ob->QueryIsPlayer())
    return ob->move(st,M_SPECIAL,
                    ({"entra en el almacén",
                      "llega de la tienda",
                      "entras en el almacén"
                    }) );
  return ob->move(st, M_SILENT);
}

public void RemoveStore()
{
  object ob;
  string fname;
  if (ob = GetStore())
    {
      fname = blueprint(ob);
      ob->remove();
      if (ob) destruct(ob);
      TO->RemoveItem(fname);
    }
}

public varargs void SetStore(string file,mapping prop)
{
  object tmp_store,store;
  mapping tmp_items;

  tmp_store = clone_object(SHOP_DIRECTORY "store");
  if (store = GetStore())
    {
      map_objects(all_inventory(store),"move",tmp_store,M_SILENT);
      tmp_items = GetStore()->QueryItems();
    }
  RemoveStore();
  if (!file)
    TO->AddItem(SHOP_DIRECTORY "store",REFRESH_HOME,prop);
  else
    TO->AddItem(file,REFRESH_HOME,prop);
  if (store = GetStore())
    {
      map_objects(all_inventory(tmp_store),"move",store,M_SILENT);
      if (tmp_items)
        store->SetItems(tmp_items);
    }
}

//--- query and set item information ----------------------------------------

public mixed *QueryArticles()       { return GetStore()->QueryItems(); }
public mixed *SetArticles(mixed *a) { return GetStore()->SetItems(a); }

public mixed *SetArticlesRefresh(mixed *items)
{
  if (!GetStore()) return 0;
  return GetStore()->SetItemsRefresh(items);
}

public mixed *QueryArticlesRefresh()
{
  if (!GetStore()) return 0;
  return GetStore()->QueryItemsRefresh();
}

public varargs object *AddArticle(mixed file, int refr,
			          mixed xarg1, mixed xarg2, mixed xarg3)
{
  if (!GetStore()) return 0;
  return GetStore()->AddItem(file,refr,xarg1,xarg2,xarg3);
}

public void RemoveArticle(mixed what)
{
  if (!GetStore()) return;
  return GetStore()->RemoveItem(what);
}
