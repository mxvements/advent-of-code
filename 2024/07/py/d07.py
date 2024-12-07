def read_input(filepath):
	test_values = []
	ecuation_values =  []
	with open (filepath, 'r') as f:
		for line in f:
			s = line.strip().split(':')
			test_values.append(int(s[0].strip()))
			ecuation_values.append(list(map(int, s[1].strip().split())))
	return test_values, ecuation_values


def build_operations_tree(root, ecuation, idx, final_val):
	if idx >= len(ecuation):
		return 0
	next_val = ecuation[idx]
	operations = [
		root + next_val,
  		root * next_val,
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

	# result = get_calibration_result(bools, test_values)
	# print(f"bools: {bools}")
	print(f"RESULT: {result}")


if __name__ == "__main__":
	main()