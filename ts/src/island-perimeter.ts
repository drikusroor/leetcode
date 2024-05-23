export function islandPerimeter(grid: number[][]): number {
    
    let perimeter = 0;
    const rows = grid.length;
    const cols = grid[0].length;

    function checkSides(y: number, x: number, row: number[]) {
        if (y - 1 < 0 || !grid[y - 1][x]) {
            perimeter += 1;
        }
        if (x - 1 < 0 || !row[x - 1]) {
            perimeter += 1;
        }
        if (y + 1 > rows - 1 || !grid[y + 1][x]) {
            perimeter += 1;
        }
        if (x + 1 > cols - 1 || !row[x + 1]) {
            perimeter += 1;
        }
    }

    grid.forEach((row, y) => {
        row.forEach((cell, x) => {
            if (!cell) {
                return;
            }
            checkSides(y, x, row);
        })
    })

    return perimeter;
};