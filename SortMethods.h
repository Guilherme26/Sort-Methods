/*
	Just Remembering some notations
	Θ -> Theta is a notation that is used to describe tight bound to the behaviour of a function F(n), i.e,
			claims that there is two constants k and k', a number M and a function G(n), such that kG(n) <= F(n) <= k'G(n)
			for all n >= M.
	Big-o or O -> This is a notation that shows an upper bound that asymptotically domains the algorithm execution time.
					Is right to say that a function F(n) is assymptotically dominated by G(n) if there is a constant k and 
					a number M such that F(n) <= kG(n) for all n >= M.
*/


/*
	A Heap structure can be one of the following types MAX-HEAP or MIN-HEAP. A MAX-HEAP is a structure where a father 
	is always bigger than its child, in the other hand, a MIN-HEAP is the one where a father is always smaller than 
	its child. Those properties must be followed by all the members of the structure. The function below has a O(lg n) 
	behaviour since every execution checks all the way of a branch down.
*/
void resetHeap(int *vector, int cur_index, int vec_size, int (*compare)(int, int));


/*
	Since the structure just need to be built once, this method is called just one time through the execution, its
	upper bound is represented as O(nlg n) although it is not a tight bound.
*/
void buildHeap(int *vector, int vec_size, int (*compare)(int, int));

/*
	This implementation do not need extra memory to use the Heap structure, instead, a vector of size n+1 is used
	where the first position is unused and the sons of a "node" are on 2n and 2n+1 position respectively. The type of 
	sort is described by the "compare" function referenced below. That function must return a value equals 0 or 1 that 
	represents a true state or a false one. To pass the function that sort the items as a parameter just write its 
	name on Heapsort's calling. Heapsort holds a time complexity of Θ(nlg n), which is constant for all the cases 
	[Worst, Average, Best] 
*/
void heapsort(int *vector, int vec_size, int (*compare)(int, int));
