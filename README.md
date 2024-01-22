# Virtual_Machine
A simple virtual machine created from scratch written in c++


##How does it work

A virtual machine uses Real hardware resources from an already pre-existing operating system to simulate another one. In practice, this means allocating memory and creating improvised instructions for our machine to use for computing. 

In this example, we create a virtual machine, along with it's own assembler and lexer, for calculating an input file in Reverse Polish Notation. It should be noted. that even with this simple example, Our method of implementation can work with any kind of syntax and with any kind of instructions. 

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


