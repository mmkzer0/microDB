/* mdb_data_types.c */

#include "mdb_data_types.h"
#include "mdb_config.h"


// enum for data types
typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CUSTOM
} DataType;
/*  am considering a separate TypeDescriptor struct 
    to also handle additional information, like different
    subtypes of primitives and descriptors for custom
    data types */

typedef struct TypeDescriptor {
    DataType type;
    void* custom_type_info; // used if type == TYPE_CUSTOM
} db_type_descriptor;

// basic column structure
typedef struct Column
{
    char name[MDB_NAME_LIMIT];
    db_type_descriptor type;
} column_t;

// basic table structure
typedef struct Table
{
    char name[MDB_NAME_LIMIT];
    column_t columns[MDB_COLUMN_LIMIT];
    uint8_t col_count;
    uint16_t row_count;
    void *data[MDB_ROW_LIMIT][MDB_COLUMN_LIMIT];
} table_t;

// basic database structure
typedef struct Database
{
    char name[MDB_NAME_LIMIT];
    table_t *tables[MDB_MAX_TABLES];
    uint8_t table_count;
} database_t;

// database init
database_t* createDB(const char *dbName)
{
    database_t *db = malloc(sizeof(database_t));
    if (!db)
    {
        printf(stderr, "Mem alloc failed for database.\n");
        return NULL;
    }

    strncpy(db->name, dbName, MDB_NAME_LIMIT);
    *db->tables = malloc(MDB_MAX_TABLES * sizeof(table_t *));
    if (!(*db->tables))
    {
        printf(stderr, "Mem alloc failed for tables.\n");
        return NULL;
    }
    db->table_count = 0;
    return db;
}

int dropTable(const char *table_name, database_t *db)
{
    for (int i = 0; i < db->table_count; i++)
    {
        if (strcmp(db->tables[i]->name, table_name) == 0)
        {
            free(db->tables[i]->data);
            free(db->tables[i]);
            for (int j = i; j < db->table_count - 1; j++)
            {
                db->tables[j] = db->tables[j + 1];
            }
            db->table_count--;
            db->tables[i] = NULL;
            return 0;
        }
    }
    printf(stderr, "Table not found!\n");
    return TABLE_NOT_FOUND;
}

char *getDBName(database_t *db)
{
    return db->name;
}