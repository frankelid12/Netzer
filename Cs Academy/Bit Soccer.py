import sys
import numpy
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   
input_parser = parser()
def get_word():
    global input_parser
    return next(input_parser)
def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)
numPlayers = get_number()
pl = sys.stdin.readline().strip('\n').strip('\r').strip(' ').split(' ')
plst = [int(i) for i in pl]
countq = get_number()
blst = plst[:]
for _ in range(0, countq):
    goal = get_number()
    ngoal = ~goal
    And = numpy.array( [player for player in blst if (ngoal & player) == 0], dtype = 'int')
    if And == []:
        print ("NO")
    else:
        f = numpy.bitwise_or.reduce(And)
        if f == goal:
            print ("YES")
        else:
            print ("NO")
    
    
    