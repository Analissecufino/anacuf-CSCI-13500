# Pointer Detective
Welcome to the agency detective. We ran into a couple of tough cases, and we need your help. As the best pointer detective in town, we thought of you first. 

## Introduction

A mysterious bug has appeared in several C++ programs. Your job as a **Pointer Detective** is to investigate each program and determine what is happening behind the scenes.

For **each mystery**, complete the following tasks **before running the program**:

1. Predict the program's output.
2. Explain **why** the output occurs.
3. Draw the call stack while the function executes.
4. Identify whether the function uses:
   - Pass by Copy
   - Pass by Reference
   - Pass by Pointer

After completing your predictions, compile and run the program to verify your answers.

---

# Mystery #1 – The Copycat

**Concepts:** Pass by Copy, Scope, Call Stack

```cpp
#include <iostream>

void addFive(int number)
{
    number += 5;
    std::cout << "Inside addFive(): " << number << std::endl;
}

int main()
{
    int value = 10;

    addFive(value);

    std::cout << "In main(): " << value << std::endl;
}
```

### Questions

1. What is the output of this program?

 The output is "In main(): 10"

2. Why doesn't `value` change after calling `addFive()`?

 The function uses pass by copy, meaning the value in addFive() only recieves a copy of value and does not affect the value in main

3. Where does the variable `number` exist?

number exists in addFive() function only (local scope)

4. Draw the call stack while `addFive()` is executing.

top --> addFive() 
        number = 15 

Bottom -> main()
        value = 10 
           
5. What happens to `number` after the function returns?

number gets dropped and no longer exists in memory 

---

# Mystery #2 – The Mirror

**Concepts:** References, `const`, Modifying Variables

```cpp
#include <iostream>

void investigate(int& suspect, const int& clue)
{
    suspect += clue;

    std::cout << "Inside investigate(): "
         << suspect << " " << clue << std::endl;
}

int main()
{
    int score = 10;
    int bonus = 5;

    investigate(score, bonus);

    std::cout << score << " " << bonus << std::endl;
}
```

### Questions

1. What is the output of this program?

    Inside investigate(): 15 5
    15 5 

2. Why does `score` change while `bonus` does not?

When the function is called, only suspect is being modified with & , while clue is const &. This means it cannot be modified using clue, but suspect will be modified and affect the variable in main. 

3. Why is `clue` declared as a `const` reference?

we want the function to be able to access and accept a value from the variable in main without changing it.

4. What would happen if the function attempted to modify `clue`?

The compiler would send an error

5. Draw the call stack while `investigate()` is executing.

top-->        investigate()
              suspect 
              clue 

bottom-->     main()
              score = 10 
              bonus = 5

---

# Mystery #3 – Following the Pointer

**Concepts:** Raw Pointers, Dereferencing, `nullptr`

```cpp
#include <iostream>

void investigate(int* evidence)
{
    if (evidence != nullptr)
    {
        *evidence *= 2;
    }
}

int main()
{
    int clue = 7;

    investigate(&clue);

    std::cout << clue << std::endl;
}
```

### Questions

1. What is the output of this program?

14

2. Why do we pass `&clue` instead of `clue`?

the parameter variable in investigate() is taking in a memory address not the value of clue - flags &clue to pass because of the &

3. What does `*evidence` do?

it accesses the int value sitting at the memory address passed in through evidence 

4. Why is the `nullptr` check important?

gaurds against following pointer that leads to undefined behvaior 

5. What would happen if the function was called as `investigate(nullptr);`?

nothing would get returned 

6. Draw the call stack while `investigate()` is executing.

top --> investigate()
        evidence = memory address 

bottom --> main()
           clue = 7

---

# Mystery #4 – The Master Case

**Concepts:** Pass by Copy, Pass by Reference, Pass by Pointer, Return Values

```cpp
#include <iostream>

int mysteryA(int x)
{
    x += 10;
    return x;
}

void mysteryB(int& y)
{
    y *= 2;
}

void mysteryC(int* z)
{
    if (z != nullptr)
    {
        (*z)--;
    }
}

int main()
{
    int value = 5;

    value = mysteryA(value);
    mysteryB(value);
    mysteryC(&value);

    std::cout << value << std::endl;
}
```

### Questions

1. Predict the output of the program.

29

2. Draw the call stack after each function call.

- after mysteryA() -

main()
value = 15

- after mysteryB() -

main()
value = 30

- after mysteryC() -

main()
value = 29

3. Which function uses:
   - Pass by Copy? mysteryA()
   - Pass by Reference? mysteryB()
   - Pass by Pointer? mysteryC()

4. Which functions modify the original variable?

mysteryB() and mysteryC()

5. Why does `mysteryA()` return a value, while `mysteryB()` and `mysteryC()` do not?

we reassign mysteryA() to value because it is using pass by copy, while mysteryB() and mysteryC() already have access to modify value built in the function parameters (reference and pointer)

6. Which approach would you choose if your goal was to modify the original variable? Explain your reasoning.

I feel that mysteryB() (pass by reference) is the cleanest method. With pass by pointer you need to check for null pointer and involves slightly more complex syntax.

---

# Reflection

Answer the following questions in complete sentences.

1. What is the difference between passing a variable by copy, by reference, and by pointer?

Passing a variable by copy is the most isolated. It is used to create a new variable with a different memory address and the modifications stay inside the function. Pass by reference in a function will directly modify the value in main, all under a different name. Pass by pointer takes in a new variable with the memory address of the original variable in main. 

2. When would you choose to use a reference instead of a pointer?

if you want to take on less risk you would choose a reference since it is always tethered to a real value and cannot cause a crash if you dont dereference with the proper check. 

3. Why might a function accept a pointer instead of a reference?

Sometimes you do need to have a less restrictive range of possibilities (reference always needs to refer to something), in that case you would use pointer (null check). 

4. What role does the `const` keyword play when working with references and pointers?

It lets a function read in a referenced value from main without modifying it.  

5. How does understanding the call stack help explain why variables change—or do not change—during function calls?

Visualizing the call stack provides shows how every functions frame looks like and what it contains. 