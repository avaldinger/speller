# Speller
==== 

Speller application written in C as part of the [![CS50 Badge](https://img.shields.io/badge/-CS50-red)](https://cs50.harvard.edu) class problem sets.

Table of content
----
* [General info](#general-info)
* [Setup](#setup)
* [Technologies](#technologies)

### General info

Speller program written in C. The aim of the application is to check whether the words in a given text can be found in the dictionary uploaded to the application. During the problem set I had to implement the functions for the actual filters: **load**, **hash**, **size**, **check** and **unload** in the `dictionary.c` file. (Application efficiency could be improved by using fgetc() to read in files and appending new words to the beginning of each linked list rather than to as a new last node.)

### Setup

The application can be run locally or using the [![CS50 Badge](https://img.shields.io/badge/-CS50-red)](https://cs50.harvard.edu) <a href="https://ide.cs50.io">IDE</a> after logging in with your GitHub account.

To run the program:
 1. It needs to be compiled: `$ make speller.c`
 2. For running a text needs to be specified: `$ ./speller texts/example.txt`
 
### Technologies
 
 Libraries:
 * stdio.h
 * stdint.h
 * stdbool.h
 * string.h
 * ctype.h
 * stdlib.h
 * [![C](https://img.shields.io/badge/-C-blue)](https://www.cprogramming.com/)
