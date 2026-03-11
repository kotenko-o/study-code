# Lab 1: From C to C++

This lab focuses on getting started with C++ especially for programmers familiar with C.

All the following sections of this and the other labs in this directory follow the following level of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟢 Section I: Get running
The goal of this section is to run your first C++ project.

### Task Description

* Open GitHub Codespace with the C++ project configuration
* Create a file called helloWorld.cpp
* Write an application that prints __Hello World!__ on the console
* Now open the "Run & Debug" view in VSCode and select the "Run/Debug C++" option before pressing the green Play-Button
* Ensure that the text is correctly printed out on the terminal
* Now navigate with the terminal into the folder where you stored your helloWorld.cpp
* Delete the previously created executeable file from the folder
* Execute the following command:
```bash
g++ helloWorld.cpp -o helloWorld
```
* Then run the newly created executable file with:
```shell
./helloWorld
```

### Hints
* Feel free to repeat this process on your local machine to ensure a correct setup there too
* If you struggle with these steps or wonder how to get running on your private, local machine, you can follow the lab1 of the C course which can be found [in this same repo](https://github.com/christian-braunagel/study-code/tree/main/courses/coding-in-C/Lab_1)

## 🟢 Section II: Age Validation

The goal of this section is to get to know some new features of the C++ language including bool, namespaces, input/output via streams.

### Task Description
Your task is to implement a software that receives the age of an user via keyboard and determines if the user is a kid/teenager, an adult or a senior citizen.

### Requirements

* Create a namespace called __validation__
* Inside it, implement two functions:
```c
bool isAdult(___ age)
```
* The function should return:
   * true if age is 18 or older
   * false otherwise
```c
bool isSenior(___ age);
```
* The function should return:
   * true if age is 65 or older
   * false otherwise

* As data type for the parameters, you should use a portable type from \<cstdint>.
* Do not use the __using__ keyword.
* Output of the main program should look like this:
```c
Please enter your age: 77
You are 77 years old.
That means that you are a senior citizen.
```
```c
Please enter your age: 48
You are 48 years old.
That means that you are an adult.
```
```c
Please enter your age: 13
You are 13 years old.
That means that you are still a kid or teenager.
```
* Use the portable data type __uint8_t__ in the main to store entered age.
* Implement it with and without the keyword __using__

### Questions & further tasks
Note: Write the answers for the questions in the code as comments.
* What exactly is the problem when using __uint8_t__ for storing the entered age of the user?
* Fix the issue when using __uint8_t__ by using an integer and static casts instead.
* Which other portable data types would make sense in this example?


