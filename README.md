*This project has been created as part of the 42 curriculum by mvelasqu.*

## Description

### Project Overview
This project creates a 2D game using C and other libraries such as math 3 and MiniLibX. Through proper code organization and management this project is divided in three (3) distinct systems:
- Parsing System
- Validation System
- Rendering System

### Project Limits and Edge Cases

#### Maps
The Maps should always have the following components
- walls
- collectibles
- free space

The Map can only be composed of this 5 characters
- 0 -> for empty space,
- 1 -> for a wall,
- C -> for collectibles,
- E -> for a map exit
- P -> for player starting position.

Map Validity Checks
- Should be **RECTANGULAR** *square is a special type of rectangle*.
- Should be **ENCLOSED** by walls, if not return ``error``.
- Should verify if there is **VALID PATH** on the map. 
- Should parse any kind of map, as long above rules are respected.
- Should there be any **MISCONFIGURATION** encountered, program ``exit`` and return ``Error\n``.

#### Test Cases

Each map was created for differet edge cases, detailed table as seen below:

| Map Name                                   | P (Start) | E (Exit) | C (Collectibles) | Walls (1) | Floors (0) | Rectangle | Enclosed | Path Valid | Valid |
|--------------------------------------------|----------|----------|------------------|-----------|------------|-----------|----------|------------|-------|
| valid_map.ber                              | 1        | 1        | ≥1               | ✔         | ✔          | ✔         | ✔        | ✔          | ✔     |
| invalid_map_no_exit.ber                    | 1        | 0        | ≥1               | ✔         | ✔          | ✔         | ✔        | ✖          | ✖     |
| invalid_map_no_start.ber                   | 0        | 1        | ≥1               | ✔         | ✔          | ✔         | ✔        | ✖          | ✖     |
| invalid_map_no_collectibles.ber            | 1        | 1        | 0                | ✔         | ✔          | ✔         | ✔        | ✖          | ✖     |
| invalid_map_multiple_exits.ber             | 1        | >1       | ≥1               | ✔         | ✔          | ✔         | ✔        | ✖          | ✖     |
| invalid_map_multiple_starts.ber            | >1       | 1        | ≥1               | ✔         | ✔          | ✔         | ✔        | ✖          | ✖     |
| invalid_map_invalid_character.ber          | 1        | 1        | ≥1               | ✔         | ✔          | ✔         | ✔        | ✖          | ✖     |
| invalid_map_not_enclosed.ber               | 1        | 1        | ≥1               | ✖         | ✔          | ✔         | ✖        | ✖          | ✖     |
| invalid_map_not_rectangle.ber              | 1        | 1        | ≥1               | ✔         | ✔          | ✖         | ✔        | ✖          | ✖     |
| invalid_map_no_path_to_collectible.ber     | 1        | 1        | ≥1               | ✔         | ✔          | ✔         | ✔        | ✖          | ✖     |
| invalid_map_no_path_to_exit.ber            | 1        | 1        | ≥1               | ✔         | ✔          | ✔         | ✔        | ✖          | ✖     |
| invalid_map_empty.ber                      | 0        | 0        | 0                | ✖         | ✖          | ✖         | ✖        | ✖          | ✖     |
| invalid_map_extra_newline.ber              | 1        | 1        | ≥1               | ✔         | ✔          | ✔         | ✔        | ✖*         | ✖     |

- Allowed characters: `0` (floor), `1` (wall), `C` (collectible), `E` (exit), `P` (player)
- Map must:
  - Contain exactly 1 `P` and 1 `E`
  - Contain at least 1 `C`
  - Be rectangular
  - Be fully enclosed by walls (`1`)
  - Have a valid path:
    - Player can reach all collectibles
    - Player can reach the exit
- `invalid_map_extra_newline.ber` may pass in weak parsers but should be treated as invalid

## Instructions

## Resources

Libraries - ``math.h``. 

## Codes Notes

