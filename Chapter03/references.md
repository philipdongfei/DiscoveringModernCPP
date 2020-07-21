#Refernces[^1]

To reflect the lvalue/rvalue and const/non-const distinctions, there are three kinds of references:

&emsp;* _lvalue references_: to refer to objects whose value we want to change
&emsp;* **const**_references_: to refer to objects whose value we do not want to change (eg., a constant)
&emsp;* _rvalue references_: to refer to objects whose value we do not need to preserve after we have used it (e.g., a temporary)

Collectively, they are called _references_. The first two are both called _lvalue references_.


##Rvalue References
The basic idea of having more than one kind of reference is to support different users of objects:
&emsp;* A non-**const** lvalue reference refers to an object, to which the user of the reference can write.
&emsp;* A **const** lvalue reference refers to a constant, which is immutable from the point of view of the user of the reference.
&emsp;* An rvalue reference refers to a temporary object, which the user of the reference can (and typically will) modify, assuming that the object will never be used again.

The **&&** declarator operator means "rvalue reference." We do _not_ use **const** rvalue references; most of the benefits from using rvalue references involve writing to the object to which it refers. Both a **const** lvalue reference and an rvalue reference can bind to an rvalue. However, the purposes will be fundamentally different:
* We use rvalue references to implement a "destructive read" for optimization of what would otherwise have required a copy.
* We use a **const** lvalue reference to prevent modification of an argument.

##References to References

It you take a reference to a reference to a type, you get a reference to that type, rather than some kind of special reference to reference type.

**using rr_i = int&&;
  using lr_i = int&;
  using rr_rr_i = rr_i&&; // "int && && " is an int&&
  using lr_rr_i = rr_i&;  // "int && &" is an int&
  using rr_lr_i = lr_i&&; // "int & &&" is an int&
  using lr_lr_i = lr_i&;  // "int & &" is an int&**
In other words, lvalue reference always wins. This makes sense: nothing we can do with types can change the fact that an lvalue reference refers to an lvalue. This is sometimes known as *reference collapse*.

##Pointers and References

If you need to change which object to refer to, use a pointer.

Conversely, if you want to be sure that a name always refers to the same object, use a reference.

If you want to use a user-defined (overloaded) operator on something that refers to an object, use a reference.

If you want a collection of something that refers to an object, you must use a pointer.

[^1] Chapter 7. Pointers, Arrays, and References -- "The C++ Programming Lanugage"" 
