# **0xff CS50 Projects**

## Description:
This repository hosts a series of code snippets and projects completed through HarvardX's F'20 & S'21 CS50 course.

*The programs are written in C, the programming language used throughout both courses.*

**Course Website:** [CS50x 2020 Website](https://cs50.harvard.edu/x/2020/) | [CS50x 2021 Website](https://cs50.harvard.edu/x/2021/)

## Cloud-Based Integrated Development Environment
* [CS50 IDE](https://ide.cs50.io/)
    * integrates the **`cs50.h`** header file
## Local Machine Integrated Development Environment
* **OS:** Kali Linux
    * [Download Binaries](https://cdimage.kali.org/)
* **Compiler:** GCC v10.2.0
    * [Installation Guide](https://gcc.gnu.org/install/)
    * Debian Installation
         * `sudo apt-get install gcc`
* **Debugger:** GDB v9.2
    * Debian Installation
         * `sudo apt-get install gdb`

## Compiling & Running
* **Compiling:** `program.c`
   * **option 1:** `gcc -o program program.c`
      * creates **`program`** executable <br/>
   * **option 2:** `make program`
      * creates **`program`** executable
         - automatically links libraries
* **Running:** `program`
   * `./program`
------------------------------------
# **Project List**
### **1. Scratch Playground**
* Assignment Link: [CS50 F'20 - Scratch](https://cs50.harvard.edu/x/2020/psets/0/scratch/) | [CS50 S'21 - Scratch](https://cs50.harvard.edu/x/2021/)
* Scratch Link: [Planets Spiral Orbit](https://scratch.mit.edu/projects/451801134)
* File: [`SB3 File`](Projects/1.%20Scratch%20Playground/Planets%20Spiral%20Orbit.sb3)
> **Description:** <br/> <br/>
> This project implements a design of one's choice in MIT's block-based and visual programming platform - [scratch](https://scratch.mit.edu). The program I created and developed, `Planets Spiral Orbit`, features two planets that orbit a common star, their sun; which they spiral out of as time passes.
<br/>

### **2. Hello World**
* Assignment Link: [CS50 F'20 - Hello World](https://cs50.harvard.edu/x/2020/psets/1/hello/) | [CS50 S'21 - Hello World](https://cs50.harvard.edu/x/2021/psets/1/hello/)
* File: [`hello.c`](Projects/2.%20Hello%20World/hello.c)
> **Description:** <br/> <br/>
> This program prompts the user for a `name` and prints "hello, `name`" to the console; a variation of new programmer's traditional first written program 'hello world.' *The source code file includes notes from class that explain C's syntax and a few important introductory guidelines (or rules of C) for beginners in the subject.*
<br/>

### **3. Mario**
* Assignment Link: [CS50 F'20 - Mario](https://cs50.harvard.edu/x/2020/psets/1/mario/more/) | [CS50 S'21 - Mario](https://cs50.harvard.edu/x/2021/psets/1/mario/more/)
* Files: [`mario.c`](Projects/3.%20Mario/mario.c) | [`marioe.c`](Projects/3.%20Mario/marioe.c)
> **Description:** <br/> <br/>
> This program prompts the user for a `height` and draws two adjacent pyramids of such, separated by spaces. The pyramids are modeled after those that appear in Nintendo’s Super Mario Brothers video game, using hashes (#) to represent bricks. There are two versions of the program, each of which uses a different approach: `mario.c` uses relational positioning and `marioe.c` uses euclidean transformation.
<br/>

### **4. Credit**
* Assignment Link: [CS50 F'20 - Credit](
https://cs50.harvard.edu/x/2020/psets/1/credit/) | [CS50 S'21 - Credit](https://cs50.harvard.edu/x/2021/psets/1/credit/)
* File: [`credit.c`](Projects/4.%20Credit/credit.c)
> **Description:** <br/> <br/>
> This program prompts the user for a credit or debit card `number` and determines whether it is valid or invalid. The validity is determined using card number's length rules and the starting (first two) digits signature, along with using the Luhn's Algorithm to determine if it has a valid checksum.
<br/>

### **5. Readability**
* Assignment Link: [CS50 F'20 - Readability](https://cs50.harvard.edu/x/2020/psets/2/readability/) | [CS50 S'21 - Readability](https://cs50.harvard.edu/x/2021/psets/2/readability/)
* File: [`readability.c`](Projects/5.%20Readability/readability.c)
> **Description:** <br/> <br/>
> This program prompts the user for `text` and calculates the U.S. grade level required to read and comprehend it. The Coleman-Liau readability index is calculated, and the required grade level is then printed to the console.
<br/>

### **6. Caesar**
* Assignment Link: [CS50 F'20 - Caesar](https://cs50.harvard.edu/x/2020/psets/2/caesar/) | [CS50 S'21 - Caesar](https://cs50.harvard.edu/x/2021/psets/2/caesar/)
* File: [`caesar.c`](Projects/6.%20Caesar/caesar.c)
> **Description:** <br/> <br/>
> This program requires the user to provide a single command line argument, a `key` which is used to encrypt the `message` they are later prompted for. It is a partial implementation of the Caesar Encryption Algorithm, which uses alphabetical rotation.
<br/>

<!--

### **X. Template**
* Assignment Link: [CS50 F'20 - Name](https://linkfa20) | [CS50 S'21 - Name](https://linksp21)
* File: [`name.c`](Projects/X.%20Template/name.c)
> **Description:** <br/> <br/>
> `DETAILS IN PROGRESS`
<br/>

-->
