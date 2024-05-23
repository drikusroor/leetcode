#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Create a "type" called "TIslandCell" with the possible values: 1, 0 and -1
typedef enum {
    ISLAND = 1,
    WATER = 0,
    VISITED = -1
} TIslandCell;

// Create a "type" called "TGrid" that is a 2D array of TIslandCell
// but its dimensions are unknown prior to runtime
typedef TIslandCell **TGrid;

// Create a function called "dfs" that takes y and x coordinates, a pointer to a grid, and the grid's dimensions
// The function should not return anything but should modify the grid in place and should be recursive
bool dfs(int y, int x, TGrid grid, int rows, int cols) {
    // If the coordinates are out of bounds, return
    if (y < 0 || y >= rows || x < 0 || x >= cols) {
        return false;
    }

    // If the cell is not an island, return
    if (grid[y][x] != ISLAND) {
        return false;
    }

    // Mark the cell as visited
    grid[y][x] = VISITED;

    dfs(y - 1, x, grid, rows, cols); // Up
    dfs(y + 1, x, grid, rows, cols); // Down
    dfs(y, x - 1, grid, rows, cols); // Left
    dfs(y, x + 1, grid, rows, cols); // Right

    return true;
}

// Create a function called "countIslands" that takes a grid and its dimensions
// The function should return the number of islands in the grid
int countIslands(TGrid grid, int rows, int cols) {
    int count = 0;

    // Iterate through the grid
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            // If the cell is an island, increment the count and perform a depth-first search
            if (grid[y][x] == ISLAND) {
                count++;
                dfs(y, x, grid, rows, cols);
            }
        }
    }

    return count;
}

// Main function
int main(int argc, char *argv[]) {
    // print "Hey, I'm an island!";
    char *message = "Hey, let's count the islands!";
    printf("%s\n", message);

    // Create a grid with 5 rows and 5 columns
    TGrid grid = (TGrid)malloc(5 * sizeof(TIslandCell *));
    for (int i = 0; i < 5; i++) {
        grid[i] = (TIslandCell *)malloc(5 * sizeof(TIslandCell));
    }

    // Initialize the grid
    grid[0][0] = ISLAND;
    grid[0][1] = ISLAND;
    grid[0][2] = WATER;
    grid[0][3] = WATER;
    grid[0][4] = ISLAND;

    grid[1][0] = ISLAND;
    grid[1][1] = WATER;
    grid[1][2] = WATER;
    grid[1][3] = WATER;

    grid[2][0] = WATER;
    grid[2][1] = WATER;
    grid[2][2] = ISLAND;
    grid[2][3] = WATER;

    grid[3][0] = WATER;
    grid[3][1] = WATER;
    grid[3][2] = WATER;
    grid[3][3] = ISLAND;

    grid[4][0] = WATER;
    grid[4][1] = WATER;
    grid[4][2] = WATER;
    grid[4][3] = ISLAND;
    grid[4][4] = ISLAND;

    // Count the islands
    int islands = countIslands(grid, 5, 5);

    // print the number of islands
    printf("Number of islands: %d\n", islands);

    // Free the grid
    for (int i = 0; i < 5; i++) {
        free(grid[i]);
    }

    free(grid);

    printf("Let's do another one!\n");

    // Create a grid with 5 rows and 5 columns
    grid[0] = (TIslandCell[]){ISLAND, ISLAND, WATER, WATER, ISLAND};
    grid[1] = (TIslandCell[]){ISLAND, WATER, WATER, WATER, WATER};
    grid[2] = (TIslandCell[]){WATER, WATER, ISLAND, WATER, ISLAND};
    grid[3] = (TIslandCell[]){ISLAND, ISLAND, WATER, ISLAND, WATER};
    grid[4] = (TIslandCell[]){ISLAND, ISLAND, WATER, ISLAND, ISLAND};

    // Count the islands
    islands = countIslands(grid, 5, 5);

    // print the number of islands
    printf("Number of islands: %d\n", islands);

    return 0;
}