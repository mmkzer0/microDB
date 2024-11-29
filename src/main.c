#include "microdb_db_datatypes.h"

int main(int argc, char const *argv[])
{
    database_t *db = createDB("DB1");
    printf("DB Name: %s.\n", getDBName(db));
    return 0;
}
