# Philosophers (42 Prague project)

> ⚠️ WARNING: This repository contains an example of *bad code*.  
> The project seems to work fine at first glance, but it fails when checked with valgrind --tool=helgrind.  
> There are possible deadlocks, race conditions, and synchronization issues that are not visible without proper tools.  
> Don't repeat this mistake — always check your code with Valgrind and Helgrind!

---

## Description

The *Philosophers* project is a classic multi-threading problem designed to teach students about thread management, synchronization, mutexes, and avoiding deadlocks.

The goal is to simulate a group of philosophers sitting at a table, eating, thinking, and not starving to death — all while sharing limited resources (forks).

This project is part of the School 42 curriculum.

---

## How to Compile

```bash
make
```

---

How to Run
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
Example:
```
./philo 5 800 200 200
```

---


Example of Valgrind usage
```
valgrind --leak-check=full ./philo 5 800 200 200
```
Example of Helgrind usage
```
valgrind --tool=helgrind ./philo 5 800 200 200
```
