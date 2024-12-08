def read_input(filepath):
	game_map = []
	with open(filepath, 'r') as f:
		for line in f:
			game_map.append(line.strip())			
	return game_map

def get_antenas(game_map):
	antenas = []
	for i in range(len(game_map)):
		for j in range(len(game_map[i])):
			if str(game_map[i][j]).isalnum():
				coord = [i, j]
				antenas.append((game_map[i][j], coord))
	return antenas

def get_pairs(antenas):
	antena_pairs = []
	for i in range(len(antenas) - 1):
		for j in range(i+1, len(antenas)):
			if (antenas[i][0] == antenas[j][0]):
				antena_pairs.append([antenas[i], antenas[j]])
	return antena_pairs

def define_antinodes(game_map, antena_pairs):
	antinodes = []
	for i in range(len(antena_pairs)):
		coord1 = antena_pairs[i][0][1]
		coord2 = antena_pairs[i][1][1]
		vector =  [coord2[0] - coord1[0], coord2[1] - coord1[1]]
		# print(f"vector: {vector}")
		antinode_coord1 = [coord1[0]-vector[0], coord1[1]-vector[1]]
		antinode_coord2 = [coord2[0]+vector[0], coord2[1]+vector[1]]
		if antinode_coord1 not in antinodes and 0 <= antinode_coord1[0] < len(game_map) and 0 <= antinode_coord1[1] < len(game_map[0]):
			antinodes.append(antinode_coord1)
		if antinode_coord2 not in antinodes and 0 <= antinode_coord2[0] < len(game_map) and 0 <= antinode_coord2[1] < len(game_map[0]):
			antinodes.append(antinode_coord2)
	return antinodes

def main():
	filepath="../src/puzzle.txt"
	game_map = read_input(filepath)
	antenas = get_antenas(game_map)	
	antena_pairs = get_pairs(antenas)
	antinodes = define_antinodes(game_map, antena_pairs)
 
	print(f"MAP: {game_map}")
	print(f"ANTENAS: {antenas}")
	print(f"ANTENA_PAIRS: {antena_pairs}")
	print(f"ANTINODES: {antinodes}")
	print(f"SOLUTION: {len(antinodes)}")

if __name__ == "__main__":
	main()