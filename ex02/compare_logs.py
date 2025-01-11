def strip_timestamps(line):
    return line.split(']', 1)[-1].strip()

def compare_logs(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        lines1 = f1.readlines()
        lines2 = f2.readlines()

    if len(lines1) != len(lines2):
        print(f"Files have a different number of lines: {len(lines1)} vs {len(lines2)}")
        return

    differences = []
    for i, (line1, line2) in enumerate(zip(lines1, lines2)):
        stripped1 = strip_timestamps(line1)
        stripped2 = strip_timestamps(line2)
        if stripped1 != stripped2:
            differences.append((i + 1, stripped1, stripped2))
    
    if differences:
        print("Differences found:")
        for line_num, content1, content2 in differences:
            print(f"Line {line_num}:")
            print(f"  File1: {content1}")
            print(f"  File2: {content2}")
    else:
        print("The files are identical except for timestamps.")

if __name__ == "__main__":
    compare_logs('19920104_091532.log', 'txt.txt')
