# so_long

A small 2D game written in C using MiniLibX. You explore the map, collect all items, and only then gain access to the exit. The user supplies the map (matrix) that the game uses to render the world.

## Features

* 2D tile-based movement
* Collectibles
* Exit unlocks only after collecting everything
* Map validation
* Rendering with MiniLibX

## How to Run

```bash
make
./so_long maps/example.ber
```

## Map Format

* The map is a matrix stored in a `.ber` file
* Must be rectangular
* Must contain: `P` (player), `E` (exit), `C` (collectibles), `1` (walls), `0` (floor)

## Controls

* **WASD** 
* **ESC** to exit the game

## Requirements

* MiniLibX
* GCC/Clang
* Make

## Notes

This project follows the 42 Norm and is part of the 42 Common Core curriculum.
