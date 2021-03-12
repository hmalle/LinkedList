/* Queue with string array */

#include <stdbool.h>
typedef struct ELE {
    char *value;
    struct ELE *next;
} list_ele_t;

/* Queue structure */
typedef struct {
    list_ele_t *head;  /* Linked list of elements */
    list_ele_t *tail; 
    int q_size; 
} queue_t;

/************** Operations on queue ************************/

queue_t *q_new();
void q_free(queue_t *q);

bool q_insert_head(queue_t *q, char *s);

bool q_insert_tail(queue_t *q, char *s);

bool q_remove_head(queue_t *q, char *sp, size_t bufsize);

int q_size(queue_t *q);

void q_reverse(queue_t *q);

