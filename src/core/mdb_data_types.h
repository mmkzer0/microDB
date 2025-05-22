// mdb_data_types.h

#ifndef MDB_DATA_TYPES_H
#define MDB_DATA_TYPES_H

#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include "mdb_config.h"


// define error enums for clear error handling
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
typedef struct TypeDescriptor db_type_descriptor;
typedef struct Column column_t;
typedef struct Table table_t;
typedef struct Database database_t;

// datatype creation 
database_t *createDB(const char* db_name);
int dropDB(database_t* db);

int createTable(const char* table_name, database_t* db);
int dropTable (const char* table_name, database_t* db);


int addColumn(const char* column_name, db_type_descriptor type, table_t* table);
int dropColumn(const char* column_name, database_t* db);

char *getDBName(database_t *db);


#endif //   *MDB_DB_DATATYPES_H*    //