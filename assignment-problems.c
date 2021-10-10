#include <stdio.h>

int main() {
	int C[][4] = {
		{9, 2, 7, 8},
		{6, 4, 3, 7},
		{5, 8, 1, 8},
		{7, 6, 9, 4}
	};
 	
	// Keep track of all the assigned jobs
 	// 0 means unassigned
	// 1 means assigned 
	int assignedJob[] = {0, 0, 0, 0};

	int maxSum = 9999;
	int currentMaxSum;

	for (int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if (i == j) continue;
			// Assign Job-i and Job-j
			assignedJob[i] = assignedJob[j] = 1;

			int jobsLeft[] = {0, 0}; // Get all the jobs left unassigned
			int counter = 0;
			for (int k = 0; k < 4; k++) {
				if (assignedJob[k] != 1) {
					// Put the unassigned job to the jobsLeft array
					jobsLeft[counter] = k;	
					counter++;	
				}
			}

			for (int k = 0; k < 2; k++) {
				currentMaxSum = 0;
				// Use the modulo operator to make the counter k avoid getting out of bounds
				// and return to the first element instead
				currentMaxSum += C[0][i] + C[1][j] + C[2][jobsLeft[k % 2]] + C[3][jobsLeft[(k+1) % 2]];
				if (currentMaxSum < maxSum)
					maxSum = currentMaxSum;
			}
			
			// Reset the assignedJob array
			for (int k = 0; k < 4; k++) {
				assignedJob[k] = 0;
			}
		}
	}
	printf("%d", maxSum);

	return 0;
}
