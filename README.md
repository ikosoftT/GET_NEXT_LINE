*This Project has been Created as part of 42 curriculum by <yikoubaz>.*

# get_next_line

## Description 

This Project Implements a function that returns one line at a time from a -  <FD> "File Descriptor" (a fd = its a varaible number Gived by OS for Each Process)
Used to define the Address of each File.
Bonus Part : Extende this Logic to Read from Multiple FDs at Same Time.

# Instractions

#### 1 - Git clone the repo via (https://github.com/ikosoftT/GET_NEXT_LINE.git)

#### 2 - `cd GET_NEXT_LINE && code .` 

#### 3 - Now You Can See <b>Source Code</b>

# Resources

#### 1 - 42 Guide (https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line)

--------------------------------

#### 2 - File Descriptors : (https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)

--------------------------------

#### 3 - System Call (https://www.geeksforgeeks.org/operating-systems/introduction-of-system-call/)

--------------------------------
# Usage Examples

## Thanks For : <img src="https://camo.githubusercontent.com/d0beb54f0e6bd0e010b1accb1f7efb15f61534beb79feef434565b2995c2cf87/68747470733a2f2f7062732e7477696d672e636f6d2f70726f66696c655f696d616765732f313437303332343339363039353036363132302f74384635416935375f343030783430302e6a7067">

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char    *line;
    int fd;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        perr("Error While OpeningFile.");
    
    // Method 1 :  Read Whole File Repeated Calls using Loop 
    
    while ((line = get_next_line(fd)))
    {
        printf("%s",line);
        free(line);
    }

    // Method 2 :  Read Line By Line at Singal Call 
    
    line = get_next_line(fd);
    printf("%s",line);
    free(line);
  
    return (0);
}

```
