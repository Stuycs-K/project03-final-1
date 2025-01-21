# Dev Log:

This document must be updated daily by EACH group member.

## Albert

### 1/6/2024- Added File Headers
Expanded description including how much time was spent on task.

### 1/7/2024 - Understanding ncurses
Watched tutorials and looked at webpages

### 1/11/2024 -

###  1/12/2024 - DId NOthing
Went to Grandparent's place for Grandma's birthday then dragged to Costco, got home at 8PM meaning that file directory stuff got delayed

### 1/13/2024 - Append done, make error
When testing got these errors, finished append code for when adding at the end of a line

/usr/bin/ld: main.c:(.text+0x1d3): undefined reference to `LINES'
/usr/bin/ld: main.c:(.text+0x20c): undefined reference to `stdscr'
/usr/bin/ld: main.c:(.text+0x214): undefined reference to `wgetch'
/usr/bin/ld: main.c:(.text+0x229): undefined reference to `printw'
/usr/bin/ld: main.c:(.text+0x230): undefined reference to `stdscr'
/usr/bin/ld: main.c:(.text+0x238): undefined reference to `wrefresh'
### 1/13/2024 - Fixed make errors
-Fixed Previous errors by adding flags to makefile when compiling prog
-Still have to decide how to handle offset adding
-Fixed seg fault error for printing out directory code but not getting any results
- 30-ish minutes spent

### 1/14/2024 - Finished offset
  - FInished offset to use -i to iterate backwards instead of math
  -Just need to finish buffers now

 1 hour total spent

 ### 1/15/2024 - Worked on display
  - Testing display worked but the text immediately disspapeared
  - Was getting seg fault when testing on lab machine

### 1/16/2024 - FInished display
  - Fixed seg fault issue on lab machine because I didn't allocae memory for a buffers  
  - Moved initscr and keyboard setup to another function as that was what was cuasing the previous dissappeance

### 1/17/2024 - More fixing
  - Fixed issue in display that caused segfault
  - Found issue when opening files that created new file with a newline character

### 1/18/2024 - Bug fixing Displays
  -Fixed issue with opens that caused arrow keys to not work
  - Fixed issue with display that caused it to skip every second line

### 1/19/2024 - New Function for Dlete, finished esc, uses for append and offsetAdd?
  - Wrote windowdelete that shifted all chars in an ncurses window to the left from a deleted point
  - exitFile works
  - More testing shows that opens works
### 1/20/2024 - More final bug fixing
  - Testing shows that editing file and writing to it's possible
  - Merged append's functionality into offsetAdd
  - Changed offsetAdd to work for files as previously only worked for char pointers
  - Fixed double input appearing in ncurses window by using noecho
  - We have no scroll functionality
  - 13 hours spent
