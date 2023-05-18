#!/usr/bin/python3

print("""
This program takes in times for each day and outputs the amount of time worked throughout the week
If you did not work on that day, do not input anything.
Please enter times in military time in the format TTTT-TTTT
""")

# Method to find the time elapsed from start time to end time
def find_time(times):

    try:

        # print(times[0][:2])
        start_time = [times[0][:2], times[0][2:]]
        # print(start_time)
        # end_time = times[1].split(":")
        end_time = [times[1][:2], times[1][2:]]
        # print(end_time)

        # (end_hours * 60 + end_minutes) - (start_hours * 60 + start_minutes)
        return (int(end_time[0]) * 60 + int(end_time[1])) - (int(start_time[0]) * 60 + int(start_time[1]))
    except:
        return 0

sum = 0
# Get user input for times worked
sunday_times = find_time(list(time for time in input("Sunday Times: ").strip().split("-")))
monday_times = find_time(list(time for time in input("Monday Times: ").strip().split("-")))
tuesday_times = find_time(list(time for time in input("Tuesday Times: ").strip().split("-")))
wednesday_times = find_time(list(time for time in input("Wednesday Times: ").strip().split("-")))
thursday_times = find_time(list(time for time in input("Thursday Times: ").strip().split("-")))
friday_times = find_time(list(time for time in input("Friday Times: ").strip().split("-")))
saturday_times = find_time(list(time for time in input("Saturday Times: ").strip().split("-")))

# Add up all the times
sum += sunday_times
sum += monday_times
sum += tuesday_times
sum += wednesday_times
sum += thursday_times
sum += friday_times
sum += saturday_times

print(f"{sunday_times} + {monday_times} + {tuesday_times} + {wednesday_times} + {thursday_times} + {friday_times} + {saturday_times} = {sum} minutes")

# find the hours and minutes from the sum
hours = sum // 60
minutes = sum % 60

print(f"{hours} hours and {minutes} minutes")

# Add wage functionality
try: 
    wage = float(input("How much are you paid per hour?\n"))
    total = wage * hours + wage * (minutes / 60)

    print(f"Your resulting amount is ${total}")
except:
    pass