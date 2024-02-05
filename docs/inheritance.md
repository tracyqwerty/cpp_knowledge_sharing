# Inheritance

In C++, the difference between private, public, and protected inheritance is all about how the base class members are accessible to the derived class and other parts of the program. Here’s a breakdown of each type:

### Public Inheritance (`class Derived : public Base`)

- **Public Members of Base Class**: Become public members of the derived class.
- **Protected Members of Base Class**: Become protected members of the derived class.
- **Private Members of Base Class**: Are not accessible directly from the derived class.

Public inheritance is the most common form of inheritance in C++ and is used to express an "is-a" relationship between the derived and the base class. It means that an object of the derived class is also an object of the base class.

### Protected Inheritance (`class Derived : protected Base`)

- **Public Members of Base Class**: Become protected members of the derived class.
- **Protected Members of Base Class**: Become protected members of the derived class.
- **Private Members of Base Class**: Are not accessible directly from the derived class.

Protected inheritance is less commonly used. It's a way to say that the derived class is implemented in terms of the base class, but does not necessarily adhere to an "is-a" relationship for outside classes. This means that outside the class, the derived class does not have the base class interface, but inside the class (and its subclasses), it does.

### Private Inheritance (`class Derived : private Base`)

- **Public Members of Base Class**: Become private members of the derived class.
- **Protected Members of Base Class**: Become private members of the derived class.
- **Private Members of Base Class**: Are not accessible directly from the derived class.

Private inheritance is also less common and is a stronger way to say that the derived class is implemented in terms of the base class, without any relationship to the base class being visible to outside classes. It can be thought of as a "has-a" relationship more than an "is-a" relationship, albeit with inheritance instead of composition.

### Summary

- **Public Inheritance**: Used for "is-a" relationships, where derived objects need to be used as base objects.
- **Protected Inheritance**: Makes the public and protected members of the base class protected in the derived class, limiting the access further to the class itself and its derived classes.
- **Private Inheritance**: Essentially turns all inherited members into private members of the derived class, which is useful for implementation inheritance where the derived class uses the base class functionality internally without exposing it.

In practice, public inheritance is used most frequently to express a clear "is-a" relationship, while protected and private inheritances are used in more specific scenarios where the relationship between the base and derived classes is intended to be used in a more controlled or restricted manner.