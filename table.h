#ifndef HEADER_FILE
#define HEADER_FILE

// to silence microsoft
#define strdup _strdup

// why doesnt C have default arguments
#define HT_DEFAULT_SIZE 5


typedef struct hte hte;
typedef struct ht ht;

unsigned int hash_djb2(char* str);
ht* ht_init(int size);
void htInsert(ht* table, char* key, char* value);
void htRemove(ht* table, char* key);
char* htFind(ht* table, char* key);
void htResize(ht* table, int size); // might remove
void printTable(ht* table);

#endif /* HEADER_FILE */
