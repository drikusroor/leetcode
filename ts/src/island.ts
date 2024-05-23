export type TIslandCell = 1 | 0 | '#'
export type TGrid = Array<Array<TIslandCell>>

export function island(grid: TGrid) {

    function dfs(y: number, x: number, first = false) {
        if (y < 0 || x < 0 || y > grid.length - 1 || x > grid[0].length - 1 || grid[y][x] !== 1) {
            return;
        }
        grid[y][x] = '#';
        if (first) {
            count += 1;
        }
        dfs(y - 1, x);
        dfs(y + 1, x);
        dfs(y, x + 1);
        dfs(y, x - 1);
    }

    let count = 0;

    grid.forEach((row, y) => {
        row.forEach((_cell, x) => {
            dfs(y, x, true);
        })
    })

    return count;
}