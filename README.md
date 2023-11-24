# push_swapbro

Push swap is an algorithm oriented project from the 42 school. 
I used the Radix sort algorithm to sort my stacks. Here's a brief explanation; 
The algorithm systematically arranges digits from the least significant to the most significant,
employing counting sort as a subroutine to sort values at each digit place. In base 10, this entails sorting by the one's place, 
followed by the ten's place, and so forth. To illustrate, for a three-digit number in base 10, counting sort is applied 
to arrange the 1st, 10th, and 100th places, yielding a fully sorted list. Consider an 8-element array where sorting begins at the unit place, 
progressing to the tenth position and repeating until reaching the last significant location. Taking the array [132, 543, 783, 63, 7, 49, 898], 
the largest element, 898, with three digits, dictates the loop's extension to hundreds of places (3 times). Subsequently, each significant location undergoes 
sorting via counting sort, commencing with the unit place digits (A = 0).

