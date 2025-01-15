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