This is a unfiltered notes of the developer during the creation of this project. This may contain Psuedo-Codes, Draft codes, function or library notes and other things. 

New Libraries their functions and uses. 

c built in library
```
#include <math.h>
```
Graphics library that allows you to render something in screen. its a 42 library called MiniLibX
```
#include "mlx.h"
```

## So_Long Study Roadmap

### Mandatory Roadmap

| Day | Phase | Topic | Objective | Output Check |
|-----|------|------|----------|-------------|
| 1 | Foundation | Read `.ber` file | Read file using get_next_line from argv | Map prints correctly in terminal |
| 1 | Foundation | 2D Array | Store map in `char **map` | Access works: `map[y][x]` |
| 1 | Foundation | Map size | Get width and height of map | Correct dimensions printed |
| 2 | Validation | Rectangular check | All rows must be same length | Invalid map returns error |
| 2 | Validation | Walls check | Borders must be `1` | Invalid map returns error |
| 2 | Validation | Elements count | `P = 1`, `E = 1`, `C >= 1` | Invalid map returns error |
| 2 | Validation | Flood fill | Player can reach all `C` and `E` | Invalid map returns error |
| 3 | MLX Basics | Init window | Use mlx_init + mlx_new_window | Window opens |
| 3 | MLX Basics | Exit handling | ESC + window close button works | Window closes clean |
| 4 | Rendering | Load image | Load `.xpm` textures | Image displays |
| 4 | Rendering | Draw map | Loop `[y][x]` and render tiles | Full map visible |
| 5 | Movement | Key input | WASD movement implemented | Player moves |
| 5 | Movement | Collision | Prevent moving into walls (`1`) | No wall crossing |
| 5 | Movement | Update map | Update player position in map | Map updates correctly |
| 6 | Game Logic | Collectibles | Decrease count when collected | Count updates |
| 6 | Game Logic | Exit rule | Allow exit only if all `C` collected | Game ends correctly |
| 6 | Game Logic | Move counter | Print moves in terminal | "Moves: X" displayed |

---

### Bonus Objectives

| Bonus | Feature | Objective | Output Check |
|------|--------|----------|-------------|
| 1 | Enemy | Add moving enemy | Player loses on contact |
| 2 | Animation | Animate sprites | Visible animation |
| 3 | UI | Moves on screen | Moves displayed in window |

---

### Portability (Outside 42)

| Area | Objective | Output Check |
|------|----------|-------------|
| Makefile | `make && ./so_long map.ber` works | Runs without manual fixes |
| MLX | Proper linking (`-lmlx -lX11 -lXext`) | No linker errors |
| Paths | Use relative paths only | Works after git clone |
| Repo | Clean structure (src, include, maps, textures) | Easy to run |

---

### Final Completion Checklist

- [ ] Invalid maps return error
- [ ] Valid map renders correctly
- [ ] Player movement works
- [ ] Collectibles system works
- [ ] Exit condition works
- [ ] Window closes cleanly
- [ ] Project runs outside 42 environment


### Pseudo-Code

- convert ``map`` data to a string using gnl
- split ``map`` to ``map_arr``
- check ``map_arr`` dimensions, print

## Developer Notes

## mlx study notes

1. step1: initializing and opening a window. These are the function you will need:
- ``void	*mlx_init();`` -> needed before everything else. returns 0 if failed.
- ``void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);`` -> makes a window, returns 0 when failed.
- ``int	mlx_loop (void *mlx_ptr);`` -> keeps the program/process alive and listen to events.

2. step2: to close the window using 'esc' and 'x' button at the top left corner:
- ``int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);`` -> generic hook for all events and minilibX functions that can be hook. Check macro and def from X11/X.h if needed.
- create my own function as called out in ``mlx_hook`` to process the arguments. I made two functions ``key_close_esc(int key, void *p)`` and ``key_close_x(void *p)`` that allows me to close the windows using key 'esc' and pressing 'x' button.

3. step3: to print image in the window.
- you need to convert image (jpg,png, etc.) to xpm file. 