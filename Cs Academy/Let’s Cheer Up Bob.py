import sys
import copy

arr = [[None,None,None],[None,None,None],[None,None,None]]

bob_arr = []
min_turn = []
for line in sys.stdin:
	spl = line.split(" ")
	bob_arr.append((int(spl[0])-1,int(spl[1])-1))


def rec_solve(tur,bt,arr_cpy):
	global min_turn
	global bob_arr
	if len(min_turn) != 0 and len(tur) >= len(min_turn):
		return
	found_m = False
	while not found_m:
		if arr_cpy[bob_arr[bt][0]][bob_arr[bt][1]] != 2:
			arr_cpy[bob_arr[bt][0]][bob_arr[bt][1]] = 1
			found_m = True
		else:
			bt+=1

		if bt >= len(bob_arr):
			return
	
	if bobw(arr_cpy) == 1:
		min_turn = tur
		return
	
	for i in range(3):
		for j in range(3):
			if arr_cpy[i][j] == None:
				arr_cpt = copy.deepcopy(arr_cpy)
				arr_cpt[i][j] = 2
				if bobw(arr_cpt) != -1:
					tcp = tur[:]
					tcp.append((i+1,j+1))
					rec_solve(tcp,bt+1,arr_cpt)



def bobw(arr_cpy):
	for i in range(3):
		if arr_cpy[i][0] == 1 and arr_cpy[i][1] == 1 and arr_cpy[i][2] == 1:
			return 1
		if arr_cpy[0][i] == 1 and arr_cpy[1][i] == 1 and arr_cpy[2][i] == 1:
			return 1
		if arr_cpy[i][0] == 2 and arr_cpy[i][1] == 2 and arr_cpy[i][2] == 2:
			return -1
		if arr_cpy[0][i] == 2 and arr_cpy[1][i] == 2 and arr_cpy[2][i] == 2:
			return -1

	if arr_cpy[0][0] == 1 and arr_cpy[1][1] == 1 and arr_cpy[2][2] == 1:
		return 1
	if arr_cpy[0][2] == 1 and arr_cpy[1][1] == 1 and arr_cpy[2][0] == 1:
		return 1
	if arr_cpy[0][0] == 2 and arr_cpy[1][1] == 2 and arr_cpy[2][2] == 2:
		return -1
	if arr_cpy[0][2] == 2 and arr_cpy[1][1] == 2 and arr_cpy[2][0] == 2:
		return -1

	return 0
		
		
rec_solve([],0,arr[:])
for i in min_turn:
	print(str(i[0]) + " " + str(i[1]))

