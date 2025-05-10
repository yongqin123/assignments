def sort_arrays(a,b):
    for i in range(len(a)):
        for j in range(0, len(a)-i-1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j] 
    new_a = []
    for i in range(len(b)):
        new_a.append(a[b[i]-1])
    return "Sorted A: " + str(new_a) + "\n" 
a = [7, 3, 8, 21, 5, 11] 
b = [3, 5, 1]  
print(sort_arrays(a,b))  
