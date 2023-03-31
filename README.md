# minitalks
In this project, you will be creating a program that can exchange data using a tool called UNIX signals.

Think of it like a special language that two programs can use to talk to each other and share information.

This is version 2 of the project.


Here is a brief description of each function and how to use them inside this project:

-----


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
