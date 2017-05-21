/***
fichero: securebox.h.
descripción: Fichero para incluir las definiciones necesarias para las taquillas.
***/

#ifndef _SECUREBOX_
#define _SECUREBOX_
#include <keeper.h>
#include <properties.h>
#include <money.h>
#include <rooms.h>
#include <moving.h>
#include <commands.h>


// path de las taquillas
#define SBOXPATH         STDPATH SBOXDIR "/"
// caja abierta o cerrada
#define BOX_OPENED              1
#define BOX_CLOSED              0

// sistema monetario
#define V_MITHRIL               MONEY_DEMON->QueryCoinValue("mithril")
#define V_PLATINUM              MONEY_DEMON->QueryCoinValue("platino")
#define V_GOLD                  MONEY_DEMON->QueryCoinValue("oro")
#define V_silver                MONEY_DEMON->QueryCoinValue("plata")
#define V_COPPER                MONEY_DEMON->QueryCoinValue("cobre")

// precios
#define P_BOX_SMALL             50
#define P_BOX_NORMAL            100
#define P_BOX_LARGE             200

// comision por intercambio
#define BOX_EXCHANGE_COMMISSION 25

// comisiones por tiempo

// comisión
#define BOX_SEC_COMMISSION      86400
#define BOX_COMMISSION_SMALL    5
#define BOX_COMMISSION_NORMAL   10
#define BOX_COMMISSION_LARGE    20

#define BOX_COMMISSION_TIME     "día"

// tipos de permisos
#define BOX_PERMISSION_NONE     0
#define BOX_PERMISSION_LIST     1
#define BOX_PERMISSION_ALL      2

// tipos de caja
#define BOX_SMALL               1
#define BOX_NORMAL              2
#define BOX_LARGE               3
#endif