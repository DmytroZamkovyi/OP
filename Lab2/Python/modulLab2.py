from pickle import dump, load
import time


def get_time(str_time: str):
    res = time.strptime(str_time, "%H:%M")
    return res


def get_arrival_time(t1, t2):
    if_night = False
    h1 = t1.tm_hour
    h2 = t2.tm_hour
    m1 = t1.tm_min
    m2 = t2.tm_min
    h = h1 + h2
    m = m1 + m2
    if m >= 60:
        h = h + 1
        m = m - 60
    if h >= 24:
        h = h - 24
        if_night = True
    else:
        if (h1 >= 23 or h1 < 6 or (h1 == 6 and m1 == 0)) or (h >= 23 or h < 6 or (h == 6 and m == 0)):
            if_night = True
    return time.strptime(str(h) + ":" + str(m), "%H:%M"), if_night


def write_file(file_name: str, mode: str) -> None:
    bus = {}
    with open(file_name, f'{mode}b') as file:
        leng = int(input('Enter how many buses you want to add: '))
        if leng <= 0:
            print('ERROR: incorrect number specified')
        else:
            for i in range(leng):
                bus['destination'] = input('\nEnter the destination: ')
                bus['departure_time'] = input('Enter the time of departure in the format <hh:mm>: ')
                bus['duration_trip'] = input('Enter the travel time in the format <hh:mm>: ')
                dump(bus, file)


def read_file(file_name: str) -> None:
    with open(file_name, 'rb') as file:
        file.seek(0)

        while True:
            try:
                bus = load(file)
                departure_time = get_time(bus['departure_time'])
                duration_trip = get_time(bus['duration_trip'])
                arrival_time, if_night = get_arrival_time(departure_time, duration_trip)

                print(f"\nDestination: {bus['destination']}")
                if if_night: print('Is NIGHT!')
                print(f"Time of departure: {departure_time.tm_hour}:{departure_time.tm_min}"
                      f"\nTime of travel: {duration_trip.tm_hour}:{duration_trip.tm_min}"
                      f"\nArrival time: {arrival_time.tm_hour}:{arrival_time.tm_min}")
            except EOFError:
                break


def remove_unnecessary_items(new_file_name: str, file_name: str) -> None:
    with open(file_name, 'rb') as file:
        file.seek(0)
        with open(new_file_name, 'wb') as new_file:
            new_file.seek(0)
            while True:
                try:
                    bus = load(file)
                    departure_time = get_time(bus['departure_time'])
                    duration_trip = get_time(bus['duration_trip'])
                    arrival_time, if_night = get_arrival_time(departure_time, duration_trip)
                    if_del = if_night and duration_trip.tm_hour < 17
                    if not if_del:
                        dump(bus, new_file)

                except EOFError:
                    break
