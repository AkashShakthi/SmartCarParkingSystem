# SmartCarParkingSystem
Smart Car Paerking System With Arduino
Smart car parking system as follows:
Connect IR sensor at each parking slot to detect cars, and connect two IR sensors at the entrance in the
right manner to detect cars IN and cars OUT. Connect a servo motor at the entrance and keep it at 0
degrees. Display ‘empty’ when the slots are empty and display ‘NA’ when the slots are occupied. Connect
a green and a red LED at each parking slot and light the green LED when the slot is empty and light the
red LED otherwise. When all slots are occupied, display a message at the top of the display (0th row)
‘Sorry, no empty’. Otherwise, display a message ‘slots’.
When a car is at the entrance for going in and there is an empty slot in the parking lot, turn the servo
motor from 0 degrees to 90 degrees and turn to 0 degrees again after 1s. When a car is at the entrance for
going out, do the same with the servo motor. If there is a car at the entrance when no slot is empty, while
displaying the above-mentioned message on the display, do not allow the car to enter the parking lot i.e.
keep the servo motor at 0 degrees
