# TREEkinator
## General information

**TREEkinator** is a text-based game of guessing for characters and objects. The character database is generated and updated according to user input.

The program makes use of data structures such as a stack and binary tree and makes generating .png and .svg files with the character library graph.

Modes of the game:
+ *Guessing*. After receiving the input from the user in the form of "yes" or "no", the program attempts to determine the character that the user is guessing.
![guess](https://github.com/A-Elbereth-Gilthoniel/images/blob/main/guessing.png)
+ *Definition*. The program receives the name of a character from the user and then generates a route along which that character is searched.
![definition](https://github.com/A-Elbereth-Gilthoniel/images/blob/main/definition.png)
+ *Difference*. The program displays the first difference that differs between the two names that the user has entered.
![difference](https://github.com/A-Elbereth-Gilthoniel/images/blob/main/differences.png)

---
## Program start
Go to directory **./TREEkinator/** and enter the command in the console:
```C
>>> mingw32-make        // start "makefile"
>>> ./program.exe tree.txt
```

Additional commands:
```C
>>> mingw32-make draw   // graph's creature
>>> mingw32-make clean  // cleaning folder ./obj/
```

## Graph diagram

When you run the "draw" command, the code generates a graph image in both .svg and .png file formats

For example, it is *.png*

![graph](https://github.com/A-Elbereth-Gilthoniel/images/blob/main/Tree_graph.png)
