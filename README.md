# minitalks
In this project, you will be creating a program that can exchange data using a tool called UNIX signals.

Think of it like a special language that two programs can use to talk to each other and share information.

This is version 2 of the project.


Here is a brief description of each function and how to use them inside this project:

-----

# CLIENTS AND  SERVERS
![image](https://user-images.githubusercontent.com/116757689/229496153-4e6f3854-1176-49c3-be70-7cf33c3c9ee1.png)


understand the concept of clients and servers.

Imagine you're at a restaurant. The waiter comes to your table and asks you what you'd like to order. You tell the waiter your order, and the waiter goes to the kitchen to get the food for you. In this scenario, you are the client, and the waiter is the server.

Similarly, in the world of computing, a client is a computer program or device that requests services or resources from another program or device, which is the server. The client sends a request to the server, and the server responds with the requested information or performs the requested action.

For example, when you open a web browser and type in a website address, your browser acts as a client and sends a request to the server hosting the website. The server then responds by sending the requested web page to your browser, which then displays it on your screen.

In summary, clients and servers work together to allow devices and programs to communicate with each other and exchange information, much like a customer and a waiter at a restaurant.




-----
# Bitwise operators:

![image](https://user-images.githubusercontent.com/116757689/229496625-b0a55049-5408-4b23-b572-50c1a13dc3d1.png)

Bitwise operators are used to manipulate individual bits in binary numbers. In C programming language, there are six bitwise operators:

* Bitwise AND (&)
* Bitwise OR (|)
* Bitwise XOR (^)
* Bitwise NOT (~)
* Left shift (<<)
* Right shift (>>)


These operators allow you to perform operations on individual bits in a binary number, such as setting or clearing a particular bit.

[![BITWISE OPERATORS](https://ytcards.demolab.com/?id=WBim3afbYQw&ab_channel=PortfolioCourses&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&width=250&duration= "bitwise operator")](https://youtu.be/WBim3afbYQw)

-----

# ASCII encoding:
![image](https://user-images.githubusercontent.com/116757689/229495654-72ca6e86-1892-4222-9c3d-69f2c361b43c.png)

ASCII (American Standard Code for Information Interchange) is a character encoding standard used to represent text in computers. It uses 7 bits to represent 128 characters, including letters, numbers, and special characters. In C programming language, each character is represented by an integer value based on the ASCII encoding standard.

-----
# Signal handling functions:

In Unix-based operating systems, signals are software interrupts delivered to a process. They are used to notify a process of an event or to request that it stop running or perform some specific action. In C programming language, signal handling functions can be used to define the behavior of a process when it receives a particular signal.

-----


<details>
 <summary><h3>SIGNAL FUNCTION EXPLAINED</h3></summary>

    
# signal:
This function is used to set a signal handler for a particular signal.

The syntax for this function is:

```c
void (*signal(int signum, void (*handler)(int)))(int);
```
Parameters:

* signum: the signal number
* handler: a pointer to a function that will handle the signal
Example usage:

```c
signal(SIGINT, sig_handler);
```

-----


# sigemptyset:
This function is used to initialize a signal set to empty.

The syntax for this function is:

```c
int sigemptyset(sigset_t *set);
```
Parameters:

* set: a pointer to a signal set that will be initialized to empty
Example usage:

```c
sigset_t set;
sigemptyset(&set);
```

-----



# sigaddset:
This function is used to add a signal to a signal set.

The syntax for this function is:

```c
int sigaddset(sigset_t *set, int signum);
```
Parameters:

* set: a pointer to a signal set
* signum: the signal number to add to the set
Example usage:

```c

sigset_t set;
sigemptyset(&set);
sigaddset(&set, SIGINT);
```


-----


# sigaction:
This function is used to change the action taken by a process on receipt of a specific signal.

The syntax for this function is:

```c
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```
Parameters:

* signum: the signal number to set the action for
* act: a pointer to a struct that specifies the new action to be taken for the signal
* oldact: a pointer to a struct that will contain the previous action for the signal
Example usage:

```c
struct sigaction new_action, old_action;
new_action.sa_handler = sig_handler;
sigemptyset(&new_action.sa_mask);
new_action.sa_flags = 0;
sigaction(SIGINT, &new_action, &old_action);
```


-----



# kill:
This function is used to send a signal to a process or a group of processes.

The syntax for this function is:

```c
int kill(pid_t pid, int sig);
```

Parameters:

* pid: the process ID of the process to send the signal to
* sig: the signal to send
Example usage:

```c
pid_t pid;
int sig;
kill(pid, sig);
```



----


# getpid:
This function is used to get the process ID of the calling process.

The syntax for this function is:

```c
pid_t getpid(void);
```


Example usage:

```c
pid_t pid = getpid();
```


----


# pause:
This function is used to suspend the calling process until a signal is received.

The syntax for this function is:

```c
int pause(void);
```


Example usage:

```c
pause();
```
# sleep:
This function causes the calling thread to sleep for a specified number of seconds.

It takes a single argument, the number of seconds to sleep, and returns 0 if the sleep completed successfully.


Here is an example of how to use the sleep function:

```c
#include <unistd.h> // include the library

int main()
{
    printf("Go to sleep for 5 seconds...\n");
    sleep(5); // sleep for 5 seconds
    printf("I'm awake!\n");
    return 0;
}
````
------

# usleep:
This function causes the calling thread to sleep for a specified number of microseconds.

It takes a single argument, the number of microseconds to sleep, and returns 0 if the sleep completed successfully.


Here is an example of how to use the usleep function:

```c
#include <unistd.h> // include the library 

int main()
{
    printf("Go to sleep for 500 milliseconds...\n");
    usleep(500000); // sleep for 500 milliseconds (500000 microseconds)
    printf("I'm awake!\n");
    return 0;
}
```

----

# exit:
This function terminates the calling process immediately.

It takes a single argument, the exit status of the process, which is a non-negative integer.

A value of 0 indicates success, while non-zero values indicate an error or other status.


Here is an example of how to use the exit function:

```c
#include <stdlib.h> // include the library

int main()
{
    printf("Exiting with status code 0...\n");
    exit(0); // exit the program with status code 0 (success)
}
```
