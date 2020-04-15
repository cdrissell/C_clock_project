# C_clock_project

This program turns your terminal into a digital alarm clock of sorts. It shows the current time as well as the calendar for the month. The program is written in C.

---

## Get Started

To run the program, access the directory where the files are. Type "./clock" to run the program. If there is no file named "clock" in the directory, compile the C file by running "gcc -o clock clock.c". This turns the C file into an executable file named "clock". Now you can run it by entering "./clock".

---

### Prerequisites

These are the things you will need to have installed on your machine to run:

- GCC
  - To check if GCC is installed, type "gcc -v" in the command line
  - If it is not installed, go here https://gcc.gnu.org/install/

---

### Uses

- Flags
  - -h
    - run the file with the flag '-h' to access the help page for the program
      - This is still a work in progress
  - -c
    - run the file with the flag '-c' to change the color of the clock's text.
    - Example: './clock -c blue'
    - Available colors:
      - red, green, yellow, blue, magenta, cyan, white
  - FUTURE:
    - Working on a timer function that would use the flag '-t' and set off an alarm after a specified amount of time.
