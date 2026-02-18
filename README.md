*This project has been created as part of the 42 curriculum by aunverdi, ahmbasar.*

# push_swap

## Description
push_swap takes an array of numbers in any order, calculates the **disorder** (how sorted the array inititally is), then uses the best algorithm based on the disorder. There are 4 flags you can use with push_swap.

Benchmark mode (--bench) displays:
* Disorder (% with 2 decimals)
* Strategy name and its complexity class
* Total number of operations

The algorithm of choice can be forced with flags.

* --simple for O(n²)
* --medium for O(n√n)
* --complex for O(nlogn)

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

AI is used for deciding which algorithms to use and learning the O(n√n) algorithm.

# DSA

## Insertion Sort

## O(n√n)

## Radix Sort
Radix Sort checks the last bit of the numbers, pushes them to Stack B if the last bit is 0. After a full rotation in Stack A, every number in Stack B gets pushed back to Stack A. The consequent rotations check the next bit and do the same operations. After every rotation, the numbers that end up in B gets sorted bitwise, so when we complete the rotation for the number(s) with most bits, everything ends up sorted in A.