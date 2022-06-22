# get_next_line
Des appels successifs à votre fonction get_next_line() doivent vous permettre de lire l’intégralité du fichier texte référencé par le descripteur de fichier, une ligne à la fois.
Successive calls to your get_next_line() function should allow you to read the entire text file referenced by the file descriptor, one line at a time.

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Installation

In the root of the repo, type:

```bash
#manual testing
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c get_next_line.h -D BUFFER_SIZE=12 -o get_next_line
```

## Usage
 
 ```bash
./get_next_line 0
[type something and press enter]
[press CTRL+D to exit]
```

## Comments
You'll find a better version of this function in the project <a href="https://github.com/pnielly/GNLReborn">GNLReborn</a>.
