
from faker import Faker
import csv

#this is where the filename is stated and created
file = open("testStudents.csv", "w")

writer = csv.writer(file)
fake = Faker(locale='en_US')

#function for creating the inputed number of students wanted
def create_students(num_student):
    for i in range(0,num_student):
        converted_dob = str(fake.date_of_birth(minimum_age=5,maximum_age=18))
        studentAddress = str(fake.street_address() + ", " + fake.city() + ", TX " +  fake.postcode())
        writer.writerow([fake.unique.random_int(min=100000, max=199999), fake.first_name(), converted_dob, studentAddress])

#declare how many entries you want
numStudents = int(input("Enter value of # of students: "))

#calls function
create_students(numStudents)


file.close()



    


