import { expect, test } from "bun:test";

import { islandPerimeter } from "./island-perimeter";

test("island perimeter 1", () => {
  const grid = [
    [0, 1, 0, 0],
    [1, 1, 1, 0],
    [0, 1, 0, 0],
    [1, 1, 0, 0],
  ];
  expect(islandPerimeter(grid)).toBe(16);
});

test("island perimeter 2", () => {
    const grid = [
        [1],
    ];
    expect(islandPerimeter(grid)).toBe(4);
});

test("island perimeter 3 (big complex example)", () => {
    const grid = [
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 1, 1, 1, 0, 0, 0],
        [1, 1, 0, 0, 1, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    ];
    expect(islandPerimeter(grid)).toBe(40);
});