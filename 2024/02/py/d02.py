def read_input(file_path):
	reports = []
	with open(file_path, 'r') as fi:
		for line in fi:
			levels = list(map(int, line.split()))
			reports.append(levels)
	return reports

def is_safe(report): 
    increasing = all(1 <= report[i+1] - report[i] <= 3 for i in range(len(report) -1))
    decreasing = all(1 <= report[i] - report[i+1] <= 3 for i in range(len(report) -1))
    return increasing or decreasing

def checker(reports):
    safe_reports = [is_safe(report) for report in reports]
    return safe_reports

def dampener(reports):
    safe_count = 0
    for report in reports:
        if (is_safe(report)):
            safe_count += 1
            continue
        for i in range(len(report)):
            modified_report = report[:i] + report[i+1:] # all elements from the start until i, not included, then from i + 1 till the end
            if (is_safe(modified_report)):
                safe_count += 1
                break
    return safe_count
    
        

def main():
	file_path='../src/puzzle-02.txt'
	reports = read_input(file_path)
 
	safe_reports = checker(reports)
	total_safe_reports = sum(safe_reports)
	print(f"TOTAL SUM OF SAFE REPORTS {total_safe_reports}")
	
	dampened_safe_reports = dampener(reports)
	print(f"DAMPENED SAFE REPORTS {dampened_safe_reports}")
	

if __name__ == "__main__":
	main()