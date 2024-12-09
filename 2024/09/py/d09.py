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
					j = int(line[i]) 
					while (j > 0):
						mem_line.append(nbr)
						j -= 1
					nbr += 1 #what if number of multiple digits
				else:
					mem_line += list(str('.') * int(line[i]))
			mem.append(mem_line)
	return mem
			
def move_file_blocks(mem_line):
	moved_mem_line = []
	j = len(mem_line) - 1
	
	for i in range(0,len(mem_line)):
		if (i > j):
			moved_mem_line.append('.')
		elif (str(mem_line[i]).isdigit()):
			moved_mem_line.append(mem_line[i])
		elif (mem_line[i] == '.' and j >= 0 and str(mem_line[j]).isdigit()):
			# print(f"mem[i]: {mem_line[i]}")
			# print(f"mem[j]: {mem_line[j]}")
			moved_mem_line.append(mem_line[j])
			j -= 1
			if (mem_line[j] == '.'):
				j -= 1
    
	return (moved_mem_line)
	

def main():
	filepath="../src/test.txt"
	mem = read_input(filepath)
	moved_mem = []
	for i in range(len(mem)):
		moved_mem.append(move_file_blocks(mem[i]))
	
	checksum = 0
	for m_mem in moved_mem:
		for i in range(len(m_mem)):
			if str(m_mem[i]).isdigit():
				print(f"m_mem[i]: {m_mem[i]}")
				print(f"i: {i}")
          
				checksum += int(m_mem[i]) * i 
	
	print(f"mem: {mem}")
	print(f"moved_mem: {moved_mem}")
	print(f"solution: {checksum}")
 

if __name__ == "__main__":
	main()