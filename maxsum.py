# maximum sum such that no two elements are adjacent

def max_sum(nums):

    if nums == None or len(nums)==0:
        return 0
    
    incl = 0
    excl = 0
    
    for num in nums:
        new_excl = max(incl,excl)
        incl = excl + num
        excl = new_excl

    return max(incl,excl)

arr = [5,5,10,100,10,5]

print(max_sum(arr))