/*
There are N blocks, numbered from 0 to N-1, arranged in a row.
A couple of frogs were sitting together on one block when they had a terrible quarrel.
Now they want to jump away from one another so that the distance between them will be as large as possible.
The distance between blocks numbered J and K, where J≤ K, is computed as K-J +1.
The frogs can only jump up, meaning that they can move from one block to another only,
if the two blocks are adjacent and the second block is of the same or greater height as the first.
What is the longest distance that they can possibly create between each other,
if they also chose to sit on the optimal starting block initially?
Write a function:
A
int solution(vector<int> &blocks);
that, given an array blocks consisting of N integers denoting the heights of the blocks,
returns the longest possible distance that two frogs can make between each other starting from one of the blocks.
*/

#include <vector>
#include <iostream>

int solution(std::vector<int>& blocks);