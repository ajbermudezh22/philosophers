# Philosophers

This project is part of the 42 school curriculum and consists of implementing the classic concurrency problem known as the **Dining Philosophers Problem**.

The main goal of this project is to understand **thread creation**, **mutexes**, and how to avoid **data races**, **deadlocks**, and **starvation** in concurrent systems.

## 🧠 The Problem

Imagine five philosophers sitting at a round table. Each has a plate of spaghetti. A fork is placed between each pair of philosophers. To eat, a philosopher needs to pick up **both forks**. Philosophers alternate between **thinking**, **eating**, and **sleeping**. The problem is to implement this logic without creating a deadlock (where no one can eat) or starvation (where a philosopher never gets to eat).

## ✅ Project Requirements

- No data races (validated using **Helgrind**) ✅
- No memory leaks ✅
- No philosophers dying unexpectedly ✅
- Norm-compliant C code ✅
- Only allowed to use `pthread`, `unistd`, `stdlib`, `stdio`, and other standard C functions

## 🧪 How to Use

Compile the program:
```bash
make
```

Run it with arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:
```bash
./philo 5 800 200 200 7
```

This means:

5 philosophers

A philosopher dies if they don’t eat within 800 ms

Eating takes 200 ms

Sleeping takes 200 ms

Each philosopher must eat at least 7 times

⚠️ Important Considerations
- Philosophers are protected by mutexes representing forks
- Each philosopher has their own meal tracking mutex
- A monitor thread checks if any philosopher has died
- A death flag is shared and protected to stop the simulation cleanly
- All shared resources are freed properly on exit

