#!/bin/bash
next(){
	read -p "Press enter to continue"
}

echo "=====================start========================="
echo "./push_swap"
./push_swap
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap 1"
./push_swap 1
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --a"
./push_swap --a
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple"
./push_swap --simple
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple 1"
./push_swap --simple 1
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple --a"
./push_swap --simple --a
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple --a 1"
./push_swap --simple --a 1
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple --a 2 1"
./push_swap --simple --a 2 1
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple --bench"
./push_swap --simple --bench
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple --bench 1"
./push_swap --simple --bench 1
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple --bench 2 1"
./push_swap --simple --bench 2 1
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --bench"
./push_swap --bench
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --benchh"
./push_swap --benchh
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --benc"
./push_swap --benc
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --bench 1"
./push_swap --bench 1
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --bench 2 1"
./push_swap --bench 2 1
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simpl"
./push_swap --simpl
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simplee"
./push_swap --simplee
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --simple  --bench"
./push_swap --simple  --bench
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --bench --simple 2"
./push_swap --bench --simple  2
echo "=====================end========================="
next
echo "=====================start========================="
echo "./push_swap --bench --simple 2 1"
./push_swap  --bench --simple 2 1
echo "=====================end========================="
next
