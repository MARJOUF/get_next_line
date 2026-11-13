*This project has been created as part of the 42 curriculum by akmarjou.*

# get_next_line

## Description

**get_next_line** is a C function that reads a file descriptor and returns **one line at a time**, each time it is called.

```c
char *get_next_line(int fd);
```

- Returns the line that was read, **including the trailing `\n`** (if there is one).
- Returns `NULL` when there is nothing left to read or if an error occurs.
- Works with files, standard input, and any valid file descriptor.
- The buffer size used by `read()` is defined at compile time with `-D BUFFER_SIZE=n`.

**Goal:** learn about static variables, file descriptors, dynamic memory management, and how to read data in chunks without losing what was already read.

**Bonus:** the bonus version handles **multiple file descriptors at the same time** (e.g. reading from fd 3 and fd 4 alternately) without mixing their content, using one static stash per fd.

### Files

| File | Description |
|------|-------------|
| `get_next_line.c` | Main function and helpers |
| `get_next_line_utils.c` | Utility functions (`ft_strchr`, `ft_get_join`, ...) |
| `get_next_line.h` | Header file |
| `get_next_line_bonus.c` | Bonus: multiple fd support |
| `get_next_line_utils_bonus.c` | Bonus utilities |
| `get_next_line_bonus.h` | Bonus header |

## Instructions

### Compilation

Mandatory part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Bonus part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

> `main.c` is your own test file. It is not part of the project.

### Execution

Example of a simple `main.c`:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Then run:

```bash
./gnl
```

You can try different buffer sizes (`1`, `42`, `9999`, `10000000`) to test that the function works with any value.

## Algorithm

The idea is to keep what has been read but not yet returned inside a **static variable** called `stash`. Since a static variable keeps its value between calls, the function "remembers" the leftovers of the previous read.

Each call to `get_next_line(fd)` follows these steps:

1. **Check the input**: if `fd < 0` or `BUFFER_SIZE <= 0`, return `NULL`.
2. **Read until a newline is found**: while the `stash` does not contain a `\n`, call `read()` with `BUFFER_SIZE` bytes, then append the new buffer to the `stash` (`ft_get_read` + `ft_join`). Stop when a `\n` is found, when `read()` returns `0` (end of file), or when it returns `-1` (error).
3. **Extract the line** (`ft_get_one_line`): copy the `stash` from the start up to and including the first `\n` (or up to the end of the string if there is no `\n`) into a newly allocated string.
4. **Clean the stash** (`ft_get_new_stash`): move everything after the `\n` to the start of the `stash`. If nothing remains, free the `stash` and set it to `NULL`.
5. **Return the line**.

**Why this approach?**

- Reading in chunks of `BUFFER_SIZE` reduces the number of `read()` calls, while the `stash` makes sure no character is lost when a chunk contains more than one line.
- The function never reads more than needed to find the next `\n`, so it works well on large files and on input such as stdin.
- Memory is freed as soon as it is no longer needed (buffer after join, stash when empty, everything on error), which avoids leaks.

**Bonus:** instead of a single `static char *stash`, the bonus uses `static char *stash[1024]`. Each file descriptor uses its own `stash[fd]`, so reading from several files alternately works correctly.

## Resources

- [`read(2)` man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static variables in C](https://en.wikipedia.org/wiki/Static_variable)
- [File descriptors explained](https://en.wikipedia.org/wiki/File_descriptor)

### Use of AI

AI was used for:

- getting ideas for edge cases to test.
- understanding the concept of static variables.

All the code was written, tested, and understood by me.