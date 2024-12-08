def read_input(file_path):
	muls = []
	with open(file_path, 'r') as fi:
		for line in fi:
			mul =line.strip().split('mul')
			muls += mul
	return muls

def get_mult_nbr(muls):
	nbrs = []
	for i in range(len(muls)):
		start = muls[i].split(')')
		rstart = start[0].strip('(')
		args = rstart.split(',')
		if len(args) == 2 and args[0].isdigit() and args[1].isdigit():
			nbrs.append([int(args[0]), int(args[1])])
	return nbrs
		

def main():
	file_path='../src/puzzle.txt'
	muls = read_input(file_path)
	nbrs = get_mult_nbr(muls)
	total_sum = 0
	for nb in nbrs:
		total_sum += nb[0] * nb[1]

	print(f"MULS: {muls}")
	print(f"NBRS: {nbrs}")
	print(f"TOTAL_SUM: {total_sum}")
	
 	

if __name__ == "__main__":
	main()