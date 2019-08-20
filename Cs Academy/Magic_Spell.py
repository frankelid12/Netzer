dic_num = {}

dic_num["xrtp"]=0
dic_num["pmr"]=1
dic_num["yep"]=2
dic_num["yjtrr"]=3
dic_num["gpit"]=4
dic_num["gobr"]=5
dic_num["doc"]=6
dic_num["drbrm"]=7
dic_num["rohjy"]=8
dic_num["momr"]=9
sum = 1;
a = int(input())
arr_num = []
for i in range(0,a):
    n = 0
    b = input()
    b = b.split(" ")

    for num in b:
        n= n*10
        n = n + dic_num[num]
    arr_num.append(str(n))


for num in arr_num:
    dec = int(num,16)
    sum = sum*dec
    
print(sum)

#the word are the numbers is letters but every letter going left .place left like "zero" is "xrtp"
"""
כל מילה בקסם היא המספר באותיות רק לקחת כל אות ימינה
לאחר מכן אחרי שממירים את המילה לספרה
בונים את המספר 
המילה הראשונה היא הספרת יחידות השנייה עשרות וכך הלאה
ולאחר מכן ממירים את המספר לבסיס עשרוני בהניתן המספר העכשיו בבסיס 16 , 
כאילו להגיד שהמספר 10 הוא תאכלס בהקסדמצימלי ואז להמיר אותו ל16
לאחר מכן כופלים את המספרים אחד בשני
"""
