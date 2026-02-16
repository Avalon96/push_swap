// function compute_disorder(stack a):
// 	mistakes = 0
// 	total_pairs = 0
// 	for i from 0 to size(a)-1:
// 		for j from i+1 to size(a)-1:
// 			total_pairs += 1
// 			if a[i] > a[j]:
// 				mistakes += 1
// 	return mistakes / total_pairs

// take process arguments, compute disorderity, and print it
// nodejs code

var process = require('process');

function compute_disorder(stack) {
	let mistakes = 0;
	let total_pairs = 0;
	for (let i = 0; i < stack.length; i++) {
		for (let j = i + 1; j < stack.length; j++) {
			total_pairs++;
			if (stack[i] > stack[j]) {
				mistakes++;
			}
		}
	}
	return mistakes / total_pairs;
}

function main() {
	const args = process.argv.slice(2).map(Number);
	const disorder = compute_disorder(args);
	console.log(`disorder: ${disorder}`);
}

main();
