# Get Next Line

## Project Description

The `Get Next Line` project is a part of the School 42 designed to improve your skills in handling file input/output operations in C. The objective of this project is to implement a function that reads a line from a file descriptor, returning it as a `NULL`-terminated string.

## What It Does

The `get_next_line` function allows you to read a file line by line. Each time the function is called, it returns the next line from the specified file descriptor until the end of the file is reached.

## Implementation Details

- **Language**: The project is implemented in C.
- **Main Function**:
  - `char *get_next_line(int fd)`: Reads the next line from the file descriptor `fd` and returns it as a string. If there are no more lines to read, it returns `NULL`.
- **Headers**:
  - `#include <stdlib.h>`: Used for dynamic memory allocation.
  - `#include <unistd.h>`: Used for the `read` function.
- **Buffer Size**: The size of the buffer used to read from the file descriptor is defined by the `BUFFER_SIZE` macro. You can set this macro to a desired value to control the chunk size of each read operation.

### How It Works

1. **Reading Data**: The function reads data from the file descriptor in chunks of size `BUFFER_SIZE` into a static buffer.
2. **Managing Buffer**: The static buffer retains leftover data between function calls to handle lines that span multiple reads.
3. **Extracting Lines**: The function searches for newline characters in the buffer to extract complete lines, returning them as dynamically allocated strings.
4. **Memory Management**: Allocates memory for each line it returns and ensures that leftover data is preserved for the next call.

---

This project is an excellent exercise in managing file I/O, memory allocation, and creating efficient C functions for real-world applications.
