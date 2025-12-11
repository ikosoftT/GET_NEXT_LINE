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
# Usage Examples (Additional.)

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
## EXPLAINTATIONS (What the FREE is Going on..)

"well well well , <b>GET_NEXT_LINE</b> as u alread Known.
 a Function that Reads a Line from a <b>FD</b> - (File Descriptor).
 Each Time We Call it till the File Ends or Reaching EOF.
 ### How That Works BROO??
 
 *Well if it Work Don't Touch it Haha*
 okey , Imagine we have a file Called "test.txt" its Content >>
 ```
 test.txt
 *Line1
  Line2
  Line3
 *
```
## THE ALGO as Follow : 

### 1 - Read the file

### 2 - Extract the line

### 3 - Save the leftOver '\n' Data

### 4 - Return Valid Line

*Note :  For Each Step : its Own - Function*

### 1 - Read the file

```c
char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (stash)
				free(stash);
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}
```
### 2 - Extract the line

```c
char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}


```

### 3 - Save the leftOver '\n' Data

```c
char	*ft_save_line(char *stash)
{
	char	*left_data;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	left_data = malloc(ft_strlen(stash) - i + 1);
	if (!left_data)
		return (NULL);
	j = 0;
	while (stash[i])
		left_data[j++] = stash[i++];
	left_data[j] = 0;
	free(stash);
	return (left_data);
}
```
### gnl - >>>
```c
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash || !*stash)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_extract_line(stash);
	stash = ft_save_line(stash);
	return (line);
}

*Note : Remmeber the File (test.txt) let Goo Through the Flow Now,gooo*
First i pass FD of (test.txt)
i Call readFile FUNC with those params (fd,stash) Wait.. STASH ?? 
<b>STASH</b> its a static variable <b>Static Varaible</b> What is this ?? bruu..
okey okey haha :)..
### Static Varaible : its all variables defined with 'static' keyword
wich Tells the compiler to store it in <strong>DATA-SEGMENT-Storage</strong>
well : the value Contains will not Erase tiil the <strong>Whoole Programm.Die :)</strong>
not Like <b>Normal-Varaibles</b>
they Die , and Live with the function <b>Call</b>.
2 - Inside read_func we have a <strong>System Call Function</strong>
ho....<b>read functionnnnnnnn</b> haha yeah!!
## System Call : before , we Must KNOW there is <b>USER MOD</b> and <b>Kernel Mod</b>
### USER-MOD = almost Programms runing on our system : they don't have direct access to Our's Computer <b>Resources : such as. [RAM,CPU]</b> etc..
this Desgined to Protect Our SYSTEM CRASH.
### KERNEL-MOD = before What is KERNEL ? kerenel its  peaice of Software that Manges BothSIdes (Software and HardWare) Make them Communicate .

# Additional Learning 
    ## 1  - File Descriptors : 
     https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/

# Finaly 

*Everything Was Made By Love && Passion BY <b>yikoubaz</b>.*

*BIG THANKS FOR : 1337.MA*
