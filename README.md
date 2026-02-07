*This project has been created as part of the 42 curriculum by aunverdi, ahmbasar.*

# push_swap

## Description

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

push_swap takes an array of numbers in any order, calculates the **disorder** (how sorted the array inititally is), then uses the best algorithm based on the disorder.

* O(n²)       for Low Disorder    (disorder < 0.2)
* O(n√n)      for Medium Disorder (0.2 ≤ disorder < 0.5)
* O(nlogn)    for High Disorder   (disorder ≥ 0.5)


## Instructions

## Resources

- <https://www.w3schools.com/dsa/dsa_algo_insertionsort.php>
- <https://www.w3schools.com/dsa/dsa_algo_radixsort.php>

AI is used for deciding which algorithms to use and learning the chunk-based algorithm.

# DSA
