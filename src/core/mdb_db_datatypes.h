#ifndef MDB_DB_DATATYPES_H
#define MICRODB_DB_DATATYPES_H

#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include "core/mdb_config.h"


// define error enums in header instead?
typedef enum {
    SUCCESS = 0,
    OUT_OF_BOUNDS = 1,
    MEM_ALLOC_ERROR = 2,
    INVAL_ARG = 3,
    INVAL_OP = 4,
    INVAL_STATE = 5,
    INVAL_INPUT = 6,
    INVAL_OUTPUT = 7,
    TABLE_NOT_FOUND = 8
} ErrorCode;

// abstract datatype definitions
typedef enum DataType db_datatype_t;
typedef struct Column column_t;;
typedef struct Table table_t;
typedef struct Database database_t;

// datatype creation 
database_t *createDB(const char* db_name);
int dropDB(database_t* db);

int createTable(const char* table_name, database_t* db);
int dropTable (const char* table_name, database_t* db);


int addColumn(const char* column_name, db_datatype_t type, table_t* table);
int dropColumn(const char* column_name, database_t* db);

char *getDBName(database_t *db);


#endif //   *MDB_DB_DATATYPES_H*    //