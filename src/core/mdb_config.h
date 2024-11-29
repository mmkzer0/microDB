#ifndef MBD_CONFIG_H
#define MBD_CONFIG_H

#define MDB_VERSION         "0.1"


#define MDB_MAX_TABLES      10
#define MDB_COLUMN_LIMIT    1024
#define MDB_ROW_LIMIT       1000

#define MDB_NAME_LIMIT      25
#define MDB_VAL_LIMIT       100

#ifndef MDB_ENABLE_CLI
#define MDB_ENABLE_CLI      1	
#endif



#endif //   *MDB_CONFIG_H*    //