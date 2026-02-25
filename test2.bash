#!/bin/bash

test_specials(){
	local files=(
		"disorder0_100.txt"
		"disorder0_500.txt"
		"disorder100_100.txt"
		"disorder100_500.txt"
		"disorder19_100.txt"
		"disorder19_500.txt"
		"disorder21_100.txt"
		"disorder21_500.txt"
		"disorder49_100.txt"
		"disorder49_500.txt"
		"disorder51_100.txt"
		"disorder51_500.txt"
		"disorder80_100.txt"
		"disorder80_500.txt"
	)
	for file in "${files[@]}"; do
		if ! [ -f "./$file" ]; then
			echo "[FATAL]: File $file not found in ./"
			exit 1
		fi
		./run.bash test run -s "$1" --bench "$file" | grep -E "KO" && echo "fail" || echo "$1 $file: OK"
	done
}

test_specials "simple"
test_specials "medium"
test_specials "complex"
