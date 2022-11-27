#include <stdio.h>

#include <iostream>
using namespace std;

int main() {
	int blockSize[5], processSize[5], temp[5], i = 0, j = 0, k = 0, n, m,
											   count = 0, choice;
	cout << endl;
	cout << "Process Count> "; cin >> n;
	cout << "Process Sizes> "; for (i = 0; i < n; i++) cin >> processSize[i];

	cout << "Block Count> "; cin >> m;
	cout << "Block Sizes> "; for (j = 0; j < m; j++) cin >> blockSize[j];

	for (k = 0; k < n; k++) temp[k] = -1;
	cout
		<< "Enter choice:\n"
		<< "  1. First Fit\n"
		<< "  2. Best Fit\n"
		<< "  3. Worst Fit\n"
		<< "> ";
	cin >> choice;
	switch (choice) {
		case 1:
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (processSize[i] <= blockSize[j] && blockSize[j] != 0) {
						temp[i] = j;
						blockSize[j] -= processSize[i];
						break;
					}
				}
			}
			break;
		case 2:
			for (i = 0; i < n; i++) {
				int diff = 9999;
				for (j = 0; j < m; j++) {
					if (processSize[i] <= blockSize[j] & blockSize[j] != 0 && (blockSize[j] - processSize[i]) < diff) {
						diff = blockSize[j] - processSize[i];
						count = j;
					}
				}
				if (diff != 0) {
					blockSize[count] -= processSize[i];
					temp[i] = count;
				}
			}
			break;
		case 3:
			for (i = 0; i < n; i++) {
				int diff = 0;
				for (j = 0; j < m; j++) {
					if (processSize[i] <= blockSize[j] & blockSize[j] != 0 && (blockSize[j] - processSize[i]) > diff) {
						diff = blockSize[j] - processSize[i];
						count = j;
					}
				}
				if (diff != 0) {
					blockSize[count] -= processSize[i];
					temp[i] = count;
				}
			}
			break;
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (i = 0; i < n; i++) {
		cout << "  " << i + 1 << "\t\t  " << processSize[i] << "\t\t";
		if (temp[i] != -1) cout << "  " << temp[i] + 1;
		else cout << "  -";
		cout << endl;
	}
}

/**
 Process Count> 4
Process Sizes> 212
417
112
426
Block Count> 5
Block Sizes> 100
500
200
300
600
Enter choice: 
  1. First Fit
  2. Best Fit 
  3. Worst Fit
> 1

Process No.     Process Size    Block no.
  1               212             2      
  2               417             5      
  3               112             2      
  4               426             -      

 	int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
*/