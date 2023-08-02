/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Answer;

typedef struct _COORD {
	int coord;
	int count;
} COORD;

void sort(COORD* d, int* n);

int cmp_coord_asc(const void* a, const void* b);

int cmp_coord_desc(const void* a, const void* b);

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
		int N, D;
		scanf("%d %d", &N, &D);

		COORD* strawberryCoord = (COORD*)calloc(N, sizeof(COORD));

		int r = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &(strawberryCoord + r)->coord);
			if (abs((strawberryCoord + r)->coord) <= D) {
				(strawberryCoord + r)->count = 1;
				r++;
			}
		}

		/*for (int i = 0; i < r; i++) {
			printf("%d %d\n", strawberryCoord[i].coord, strawberryCoord[i].count);
		}
		printf("\n\n");*/

		sort(strawberryCoord, &r);

		//for (int i = 0; i < r; i++) {
		//	printf("%d %d\n", strawberryCoord[i].coord, strawberryCoord[i].count);
		//}
		//printf("\n\n");

		int count = 0;
		int robotLoc = 0;
		int temp = D;
		
		if (r == 0) {
			Answer = r;
		}
		else {
			for (int i = 0; i < r; i++) {
				temp -= abs(robotLoc - (strawberryCoord + i)->coord);
				
				count += (strawberryCoord + i)->count;
				if (temp < 0) {
					temp += (strawberryCoord + i)->coord;
					count -= (strawberryCoord + i)->count;
				}
				else {
					robotLoc = (strawberryCoord + i)->coord;
				}
				Answer = count;
			}
			int tmp = 0;
			temp = D;
			robotLoc = 0;
			count = 0;
			for (int i = 1; i < r; i++) {
				temp -= abs(robotLoc - (strawberryCoord + i)->coord);
				count += (strawberryCoord + i)->count;
				if (temp < 0) {
					temp += (strawberryCoord + i)->coord;
					count -= (strawberryCoord + i)->count;
				}
				else {
					robotLoc = (strawberryCoord + i)->coord;
				}
				tmp = count;
			}
			if (tmp > Answer) Answer = tmp;
		}
		


		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		*/
		 /////////////////////////////////////////////////////////////////////////////////////////////

				 // Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

		free(strawberryCoord);
	}

	return 0;//Your program should return 0 on normal termination.
}

int cmp_coord_asc(const void* a, const void* b) {

	int num1 = ((COORD*)a)->coord;
	int num2 = ((COORD*)b)->coord;

	if (num1 < num2) {
		return -1;
	}
	else if (num1 > num2) {
		return 1;
	}
	else {
		return 0;
	}
}

int cmp_coord_desc(const void* a, const void* b) {

	int num1 = ((COORD*)a)->count;
	int num2 = ((COORD*)b)->count;

	if (num1 > num2) {
		return -1;
	}
	else if (num1 < num2) {
		return 1;
	}
	else {
		return 0;
	}
}

void sort(COORD* d, int* n)
{
	qsort(d, *n, sizeof(COORD), cmp_coord_asc);

	//for (int i = 0; i < *n; i++) {
	//	printf("%d %d\n", d[i].coord, d[i].count);
	//}
	//printf("\n\n");

	for (int i = 0; i < *n - 1; i++) {
		if ((d + i)->coord == (d + (i + 1))->coord) {
			(d + i)->count++;
			for (int j = i+1; j < *n - 1; j++) {
				(d + j)->coord = (d + (j + 1))->coord;
				(d + j)->count = (d + (j + 1))->count;
			}
			i--;
			*n -= 1;
		}
	}

	//for (int i = 0; i < *n; i++) {
	//	printf("%d %d\n", d[i].coord, d[i].count);
	//}
	//printf("\n\n");

	qsort(d, *n, sizeof(COORD), cmp_coord_desc);

	//for (int i = 0; i < *n; i++) {
	//	printf("%d %d\n", d[i].coord, d[i].count);
	//}
	//printf("\n\n");

}

