# find the repeat number

def get_repeat_number(nums):
    nums_seen = set()

    for num in nums:
        if num in nums_seen:
            return num
        nums_seen.add(num)
        