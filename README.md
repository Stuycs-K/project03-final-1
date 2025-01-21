[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Vh67aNdh)
# PROJECT NAME HERE

Worst notepad is still a text editor
### GROUP NAME HERE

Albert Chen

### Project Description:

THe Project is a text editor in the vein of notepad, except missing some functionality's mainly being able to use the mouse, scrolling, and  using enter to make new lines.

### Instructions:

How does the user install/compile/run the program.
- The User needs to have ncurses on their computer as well as all the libraries listed in the main file
- Once in the directory the user just types make which starts up the UI

How does the user interact with this program?
 - On startup, the user types in one of 3(?) commands open [FILENAME], rm/remove or delete[FILENAME], cd
 - If using open, the user is then presented with the text of the file where they're able to type, and navigate between lines and places with the arrow keys
  - If opening a file that doesn't exist in the current directory, one will be created
 - To exit a file the user must print esc which also saves changes made to the file
 - If using rm/remove or delete the user simply types in that command with the name of the file that they wish to delete and upon finishing they're taken back to the home screen
 - If using cd, the user must type the full name of the path that they wish to take, after which display is ran again
