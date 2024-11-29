#include "microdb_db_datatypes.h"

typedef enum {
    SUCCESS = 0,
    OUT_OF_BOUNDS = 1,
    MEM_ALLOC_ERROR = 2,
    INVAL_ARG = 3,
    INVAL_OP = 4,
    INVAL_STATE = 5,
    INVAL_INPUT = 6,
    INVAL_OUTPUT = 7
} ErrorCode;

// enum for basic data types
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} DataType;

// basic column structure 
typedef struct Column {
    char name[MAX_NAME_LIMIT];
    DataType type;
} column_t;

// basic table structure
typedef struct Table {
    char name[MAX_NAME_LIMIT];
    column_t columns[MAX_COLUMNS];
    uint8_t col_count;
    uint16_t row_count;
    void* data[MAX_ROWS][MAX_COLUMNS];
} table_t;

// basic database structure
typedef struct Database {
    char name[MAX_NAME_LIMIT];
    table_t *tables[TABLE_LIMIT];
    uint8_t table_count;
} database_t;

// database init
database_t *createDB(const char* dbName) {
    database_t *db = malloc(sizeof(database_t));
    if (!db) {
        printf(stderr, "Mem alloc failed for database.\n");
        return NULL;
    }

    strncpy(db->name, dbName, MAX_NAME_LIMIT);
    *db->tables = malloc(TABLE_LIMIT * sizeof(table_t*));
    if (!(*db->tables)) {
        printf(stderr, "Mem alloc failed for tables.\n");
        return NULL;
    }
    db->table_count = 0;
    return db;
}

char *getDBName(database_t *db) {
    return db->name;
}