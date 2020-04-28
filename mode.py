# find the mode of an array of numbers

def get_mode_brute_force(nums):
    mode = None
    max_count = 0
    for potential_mode in nums:
        # get its count 
        count = 0
        for num in nums:
            if num == potential_mode:
                count += 1
            
            # is it a new mode 
            if count > max_count:
                max_count = count
                mode = potential_mode
    return mode

def get_mode_sorting(nums):
    # edge cases
    if len(nums) == 0:
        return None
    elif len(nums) == 1:
        return nums[0]
    
    sorted_nums = sorted(nums)
    mode, previous_num = None, None
    max_count, current_count = 0, 0

    for current_num in sorted_nums:

        # update count
        if current_num == previous_num:
            current_count += 1
        
        # new mode?
        if current_num > previous_num:
            max_count = current_count
            mode = current_num
    
        # reset for next iteration
        if current_num != previous_num:
            current_count = 1
        previous_num = current_num

    return mode

def get_mode_hashing(nums):
    # keys: numbers in input array
    # values: number of time key appears

    counts = {}

    # get the counts
    for num in nums:
        if nums in counts:
            counts[num] += 1
        else:
            counts[num] = 1
    
    # get the number with the max count

    max_count = 0
    mode = None

    for num, count in counts.items():
        if count > max_count:
            max_count = count  
            mode = num
    
    return mode
    

