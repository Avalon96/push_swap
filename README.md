*This project has been created as part of the 42 curriculum by aunverdi, ahmbasar.*

# push_swap

## Description
push_swap takes an array of numbers in any order, calculates the **disorder** (how sorted the array inititally is), then uses the best algorithm based on the disorder.

There are 5 flags you can use with push_swap.

Benchmark mode (--bench) displays:
* Disorder (% with 2 decimals)
* Strategy name and its complexity class
* Total number of operations

The algorithm of choice can be forced with flags.

* --simple for O(n²)
* --medium for O(n√n)
* --complex for O(nlogn)
* --adaptive chooses an algorithm based on disorder

**Example Usage**
```txt
push_swap --bench -1 0 1 2 3 4 5
push_swap --bench --simple -1 0 1 2 3 4 5
push_swap --complex -1 0 1 2 3 4 5
```

## Instructions
Use the make command in the root folder to create push_swap. The numbers can be inputted in various ways, such as:

```txt
push_swap -1 0 1 2 3 4 5
push_swap "-1 0 1 2 3 4 5"
xargs push_swap < test.txt
push_swap --bench -1 0 1 2 3 4 5
push_swap --bench --complex -1 0 1 2 3 4 5
xargs push_swap --medium < test.txt
```

## DSA

### Disorder
Disorder measures how far the input sequence deviates from ascending order.
It is defined as the ratio of inversion pairs to the total possible pairs.
For each index i, we compare it with every subsequent index j > i.
If a[i] > a[j], the pair is counted as an inversion.

```txt
Disorder = number_of_inversion_pairs/total_pairs
```
This produces a normalized value in the range [0, 1], where:

*  0 means fully sorted
*  1 means fully reverse-sorted

### Insertion Sort

Insertion Sort pushes 2 elements to B blindly, then repeatedly finds the cheapest element in A to move into its correct position in B, maintaining B in descending order throughout. The cost of each move is calculated by checking how many rotations are needed in both stacks, doing them simultaneously when both stacks rotate in the same direction. This continues until 3 elements remain in A, which get sorted directly with at most 2 operations. Then each element from B is inserted into its correct position in A one by one using the same approach, and finally A is rotated so the minimum is on top.

### Bucket-Insertion Sort

Bucket Sort assigns each number a bucket index based on where its value falls in the overall range — smaller numbers get lower bucket indices. It then pushes elements from A to B bucket by bucket, starting from the smallest bucket, finding the cheapest element to push next within each bucket by rotating to the nearest member and pushing it. Once all elements are in B, roughly grouped by value range, they get inserted back into A one by one using the same approach as Insertion Sort — finding the cheapest combination of rotations to place each element in its correct position in A. Finally A is rotated so the minimum is on top.

### Radix Sort

Radix Sort assigns each number an index based on its relative value. It then performs one pass per bit, starting from the least significant. In each pass, elements whose current bit is 0 are pushed to B, and elements whose bit is 1 are rotated to the bottom of A. After a full pass, B is pushed back to A, placing 0-bit elements on top of 1-bit elements. Repeating this for every bit results in a fully sorted A, because each pass refines the order one bit at a time while preserving the ordering established by previous passes.

### Adaptive Sort
Adaptive Sort chooses which sorting algorithm to use based on disorder.

* O(n²)       for Low Disorder    (disorder < 0.2)
* O(n√n)      for Medium Disorder (0.2 ≤ disorder < 0.5)
* O(nlogn)    for High Disorder   (disorder ≥ 0.5)

### Space and Time Complexity
For low disorder inputs, we use Insertion Sort.
Insertion Sort has a worst-case time complexity of O(n²), which satisfies the required upper bound for this regime.
Its runtime is proportional to the number of inversions in the input. When disorder < 0.2, the inversion count is small relative to the maximum possible n(n−1)/2.
Therefore, although the theoretical upper bound remains O(n²), the actual number of corrective operations is significantly reduced for nearly sorted inputs.
Space complexity is O(1) auxiliary space in the Push_swap model.

For medium disorder inputs, we use a hybrid of Bucket and Insertion Sort.
The input is partitioned into √n buckets based on value ranges. Each bucket contains approximately √n elements.
We then apply Insertion Sort within each bucket.
Sorting one bucket costs O((√n)²) = O(n), and since there are √n buckets, the total time complexity is O(n√n).
This reduces the quadratic behavior of insertion sort while still remaining below the O(n²) bound required for low disorder.
Space complexity is O(n) for bucket partitioning within the Push_swap stack operations.

Radix Sort runs in O(n log n) time in the Push_swap model (log n bit passes, each requiring a linear scan).
When disorder ≥ 0.5, the input behaves similarly to a random or reverse-sorted array, where quadratic methods would approach worst-case performance.
Therefore, a bitwise radix strategy ensures predictable O(n log n) behavior regardless of inversion density.
Space complexity remains O(1) auxiliary space, using only the two stacks.

## Resources

- <https://www.w3schools.com/dsa/dsa_algo_insertionsort.php>
- <https://www.w3schools.com/dsa/dsa_algo_radixsort.php>
- <https://en.wikipedia.org/wiki/Bucket_sort>
- <https://www.youtube.com/watch?v=VuXbEb5ywrU>

AI is used for deciding which algorithms to use, as well as learning how to optimize the operation count.

2 4 6 8 0