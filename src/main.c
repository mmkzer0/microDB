/* main.c */

#include "core/mdb_core.h"

int main(int argc, char const *argv[])
{
    database_t *db = createDB("DB1");
    printf("DB Name: %s.\n", getDBName(db));
    return 0;
}
