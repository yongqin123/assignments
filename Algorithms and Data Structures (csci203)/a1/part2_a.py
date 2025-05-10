def sort_arrays(a,b):
    total = [a,b]
    for s in range(len(total)):
        for i in range(len(total[s])):
            for j in range(0, len(total[s])-i-1):
                if total[s][j] > total[s][j+1]:
                    total[s][j], total[s][j+1] = total[s][j+1], total[s][j] 
    total.append([])
    for i in range(len(total[1])):
        total[2].append(total[0][total[1][i] - 1] )
    return "Sorted A: " + str(total[2]) + "\n" + "Sorted B: " + str(total[1])
a = [7, 3, 8, 21, 5, 11] 
b = [3, 5, 1]  
print(sort_arrays(a,b))  
