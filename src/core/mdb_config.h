// mdb_config.h //

#ifndef MBD_CONFIG_H
#define MBD_CONFIG_H

/****************************/
#define MDB_VERSION         "0.1"

/* table limits */
#define MDB_MAX_TABLES      64
#define MDB_COLUMN_LIMIT    1024
#define MDB_ROW_LIMIT       1024

#define MDB_NAME_LIMIT      64
#define MDB_KEY_LIMIT       128
#define MDB_VAL_LIMIT       128

/* config flags */
#ifndef MDB_ENABLE_CLI
#define MDB_ENABLE_CLI      1	
#endif

/* debug flags */
#ifndef MDB_ENABLE_DEBUG
#define MDB_ENABLE_DEBUG    0
#endif


#endif //   *MDB_CONFIG_H*    //