#ifndef TABLE
#define TABLE

// to silence microsoft
#define strdup _strdup

// why doesnt C have default arguments
#define HT_DEFAULT_SIZE 5


// element implementation
typedef struct hte {
    char* key;
    char* value;
} hte;

// table implementation
typedef struct ht {
    int length;
    int count;
    hte** rows;
} ht;

unsigned int hash_djb2(char* str);
ht* ht_init(int size);
void htInsert(ht* table, char* key, char* value);
void htRemove(ht* table, char* key);
char* htFind(ht* table, char* key);
void htResize(ht* table, int size); // might remove
void printTable(ht* table);

#endif /* HEADER_FILE */
