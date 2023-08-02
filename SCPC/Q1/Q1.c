/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

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
	// setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int apples; // 전체 사과 갯수
		int boxA;
		int boxB;

		scanf("%d %d %d", &apples, &boxA, &boxB);

		int temp;
		// 필요할 경우 A B 대소 비교하고 큰걸 무조건 A에 넣기

		if (boxB > boxA) {
			temp = boxA;
			boxA = boxB;
			boxB = temp;
		}
		
		temp = apples;
		int countA = 0;
		int countB = 0;

		while (countB == 0) {
			
			if (temp < boxA && temp < boxB) {
				temp = apples;
				countA = 0;
				countB = 0;
			}

			if (temp % boxB == 0) {
				countB = temp / boxB;
				break;
			}

			temp -= boxA;
			countA++;
		}

		Answer = countA + countB;

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

				 // Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}