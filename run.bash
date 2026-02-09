args="--simple"
# args="--medium"
# args="--complex"

args+=" "
# args+=" $(shuf -i 0-9999 -n 39 | xargs)"
args+="1 3 2"

make run args="$args" err=0
