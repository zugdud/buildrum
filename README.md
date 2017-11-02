# Buildrum

Buildrum is an abandoned personal game project using SDL. It isn't really much of a game, it will build/run, you can scroll the map and build objects, however one cannot actually "win".

To build on Linux:

 * make working directory: `mkdir buildrumWork`
 * change to working directory: `cd buildrumWork`
 * clone buildrum source repo: `git clone https://github.com/zugdud/buildrum.git`
 * clone buildrum game-assets repo: `git clone https://gitlab.com/zugdud/game-assets.git`
 * create Makefile symlink: `ln -s build/linux/Makefile .`
 * make Buildrum.bin: 'make'
 * create symlink for game-assets , Buildrum.bin will search current directory for a files directory with these assets: `ln -s ../game-assets/ files`
 * Run buildrum.bin: `./Buildrum.bin`
