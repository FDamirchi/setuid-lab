# setuid-lab

A small educational C project for understanding Linux `setuid`, real UID, effective UID, and command execution with `execvp`.

Inspired by the OverTheWire Bandit `bandit20-do` challenge.

## What It Does

The program prints:

* Real UID
* Effective UID

Then it executes a command passed as an argument.

## Build

```bash
gcc -Wall -Wextra -o setuid-demo setuid-demo.c
```

## Run

```bash
./setuid-demo <command>
```

Example:

```bash
./setuid-demo id
```

## setuid Test

```bash
sudo chown test:test ./setuid-demo
sudo chmod 4755 ./setuid-demo
./setuid-demo id
```

## Note

This project is for learning purposes only. Do not use setuid binaries carelessly on real systems.
