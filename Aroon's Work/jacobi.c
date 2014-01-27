#include <stdio.h>

#define GRID_MAX 10
#define ITERATIONS 1

void print_grid();
void init_grid();
void relax();

double grid[GRID_MAX][GRID_MAX];
double B[GRID_MAX][GRID_MAX], **temp;

int main() {
	init_grid();
	print_grid(grid);
	printf("\n");
	relax();
}

void print_grid() {
	int i, j;
	for(i = 0; i < GRID_MAX; i++) {
		for(j = 0; j < GRID_MAX; j++) {
			printf("%.1f ", grid[i][j]);
		}
		printf("\n");
	}
}

void init_grid() {
	int i, j;
	for(i = 0; i < GRID_MAX; i++) {
		for(j = 0; j < GRID_MAX; j++) {
			if(i == 0 || i == GRID_MAX - 1 || j == 0 || j == GRID_MAX - 1) {
				grid[i][j] = 1;
			}
		}
	}
}

void relax() {
	int i, j;
	for(i = 0; i < GRID_MAX; i++) {
		for(j = 0; j < GRID_MAX; j++) {
			B[i][j] = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][k+1])/4.0;

		}
	}
}

