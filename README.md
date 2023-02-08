# Traveling Salesman Problem
The travelling salesman problem is a classic mathematical problem. It is used for optimization in the field of computer science and operational research. 

### AIM:

Given a list of cities and the distances between them, to find the shortest possible route that visit each city and return to the origin city.

### OBJECTIVE:

The objective of the project is to demonstrate an algorithm to solve the traveling salesman problem. The console application focuses on one of the purest applications of the problem and solves it using a working algorithm which in our case is using Greedy’s algorithm.

### WHAT IS A 'GREEDY ALGORITHM’?

A greedy algorithm, as the name suggests, always makes the choice that seems to be the best at that moment. This means that it makes a locally-optimal choice in the hope that this choice will lead to a globally-optimal solution.

* How do you decide which choice is optimal?

  Assume that you have an objective function that needs to be optimized (either maximized or minimized) at a given point. A Greedy algorithm makes greedy choices at each step to ensure that the objective function is optimized. The Greedy algorithm has only one shot to compute the optimal solution so that it never goes back and reverses the decision.

### TOP LEVEL BLOCK DIAGRAM


### GREEDY ALGORITHM

1. Enter the number of cities, places, etc.  
2. Prompt the user to enter the distance between each and every city. 
3. Prompt the user to enter the starting city.
4. Repeat step 2, until all cities are done.  
5. Print the cost matrix, which is a graphical representation of all cities with their distances in a matrix.
6.Find the path with the lowest cost or distance, this is an indirect way of calculating the (n-1)! path.  
 7. Go to the starting city and print it, then mark that city as done. 
 8. Find the minimum valued element in the row corresponding to the city number. 
 9. Print the corresponding city name of that element and mark that city as done. 
 10. Go to the next city, after recording the distance travelled or the cost. 
 11. Go to step 7, until all the rows (cities) are marked as done.  
 12. After printing the path, print the distance travelled or the total cost of the given path. 



### SAMPLE OUTPUT


### APPLICATIONS OF TSP

* Fulfilling orders by logistic companies.
* Drilling.
* Astronomy.
* School bus scheduling.
* GPS satellite systems.
* Designing and building printed circuit boards.
* Analyzing an X-Ray.


















