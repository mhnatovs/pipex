*This project has been created as part of the 42 curriculum by mhnatovs.*

# Pipex

## Description
Pipex is a 42 school project that drills into the depths of UNIX mechanisms. The program mimics the behavior of the shell pipe command: < file1 cmd1 | cmd2 > file2. It handles the redirection of standard input and output, executes system commands via child processes, and manages the synchronization between them using pipes.

## Features
- Redirection: Handles input from a file and output to another file.
- Piping: Implements a pipe to pass the output of the first command as the input to the second.
- Path Resolution: Searches the PATH environment variable to find and execute binaries.
- Error Handling: Robust management of file permissions, non-existent commands, and memory allocation.

## Instructions

### Prerequisites
- Linux or macOS
- `cc` compiler
- `make`
  
### Compilation
To compile the project, run:
```bash
make
```
This will produce the pipex executable.

**Usage:**
The program should be executed as follows:
- `file1`: Input file (source).
- `cmd1`: First command with its parameters.
- `cmd2`: Second command with its parameters.
- `file2`: Output file (destination).

**Example:**
This is equivalent to the shell command: `< infile ls -l | wc -l > outfile`

#### Technical Concepts
- pipe():Creating a unidirectional data channel for inter-process communication.
- fork(): Creating child processes to run multiple commands simultaneously.
- dup2(): Redirecting file descriptors (STDIN/STDOUT) to the pipe or files.
- execve(): Replacing the current process image with a new process (executing the command).
- Environment Variables: Parsing the char **envp to locate command binaries.

#### AI Usage
AI was utilized during development for:

- Learning support:

Visualizing the flow of file descriptors ($0, 1, 2$) during a fork() and dup2() call.
Explaining the necessity of closing unused pipe ends to avoid hanging processes (EOF behavior).
Understanding how waitpid() synchronizes the parent process with its children.

- Debugging assistance:

Identifying "zombie processes" and ensuring all children are properly reaped.
Debugging edge cases like /dev/urandom as input or commands without absolute paths.

What I did NOT use AI for:

The logic of the pipe-to-child-process execution flow.
Handling the environment path parsing and command split logic.
###### Team
mhnatovs (https://github.com/mhnatovs) — Single Contributor / Developer
