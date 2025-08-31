// mdb_config.h //

#pragma once
#include <stdint.h>

/****************************/
#define MDB_VERSION_MAJ     0
#define MDB_VERSION_MIN     1
#define MDB_VERSION_PATCH   0
#define MDB_VERSION          "0.1.0"

/* page config */
#ifndef MDB_PAGE_SIZE
#   define MDB_PAGE_SIZE    4096u
#endif

#define MDB_MAGIC 0x6D444230u   // mDB0

/* ensure pages are configured correctly */
_Static_assert((MDB_PAGE_SIZE & (MDB_PAGE_SIZE - 1)) == 0, "MDB_PAGE_SIZE must be power of two");
_Static_assert(MDB_PAGE_SIZE >= 1024 && MDB_PAGE_SIZE <= (64u*1024u), "reasonable page size within limits");

/* config flags */
#ifndef MDB_ENABLE_CLI
#define MDB_ENABLE_CLI      1	
#endif

/* debug flags */
#ifndef MDB_ENABLE_DEBUG
#define MDB_ENABLE_DEBUG    0
#endif


//   *MDB_CONFIG_H*    //