typedef struct ht ht;


ht* ht_create(void);

void ht_destroy(ht* table);

void* ht_get(ht* table, const char* key);
