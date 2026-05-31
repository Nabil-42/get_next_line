# get_next_line

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=flat&logo=c)](https://github.com/Nabil-42/get_next_line)
[![School](https://img.shields.io/badge/%C3%89cole_42-Paris-00babc?style=flat)](https://42.fr)
[![Norminette](https://img.shields.io/badge/Norminette-compliant-brightgreen?style=flat)](https://github.com/42School/norminette)

A C function that reads one line at a time from a file descriptor, with static buffer management across multiple calls.

## Description

`get_next_line` reads from any file descriptor (file, stdin, pipe) and returns one complete line per call. It handles arbitrary buffer sizes defined at compile time via `BUFFER_SIZE`, and correctly manages partial reads across consecutive calls using a static variable.

## Prototype

```c
char *get_next_line(int fd);
```

Returns the next line (including the trailing `\n` if present), or `NULL` on EOF or error.

## Stack

- **Language**: C
- **Key concepts**: static variables, dynamic memory allocation, file descriptor I/O (`read(2)`), buffer management

## How It Works

```
get_next_line(fd)
  → read BUFFER_SIZE bytes into a static remainder buffer
  → search for '\n' in the accumulated buffer
  → if found: extract and return the line, keep the rest for next call
  → if EOF: return remaining content without '\n'
  → on error or empty: return NULL
```

## 42 Project Info

| Field | Value |
|-------|-------|
| **Project** | get_next_line |
| **Circle** | 1 |
| **Norminette** | Compliant |

## What I Learned

- Managing persistent state across function calls with static variables
- Efficient string splitting with dynamic memory allocation
- Handling edge cases: no newline at EOF, empty files, multiple file descriptors (bonus)