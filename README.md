## Fitness Center Management System

In this code, I have implemented a simple fitness center management system to manage memberships, personal training sessions, and fitness classes. The program consists of 9 files: 4 header files (.hpp), 4 source files (.cpp) for classes, and 1 main source file (.cpp) where program execution begins. The program starts by creating an object of the class "FitnessCenterManager" with the name "fitnessCenter". This initializes the fitness center itself, with which we can manage the overall operations of the fitness center.

## Class "FitnessCenterManager" 
Consists of three vectors to store members as objects of class "Member", fitness group classes as objects of class "FitnessClass", and personal trainings as objects of class "PersonalTraining".

Abilities:

Print lists of members, classes, or personal trainings (methods: void printFitnessTraining(), void printClasses(), void printMembers()).

Add members, classes, or personal trainings to the overall lists of members, classes, or trainings (methods: addMember, addFClass, addPTraining).

Remove members, classes, or personal trainings by their name from the whole fitness center (methods: removeMember, removeClass, removePTraining).

Search for information about members, classes, or personal trainings by their name.

Enroll members to classes or personal trainings by their name.

## Class "Member"
Represents fitness center members with properties such as name, email, phone number, and membership type. Also, every member can be outputted with the operator "<<", and compared to other members by membership type with operators <, >, <=, >=. It also has operators =, ==, and != that equate and verify members' equality.

## Class "FitnessClass"
Represents different types of fitness classes offered by the center, with properties like name, description, instructor, schedule, number of members, array "group" that represents a group of members, and where all members are written when they enroll in the class. A bool variable "freePlaces" represents the availability of free places (1 if there are some free places in the group, 0 if there are completely no places). If a class has no free places, the user can create another object of "FitnessClass" with the same properties, and enroll a member in this new object. We can't change anything from the fitness class except for adding and removing from groups and the variable "freePlaces" that depends on it. That's why the "FitnessClass" class doesn't have any wrong "setters".

Every class can also be outputted with the operator "<<", and compared to other classes by the maximum number of members in the group with operators <, >, <=, >=. It also has operators =, ==, and != that equate and verify classes' equality.

## Class "PersonalTraining"
Inherits class "FitnessClass" because it also has properties like name, description, instructor, schedule, and bool variable "freePlaces". As it is a "personal" training, the number of members is set by default to 1. Also, in contrast to "FitnessClass", we can change the schedule (that's why the schedule is protected in "FitnessClass") as we want because in personal schedule, the member must choose their schedule themselves. When the program enrolls a member in personal training, it asks the user to input a suitable day.

Personal Trainings are compared by description symbols length.

## USER INTERFACE

A simple text-based user interface helps to interact with the fitness center management system. The interface allows users to perform operations like managing members, managing fitness classes, and managing personal
