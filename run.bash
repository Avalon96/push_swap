args="--simple"
# args="--medium"
# args="--complex"

args+=" $(shuf -i 0-9999 -n 39 | xargs)"

make run args="$args"
