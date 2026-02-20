*This project has been created as part of the 42 curriculum by aunverdi, ahmbasar.*

# push_swap

## Description
push_swap takes an array of numbers in any order, calculates the **disorder** (how sorted the array inititally is), then uses the best algorithm based on the disorder. There are 5 flags you can use with push_swap.

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

### Project Structure

```txt
.
├── cmd.c                       # Command source file
├── push_swap.h                 # Header file for push_swap
├── push_swap.c                 # Source file for push_swap
├── Makefile                    # Ana yapım dosyası
├── libft/                      # Oluşturulan final kütüphane
└── README.md
```

* O(n²)       for Low Disorder    (disorder < 0.2)
* O(n√n)      for Medium Disorder (0.2 ≤ disorder < 0.5)
* O(nlogn)    for High Disorder   (disorder ≥ 0.5)


## Instructions
Use the make command in the root folder to create push_swap. The numbers can be inputted in various ways, such as:

```txt
push_swap -1 0 1 2 3 4 5
push_swap "-1 0 1 2 3 4 5"
xargs push_swap < test.txt
```

## Resources

- <https://www.w3schools.com/dsa/dsa_algo_insertionsort.php>
- <https://www.w3schools.com/dsa/dsa_algo_radixsort.php>

AI is used for deciding which algorithms to use.

# DSA

## Disorder
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

Computing disorder using this method requires O(n²) time and O(1) additional space.

## Adaptive Sort
Adaptive chooses which sorting algorithm to use based on disorder.
```txt
Low Disorder (< 0.2)
Medium Disorder (0.2 ≤ Disorder < 0.5)
High Disorder (Disorder ≥ 0.5)
```

For low disorder inputs, we use an insertion-based sorting strategy.
Insertion Sort has a worst-case time complexity of O(n²), which satisfies the required upper bound for this regime.
However, its runtime is proportional to the number of inversions in the input. When disorder < 0.2, the inversion count is small relative to the maximum possible n(n−1)/2.
Therefore, although the theoretical upper bound remains O(n²), the actual number of corrective operations is significantly reduced for nearly sorted inputs.
Space complexity is O(1) auxiliary space in the Push_swap model.

For medium disorder inputs, we use a bucket-based insertion strategy.
The input is partitioned into √n buckets based on value ranges. Each bucket contains approximately √n elements.
We then apply Insertion Sort within each bucket.
Sorting one bucket costs O((√n)²) = O(n), and since there are √n buckets, the total time complexity is O(n√n).
This reduces the quadratic behavior of insertion sort while still remaining below the O(n²) bound required for low disorder.
Space complexity is O(n) for bucket partitioning within the Push_swap stack operations.

Radix Sort runs in O(n log n) time in the Push_swap model (log n bit passes, each requiring a linear scan).
When disorder ≥ 0.5, the input behaves similarly to a random or reverse-sorted array, where quadratic methods would approach worst-case performance.
Therefore, a bitwise radix strategy ensures predictable O(n log n) behavior regardless of inversion density.
Space complexity remains O(1) auxiliary space, using only the two stacks.

## Insertion Sort

## Bucket Insertion Sort

## Radix Sort
Radix Sort attains an index to each number according to their value (bigger numbers get bigger indices). It then checks the last bit of the indices, pushes them to Stack B if the last bit is 0. After a full rotation in Stack A, every number in Stack B gets pushed back to Stack A. The consequent rotations check the next bit of the indices and do the same operations. After every rotation, the numbers that end up in B gets sorted bitwise, so when we complete the rotation for the number(s) with most bits, everything ends up sorted in A.