## Installation

To compile and run the application, please, follow these steps:

- Ensure the board connection to your PC.
- Update Makefile with correct IP address of your board.
- Update import paths in `render_controller.cpp` and `player.cpp` files. (The application needs to import some custom graphic assets from the assets directory. You need to replace current imports with the correct ones for your system).
- From the project’s root directory compile and launch the application using make run command via terminal.