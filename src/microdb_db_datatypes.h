#ifndef MICRODB_DB_DATATYPES_H
#define MICRODB_DB_DATATYPES_H

#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_LIMIT 10
#define MAX_COLUMNS 15
#define MAX_ROWS 1000
#define MAX_NAME_LIMIT 25
#define MAX_VAL_LIMIT 100

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


#endif //   *MICRODB_DB_DATATYPES_H*    //