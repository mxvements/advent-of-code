def read_input(filepath):
	game_map = []
	with open(filepath, 'r') as f:
		for line in f:
			game_map.append([c for c in line.strip()])
	# print(f"MAP:{map}")
	return game_map

def walk_map(game_map):
	directions = {
		'up': '^',
		'left': '>',
		'down': 'v',
		'right': '<'
		}
	vectors = {
		'up' : (-1, 0),
		'left': (0, 1),
		'down': (1, 0),
		'right': (0, -1)
	}
 
	def get_guard_pos(game_map, directions):
		for i in range(len(game_map)):
			for j in range(len(game_map[i])):
				if (game_map[i][j] in directions.values()):
					for key, value in directions.items():
						return key, [i, j]
		return None, None

	def is_valid_pos(pos, rows, cols):
		return 0 <= pos[0] < rows and 0 <= pos[1] < cols

	def is_at_exit(guard_pos, rows, cols):
		return guard_pos[0] == rows or guard_pos[1] == cols
		
	def rotate_guard(vector, vectors):
		keys = list(vectors.keys())
		values = list(vectors.values())
		if vector in values:
			current_idx = values.index(vector)
			next_idx = (current_idx + 1) % len(values)
			return values[next_idx]
		
	def move_guard(game_map):
		key, guard_pos = get_guard_pos(game_map, directions)
		if not key or not guard_pos:
			return

		rows, cols = len(game_map), len(game_map[0])
		current_pos = guard_pos
		vector = vectors[key]
  
		while True:
			next_pos = [current_pos[0] + vector[0], current_pos[1] + vector[1]]
			if is_at_exit(next_pos, rows, cols):
				game_map[current_pos[0]][current_pos[1]] = 'X'
				break
			if is_valid_pos(next_pos, rows, cols) and game_map[next_pos[0]][next_pos[1]] == '#':
				vector = rotate_guard(vector, vectors)
			elif is_valid_pos(current_pos, rows, cols): 
				game_map[current_pos[0]][current_pos[1]] = 'X'
				current_pos = next_pos
			
	move_guard(game_map)
	print(f"MAP: {game_map}")
	return game_map
	
def count_x(game_map):
	return (sum(row.count('X') for row in game_map))

def main():
	filepath="../src/puzzle.txt"
	game_gap = read_input(filepath)
	final_game_map = walk_map(game_gap)
	solution = count_x (final_game_map)
	print(f"SOLUTION:{solution}")


 

if __name__ == "__main__":
	main()