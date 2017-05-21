/* SIMAURIA '/sys/shop.h'
   =======================
   [h] Nyh@simauria

*/

#ifndef _SHOP_
#define _SHOP_

#include <rooms.h>

#define SHOP_DIRECTORY  "/std/"
#define SHOP_SUBDIRECTORY	SHOP_DIRECTORY "shopnyh/"
#define REGISTER "SHOPnyh"

#define MYFILE	SHOP_DIRECTORY "shopnyh"	// this is me, we need this for tests
#define P_LASTLIST "shoplist"
#define P_SELL_MUTEX (to_string(this_object())+":is selling")
#define MAX_PRICE	10000 	// Is used in 'GetMaxPrice', this func
				// can be overloaded by an inherit shop.
#define DYNAMIC_DEFAULT   20	// Speed refers to dynamic.
#define DEFAULT_MIN_CASH 50000	// Minimal cash of a shop. When a shop is lower
				// at cash it will be restored at reset().


#define ITEM_FILE	0
#define ITEM_REFRESH	1
#define ITEM_PROPERTIES	2
#define ITEM_NUMBER	3

#endif //_SHOP_
