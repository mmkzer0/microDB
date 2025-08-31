// mdb_pager.h //

#pragma once
#include <stdint.h>
#include "mdb_config.h"

typedef struct mdb_db mdb_db;

typedef struct mdb_pager {
    uint32_t magic;             // magic
    uint16_t ver_major;         // major version
    uint16_t ver_minor;         // minor version
    uint32_t page_size;         // == MDB_PAGE_SIZE as of now
    uint64_t page_count;        // including superblock (page 0)
    uint8_t reserved[32];       // reserved for future use
} mdb_superblock;

typedef struct {
    uint16_t kind;              // 0==free, 1==heap...
    uint16_t cell_count;        // page entries (relevant for heap)
    uint16_t free_start;        // offset for free space
    uint16_t dir_start;         // start of directory for slot
    uint32_t crc32;             // checksum for later, 0 for now
} mdb_page_hdr;

// lifetime functions
int mdb_db_create(mdb_db* db, uint32_t pgno, void* out_page);
int mdb_db_open(const char* pth, mdb_db** out);
int mdb_db_close();