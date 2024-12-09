def read_input(filepath):
	mem = []
	with open(filepath, 'r') as f:
		for line in f:
			nbr = 0
			mem_line = []
			for i in range(len(line)):
				if (line[i] == '\n'):
					continue
				if i % 2 == 0:
					mem_line += list([str(nbr) ]* int(line[i]))
					nbr+=1
				else:
					mem_line += list([str('.')] * int(line[i]))
			mem.append(mem_line)
	return mem
			
def move_file_blocks(mem: list):
	while '.' in mem:
		# with list.pop() we remove the last element of a list
		# in each '.' we replace it with the last element of the list
  		# unless the last element is a '.', which we remove
		if (mem[-1] == '.'):
			mem.pop()
		else:
			i = mem.index('.')
			mem[i] = mem.pop()
	return (mem)
	
 
 
def checksum(mem_line):
	csum = 0
	for index, char in enumerate(mem_line):
		csum += index * int(char) if char.isdigit() else 0
	return csum

def main():
	filepath="../src/puzzle.txt"
	mem = read_input(filepath)
	moved_mem = []
	for i in range(len(mem)):
		moved_mem.append(move_file_blocks(mem[i]))
	
	tchecksum = checksum(moved_mem[0])
	
	# print(f"mem: {mem}")
	# print(f"moved_mem: {moved_mem}")
	print(f"solution: {tchecksum}")
 

if __name__ == "__main__":
	main()