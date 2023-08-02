#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _STATE_NODE {
    int* state;
    int num;
    struct _STATE_NODE* next;
} STATE_NODE;

typedef struct _LIST {
    STATE_NODE* head;
    STATE_NODE* last;
    int size;
} LIST;

void init_list(LIST* list);
void push_back(LIST* list, int* value, int valueSize);
int* get_idx(LIST* list, int idx);
void clear_list(LIST* mylist);
void free_node(STATE_NODE* current_node);

int* move_next(int* A, int N);

int compare(int* current, int* original, int N);

int Answer;

int main(void) {
    int T, test_case;
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        int N;

        scanf("%d", &N);

        LIST list;
        init_list(&list);

        int* A = (int*)malloc(N * sizeof(int));

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        push_back(&list, A, N);

        int count = 0;
        while (1) {
            int* next_state = move_next(A, N);
            count++;

            for (int i = 0; i < count - 1; i++) {
                int* checking = get_idx(&list, i);
                if (*checking == *A) {
                    Answer = count - i;
                    break;
                }
            }

            if (Answer > 0)
                break;

            push_back(&list, next_state, N);
        }


        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);

        free(A);
    }

    return 0;
}

int* move_next(int* A, int N) {
    int currentRound = 0;
    int nextRound = 0;

    if (A[N - 1] > 0) {
        nextRound = 1;
        A[N - 1]--;
    }

    for (int i = 0; i < N; i++) {
        if (nextRound) {
            currentRound = 1;
            nextRound = 0;
        }
        if (A[i] > 0) {
            nextRound = 1;
            A[i]--;
        }
        if (currentRound) {
            A[i]++;
            currentRound = 0;
        }
    }

    return A;
}

int compare(int* current, int* original, int N) {
    for (int i = 0; i < N; i++) {
        if (current[i] != original[i]) {
            return 0;
        }
    }
    return 1;
}

void init_list(LIST* list) {
    list->head = (STATE_NODE*)malloc(sizeof(STATE_NODE));
    list->head->next = NULL;
    list->last = list->head;
    list->size = 0;
}

void push_back(LIST* list, int* value, int valueSize) {
    STATE_NODE* new_node = (STATE_NODE*)malloc(sizeof(STATE_NODE));
    new_node->state = (int*)malloc(valueSize * sizeof(int));
    for (int i = 0; i < valueSize; i++) {
        new_node->state[i] = value[i];
    }
    new_node->num = valueSize;
    new_node->next = NULL;
    list->last->next = new_node;
    list->last = new_node;
    list->size++;
}

int* get_idx(LIST* list, int idx) {
    STATE_NODE* pre_node = list->head;
    while (idx--) {
        pre_node = pre_node->next;
    }
    return pre_node->next->state;
}

void clear_list(LIST* mylist) {
    while (mylist->head->next) {
        free_node(mylist->head->next);
    }
    mylist->last = mylist->head;
    mylist->size = 0;
}

void free_node(STATE_NODE* current_node) {
    if (current_node->next != NULL) {
        free_node(current_node->next);
    }
    free(current_node->state);
    free(current_node);
}
