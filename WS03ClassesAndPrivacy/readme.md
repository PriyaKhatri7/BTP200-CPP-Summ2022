# Workshop #3: Classes and Privacy

In this workshop, you will use classes, access levels and member functions to create encapsulated objects. You will be doing so via the use of a class that represents a train carrying cargo.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- to define a class type
- to privatize data within the class type
- to instantiate an object of class type
- to access data within an object of class type through public member functions
- to use standard library facilities to format data inserted into the output stream
- to describe to your instructor what you have learned in completing this workshop


## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 50% of the workshop's total mark, is due on **Wednesday at 23:59:59** of the week of your scheduled lab.
- *Part 2*: worth 50% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. Te reflection doesn't have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.





# Part 1 (50%)


## Cargo Module

Create a module called `Cargo` that contains a structure named `Cargo` representing cargo carried by a train.  This module contains only the header file.  The structure should be in a namespace called `sdds`.

### Global Constants

- `MAX_DESC`: the maximum length of cargo description (not including the null terminator). Set it to 20.



## Train Module

Create a module called `Train` that contains a class named `Train` representing a train that can move cargo.  This module contains a header and an implementation file.  The class should be in a namespace called `sdds`.

### Global Constants

- `MAX_NAME`: the maximum length of a train name (not including the null terminator). Set it to 30.


### Train Class

The class should be able to store a name for a train (a human readable string to easy refer to the train; this is a statically allocated array of characters of at most `MAX_NAME` characters), an id (as an integer), and cargo (an object of type `Cargo`, dynamically allocated).

***Valid Name***: a string of at most `MAX_NAME` characters (not including the null terminator); must be not null and not empty.

***Valid ID***: an integer greater than 0.

***Valid Cargo***: any object of type `Cargo`.


#### Class Public Members

In order to interact with the private data members of the `Train` class, public member functions are needed. The following function prototypes should be placed in the `Train` header and their definitions in the implementation file (`.cpp`).

- `void initialize(const char* name, int id)`: a modifier that receives the train name and the id as parameters. If the parameters are invalid, set the object to an empty state (choose an empty state that makes sense; possible empty states could be a 0 or negative values for the id, or an empty string for the name).  If parameters are valid, copy them into the attributes.  If the name is too long, accept only the first `MAX_NAME` characters.  Make sure to initialize the cargo attribute to null.
- `bool isValid() const`: a query that returns `true` if the object contains valid data, `false` otherwise (check for empty state).
- `void loadCargo(Cargo car)`: stores the parameter in the current instance.  This function should dynamically allocate memory for a single instance of `Cargo` to the cargo pointer data member then copy over the values from the parameter to it.
- `void unloadCargo()`: removes the existing cargo from the train by deallocating the memory used. Then set the pointer to `nullptr`.
- `void display() const`: a query that prints to the screen the content of the current object. The information is printed as follow:
  - if the train is an invalid object, print
  ```txt
  ***Train Summary***
  This is an invalid train.
  ``` 
  - if the train carries no cargo, print
  ```txt
  ***Train Summary***
  Name: [NAME]
  ID: [ID]
  No cargo on this train.
  ```
  - otherwise, print
  ```txt
  ***Train Summary***
  Name: [NAME]
  ID: [ID]
  Cargo: [CARGO_DESCRIPTION]
  Weight: [WEIGHT]
  ```


## `main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.



### Sample Output

The output should look like the one from the `sample_output.txt` file.



## Submission

To test and demonstrate execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 200/w3/p1
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.





# Part 2 (50%)

In this part you must update the modules according to the specs below.


## Cargo Module

Convert the structure `Cargo` into a class.  Follow the convention that all attributes should be private.

### Global Constants

Add two more global constants in the module:

- `MAX_WEIGHT`: the maximum weight allowed for a cargo. Set it to 777.555.
- `MIN_WEIGHT`: the minimum weight allowed for a cargo. Set it to 44.2222.


### Cargo Class

The class should be able to store a description of the cargo (as a statically allocated array of characters) and the weight of the cargo (in tonnes).  Anytime an attribute is updated, the class must validate the new value; if the new value is not valid, the class must reject the new value.

***Valid Description***: a string of at most `MAX_DESC` characters (not including the null terminator).

***Valid Weight***: a floating point number in double precision in the interval `[MIN_WEIGHT, MAX_WEIGHT]`.


#### Class Public Members

- `void initialize(const char* desc, double weight)`: a modifier that receives two parameters (description and weight). Calls the functions below to set the value for the attributes to the value received as parameters.
- `const char* getDesc() const`: a query that returns the description of the cargo
- `double getWeight() const`: a query that returns the weight of the cargo
- `void setDesc(const char* description)`: a modifier that sets the description of the cargo. If the string is longer than `MAX_DESC`, accept only `MAX_DESC` characters.
- `void setWeight(double weight)`: a modifier that sets the weight of the cargo. If the parameter is invalid, set the attribute to `MIN_WEIGHT`.


## Train Module

Modify the module `Train` according to the following specs.

### Train Class

To the class `Train`, you must add a few extra functions and update the implementation of `display`.


#### Class Public Members

- `bool swapCargo(Train& other)`: swap the cargo between the two trains only if both trains are valid and carry valid cargo. Return `true` if a change has been made, `false` otherwise.
- `bool increaseCargo(double weight)`: increases the carried cargo by `weight` tonnes **only** if the current train is valid, carries valid cargo and the new weight doesn't exceed `MAX_WEIGHT`. If the new cargo exceeds the capcity, do not accept more than capacity. Return `true` if a change has been made, `false` otherwise.
- `bool decreaseCargo(double weight)`: decreases the carried cargo by `weight` tonnes **only** if the current train is valid, carries valid cargo and the new weight is not less than `MIN_WEIGHT`. If the new cargo is below the lower limit, do not go below the lower limit. Return `true` if a change has been made, `false` otherwise.
- `void display() const`: a query that prints to the screen the content of the current object. The information is printed as follow:
  - if the train is an invalid object, print
  ```txt
  ***Train Summary***
  This is an invalid train.
  ``` 
  - if the train carries no cargo, print
  ```txt
  ***Train Summary***
      Name: [NAME]
        ID: [ID]
  No cargo on this train.
  ```
  - otherwise, print
  ```txt
  ***Train Summary***
      Name: [NAME]
        ID: [ID]
     Cargo: [CARGO_DESCRIPTION]
    Weight: [WEIGHT]
  ```
  - The labels should be printed on a field of size 10 aligned to the right, and the weight should be printed with 2 significant digits.






## `main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.



### Sample Output

The output should look like the one from the `sample_output.txt` file.



## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.


## Submission

To test and demonstrate execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 200/w3/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
