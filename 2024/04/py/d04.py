def read_input(filepath):
	wordgrid = []
	with open (filepath, 'r') as f:
		for line in f:
			wordgrid.append([c for c in line.strip()])
	return wordgrid
    
    
def word_search(wordgrid, search):
	rows, cols = len(wordgrid), len(wordgrid[0])
	counter = 0
	directions = [(-1,0), (1,0), (0,-1), (0,1), (-1,-1), (1,1), (-1,1), (1,-1)]

	def is_valid(x, y):
		return 0 <= x < rows and 0 <= y < cols

	def is_word_at(r, c, dr, dc):
		for i in range(len(search)):
			nr, nc = r + (i * dr), c + (i * dc)
			if not is_valid(nr, nc) or (wordgrid[nr][nc] != search[i]):	
				return False
		return True

	#recursive funct in word_search
	for r in range(rows):
		for c in range(cols):
			for dr, dc in directions:
				if (is_word_at(r, c, dr, dc)):
					counter += 1 

	return counter


def main():
	filepath="../src/puzzle.txt"
	wordgrid = read_input(filepath)
	count = word_search(wordgrid, "XMAS")
	print(f"XMAS COUNT: {count}")
 

if __name__ == "__main__":
	main()