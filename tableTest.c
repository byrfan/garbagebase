#include "table.h"

int main() {
    ht* table = ht_init(5);
    
    htInsert(table, "1", "Test1");
    htInsert(table, "2", "Test2");
    htInsert(table, "3", "Test3");
    htRemove(table, "2");
    
    htInsert(table, "2", "Test4");

    htResize(table, 6);
    
    htInsert(table, "4", "Test5");

    printTable(table);

    return 0;
}

