# -*- coding: utf-8 -*-
"""
Created on Sat Jun 27 14:18:26 2020

@author: USER1
"""

filein = open("salein.txt","r")
route = []
for i in range(3):
    content = filein.readline()
    route.append(int(content))
filein.close()
go = max(route)
route.remove(max(route))
back = max(route)
peoplevisited = go + back
fileout = open("saleout.txt","w")
fileout.write(str(peoplevisited))
