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

### Bonus Objectives

| Bonus | Feature | Objective | Output Check |
|------|--------|----------|-------------|
| 1 | Enemy | Add moving enemy | Player loses on contact |
| 2 | Animation | Animate sprites | Visible animation |
| 3 | UI | Moves on screen | Moves displayed in window |

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

To be able to start the game, you have to compile all the files using the command:
```
make
```

To be able to implement the bonus, you have to compile using the command:
```
make bonus
```

To run the game you may choose any map inside ```/maps``` folder. The command should be as follows:
```bash
./so_long maps/<map_file>
```
### Game Test

To simplify testing you can copy paste the commands listed below:

| Test Case | Command |
|---|---|
| An invalid empty map | `./so_long maps/invalid_map_empty.ber` |
| An invalid map with an extra newline | `./so_long maps/invalid_map_extra_newline.ber` |
| An invalid map with invalid characters | `./so_long maps/invalid_map_invalid_character.ber` |
| An invalid map with multiple exits | `./so_long maps/invalid_map_multiple_exits.ber` |
| An invalid map with multiple starting positions | `./so_long maps/invalid_map_multiple_starts.ber` |
| An invalid map with no collectibles | `./so_long maps/invalid_map_no_collectibles.ber` |
| An invalid map with no exit | `./so_long maps/invalid_map_no_exit.ber` |
| An invalid map with no path to a collectible | `./so_long maps/invalid_map_no_path_to_collectible.ber` |
| An invalid map with no path to the exit | `./so_long maps/invalid_map_no_path_to_exit.ber` |
| An invalid map with no starting position | `./so_long maps/invalid_map_no_start.ber` |
| An invalid map with a wrong file extension | `./so_long maps/invalid_map_not_ber.ber` |
| An invalid map that is not enclosed by walls | `./so_long maps/invalid_map_not_enclosed.ber` |
| An invalid map that is not rectangular | `./so_long maps/invalid_map_not_rectangle.ber` |
| An invalid map with unreachable areas | `./so_long maps/invalid_map_some_area_no_access.ber` |
| A valid map bigger than the screen | `./so_long maps/valid_map_big.ber` |
| A valid map with an enemy | `./so_long maps/valid_map_enemy.ber` |
| A valid smallest map executable | `./so_long maps/valid_map_small.ber` |
| A valid map | `./so_long maps/valid_map.ber` |

## Resources

AI used for understanding mlx library and support for understanding different functions
Used itch.io for xpm ideas
42paris/minilibx-linux - for library and testing
https://tronche.com/gui/x/xlib/events/ - for understanding linux events and hooks