# Virtual_Machine
A simple virtual machine created from scratch written in c++


This is a topic from the module Advanced Programming Concepts at Saxion University. 

#### Team members

> Aleksandar Dikov(528052)<br>

> Stiliyan Batinkov(530007)<br>
## How does it work

A virtual machine uses Real hardware resources from an already pre-existing operating system to simulate another one. In practice, this means allocating memory and creating improvised instructions for our machine to use for computing. 


In this example, we create a virtual machine, along with it's own assembler and lexer, for calculating an input file in Reverse Polish Notation. It should be noted. that even with this simple example, Our method of implementation can work with any kind of syntax and with any kind of instructions. 

The virtual machine can only read binary instructions created from the assembler and lexer, so for this case if we want to run any program we want, we must have compile it into a binary file for tha machine to read. This is done by feeding our program into the assembler. 
## Installation 

To build this project, simply clone this repository, add a build directory and compile using cmake

```sh
git clone https://github.com/Student528052/Virtual_Machine.git
cd Virtual_Machine
mkdir build && cd build
cmake ..
cmake -build . 
```
## Using the machine

You can use this Virtual Machine as a simple calculator that can support the following operations: 
>- Addition 
>- Substaction
>- Multiplication 
>- Division

The machine can perform these calculations by simply reading from a file with the instructions. In this case, it's mathematical equasions in Reverse Polish Notation: 

```
5 3 * 
100 10 / 
14 2 * 7 /  //multiply 14 and 2 and then divide by 7 
```

## Future improvements
This virtual machine currently only uses 4 of the basic arithmatic operations. In the future it can be improved to use more advanced operations, such as power, square root and even sine and cosine functions. 

