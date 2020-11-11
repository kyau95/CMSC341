# **CMSC341**
This is a composition of the school projects I completed for my CMSC341 course.

I'll also share my thoughts on what I thought about each project and what I learned from each one as well.

<br>

## **Project 0: Memory Management and Using GL**
This was the basic first project to get everyone re-acclimated with the learning environment, but it was also a test on our current knowledge of memory management when tasked to implement a templated Queue class. 

Though the project itself was not difficult as it was only a few functions to implement, it was a good chance to test my skills and also get used to using the external tools for memory checking, such as Valgrind.

<br>

## **Project 1: List of Sparse Matrices**
The project was to make a Linked List object that held a Compressed Sparse Matrix object (CSR object). It was interesting to have to do research on the topic and then apply it to a program that could be used. 

It was challenging as this was the first time I had to implement a data structure to a real life application problem. I learned a lot on the structure of CSRs and how to interact between a pseudo 3d object as I had the CSR containing a broken down matrix and then turduckening them all into a Linked List. 

<br>

## **Project 2: Splay Tree of AVL Trees**
This project was HARD. The concept is there are two main data structures, BookTree which is a splay tree, and WordTree which is an AVL tree. The BookTree object is the main tree structure containing all the AVL tree in its nodes. 

The project was a test of will as the rotations in the AVL tree did not cooperate. I spent a lot of time breaking down the process and relearning it each time. I didn't complete the project on time and it was a very humbling experience to have a project of this magnitude. Will revisit and finish another day.

<br>

## **Project 3: ER Triage Prioritization Process**
This project was much nicer compared to the previous two. The project was to make a priority queue from a skew heap data structure. Each node contained a Patient object with their respective information to determine their priority in the queue. 

This project introduced to me the concept of function pointers. Though the concept is not difficult, it is strange to those that have not witnessed it before. I think though, I will stick to more lambdas over function pointers unless necessary. 

The skew heap itself was not too challenging. The merges took some time to get right and make sure they end up in the correct order so that each insertion would result in O(logn) time. The most challenging part to me was when rebuilding the entire heap after changing the function pointer that determined the priority of each node. Overall the result was O(nlogn) restructures and O(logn) merges.

<br>

## **Project 4: Hash Table of Heaps**
In progress. Breaking for now after project3.
