# AOC DAY01
# as a piscine to learn python
# methods used:
# 	append()
#	split(), default delimitier is an space
#	zip(), to iterate over two lists at the same time
#	sort()

def read_input(file_path):
	first_list = []
	secnd_list = []
	with open(file_path, 'r') as fi:
		for line in fi:
			numbers = line.split()
			first_list.append(int(numbers[0]))
			secnd_list.append(int(numbers[1]))
	return first_list, secnd_list

def get_recurrence(first_list, second_list):
	recurrence = []
	for el_left in first_list:
		rec = 0
		for el_right in second_list:
			if (el_left == el_right):
				rec += 1
		recurrence.append(int(rec))
	return recurrence

def main():
	file_path='../src/puzzle-01.txt'
	first_list, secnd_list = read_input(file_path)
	
	first_list.sort()
	secnd_list.sort()
	
	total_distance = 0
	for f, s in zip(first_list, secnd_list):
		total_distance += abs(f -s)
	print(f"SUM OF DISTANCES: {total_distance}")

	recurrence = get_recurrence(first_list, secnd_list)
	recurrence_prod = 0
	for f, s in zip(first_list, recurrence):
		recurrence_prod += f * s
	print(f"RECURRENCE PRODUCT SUM: {recurrence_prod}")


if __name__ == "__main__":
	main()