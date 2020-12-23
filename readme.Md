## Primitive calculator

Algorithm description:
This algorithm uses dynamic programming to store the minimum operations necessary to go from 1 to n using only +1, *2 and *3. It calculates the minimum operations necessary for each integer from 1 to n and stores them in an array. Each calculation takes the minimum number of operations of 

Steps in algorithm:
	1. Initiate a cache as an array of size n+1 (size + 1 prevents need to check if 0th element in array) initialize elements to be 0
	2. Loop n times and store the minimum solution after checking all possible solutions
		a. Set cache[n] = cache[n-1]
		b. If n %2 take minimum of step a value and cache[n/2] + 1
		c. If n %3 take minimum of value from previous two steps and cache[n/3] + 1
	3. Next initiate another array to store the intermediate values with size = to the last element in the cache. Initialize elements to be 1
	4. Now we loop k times where k is the operations needed and set the k-1 value from back to front and the kth value is our n.
		a. Set result[i] = n
		b. Then we reduce our n towards 0 with the following steps
			i. n is calculated by checking if cache[n-1] == cache[n] - 1
			ii. Else if  (n % 2 == 0 && (cache[n / 2] == cache[n] - 1))
			iii. Else the n must be (n % 3 == 0 && (cache[n / 3] == cache[n] - 1)
The result array is returned
