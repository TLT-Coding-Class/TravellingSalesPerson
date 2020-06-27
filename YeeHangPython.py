fin = open("salesin.txt", "r")
lis = []
for i in range(3):
    lis.append(int(fin.readline()))
fin.close()
lis.remove(min(lis))
ans = lis[0] + lis[1]
fout = open("salesout.txt", "w")
fout.write(str(ans))
fout.close()
