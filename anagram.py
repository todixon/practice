def anagram(s1,s2):
    
    # remove spaces and make letters lowercase
    s1 = s1.replace(' ','').lower()
    s2 = s2.replace(' ','').lower()

    # setup dictionary
    count = {}

    # make sure strings are same length
    if len(s1) != len(s2):
        return False


    for letter in s1:
        if letter in count:
            count[letter] += 1
        else:
            count[letter] = 1

    for letter in s2:
        if letter in count:
            count[letter] -= 1
        else:
            count[letter] = 1

    for k in count:
        if count[k] != 0:
            return False
    
    return True

#s1 = "clint eastwood"
#s2 = "old west action"

print(anagram("clint eastwood", "old west action"))