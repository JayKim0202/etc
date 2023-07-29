/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _STATE_NODE {
	int* state;
	struct _STATE_NODE* next;
}STATE_NODE;

typedef struct _LIST {
	STATE_NODE* head;
	STATE_NODE* last;
	int size;
}LIST;

void init_list(LIST* list);
void push_back(LIST* list, int* value, int valueSize);
int* get_idx(LIST* list, int idx);

int* move_next(LIST* list, int* A, int N);

int compare(int* current, int* original, int N);

int Answer;

int main(void)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	 // freopen("input.txt", "r", stdin);

	 /*
		If you remove the statement below, your program's output may not be recorded
		when your program is terminated after the time limit.
		For safety, please use setbuf(stdout, NULL); statement.
	  */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int N;

		scanf("%d", &N);

		LIST list;
		init_list(&list);

		int* A = calloc(N, sizeof(int));
		//int* checking = calloc(N, sizeof(int));

		for (int i = 0; i < N; i++) {
			scanf("%d", A+i);
		}

		push_back(&list, A, N);

		//A = get_idx(&list, 0);	// 0부터 시작임

		int count = 0;
		int same = 0;
		while (1) {
			push_back(&list, move_next(&list, A, N), N);
			count++;
			/*printf("\n\nmove_next %d번 한후 임\n", count);
			printf("count %d: A임\n", count);*/
			A = get_idx(&list, count);
			/*for (int i = 0; i < N; i++) {
				printf("%d", A[i]);
			}*/
			for (int i = 0; i < count-1; i++) {
				int* checking = get_idx(&list, i);
				same = compare(A, checking, N);

				/*printf("\ncount %d: 체킹용\n", i);
				for (int i = 0; i < N; i++) {
					printf("%d", checking[i]);
				}*/

				if (same) {
					if (i > 0) {
						Answer = count - (i + 1);
					}
					else {
						Answer = count - i;
					}
					/*printf("\ncount = %d, check = %d\n", count, i);*/
					break;
				}
			}
			if (Answer > 0) break;
		}



		//printf("A임\n");
		//for (int i = 0; i < N; i++) {
		//	printf("%d", A[i]);
		//}
		//printf("org임\n");
		//for (int i = 0; i < N; i++) {
		//	printf("%d", org[i]);
		//}

		//printf("\n\n");

		/*int count = 0;
		do {
			move_next(A, N);
			count++;
			printf("\n\nmove_next %d번 한후 임\n", count);
			printf("A임\n");
			for (int i = 0; i < N; i++) {
				printf("%d", A[i]);
			}
			printf("\norg임\n");
			for (int i = 0; i < N; i++) {
				printf("%d", org[i]);
			}
			printf("\n\n");

		} while (compare(A, org, N) == 0);

		Answer = count;*/


		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

				 // Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

		free(A);
		//free(checking);
	}

	return 0;//Your program should return 0 on normal termination.
}

int* move_next(LIST* list, int* A, int N) {
	int currentRound = 0;
	int nextRound = 0;

	if (*(A+(N - 1)) > 0) {
		nextRound = 1;
		*(A + (N - 1)) -= 1;
	}

	for (int i = 0; i < N; i++) {
		if (nextRound) {
			currentRound = 1;
			nextRound = 0;
		}
		if (*(A+i) > 0) {
			nextRound = 1;
			*(A + i) -= 1;
		}
		if (currentRound) {
			*(A + i) += 1;
			currentRound = 0;
		}
		//printf("%d", A[i]);
	}


	//printf("\n\n");

	/*printf("\n\n\nA임\n");
	for (int i = 0; i < N; i++) {
		printf("%d", A[i]);
	}

	printf("\n\n\nlist last임\n");
	for (int i = 0; i < N; i++) {
		printf("%d", list->last->state[i]);
	}*/



	return A;
}

int compare(int* current, int* original, int N) {
	for (int i = 0; i < N; i++) {
		if (*(current+i) != *(original+i)) {
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
	memcpy(new_node->state, value, sizeof(int)*valueSize);
	/*for (int i = 0; i < valueSize; i++) {
		new_node->state[i] = value[i];
	}*/
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
