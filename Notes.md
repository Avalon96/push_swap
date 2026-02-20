# Push_swap Notes

## Usage

> ./push_swap [[--bench] **strategy**] numbers...

## Edge Cases

single argument case
./push_swap 2



In case of error, it must display "Error" followed by a \n on the standard error.
Errors include, for example: **arguments that are not integers, integers outside the
valid range, or duplicate values**


## Todo
- operation executer

## DSA
* O(n²)       Insertion Sort
* O(n√n)      Chunk-Based Insertion Sort
* O(nlogn)    Radix Sort

## PDF commands
* ./push_swap 2 1 3 6 5 8
* ./push_swap --simple 5 4 3 2 1
* shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
* shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
* ./push_swap --adaptive 0 one 2 3
* ./push_swap --simple 3 2 3

## Failing Commands
* ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
* ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
* ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l