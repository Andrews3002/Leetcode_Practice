nums = [0,1,2,2,3,0,4,2]
val = 2
k = 0

oldnums = nums

nums = []

for i in oldnums:
    if i != val:
        nums.append(i)
        k = k + 1

for i in range(k,len(oldnums)):
    nums.append("_")

print(k)
print(nums)
