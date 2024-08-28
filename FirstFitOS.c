/*
* Copyright @Rhythm 
* Special thanks Bijay
* First Fit OS
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
	int i, j;
	int occupiedBy[m];
	bool processAllocated[m];
  memset(processAllocated, false, m * sizeof(bool));
  
	bool blocksAllocated[m];
  memset(blocksAllocated, false, m * sizeof(bool));
// 	bool runFlag = false;
//	while(!runFlag) {
		
		for(i = 0; i<m; i++) {
			for (j = 0; j<n; j++) {
				if(!blocksAllocated[i] && 
				!processAllocated[j] 
				&& processSize[j] < blockSize[i]) {
					occupiedBy[i] = j;
					processAllocated[j] = true;
					blocksAllocated[i] = true;
					continue;			
				}
			}
		}
		
		for ( i = 0; i <m; i++) {
			if(blocksAllocated[i]) {
				printf("\nBlock %d is occupied by process %d", i, occupiedBy[i]);
			} else {
				printf("\nBlock %d not occupied", i);
			}
		}
//	}
}

int main() {
	int processSize[] = {100, 80, 100}; // incoming process blocks
	int blockSize[] = {500,100,80}; // memory blocks
	int m; // no. of blocks
	int n; // no. of processes
	m = sizeof(blockSize) / sizeof(blockSize[0]);
	n = sizeof(processSize) / sizeof(processSize[0]);
	
	firstFit(blockSize, m, processSize, n);
	
	return 0;
}
