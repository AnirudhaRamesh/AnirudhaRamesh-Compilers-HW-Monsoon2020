# Homework 5

Implement a program which prints postfix pattern of the given infix expressions.

## Installation

### Flex & Bison

```bash
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install flex bison
```

### Check Installation

```bash
$ which bison
$ which flex
```

## Usage

There are two base code templates.
* Normal Postfix pattern generation
* Postfix pattern generation using Visitor design pattern 

__Both directories have a Makefile__  

#### Compile  
```bash
$ make
```
#### Run
```bash
$ ./calc
```
#### Clean
```bash
$ make clean
```
## Note
* Do NOT change code in calc.yy or calc.cc
* Make sure you install latest versions of flex and bison
* Given code just takes an input expression and parses it(Grammar is in calc.yy). It is your job to write a Postfix method for each base code template.