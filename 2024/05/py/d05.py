def read_input(filepath):
	rules = []
	updates = []
	with open(filepath, 'r') as f:
		for line in f:
			if ('|' in line):
				rule = list(map(int, line.split('|')))
				rules.append(rule)
			if ('|' not in line and line != '\n'):
				update = list(map(int, line.split(',')))
				updates.append(update)
	return rules, updates

def get_right_updates_pattern(input_rules, updates):
	all_updates_rules = []
	all_updates_rules_bool = []
	right_updates = []
	#get combination of rules that need to be checked for each update
	for update in updates:
		update_rules = [
      		[update[i], update[j]] 
        	for i in range(len(update))
         	for j in range(i + 1, len(update))
        ]
		all_updates_rules.append(update_rules)
	# print(f"UPDATES_RULES: {all_updates_rules}")
	#check if those updates_rules exist in rules
	for update_rules in all_updates_rules:
		update_rules_bool = [1 if rule in input_rules else 0 for rule in update_rules]
		all_updates_rules_bool.append(update_rules_bool)
	# print(f"UPDATES_RULES_BOOLS: {all_updates_rules_bool}")
	#return absolute bool for each update
	for update_rules_bool in all_updates_rules_bool:
		b = 1
		for num in update_rules_bool:
			b *= num
		right_updates.append(b)
	# print(f"RIGHT_UPDATES_BOOL: {right_updates}")
	return right_updates
	
def get_right_updates(updates, pattern):
	right_updates = []
	for i in range(len(updates)):
		if pattern[i] == 1:
			right_updates.append(updates[i])
	# print(f"RIGHT_UPDATES_BOOL: {right_updates}")
	return right_updates

def main():
	filepath="../src/puzzle.txt"
	rules, updates = read_input(filepath)
	# print(f"RULES: {rules}")
	# print(f"UPDATES: {updates}")
	right_updates_pattern = get_right_updates_pattern(rules, updates)
	right_updates = get_right_updates(updates, right_updates_pattern)
	solution = sum(update[len(update) // 2] for update in right_updates)
	# print(f"RIGHT_UPDATES: {right_updates}")
	print(f"SOLUTION: {solution}")
 

if __name__ == "__main__":
	main()