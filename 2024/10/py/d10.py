def read_input(filepath):
	game_map = []
	trailheads = []
	with open(filepath, 'r') as f:
		game_map = [line.strip('\n') for line in f]
		trailheads = [[i,j]
                for i, line in enumerate(game_map)
                for j, c in enumerate(line)
                if c == '0']
	return game_map, trailheads

def trailheads_scores(game_map, trailheads):
	vector = [(1,0), (0,1), (-1,0), (0, -1)]
	diff = 1
	top = '9'
	scores = [[] for _ in range(len(trailheads))]
	# print(f"init scores: {scores}")

	def follow_path(i, trail_x, trail_y):
		for j, (dx, dy) in enumerate(vector):
			x, y = trail_x + dx, trail_y + dy
			if 0 <= x < len(game_map) and 0 <= y < len(game_map[0]):
				if int(game_map[x][y]) - int(game_map[trail_x][trail_y]) == diff and game_map[x][y] == top and [x,y] not in trail_top:
					trail_top.append([x,y])
				if int(game_map[x][y]) - int(game_map[trail_x][trail_y]) == diff:
					follow_path(i, trail_x + dx, trail_y + dy)

	for i, (trail_x, trail_y) in enumerate(trailheads):
		trail_top = []
		follow_path(trail_top, trail_x, trail_y)
		scores[i] = len(trail_top)
		# print(f"trail_top: {trail_top}")
	return scores



def main():
	filepath="../src/puzzle.txt"
	game_map, trailheads = read_input(filepath)
	scores = trailheads_scores(game_map, trailheads)
	solution = sum([s for s in scores])

	print(f"game_map: {game_map}")
	print(f"trailheads: {trailheads}")
	print(f"scores: {scores}")
	print(f"solution: {solution}")





if __name__ == "__main__":
	main()