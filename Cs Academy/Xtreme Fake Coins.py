import sys
import itertools

ch = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
firstline = sys.stdin.readline().strip()
N = int(firstline.split(",")[0])
M = int(firstline.split(",")[1])
experiments = []
for line in sys.stdin:
	line = line.strip()
	experiments.append(line.split("-"))
def retx(A,B):
	results = []
	results.append("9")
	for exp in experiments:
		if A in exp[0] and B not in exp[1]:
			results.append("0")
		elif A in exp[1] and B not in exp[0]:
			results.append("2")
		elif B in exp[0] and A not in exp[1]:
			results.append("0")
		elif B in exp[1] and A not in exp[0]:
			results.append("2")
		else:
			results.append("1")
	return int("".join(results))
ch_r = ch[:N]
combos = [x for x in itertools.combinations(ch_r,2)]
combo_dict = {}
for combo in combos:
	key = retx(combo[0],combo[1])
	val = combo[0] + combo[1]
	if key in combo_dict:
		combo_dict[key].append(val)
	else:
		combo_dict[key] = [val]

f_lst = []
for key in combo_dict:
	if len(combo_dict[key]) > 1:
		fin_combos = [x for x in itertools.combinations(combo_dict[key],2)]
		for x in fin_combos:
			f_lst.append(x[0] + "=" + x[1])

f_lst.sort()
for x in f_lst:
	print(x)
