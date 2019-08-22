
a = int(input())
arr = list()
arr.insert(0, 0)
arr.insert(1, 1)
#every 60 numbers the fibonachi modulo 10 repeat it self 
#so i belt a array of 60 numbersof the fibonaci that repeat it self
for i in range(2,60):
    arr.insert(i, (arr[i-1]+arr[i-2])%10)
for i in range(0,a):
    b = int(input())
    #and to answer the qeustion we do the nubmer + 1 and module so we can get answer
    print(arr[(b+1)%60])

