# Installation — get_next_line

## Requirements

- OS: Linux or macOS
- Compiler: gcc or clang
- Make (optional)

## Integrate in Your Project

Copy these files into your project:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

Compile with a custom `BUFFER_SIZE` (default is 42 if not specified):

```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o my_program
```