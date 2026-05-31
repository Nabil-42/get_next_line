# Usage — get_next_line

## Prototype

```c
char *get_next_line(int fd);
```

## Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int  fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Behavior

- Returns the next line from `fd` including the trailing `\n` (if present)
- Returns `NULL` on EOF or error
- Reads `BUFFER_SIZE` bytes per `read()` call
- Handles multiple file descriptors simultaneously (bonus version)
- The caller is responsible for freeing the returned string