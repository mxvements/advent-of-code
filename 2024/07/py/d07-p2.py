import math

def read_input(filepath):
	test_values = []
	ecuation_values =  []
	with open (filepath, 'r') as f:
		for line in f:
			s = line.strip().split(':')
			test_values.append(int(s[0].strip()))
			ecuation_values.append(list(map(int, s[1].strip().split())))
	return test_values, ecuation_values

def compute_expression(a, b):
    # result = a * 10 ** math.ceil(math.log10(b + 1)) + b #int(str(root) + str(next_val)), thanks reddit
    result = a * 10 ** len(str(b)) + b
    return result

def build_operations_tree(root, ecuation, idx, final_val):
	if idx >= len(ecuation):
		return 0
	next_val = ecuation[idx]
	operations = [
		root + next_val,
  		root * next_val,
		compute_expression(root, next_val) #new concatenation operation ERR CONCATENATNG LARGE NBR
	]
	if int(final_val) in operations:
		return final_val
	for op_result in operations:
		if op_result > int(final_val):
			return 0
		if op_result is not None:
			if build_operations_tree(op_result, ecuation, idx + 1, final_val) == final_val:
				return final_val
	return 0

def solver(ecuation, final_val):
	return build_operations_tree(ecuation[0], ecuation, 1, final_val)


def main():
	filepath="../src/puzzle.txt"
	test_values, ecuation_values = read_input(filepath)
	# print(f"TEST VALUES: {test_values}")
	# print(f"ECUATION VALUES: {ecuation_values}")
	result = 0
	for i in range(len(ecuation_values)):
		result += solver(ecuation_values[i],test_values[i])
	print(f"RESULT: {result}")


if __name__ == "__main__":
	main()