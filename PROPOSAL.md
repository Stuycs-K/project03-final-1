Group Members: Albert Chen

Statement: This Project aims to create a simple text editor a-la Notepad which should be capable of opening and creating text files from the current directory, editing them, find and replace functionality. Though it will likely not work with other compatible files such as batch files, INI files, and log files.

UI: Will be operated solely with the command line. Upon program startup the program will display a list of all .txt files within the current directory alongside a list of data showing info like file type, date last modified, file size etc. Upon opening a file using the command line ("open file.txt") the file will open displaying the entirety of the text file. Upon entering some commands ex" append Hello Leinad" the text file will be modified while we hope that some keyboard commands may work ex.) Using backspace to delete


Allocating memory: Used to allocate struct stats as well as handling the buffer for editing the text files as well as handling what's printed out
Working with files: Open (naturally), read also for printing out the text file, write for editing the text file will be needed, fgets for reading from stdin is also needed
Finding information about files (stat and such): Mostly only relevant when selecting and opening files with statbuffer to show the user file metadata
Processes (fork, exec etc.): Main process used is exec to handle command line arguments


Timeline/Deadlines


January 11: Opening, creating and exiting files

January 16: Editing text files, (adding text to a doc deleting things etc)

January 18- Working version

Jan 20-21 Fixing bugs and Polishing




