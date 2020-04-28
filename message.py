names =  input("enter names separated by commas: ") # get and process input for a list of names
names = names.split(",")

assignments = input("enter number of assignments separated by commas: ")  # get and process input for a list of the number of assignments
assignments = assignments.split(",")
assignments = list(map(int,assignments))

grades =  input("enter grades separated by commas: ") # get and process input for a list of grades
grades = grades.split(",")
grades = list(map(int,grades))

# message string to be used for each student
# HINT: use .format() with this string in your for loop
message = "Hi {},\n\nThis is a reminder that you have {} assignments left to \
submit before you can graduate. You're current grade is {} and can increase \
to {} if you submit all assignments before the due date.\n\n"

# write a for loop that iterates through each set of names, assignments, and grades to print each student's message
for name, assignment, grade in zip(names,assignments,grades):
    possible_grade = grade+(2*assignment)
    print(message.format(name, assignment, grade, possible_grade))
