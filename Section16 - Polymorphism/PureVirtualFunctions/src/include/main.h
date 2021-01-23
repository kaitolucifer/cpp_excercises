#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>

class Shape                         // Abstract Base class
{
private:
                                    // attributes common to all shapes
public:
    virtual void draw() = 0;        // pure virtual funciton
    virtual void rotate() = 0;      // pure virtual function
    virtual ~Shape() {}
};

class OpenShape : public Shape      // Abstract Base class
{
public:
    virtual ~OpenShape() {}
};

class ClosedShape : public Shape     // Abstract Base class
{
public:
    virtual ~ClosedShape() {}
};

class Line : public OpenShape       // Concrete class
{
public:
    virtual void draw() override
    {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a line" << std::endl;
    }
};

class Circle : public ClosedShape   // Concrete class
{
public:
    virtual void draw() override
    {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a circle" << std::endl;
    }
};

class Square : public ClosedShape   // Concrete class
{
public:
    virtual void draw() override
    {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a square" << std::endl;
    }
};

#endif // _MAIN_H_
