die() {
	echo "Error: $1"
	echo "$USAGE"
	exit 1
}

is_uint() {
	[[ "$1" =~ ^[0-9]+$ ]]
}

require_value() {
	local opt="$1"
	local val="$2"
	[ -n "$val" ] || die "$opt requires a value"
}

USAGE="Usage: $0 run|test [-x N] [-n N] <make_target> [-s STRATEGY] [preset|numbers...]"

# Initialize variables
flags=""
nexec=1
number_count=""
args=""
random_args=0
subcmd=""
makecmd=""

# Parse arguments
if [ "$#" -eq 0 ]; then
	die "missing arguments"
fi

# Step 1: Parse run|test (subcommand)
case "$1" in
	run|test)
		subcmd="$1"
		shift
		;;
	*)
		die "first argument must be 'run' or 'test'"
		;;
esac

# Step 2: Parse global flags [-x N] [-n N]
while [ "$#" -gt 0 ]; do
	case "$1" in
		-x)
			require_value "-x" "$2"
			is_uint "$2" || die "-x requires a non-negative integer"
			nexec="$2"
			shift 2
			;;
		-n)
			require_value "-n" "$2"
			is_uint "$2" || die "-n requires a non-negative integer"
			number_count="$2"
			shift 2
			;;
		-*)
			break
			;;
		*)
			break
			;;
	esac
done

# Step 3: Parse make_target
if [ "$#" -eq 0 ]; then
	die "missing make_target"
fi
makecmd="$1"
shift

# Step 4: Parse strategy flag [-s STRATEGY] (can appear after make_target)
while [ "$#" -gt 0 ]; do
	case "$1" in
		-s)
			require_value "-s" "$2"
			flags="--$2"
			shift 2
			;;
		-*)
			die "unknown flag: $1"
			;;
		*)
			die "unexpected argument: $1"
			break
			;;
	esac
done


# Step 5: Parse preset or numbers
if [ "$#" -eq 0 ]; then
	random_args=1
elif [ "$1" = "19_500" ]; then
	args="$(cat disorder19_500.txt | xargs)"
elif [ "$1" = "19_500_mini" ]; then
	args="$(cat disorder19_500_mini.txt | xargs)"
elif [ "$1" = "ex1nums" ]; then
	args="$(cat ex1nums | xargs)"
elif [ "$1" = "worst" ]; then
	args="$(cat /home/ahmbasar/sources/repos/push_swap/worst | xargs)"
else
	args="$*"
fi

echo "args: $args"

test_ps() {
	out=$(	make -s $makecmd flags="$flags" args="$1" err=0 2>&1 1>stdout.txt | tee stderr.log | \
			awk '/opera/ {lastprev=prev; last=$0} {prev=$0} END {print lastprev; print last}'
		)
	read disorder operations < <(echo "$out" | awk -F': ' '/disorder/ {d=$2} /operations/ {o=$2} END {print d, o}')
	disorder=$(echo "$disorder" | sed 's/\x1B\[[0-9;]*[mKJ]//g')
	operations=$(echo "$operations" | sed 's/\x1B\[[0-9;]*[mKJ]//g')


	# cat stdout.txt
	# cat stderr.log
	# echo "args: $1"

	# grep KO from checker_linux output, if exist, then exit with error
	./checker_linux $1 < stdout.txt | grep -E "KO|Error" && {
		echo "KO!, args: $1"
		echo "disorder: $disorder, operations: $operations"
		cat >"$(md5sum <<<$1)_$(md5sum <<<$(cat stdout.txt))" <<EOF
		args: $1
		=================================================================
		$(cat stdout.txt)
EOF
	} || {
		echo -e -n "${LIGHT_GREEN}"
		echo "====================================================================="
			total_ops=$((total_ops + operations))
			i=$2
			echo -n -e "${LIGHT_GREEN}" "[OK!]: "
			echo -e "${CLR_RST}" "exec $i: disorder=$disorder operations=$operations" "tot: $total_ops, avg: $((total_ops / (i+ 1)))" "${LIGHT_GREEN}"
		echo "====================================================================="
	}
	echo -e -n "${CLR_RST}"
}

test_ps_ntimes() {
	for ((i=0; i<nexec; i++)); do
		test_ps "$args" "$i"
	done
}

test() {
	echo "--strategy selected: ${flags:-<default>}"
	echo "makecmd: $makecmd"
	echo "random_args: $random_args"

	# args+=" 1 5 7 9 8 2 3 4 6"
	# args+=" 1 2 3 4 5 6 7 8 9"
	# args+=" $(shuf -i 0-500 -n 500 | xargs)"
	# args+="9996 -4 4996 -3 4997 -2 4998 -1 4999 1 3 2 5000 5001 7 5002 6 5003 5004 8 9999 9998 9997"
	# args+="4996 4997 4998 4999 1 3 2 5000 5001 7 5002 6 5003 5004 8 9999"
	# args+="1 3 2 8 4 7 6 5 9 10 99999" # len 11, bucket ct = 3
	# args+="111111 3 2 8 4 7 6 5 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25" # len 25, bucket ct = 5
	# args+="111111 3"

	# make $makecmd flags="$flags" args="$args" err=0 2>&1 | tee out.log


	GREEN='\033[0;32m'
	LIGHT_GREEN='\033[1;32m'
	CLR_RST='\033[0m'

	total_ops=0
	if [ "$random_args" = "1" ]; then
		for ((i=0; i<nexec; i++)); do
			args="$(shuf -i 0-$number_count -n $number_count | xargs)"
			test_ps "$args" "$i"
		done
	else
		test_ps "$args" "$i"
		# test_ps_ntimes "$args"
	fi

}

test_ps_ntimes() {
	for ((i=0; i<nexec; i++)); do
		test_ps "$args" "$i"
	done
}

test() {
	echo "--strategy selected: ${flags:-<default>}"
	echo "makecmd: $makecmd"
	echo "random_args: $random_args"

	GREEN='\033[0;32m'
	LIGHT_GREEN='\033[1;32m'
	CLR_RST='\033[0m'

	total_ops=0
	if [ "$random_args" = "1" ]; then
		for ((i=0; i<nexec; i++)); do
			args="$(shuf -i 0-$number_count -n $number_count | xargs)"
			test_ps "$args" "$i"
		done
	else
		test_ps "$args" "$i"
	fi
}

run() {
	echo "--strategy selected: ${flags:-<default>}"
	echo "makecmd: $makecmd"
	echo "random_args: $random_args"

	GREEN='\033[0;32m'
	LIGHT_GREEN='\033[1;32m'
	CLR_RST='\033[0m'

	total_ops=0
	if [ "$random_args" = "1" ]; then
		for ((i=0; i<nexec; i++)); do
			args="$(shuf -i 0-500 -n 500 | xargs)"
			test_ps "$args" "$i"
		done
	else
		test_ps "$args" "$i"
	fi
}

"$subcmd"
