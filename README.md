# survivor

Game prototype using a hand rolled game engine.

## Why?

I've been programming professionally for a while now, but have not worked directly in the games industry. My focus has always been on full stack web development. I've played games my entire life starting with playing my brother's SNES when I was about 5 years old. This project is a way for me to dig deeper into some of the "behind the scenes" concepts of the game engines that I've use for hobby game dev projects; Unity, GMS2, Godot, etc.

## Assumptions

Since I'm creating this just for the sake of learning and I'm not a c++ veteran, I plan on putting as little time as possible into the build system/build processes. I want to focus on making the game and game dev concepts more than the specific ecosystem. The main goal is to create a functional small game with c++ using [raylib](https://github.com/raysan5/raylib) for graphics rendering.

This project is being built on an Ubuntu 21.04 instance running on a Dell XPS 15 laptop.

## The Art

I'm using the [Kenny Monochrome RPG asset pack](https://www.kenney.nl/assets/monochrome-rpg) as a starting point for sprites and tiles.

![Kenny Monochrome RGB Tileset Preview](https://github.com/holdenrehg/survivor/blob/main/resources/textures/tilemap_packed.png?raw=true)

---

## Building and running the project

### Dependencies

- `libxrandr-dev`
- `libxinerama-dev`

### Building (w/ cmake)

```console
$> bin/build
```

### Running

```console
$> build/Survivor
```
