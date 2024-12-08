def read_input(file_path):
	muls = []
	bools = []
	with open(file_path, 'r') as fi:
		for line in fi:
			mul = line.strip().split('mul')
			muls += mul
		b = 1
		for m in muls:
			bools.append(b)
			if 'do()' in m:
				b = 1
			elif "don't()" in m:
				b = 0
	return muls, bools

def get_mult_nbr(muls, bools):
	nbrs = []
	for i in range(len(muls)):
		if (bools[i]):
			start = muls[i].split(')')
			rstart = start[0].strip('(')
			args = rstart.split(',')
			if len(args) == 2 and args[0].isdigit() and args[1].isdigit():
				nbrs.append([int(args[0]), int(args[1])])
	return nbrs
		

def main():
	file_path='../src/puzzle.txt'
	muls, bools = read_input(file_path)
	nbrs = get_mult_nbr(muls, bools)
	total_sum = 0
	for nb in nbrs:
		total_sum += nb[0] * nb[1]

	# print(f"MULS: {muls}")
	# print(f"BOOLS: {bools}")
	print(f"NBRS: {nbrs}")
	print(f"TOTAL_SUM: {total_sum}")
	
 	

if __name__ == "__main__":
	main()