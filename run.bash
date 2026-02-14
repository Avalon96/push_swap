args="--medium"
# args="--medium"
# args="--complex"

args+=" "
# args+=" $(shuf -i 0-500 -n 500 | xargs)"
args+=" $(cat /home/ahmbasar/sources/repos/push_swap/worst)"
# args+="9996 -4 4996 -3 4997 -2 4998 -1 4999 1 3 2 5000 5001 7 5002 6 5003 5004 8 9999 9998 9997"

# args+="4996 4997 4998 4999 1 3 2 5000 5001 7 5002 6 5003 5004 8 9999"

# args+="1 3 2 8 4 7 6 5 9 10 99999" # len 11, bucket ct = 3
# args+="111111 3 2 8 4 7 6 5 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25" # len 25, bucket ct = 5
# args+="111111 3"

make run args="$args" err=0
